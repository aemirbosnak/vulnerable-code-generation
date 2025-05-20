//FormAI DATASET v1.0 Category: Database querying ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

//set your database credentials here
const char *DB_USER = "your_db_username";
const char *DB_PASSWORD = "your_db_password";
const char *DB_NAME = "your_db_name";

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

int main() {
    MYSQL *conn = mysql_init(NULL);

    if (conn == NULL) {
        printf("Error initializing MySQL: %s\n", mysql_error(conn));
        exit(1);
    }

    if (!mysql_real_connect(conn, "localhost", DB_USER, DB_PASSWORD, DB_NAME, 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }

    if (mysql_query(conn, "SELECT * FROM users")) {
        finish_with_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);

    if (result == NULL) {
        finish_with_error(conn);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;

    printf("ID\tName\tEmail\t\t\tAge\n");

    while ((row = mysql_fetch_row(result))) {
        printf("%s\t%s\t%s\t%d\n", row[0], row[1], row[2], atoi(row[3]));
    }

    mysql_free_result(result);
    mysql_close(conn);
    exit(0);
}