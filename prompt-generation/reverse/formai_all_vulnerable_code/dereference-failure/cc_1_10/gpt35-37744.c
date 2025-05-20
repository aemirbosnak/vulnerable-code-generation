//FormAI DATASET v1.0 Category: Database querying ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// This function initializes the MySQL connection
MYSQL* initialize_sql_connection() {
    MYSQL *con = mysql_init(NULL);

    if (con == NULL) {
        printf("MySQL initialization failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "username", "password", "mydb", 0, NULL, 0) == NULL) {
        printf("Connection to MySQL failed\n");
        mysql_close(con);
        exit(1);
    }

    return con;
}

// This function performs a SELECT query on the specified table
void select_from_table(MYSQL *con, char *table_name, char *column_name) {
    // Prepare the query string
    char query[512];
    sprintf(query, "SELECT %s FROM %s;", column_name, table_name);

    // Execute the query
    if (mysql_query(con, query) != 0) {
        printf("Query failed: %s\n", mysql_error(con));
        return;
    }

    MYSQL_RES *result = mysql_store_result(con);

    unsigned int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    // Print the results
    while ((row = mysql_fetch_row(result))) {
        for (unsigned int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
}

// This function performs a INSERT query on the specified table
void insert_into_table(MYSQL *con, char *table_name, char *column_name, char *column_value) {
    // Prepare the query string
    char query[512];
    sprintf(query, "INSERT INTO %s (%s) VALUES('%s');", table_name, column_name, column_value);

    // Execute the query
    if (mysql_query(con, query) != 0) {
        printf("Query failed: %s\n", mysql_error(con));
        return;
    }

    printf("Data inserted successfully.\n");
}

// This function performs a DELETE query on the specified table
void delete_from_table(MYSQL *con, char *table_name, char *column_name, char *column_value) {
    // Prepare the query string
    char query[512];
    sprintf(query, "DELETE FROM %s WHERE %s='%s';", table_name, column_name, column_value);

    // Execute the query
    if (mysql_query(con, query) != 0) {
        printf("Query failed: %s\n", mysql_error(con));
        return;
    }

    printf("Data deleted successfully.\n");
}

int main() {
    MYSQL *con = initialize_sql_connection();

    select_from_table(con, "employees", "*");
    insert_into_table(con, "employees", "employee_name", "John Doe");
    delete_from_table(con, "employees", "employee_name", "John Doe");

    mysql_close(con);

    return 0;
}