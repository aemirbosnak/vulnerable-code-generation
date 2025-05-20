//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a database
void create_database(char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to create file: %s\n", filename);
        exit(1);
    }
    fclose(file);
}

// Function to insert data into the database
void insert_data(char* filename, char* key, char* value) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        exit(1);
    }
    fprintf(file, "%s %s\n", key, value);
    fclose(file);
}

// Function to search data in the database
int search_data(char* filename, char* key) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        exit(1);
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, key)) {
            printf("Data found for key: %s\n", key);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int main() {
    char filename[] = "database.txt";
    create_database(filename);

    insert_data(filename, "Name", "John");
    insert_data(filename, "Age", "25");
    insert_data(filename, "Country", "USA");

    printf("Search data for key 'Name': %s\n", search_data(filename, "Name")? "Data found" : "Data not found");
    printf("Search data for key 'Country': %s\n", search_data(filename, "Country")? "Data found" : "Data not found");

    return 0;
}