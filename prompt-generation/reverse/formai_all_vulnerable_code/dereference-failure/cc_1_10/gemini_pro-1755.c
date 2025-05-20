//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: post-apocalyptic
// Amidst the desolate wasteland lies a relic of the ancient world: a database.
// Weary survivors scavenge its depths, seeking solace in its forgotten knowledge.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A table to hold our scavenged data
struct Table {
    char name[20];
    int num_rows;
    int num_columns;
    char** data;
};

// An index to guide us through the chaos
struct Index {
    char* column;
    int* values;
    int num_values;
};

// A list to hold all our scavenger parties
struct IndexList {
    struct Index* index;
    struct IndexList* next;
};

// A database to house our scavenged treasures
struct Database {
    struct Table* table;
    struct IndexList* index_list;
};

// Initialize our database
struct Database* create_database() {
    struct Database* db = malloc(sizeof(struct Database));
    db->table = NULL;
    db->index_list = NULL;
    return db;
}

// Add a table to our database, like a beacon of hope in the wasteland
struct Table* create_table(struct Database* db, char* name, int num_rows, int num_columns) {
    struct Table* table = malloc(sizeof(struct Table));
    strcpy(table->name, name);
    table->num_rows = num_rows;
    table->num_columns = num_columns;
    table->data = malloc(sizeof(char*) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = malloc(sizeof(char) * num_columns);
    }
    db->table = table;
    return table;
}

// Index a column, a lifeline in the sea of data
struct Index* create_index(struct Table* table, char* column) {
    struct Index* index = malloc(sizeof(struct Index));
    index->column = malloc(sizeof(char) * strlen(column));
    strcpy(index->column, column);
    index->values = malloc(sizeof(int) * table->num_rows);
    for (int i = 0; i < table->num_rows; i++) {
        index->values[i] = -1;
    }
    index->num_values = 0;
    return index;
}

// Link the index to the table, connecting knowledge and data
struct IndexList* add_index_to_list(struct IndexList* list, struct Index* index) {
    struct IndexList* new_node = malloc(sizeof(struct IndexList));
    new_node->index = index;
    new_node->next = list;
    return new_node;
}

// Add an index to the database, strengthening our knowledge network
void add_index(struct Database* db, char* table_name, char* column) {
    struct Table* table = db->table;
    struct Index* index = create_index(table, column);
    db->index_list = add_index_to_list(db->index_list, index);
}

// Populate our table with scavenged data, piece by piece
void populate_table(struct Table* table, char* data) {
    char* row = strtok(data, ",");
    int row_index = 0;
    while (row != NULL) {
        char* column = strtok(row, " ");
        int column_index = 0;
        while (column != NULL) {
            strcpy(table->data[row_index][column_index], column);
            column = strtok(NULL, " ");
            column_index++;
        }
        row = strtok(NULL, ",");
        row_index++;
    }
}

// Query our database, a beacon of hope in the desolate wasteland
void query_database(struct Database* db, char* query) {
    char* table_name = strtok(query, " ");
    char* column_name = strtok(NULL, " ");
    char* value = strtok(NULL, " ");

    // Find the index for the specified column
    struct Index* index = NULL;
    struct IndexList* list = db->index_list;
    while (list != NULL) {
        if (strcmp(list->index->column, column_name) == 0) {
            index = list->index;
            break;
        }
        list = list->next;
    }

    // Find the rows that match the specified value
    int num_matches = 0;
    int* matches = malloc(sizeof(int) * db->table->num_rows);
    for (int i = 0; i < db->table->num_rows; i++) {
        if (strcmp(db->table->data[i][index->values[i]], value) == 0) {
            matches[num_matches] = i;
            num_matches++;
        }
    }

    // Print the matching rows
    printf("Matching rows:\n");
    for (int i = 0; i < num_matches; i++) {
        for (int j = 0; j < db->table->num_columns; j++) {
            printf("%s ", db->table->data[matches[i]][j]);
        }
        printf("\n");
    }
}

int main() {

  // Create our database, a beacon of knowledge in the wasteland
  struct Database* db = create_database();

  // Create a table to hold our scavenged data
  struct Table* table = create_table(db, "Survivors", 5, 3);

  // Populate our table with data salvaged from the ruins
  char* data1 = "John Doe 25 male";
  char* data2 = "Jane Smith 30 female";
  char* data3 = "Tom Jones 35 male";
  char* data4 = "Mary Johnson 28 female";
  char* data5 = "Bob Smith 22 male";
  populate_table(table, data1);
  populate_table(table, data2);
  populate_table(table, data3);
  populate_table(table, data4);
  populate_table(table, data5);

  // Index the table by gender, making it easier to find survivors
  add_index(db, "Survivors", "gender");

  // Query our database, searching for survivors of a particular gender
  char* query = "Survivors gender male";
  query_database(db, query);

  return 0;
}