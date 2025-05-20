//FormAI DATASET v1.0 Category: Database querying ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// MySQL server address, username, password, and database name
#define SERVER "localhost"
#define USER "root"
#define PASSWORD "password"
#define DATABASE "mydatabase"

MYSQL *con;

void finish_with_error()
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

int main() 
{
    con = mysql_init(NULL);

    if (con == NULL) 
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    // MySQL connection
    con = mysql_real_connect(con, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0);

    if (con == NULL) 
    {
        finish_with_error(con);
    }

    char query[500];

    // Modify the query to extract data according to your needs
    sprintf(query, "SELECT * FROM myTable WHERE age > '%d'", 18);

    if (mysql_query(con, query)) 
    {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL) 
    {
        finish_with_error(con);
    }

    int numRows = mysql_num_rows(result);
    int numFields = mysql_num_fields(result);

    MYSQL_ROW row;

    // Print the column headers
    MYSQL_FIELD *field;
    while ((field = mysql_fetch_field(result)))
    {
        printf("%s\t", field->name);
    }
    printf("\n");

    // Print the rows of data
    while ((row = mysql_fetch_row(result))) 
    {
        for(int i = 0; i < numFields; i++) 
        {
            printf("%s\t", row[i]);
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(con);

    return 0;
}