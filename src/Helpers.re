let makeDbClient = (~uri, ~masterKey, ()) =>
  DocumentDb.documentClient(~uri, DocumentDb.clientOptions(~masterKey));

let getDatabase = (dbClient, ~databaseId, ()) => {
  let databaseUrl =
    DocumentDb.createDatabaseUri(DocumentDb.uriFactory, databaseId);

  Js.Promise.make((~resolve, ~reject) =>
    DocumentDb.readDatabase(dbClient, databaseUrl, (err, res) =>
      switch (Js.Nullable.toOption(err)) {
      | Some(e) => reject(. e)
      | None => resolve(. res)
      }
    )
  );
};

let getCollection = (dbClient, ~databaseId, ~collectionId, ()) => {
  let collectionUri =
    DocumentDb.createCollectionUri(
      DocumentDb.uriFactory,
      ~databaseId,
      ~collectionId,
    );

  Js.Promise.make((~resolve, ~reject) =>
    DocumentDb.readCollection(dbClient, ~collectionUri, (err, res) =>
      switch (Js.Nullable.toOption(err)) {
      | Some(e) => reject(. e)
      | None => resolve(. res)
      }
    )
  );
};

let getDocument = (dbClient, ~databaseId, ~collectionId, ~documentId, ()) => {
  let documentUri =
    DocumentDb.createDocumentUri(
      DocumentDb.uriFactory,
      ~databaseId,
      ~collectionId,
      ~documentId,
    );

  Js.Promise.make((~resolve, ~reject) =>
    DocumentDb.readDocument(dbClient, ~documentUri, (err, res) =>
      switch (Js.Nullable.toOption(err)) {
      | Some(e) => reject(. e)
      | None => resolve(. res)
      }
    )
  );
};

let createDocument = (dbClient, ~databaseId, ~collectionId, ~document, ()) => {
  let collectionUri =
    DocumentDb.createCollectionUri(
      DocumentDb.uriFactory,
      ~databaseId,
      ~collectionId,
    );

  Js.Promise.make((~resolve, ~reject) =>
    DocumentDb.createDocument(dbClient, ~collectionUri, ~document, (err, res) =>
      switch (Js.Nullable.toOption(err)) {
      | Some(e) => reject(. e)
      | None => resolve(. res)
      }
    )
  );
};

let getByQuery = (dbClient, ~databaseId, ~collectionId, ~query, ()) => {
  let collectionUri =
    DocumentDb.createCollectionUri(
      DocumentDb.uriFactory,
      ~databaseId,
      ~collectionId,
    );

  Js.Promise.make((~resolve, ~reject) =>
    DocumentDb.queryDocuments(dbClient, ~collectionUri, ~query)
    |. DocumentDb.queryToArray((err, data) =>
         switch (Js.Nullable.toOption(err)) {
         | Some(e) => reject(. e)
         | None => resolve(. data)
         }
       )
  );
};

let replaceDocument =
    (dbClient, ~databaseId, ~collectionId, ~documentId, ~document, ()) => {
  let documentUri =
    DocumentDb.createDocumentUri(
      DocumentDb.uriFactory,
      ~databaseId,
      ~collectionId,
      ~documentId,
    );

  Js.Promise.make((~resolve, ~reject) =>
    DocumentDb.replaceDocument(dbClient, ~documentUri, ~document, (err, res) =>
      switch (Js.Nullable.toOption(err)) {
      | Some(e) => reject(. e)
      | None => resolve(. res)
      }
    )
  );
};
