//FormAI DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>  // MySQL header files

#define SERVER "localhost"
#define USER "your_username"
#define PASSWORD "your_password"
#define DATABASE "your_database_name"

int main()
{
    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *result;
    int status;

    char name[50]; // variable to store user input
    printf("Enter name to search for: ");
    scanf("%s", name);
    
    conn = mysql_init(NULL); // initialize the MySQL connection
    if(!conn)
    {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn)); // display any errors
        exit(1);
    }

    // establish a connection to the MySQL server
    if(!mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0))
    {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn)); // display any errors
        exit(1);
    }

    char query[100]; // variable to store the SQL query
    sprintf(query, "SELECT * FROM user WHERE name='%s'", name); // format the query string

    status = mysql_query(conn, query); // execute the query
    if(status)
    {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn)); // display any errors
        exit(1);
    }

    result = mysql_store_result(conn); // store the result in a variable

    if(result == NULL)
    {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn)); // display any errors
        exit(1);
    }

    int num_fields = mysql_num_fields(result); // get the number of fields in the result
    printf("Name\t\tAge\t\tEmail\n");
    while(row = mysql_fetch_row(result)) // loop through the result
    {
        for(int i = 0; i < num_fields; i++)
            printf("%s\t\t", row[i]); // print each field value
        printf("\n");
    }

    mysql_free_result(result); // free the memory used by the result
    mysql_close(conn); // close the connection

    return 0;
}