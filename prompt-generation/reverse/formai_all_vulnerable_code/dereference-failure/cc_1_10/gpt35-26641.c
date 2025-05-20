//FormAI DATASET v1.0 Category: Database querying ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

/*
 * This program demonstrates how to perform database querying in C using the MySQL API.
 * The program connects to a MySQL server and queries the "employees" table of the "employees" database.
 * The program then prints the results of the query to the console in a tabular format.
 */

int main(int argc, char **argv)
{
    MYSQL *conn;           // MySQL connection object
    MYSQL_RES *result;     // MySQL result object
    MYSQL_ROW row;         // MySQL row object
    int num_fields;        // number of fields returned by the query
    int i;

    // connect to the MySQL server
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "password", "employees", 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // execute the query
    if (mysql_query(conn, "SELECT * FROM employees")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // get the result set
    result = mysql_use_result(conn);
    if (!result) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // get the number of fields in the result set
    num_fields = mysql_num_fields(result);

    // print the table header
    for (i = 0; i < num_fields; i++) {
        printf("%-15s", mysql_fetch_field_direct(result, i)->name);
    }
    printf("\n");

    // print the table body
    while ((row = mysql_fetch_row(result))) {
        for (i = 0; i < num_fields; i++) {
            printf("%-15s", row[i]);
        }
        printf("\n");
    }

    // free the result set
    mysql_free_result(result);

    // close the MySQL connection
    mysql_close(conn);

    return 0;
}