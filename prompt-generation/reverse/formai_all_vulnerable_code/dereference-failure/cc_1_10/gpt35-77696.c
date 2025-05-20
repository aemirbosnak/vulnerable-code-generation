//FormAI DATASET v1.0 Category: Database querying ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

MYSQL *con;

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);        
}

int main(int argc, char **argv)
{
    char *host = "localhost";
    char *user = "root";
    char *password = "pass123";
    char *database = "employees";
    char query[500];
    MYSQL_RES *result;
    MYSQL_ROW row;
    int num_fields, i, j;
    
    con = mysql_init(NULL);
    
    if (con == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, host, user, password, database, 0, NULL, 0) == NULL) 
    {
        finish_with_error(con);
    }  
    
    sprintf(query, "SELECT * FROM employees WHERE age > %d AND gender = '%c'", 25, 'M');

    if (mysql_query(con, query)) 
    {
        finish_with_error(con);
    }

    result = mysql_store_result(con);
    
    if (result == NULL) 
    {
        finish_with_error(con);
    }

    num_fields = mysql_num_fields(result);
    
    while ((row = mysql_fetch_row(result))) 
    { 
        for(i = 0; i < num_fields; i++) 
        { 
            printf("%s ", row[i] ? row[i] : "NULL"); 
        } 
        printf("\n"); 
    }
    
    mysql_free_result(result);
    mysql_close(con);

    exit(0);
}