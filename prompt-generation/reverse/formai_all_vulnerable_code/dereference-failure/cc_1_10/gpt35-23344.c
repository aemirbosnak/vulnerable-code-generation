//FormAI DATASET v1.0 Category: Database querying ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure for storing database rows
struct Row {
    int id;
    char title[100];
    char author[100];
    float price;
};

// Function for printing rows
void print_row(struct Row row) {
    printf("%d, %s, %s, $%.2f\n", row.id, row.title, row.author, row.price);
}

int main() {
    // Configurable database parameters
    const char* db_filename = "books.db";
    const char* table_name = "books";
    const char* column_names[] = {"id", "title", "author", "price"};
    const int num_columns = 4;

    // Open database file
    FILE* db_file = fopen(db_filename, "rb");
    if (db_file == NULL) {
        printf("Error: could not open database file %s\n", db_filename);
        return 1;
    }

    // Read number of rows in table
    int num_rows;
    fread(&num_rows, sizeof(int), 1, db_file);
    printf("%d rows\n", num_rows);

    // Read column data
    int column_sizes[num_columns];
    for (int i = 0; i < num_columns; i++) {
        fread(&column_sizes[i], sizeof(int), 1, db_file);
    }

    // Print column names
    printf("%s", column_names[0]);
    for (int i = 1; i < num_columns; i++) {
        printf(", %s", column_names[i]);
    }
    printf("\n");

    // Read rows and print them
    for (int i = 0; i < num_rows; i++) {
        // Read row ID
        int id;
        fread(&id, sizeof(int), 1, db_file);

        // Read title
        char title[column_sizes[1]];
        fread(title, sizeof(char), column_sizes[1], db_file);

        // Read author
        char author[column_sizes[2]];
        fread(author, sizeof(char), column_sizes[2], db_file);

        // Read price
        float price;
        fread(&price, sizeof(float), 1, db_file);

        // Create row struct and print it
        struct Row row = {id, "", "", 0.0};
        strcpy(row.title, title);
        strcpy(row.author, author);
        row.price = price;
        print_row(row);
    }

    // Close database file
    fclose(db_file);

    return 0;
}