//FormAI DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main(int argc, char *argv[]) {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "root";
    char *password = "password";
    char *database = "mydatabase";

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // Querying the database for all users
    if (mysql_query(conn, "SELECT * FROM users")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_use_result(conn);

    printf("All users:\n");
    printf("%-10s %-15s %-15s %-15s\n", "ID", "Name", "Email", "Phone");
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%-10s %-15s %-15s %-15s\n", row[0], row[1], row[2], row[3]);
    }

    mysql_free_result(res);

    // Querying the database for users with email ending in "gmail.com"
    char *query_email = "SELECT * FROM users WHERE email LIKE '%gmail.com'";
    if (mysql_query(conn, query_email)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_use_result(conn);

    printf("\nUsers with email ending in 'gmail.com':\n");
    printf("%-10s %-15s %-15s %-15s\n", "ID", "Name", "Email", "Phone");
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%-10s %-15s %-15s %-15s\n", row[0], row[1], row[2], row[3]);
    }

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}