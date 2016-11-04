#pragma once

#include "mongo/platform/basic.h"

#include "mongo/db/pipeline/document_source.h"

namespace mongo {

class DocumentSourceInject : public DocumentSource {
public:
    // virtuals from DocumentSource
    virtual boost::optional<Document> getNext();
    virtual const char* getSourceName() const;
    virtual Value serialize(bool explain = false) const;

    virtual GetDepsReturn getDependencies(DepsTracker* deps) const;

    /**
      Create a new projection DocumentSource from BSON.

      This is a convenience for directly handling BSON, and relies on the
      above methods.

      @param pBsonElement the BSONElement with an object named $project
      @param pExpCtx the expression context for the pipeline
      @returns the created projection
     */
    static boost::intrusive_ptr<DocumentSource> createFromBson(
        BSONElement elem, const boost::intrusive_ptr<ExpressionContext>& pExpCtx);

private:
    DocumentSourceInject(const boost::intrusive_ptr<ExpressionContext>& pExpCtx);

    std::string _field;
};
}
