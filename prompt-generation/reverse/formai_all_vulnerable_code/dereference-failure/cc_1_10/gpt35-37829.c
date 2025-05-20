//FormAI DATASET v1.0 Category: Database querying ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() 
{
    MYSQL *con = mysql_init(NULL);

    if (con == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "username", "password", 
          NULL, 0, NULL, 0) == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }  

    if (mysql_query(con, "USE database_name")) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    if (mysql_query(con, "SELECT * FROM table_name")) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;
    
    while ((row = mysql_fetch_row(result))) 
    { 
        for(int i = 0; i < num_fields; i++) 
        { 
            printf("%s ", row[i] ? row[i] : "NULL"); 
        } 
        printf("\n"); 
    }

    mysql_free_result(result);
    mysql_close(con);
    exit(0);
}