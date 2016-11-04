#include "mongo/platform/basic.h"

#include "inject.h"

namespace mongo {

REGISTER_DOCUMENT_SOURCE(inject, DocumentSourceInject::createFromBson);

boost::optional<Document> DocumentSourceInject::getNext() {
    // We check for interrupts so that a user killOp or a $maxTimeMillis can stop the process
    pExpCtx->checkForInterrupt();

    // Pull the next doc from the parent stage.
    // Here we are doing a 1 to 1 transformation, but you could pull N or all docs here.
    // For example if you wanted to compute an average you would just put getNext in a loop.
    boost::optional<Document> input = pSource->getNext();
    if (!input) {
        // input exhausted, we're done here
        return boost::none;
    }

    // This is the meat of our agg stage.
    // You can put whatever you wat here.
    MutableDocument output(*input);
    output.setNestedField(FieldPath(_field), Value(5.17));
    return output.freeze();
}

const char* DocumentSourceInject::getSourceName() const {
    return "$inject";
}

Value DocumentSourceInject::serialize(bool explain) const {
    // TODO: this should output the serialized form.
    invariant(false);
}

DocumentSource::GetDepsReturn DocumentSourceInject::getDependencies(DepsTracker* deps) const {
    // If you can take a subset of fields you can fill this in so the optimizer can do better work.
    return SEE_NEXT;
}

boost::intrusive_ptr<DocumentSource> DocumentSourceInject::createFromBson(
    BSONElement elem, const boost::intrusive_ptr<ExpressionContext>& pExpCtx) {
    // This is where we parse the options to the stage.
    // You could required any BSON you want here.
    boost::intrusive_ptr<DocumentSourceInject> inject(new DocumentSourceInject(pExpCtx));
    inject->_field = elem.String();
    return inject;
}

DocumentSourceInject::DocumentSourceInject(const boost::intrusive_ptr<ExpressionContext>& pExpCtx)
    : DocumentSource(pExpCtx) {}
}
