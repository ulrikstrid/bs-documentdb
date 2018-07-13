type uriFactory;

[@bs.module "documentdb"] external uriFactory : uriFactory = "UriFactory";

type documentClient;

[@bs.deriving abstract]
type clientOptions = {masterKey: string};

[@bs.new] [@bs.module "documentdb"]
external documentClient : (~uri: string, clientOptions) => documentClient =
  "DocumentClient";

type dbUri;

[@bs.send] external createDatabaseUri : (uriFactory, string) => dbUri = "";

[@bs.send]
external readDatabase :
  (documentClient, dbUri, (Js.Nullable.t(exn), 'res) => unit) => unit =
  "";

type collectionUri;

[@bs.send]
external createCollectionUri :
  (uriFactory, ~databaseId: string, ~collectionId: string) => collectionUri =
  "createDocumentCollectionUri";

[@bs.send]
external readCollection :
  (
    documentClient,
    ~collectionUri: collectionUri,
    (Js.Nullable.t(exn), 'res) => unit
  ) =>
  unit =
  "";

type documentUri;

[@bs.send]
external createDocumentUri :
  (
    uriFactory,
    ~databaseId: string,
    ~collectionId: string,
    ~documentId: string
  ) =>
  documentUri =
  "";

[@bs.send]
external readDocument :
  (
    documentClient,
    ~documentUri: documentUri,
    (Js.Nullable.t(exn), 'res) => unit
  ) =>
  unit =
  "";

[@bs.send]
external createDocument :
  (
    documentClient,
    ~collectionUri: collectionUri,
    ~document: 'a,
    (Js.Nullable.t(exn), 'a) => unit
  ) =>
  unit =
  "";

[@bs.send]
external replaceDocument :
  (
    documentClient,
    ~documentUri: documentUri,
    ~document: 'a,
    (Js.Nullable.t(exn), 'a) => unit
  ) =>
  unit =
  "";

type documentQuery;

[@bs.send]
external queryDocuments :
  (documentClient, ~collectionUri: collectionUri, ~query: string) =>
  documentQuery =
  "";

[@bs.send]
external queryToArray :
  (documentQuery, (Js.Nullable.t(exn), array('a)) => unit) => unit =
  "toArray";
