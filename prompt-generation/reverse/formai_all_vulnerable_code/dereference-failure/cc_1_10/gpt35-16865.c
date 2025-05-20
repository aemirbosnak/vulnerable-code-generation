//FormAI DATASET v1.0 Category: Database querying ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql/mysql.h>

//Grateful style C database querying example program

int main(){

    printf("Welcome to the Grateful style C database querying program!\n\n");

    // Let's establish a connection to the database
    MYSQL *conn;
    conn = mysql_init(NULL);
    if (!conn) {
        printf("Could not initialize MySQL library\n");
        exit(1);
    }

    char *host = "localhost";
    char *user = "root";
    char *password = "password";
    char *database = "mydatabase";

    if(!mysql_real_connect(conn, host, user, password, database, 0, NULL, 0)){
        printf("Could not connect to database: %s", mysql_error(conn));
        return 1;
    }

    printf("Connection to database established!\n\n");

    // Let's execute a query to retrieve some data from the database

    if(mysql_query(conn, "SELECT * FROM employees")){
        printf("Could not execute query: %s", mysql_error(conn));
        return 1;
    }

    MYSQL_RES * result = mysql_store_result(conn);

    // Let's iterate through the results and output them to the console

    printf("Here are the results of your query:\n\n");
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        printf("Employee ID: %s\n", row[0]);
        printf("Employee Name: %s\n", row[1]);
        printf("Employee Age: %s\n\n", row[2]);
    }

    // Let's free the result object and close the connection to the database
    mysql_free_result(result);
    mysql_close(conn);

    printf("Thanks for using the Grateful style C database querying program!\n");

    return 0;
}