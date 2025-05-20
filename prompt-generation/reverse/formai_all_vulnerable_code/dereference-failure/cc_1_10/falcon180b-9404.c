//Falcon-180B DATASET v1.0 Category: Database querying ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1000
#define MAX_ROW_LENGTH 1000

MYSQL *conn = NULL;
char *host = "localhost";
char *user = "root";
char *password = "password";
char *database = "test_db";

int main() {
    conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("Error initializing MySQL connection\n");
        exit(1);
    }

    if (!mysql_real_connect(conn, host, user, password, database, 0, NULL, 0)) {
        printf("Error connecting to MySQL database: %s\n", mysql_error(conn));
        exit(1);
    }

    printf("Connected to MySQL database\n");

    char query[MAX_QUERY_LENGTH];
    sprintf(query, "CREATE TABLE IF NOT EXISTS users (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255), email VARCHAR(255))");
    if (mysql_query(conn, query)) {
        printf("Error creating table: %s\n", mysql_error(conn));
        exit(1);
    }

    char insert_query[MAX_QUERY_LENGTH];
    sprintf(insert_query, "INSERT INTO users (name, email) VALUES ('John Doe', 'john.doe@example.com')");
    if (mysql_query(conn, insert_query)) {
        printf("Error inserting data: %s\n", mysql_error(conn));
        exit(1);
    }

    char select_query[MAX_QUERY_LENGTH];
    sprintf(select_query, "SELECT * FROM users");
    if (mysql_query(conn, select_query)) {
        printf("Error selecting data: %s\n", mysql_error(conn));
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        printf("Error storing result\n");
        exit(1);
    }

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))!= NULL) {
        printf("ID: %s, Name: %s, Email: %s\n", row[0], row[1], row[2]);
    }

    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}