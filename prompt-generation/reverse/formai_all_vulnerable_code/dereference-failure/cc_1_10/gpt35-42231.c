//FormAI DATASET v1.0 Category: Database querying ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql/mysql.h> //include MySQL library

//function for printing error message
void error_exit(MYSQL* connection) {
    fprintf(stderr, "%s\n", mysql_error(connection));
    mysql_close(connection);
    exit(1);
}

int main() {
    MYSQL* connection;
    MYSQL_RES* result_set;
    MYSQL_ROW row;

    //initialize MySQL connection
    connection = mysql_init(NULL);
    if (connection == NULL) {
        printf("Failed to initialize MySQL connection: %s\n", mysql_error(connection));
        return 1;
    }

    //connect to MySQL server, host, username and password are given as arguments
    if (mysql_real_connect(connection, "localhost", "root", "password", "testdatabase", 0, NULL, 0) == NULL) {
        error_exit(connection);
    }

    //query the database
    if (mysql_query(connection, "SELECT fname, lname, age FROM employees WHERE position='Manager'")) {
        error_exit(connection);
    }

    //store the resulting rows in result_set
    result_set = mysql_store_result(connection);
    if (result_set == NULL) {
        error_exit(connection);
    }

    //loop through the rows and print the data
    while ((row = mysql_fetch_row(result_set)) != NULL) {
        printf("%s %s is a %s year old Manager.\n", row[0], row[1], row[2]);
    }

    //free memory and close connection
    mysql_free_result(result_set);
    mysql_close(connection);

    return 0;
}