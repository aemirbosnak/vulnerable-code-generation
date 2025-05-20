//FormAI DATASET v1.0 Category: Database querying ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h> // MySQL library header

int main()
{
    MYSQL *conn; // MySQL connection object
    MYSQL_RES *res; // MySQL result object
    MYSQL_ROW row; // MySQL row object
    char *server = "localhost";
    char *user = "root";
    char *password = "password123";
    char *database = "mydb";
    char query[100];
    char name[20];
    int age;

    conn = mysql_init(NULL); // initialize MySQL connection object
    if (!conn)
    {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        exit(1);
    }

    // connect to the database
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
    {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &age);

    // create query string
    sprintf(query, "SELECT * FROM people WHERE name='%s' AND age=%d", name, age);

    // execute query
    if (mysql_query(conn, query))
    {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    res = mysql_use_result(conn); // retrieve result set
    if (!res)
    {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    // print results
    printf("Results:\n");
    while ((row = mysql_fetch_row(res)))
    {
        printf("%s %s %s\n", row[0], row[1], row[2]);
    }

    mysql_free_result(res); // free result set
    mysql_close(conn); // close database connection

    return 0;
}