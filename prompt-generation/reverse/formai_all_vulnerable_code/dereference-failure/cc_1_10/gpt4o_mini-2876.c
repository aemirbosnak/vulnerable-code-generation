//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "yourusername"
#define PASSWORD "yourpassword"
#define DATABASE "yourdatabase"

// Function to handle errors
void handle_error(MYSQL *conn) {
    fprintf(stderr, "Error: %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(EXIT_FAILURE);
}

// Function to run a simple query and print results
void run_query(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        handle_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        handle_error(conn);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    mysql_free_result(result);
}

// Function to insert data into the database
void insert_data(MYSQL *conn, const char *name, int age) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO people (name, age) VALUES ('%s', %d)", name, age);
    
    if (mysql_query(conn, query)) {
        handle_error(conn);
    }
    printf("Inserted %s, Age: %d\n", name, age);
}

// Function to retrieve all records from the people table
void retrieve_all_people(MYSQL *conn) {
    printf("Retrieving all people:\n");
    run_query(conn, "SELECT * FROM people");
}

// Function to retrieve people by age
void retrieve_people_by_age(MYSQL *conn, int age) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT * FROM people WHERE age = %d", age);
    printf("Retrieving people aged %d:\n", age);
    run_query(conn, query);
}

// Function to update a person's name by their ID
void update_person_name(MYSQL *conn, int id, const char *new_name) {
    char query[256];
    snprintf(query, sizeof(query), "UPDATE people SET name = '%s' WHERE id = %d", new_name, id);
    
    if (mysql_query(conn, query)) {
        handle_error(conn);
    }
    printf("Updated ID: %d to New Name: %s\n", id, new_name);
}

// Function to delete a person by their ID
void delete_person_by_id(MYSQL *conn, int id) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM people WHERE id = %d", id);
    
    if (mysql_query(conn, query)) {
        handle_error(conn);
    }
    printf("Deleted person with ID: %d\n", id);
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(EXIT_FAILURE);
    }

    if (mysql_real_connect(conn, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        handle_error(conn);
    }

    insert_data(conn, "Alice", 30);
    insert_data(conn, "Bob", 35);
    insert_data(conn, "Charlie", 30);

    retrieve_all_people(conn);
    retrieve_people_by_age(conn, 30);

    update_person_name(conn, 1, "Alicia");
    retrieve_all_people(conn);

    delete_person_by_id(conn, 2);
    retrieve_all_people(conn);

    mysql_close(conn);
    return EXIT_SUCCESS;
}