This is a sample aggregation stage that insert a field into every document. 

Steps:

1. Git clone the mongodb source code. 
2. Create a directory called 'modules' in `src/mongo/db/modules`.
3. Git clone this repo as `src/mongo/db/modules/inject`
4. [Build MongoDB](https://github.com/mongodb/mongo/blob/v3.2/docs/building.md)
5. Now try the new aggregation stage:

```js
db.foo.aggregate( { $inject : "funField" } );
```

This gist has been tested with:

* MongoDB master. Currently is at git version `3125749c23f8cf341768ecc37c86e64a2c30a356` or `v3.3.1-229-g3125749`. 
* MongoDB [branch v3.2](https://github.com/mongodb/mongo/tree/v3.2).
* MongoDB [tag r3.2.1](https://github.com/mongodb/mongo/tree/r3.2.1). 


See [Blog: Extending the aggregation framework](http://www.eliothorowitz.com/blog/2015/07/09/extending-the-aggregation-framework/) for more information. 

