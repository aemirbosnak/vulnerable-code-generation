//FormAI DATASET v1.0 Category: Database Indexing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for the indexing system
typedef struct {
    int key; // unique key
    int position; // position in the database file
} Index;

int main() {
    Index index[100]; // Index array with size 100

    // Open and read the database file
    FILE* db = fopen("database.txt", "r");
    if (db == NULL) {
        printf("Error opening database file!\n");
        return 1;
    }

    char line[256];
    int pos = 0; // current position in the file

    while (fgets(line, sizeof(line), db)) {
        // Parse the line and extract the key
        char* key_str = strtok(line, ",");
        int key = atoi(key_str);

        // Update the index with the key and position
        index[key].key = key;
        index[key].position = pos;

        // Move the file position to the next line
        pos = ftell(db);
    }

    fclose(db);

    // Search for a record by key
    int search_key = 42;
    int found = 0; // flag for whether the record was found

    for (int i = 0; i < 100; i++) {
        if (index[i].key == search_key) {
            // Open the database file and move to the position of the record
            db = fopen("database.txt", "r");
            fseek(db, index[i].position, SEEK_SET);

            // Read the record and print it to the console
            fgets(line, sizeof(line), db);
            printf("Record found: %s", line);

            fclose(db);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found!\n");
    }

    return 0;
}