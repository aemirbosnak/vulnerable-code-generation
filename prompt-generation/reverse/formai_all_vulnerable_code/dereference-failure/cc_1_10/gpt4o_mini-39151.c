//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

void print_error(MYSQL *conn) {
    fprintf(stderr, "Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
}

void execute_query(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        print_error(conn);
        exit(EXIT_FAILURE);
    }
}

void display_results(MYSQL *conn) {
    MYSQL_RES *result;
    MYSQL_ROW row;

    result = mysql_store_result(conn);
    if (result == NULL) {
        print_error(conn);
        return;
    }

    int num_fields = mysql_num_fields(result);
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
}

void fetch_and_display_data(MYSQL *conn, const char *table_name) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT * FROM %s", table_name);
    execute_query(conn, query);
    display_results(conn);
}

void insert_data(MYSQL *conn, const char *table_name, const char *data) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO %s VALUES (%s)", table_name, data);
    execute_query(conn, query);
}

void delete_data(MYSQL *conn, const char *table_name, const char *condition) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM %s WHERE %s", table_name, condition);
    execute_query(conn, query);
}

void update_data(MYSQL *conn, const char *table_name, const char *updates, const char *condition) {
    char query[256];
    snprintf(query, sizeof(query), "UPDATE %s SET %s WHERE %s", table_name, updates, condition);
    execute_query(conn, query);
}

void create_table(MYSQL *conn, const char *table_name) {
    char query[256];
    snprintf(query, sizeof(query), "CREATE TABLE %s (ID INT AUTO_INCREMENT PRIMARY KEY, Name VARCHAR(100), Age INT)", table_name);
    execute_query(conn, query);
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0) == NULL) {
        print_error(conn);
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    const char *table_name = "people";
    
    // Create table example
    create_table(conn, table_name);

    // Insert some data
    insert_data(conn, table_name, "'Alice', 30");
    insert_data(conn, table_name, "'Bob', 25");

    // Fetch and display data
    printf("Data from '%s':\n", table_name);
    fetch_and_display_data(conn, table_name);

    // Update data
    update_data(conn, table_name, "Age = 31", "Name = 'Alice'");

    // Fetch and display data again
    printf("Data after update:\n");
    fetch_and_display_data(conn, table_name);

    // Delete data
    delete_data(conn, table_name, "Name = 'Bob'");

    // Final data display
    printf("Final data after deletion:\n");
    fetch_and_display_data(conn, table_name);
    
    mysql_close(conn);
    return EXIT_SUCCESS;
}