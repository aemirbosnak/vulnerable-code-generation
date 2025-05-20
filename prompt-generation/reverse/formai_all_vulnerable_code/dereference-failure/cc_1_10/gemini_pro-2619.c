//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define the maximum number of rows to return from the database
#define MAX_ROWS 100

// Define the maximum length of a string
#define MAX_STRING_LENGTH 100

// Define the structure of a row in the database
typedef struct {
    int id;
    char *name;
    int age;
    char *gender;
    char *occupation;
} Row;

// Define the structure of a database query
typedef struct {
    char *sql;
    sqlite3_stmt *stmt;
} Query;

// Create a new database connection
sqlite3 *db = NULL;

// Create a new database query
Query *new_query(const char *sql) {
    Query *query = malloc(sizeof(Query));
    query->sql = strdup(sql);
    query->stmt = NULL;
    return query;
}

// Free a database query
void free_query(Query *query) {
    free(query->sql);
    sqlite3_finalize(query->stmt);
    free(query);
}

// Execute a database query
int execute_query(Query *query) {
    int rc = sqlite3_prepare_v2(db, query->sql, -1, &query->stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
        return -1;
    }
    return 0;
}

// Get the next row from a database query
Row *get_next_row(Query *query) {
    int rc = sqlite3_step(query->stmt);
    if (rc == SQLITE_ROW) {
        Row *row = malloc(sizeof(Row));
        row->id = sqlite3_column_int(query->stmt, 0);
        row->name = strdup(sqlite3_column_text(query->stmt, 1));
        row->age = sqlite3_column_int(query->stmt, 2);
        row->gender = strdup(sqlite3_column_text(query->stmt, 3));
        row->occupation = strdup(sqlite3_column_text(query->stmt, 4));
        return row;
    }
    return NULL;
}

// Free a row from the database
void free_row(Row *row) {
    free(row->name);
    free(row->gender);
    free(row->occupation);
    free(row);
}

// Print a row from the database
void print_row(Row *row) {
    printf("%d %s %d %s %s\n", row->id, row->name, row->age, row->gender, row->occupation);
}

// Get the average age of people in the database
int get_average_age() {
    Query *query = new_query("SELECT AVG(age) FROM people");
    if (execute_query(query) != 0) {
        return -1;
    }
    Row *row = get_next_row(query);
    if (row == NULL) {
        return -1;
    }
    int average_age = row->age;
    free_row(row);
    free_query(query);
    return average_age;
}

// Get the most common gender in the database
char *get_most_common_gender() {
    Query *query = new_query("SELECT gender, COUNT(*) AS count FROM people GROUP BY gender ORDER BY count DESC LIMIT 1");
    if (execute_query(query) != 0) {
        return NULL;
    }
    Row *row = get_next_row(query);
    if (row == NULL) {
        return NULL;
    }
    char *most_common_gender = strdup(row->gender);
    free_row(row);
    free_query(query);
    return most_common_gender;
}

// Get the most common occupation in the database
char *get_most_common_occupation() {
    Query *query = new_query("SELECT occupation, COUNT(*) AS count FROM people GROUP BY occupation ORDER BY count DESC LIMIT 1");
    if (execute_query(query) != 0) {
        return NULL;
    }
    Row *row = get_next_row(query);
    if (row == NULL) {
        return NULL;
    }
    char *most_common_occupation = strdup(row->occupation);
    free_row(row);
    free_query(query);
    return most_common_occupation;
}

// Main function
int main() {
    // Open the database
    int rc = sqlite3_open("people.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        return -1;
    }
    // Print the average age of people in the database
    int average_age = get_average_age();
    if (average_age == -1) {
        fprintf(stderr, "Error getting average age\n");
        return -1;
    }
    printf("Average age: %d\n", average_age);
    // Print the most common gender in the database
    char *most_common_gender = get_most_common_gender();
    if (most_common_gender == NULL) {
        fprintf(stderr, "Error getting most common gender\n");
        return -1;
    }
    printf("Most common gender: %s\n", most_common_gender);
    // Print the most common occupation in the database
    char *most_common_occupation = get_most_common_occupation();
    if (most_common_occupation == NULL) {
        fprintf(stderr, "Error getting most common occupation\n");
        return -1;
    }
    printf("Most common occupation: %s\n", most_common_occupation);
    // Close the database
    sqlite3_close(db);
    return 0;
}