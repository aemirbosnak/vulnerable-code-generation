//FormAI DATASET v1.0 Category: Database querying ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "mypassword"
#define DATABASE "mydatabase"

MYSQL* connection;
MYSQL_RES* result;
MYSQL_ROW row;

int main()
{
    connection = mysql_init(NULL);

    if(mysql_real_connect(connection, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL)
    {
        printf("Connection to database failed: %s\n", mysql_error(connection));
        mysql_close(connection);
        exit(1);
    }
    printf("Connection to database succeeded\n");

    if(mysql_query(connection, "SELECT * FROM customers WHERE age > 30"))
    {
        printf("Error in querying database: %s\n", mysql_error(connection));
        mysql_close(connection);
        exit(1);
    }
    printf("Querying database succeeded\n");

    result = mysql_store_result(connection);

    if(result == NULL)
    {
        printf("Error in fetching results: %s\n", mysql_error(connection));
        mysql_close(connection);
        exit(1);
    }

    while((row = mysql_fetch_row(result)))
    {
        printf("Name: %s, Age: %s, Address: %s\n", row[0], row[1], row[2]);
    }

    mysql_free_result(result);
    mysql_close(connection);

    return 0;
}