//FormAI DATASET v1.0 Category: Database querying ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "mypassword"
#define DATABASE "mydatabase"

void error_and_exit(MYSQL *conn) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        exit(1);
    }

    if (mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        error_and_exit(conn);
    }

    char query[500];
    sprintf(query, "SELECT * FROM customers WHERE country='%s' AND age>='%d'", "USA", 18);

    if (mysql_query(conn, query) != 0) {
        error_and_exit(conn);
    }

    MYSQL_RES *result = mysql_use_result(conn);
    if (result == NULL) {
        error_and_exit(conn);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    printf("CustomerID\tName\t\t\tCity\t\t\tState\tCountry\t\tAge\tCreditLimit\n");
    printf("---------------------------------------------------------------------------------------\n");

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            if (row[i] == NULL) {
                printf("NULL\t\t");
            } else {
                printf("%s\t\t", row[i]);
            }
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}