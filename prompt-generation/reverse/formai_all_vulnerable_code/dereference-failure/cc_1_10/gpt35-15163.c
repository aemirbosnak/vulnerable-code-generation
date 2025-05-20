//FormAI DATASET v1.0 Category: Database querying ; Style: Cyberpunk
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<mysql/mysql.h>

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);        
}

int main(int argc, char **argv)
{
    MYSQL *con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "password", 
            "cyberspace", 0, NULL, 0) == NULL) 
    {
        finish_with_error(con);
    }   

    if (mysql_query(con, "SELECT * FROM users WHERE username LIKE '%cyber%'")) 
    {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL) 
    {
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) 
    { 
        printf("Username: %s, Password: %s, Rating: %s\n", 
            row[0], row[1], row[2]); 
    }

    mysql_free_result(result);
    mysql_close(con);

    exit(0);
}