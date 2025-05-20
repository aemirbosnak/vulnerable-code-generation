//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char data[MAX_DATA_SIZE];
} Database;

Database* createDatabase() {
    Database* db = (Database*)malloc(sizeof(Database));
    return db;
}

void addDataToDatabase(Database* db, const char* key, const char* data) {
    if (db == NULL) {
        fprintf(stderr, "Database is null\n");
        return;
    }
    
    strcpy(db->key, key);
    strcpy(db->data, data);
}

const char* retrieveDataFromDatabase(Database* db, const char* key) {
    if (db == NULL) {
        fprintf(stderr, "Database is null\n");
        return NULL;
    }
    
    if (strcmp(db->key, key) == 0) {
        return db->data;
    }
    
    return NULL;
}

void updateDataInDatabase(Database* db, const char* key, const char* data) {
    if (db == NULL) {
        fprintf(stderr, "Database is null\n");
        return;
    }
    
    if (strcmp(db->key, key) == 0) {
        strcpy(db->data, data);
    }
}

void deleteDataFromDatabase(Database* db, const char* key) {
    if (db == NULL) {
        fprintf(stderr, "Database is null\n");
        return;
    }
    
    if (strcmp(db->key, key) == 0) {
        free(db);
        db = NULL;
    }
}

int main() {
    Database* db = createDatabase();
    if (db == NULL) {
        fprintf(stderr, "Failed to create database\n");
        return 1;
    }
    
    addDataToDatabase(db, "key1", "data1");
    addDataToDatabase(db, "key2", "data2");
    
    const char* retrievedData = retrieveDataFromDatabase(db, "key1");
    printf("Retrieved data for key1: %s\n", retrievedData);
    free(retrievedData);
    
    updateDataInDatabase(db, "key1", "new data1");
    retrievedData = retrieveDataFromDatabase(db, "key1");
    printf("Updated retrieved data for key1: %s\n", retrievedData);
    free(retrievedData);
    
    deleteDataFromDatabase(db, "key2");
    const char* deletedData = retrieveDataFromDatabase(db, "key2");
    printf("Retrieved deleted data for key2: %s\n", deletedData);
    free(deletedData);
    
    return 0;
}