//Falcon-180B DATASET v1.0 Category: Database querying ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to perform database query
int query_database(MYSQL *conn, const char *query) {
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    int num_rows = 0;
    int num_fields = 0;

    if (mysql_query(conn, query)) {
        printf("Error performing query: %s\n", mysql_error(conn));
        return 1;
    }

    if (!(result = mysql_store_result(conn))) {
        printf("Error storing result\n");
        return 1;
    }

    num_fields = mysql_num_fields(result);
    printf("Query results:\n");

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
        num_rows++;
    }

    if (num_rows == 0) {
        printf("No results found\n");
    }

    mysql_free_result(result);
    return 0;
}

// Function to connect to database
MYSQL *connect_to_database(const char *host, const char *user, const char *password, const char *database) {
    MYSQL *conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, host, user, password, database, 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        return NULL;
    }

    return conn;
}

// Main function
int main() {
    MYSQL *conn = NULL;
    const char *host = "localhost";
    const char *user = "username";
    const char *password = "password";
    const char *database = "database_name";

    // Connect to database
    conn = connect_to_database(host, user, password, database);
    if (conn == NULL) {
        return 1;
    }

    // Perform database query
    if (query_database(conn, "SELECT * FROM table_name")) {
        mysql_close(conn);
        return 1;
    }

    // Close database connection
    mysql_close(conn);

    return 0;
}