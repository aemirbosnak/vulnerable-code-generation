//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a database
int createDatabase(char* filename) {
    FILE* db = fopen(filename, "w");
    if (db == NULL) {
        printf("Error: Could not create database file.\n");
        return -1;
    }

    printf("Database created successfully.\n");
    return 0;
}

// Function to insert data into the database
int insertData(char* filename, char* key, char* value) {
    FILE* db = fopen(filename, "a");
    if (db == NULL) {
        printf("Error: Could not open database file.\n");
        return -1;
    }

    fprintf(db, "%s,%s\n", key, value);
    fclose(db);
    printf("Data inserted successfully.\n");
    return 0;
}

// Function to retrieve data from the database
int retrieveData(char* filename, char* key) {
    FILE* db = fopen(filename, "r");
    if (db == NULL) {
        printf("Error: Could not open database file.\n");
        return -1;
    }

    char line[100];
    fgets(line, sizeof(line), db);

    if (strstr(line, key)!= NULL) {
        char* value = strstr(line, key);
        printf("%s\n", value + strlen(key) + 1);
    } else {
        printf("Key not found.\n");
    }

    fclose(db);
    return 0;
}

// Function to update data in the database
int updateData(char* filename, char* key, char* newValue) {
    FILE* db = fopen(filename, "w");
    if (db == NULL) {
        printf("Error: Could not open database file.\n");
        return -1;
    }

    char line[100];
    fgets(line, sizeof(line), db);

    if (strstr(line, key)!= NULL) {
        char* value = strstr(line, key);
        strcpy(value, newValue);
        printf("Data updated successfully.\n");
        fclose(db);
        return 0;
    } else {
        printf("Key not found.\n");
        fclose(db);
        return -1;
    }
}

// Main function
int main() {
    char* filename = "database.txt";
    char* key = "name";
    char* value = "John Doe";

    createDatabase(filename);
    insertData(filename, key, value);
    retrieveData(filename, key);
    updateData(filename, key, "Jane Doe");

    return 0;
}