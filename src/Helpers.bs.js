// Generated by BUCKLESCRIPT VERSION 4.0.0, PLEASE EDIT WITH CARE
'use strict';

var Documentdb = require("documentdb");

function makeDbClient(uri, masterKey, _) {
  return new Documentdb.DocumentClient(uri, {
              masterKey: masterKey
            });
}

function getDatabase(dbClient, databaseId, _) {
  var databaseUrl = Documentdb.UriFactory.createDatabaseUri(databaseId);
  return new Promise((function (resolve, reject) {
                dbClient.readDatabase(databaseUrl, (function (err, res) {
                        if (err == null) {
                          return resolve(res);
                        } else {
                          return reject(err);
                        }
                      }));
                return /* () */0;
              }));
}

function getCollection(dbClient, databaseId, collectionId, _) {
  var collectionUri = Documentdb.UriFactory.createDocumentCollectionUri(databaseId, collectionId);
  return new Promise((function (resolve, reject) {
                dbClient.readCollection(collectionUri, (function (err, res) {
                        if (err == null) {
                          return resolve(res);
                        } else {
                          return reject(err);
                        }
                      }));
                return /* () */0;
              }));
}

function getDocument(dbClient, databaseId, collectionId, documentId, _) {
  var documentUri = Documentdb.UriFactory.createDocumentUri(databaseId, collectionId, documentId);
  return new Promise((function (resolve, reject) {
                dbClient.readDocument(documentUri, (function (err, res) {
                        if (err == null) {
                          return resolve(res);
                        } else {
                          return reject(err);
                        }
                      }));
                return /* () */0;
              }));
}

function createDocument(dbClient, databaseId, collectionId, $$document, _) {
  var collectionUri = Documentdb.UriFactory.createDocumentCollectionUri(databaseId, collectionId);
  return new Promise((function (resolve, reject) {
                dbClient.createDocument(collectionUri, $$document, (function (err, res) {
                        if (err == null) {
                          return resolve(res);
                        } else {
                          return reject(err);
                        }
                      }));
                return /* () */0;
              }));
}

function getByQuery(dbClient, databaseId, collectionId, query, _) {
  var collectionUri = Documentdb.UriFactory.createDocumentCollectionUri(databaseId, collectionId);
  return new Promise((function (resolve, reject) {
                dbClient.queryDocuments(collectionUri, query).toArray((function (err, data) {
                        if (err == null) {
                          return resolve(data);
                        } else {
                          return reject(err);
                        }
                      }));
                return /* () */0;
              }));
}

function replaceDocument(dbClient, databaseId, collectionId, documentId, $$document, _) {
  var documentUri = Documentdb.UriFactory.createDocumentUri(databaseId, collectionId, documentId);
  return new Promise((function (resolve, reject) {
                dbClient.replaceDocument(documentUri, $$document, (function (err, res) {
                        if (err == null) {
                          return resolve(res);
                        } else {
                          return reject(err);
                        }
                      }));
                return /* () */0;
              }));
}

exports.makeDbClient = makeDbClient;
exports.getDatabase = getDatabase;
exports.getCollection = getCollection;
exports.getDocument = getDocument;
exports.createDocument = createDocument;
exports.getByQuery = getByQuery;
exports.replaceDocument = replaceDocument;
/* documentdb Not a pure module */
