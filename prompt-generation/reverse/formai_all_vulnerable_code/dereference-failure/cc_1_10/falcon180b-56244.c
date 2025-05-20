//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 100

// Node structure for linked list
typedef struct node {
    char data[MAX_DATA_SIZE];
    struct node *next;
} Node;

// Table structure
typedef struct table {
    char name[MAX_DATA_SIZE];
    int num_rows;
    int num_cols;
    Node **data;
} Table;

// Function to create a new table
Table *create_table(char *name) {
    Table *table = (Table *) malloc(sizeof(Table));
    strcpy(table->name, name);
    table->num_rows = 0;
    table->num_cols = 0;
    table->data = NULL;
    return table;
}

// Function to add a row to a table
void add_row(Table *table, char *data) {
    Node *node = (Node *) malloc(sizeof(Node));
    strcpy(node->data, data);
    node->next = NULL;
    if (table->data == NULL) {
        table->data = node;
    } else {
        Node *curr = table->data;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
    table->num_rows++;
}

// Function to add a column to a table
void add_col(Table *table, char *data) {
    int i;
    for (i = 0; i < table->num_rows; i++) {
        Node *node = table->data;
        while (node!= NULL) {
            strcat(node->data, ",");
            strcat(node->data, data);
            node = node->next;
        }
    }
    table->num_cols++;
}

// Function to print a table
void print_table(Table *table) {
    printf("Table name: %s\n", table->name);
    printf("Number of rows: %d\n", table->num_rows);
    printf("Number of columns: %d\n", table->num_cols);
    printf("Data:\n");
    Node *node = table->data;
    while (node!= NULL) {
        printf("%s\n", node->data);
        node = node->next;
    }
}

// Main function
int main() {
    Table *table = create_table("example_table");
    add_row(table, "John,Doe,25");
    add_row(table, "Jane,Doe,30");
    add_col(table, "City");
    add_col(table, "State");
    print_table(table);
    return 0;
}