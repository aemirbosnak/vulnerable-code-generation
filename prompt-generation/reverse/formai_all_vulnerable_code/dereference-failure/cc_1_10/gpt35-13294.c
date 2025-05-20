//FormAI DATASET v1.0 Category: Database querying ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql/mysql.h>// MySQL Headers

#define DB_HOST "localhost"
#define DB_USER "root" //mysql username
#define DB_PASS "testpassword" //mysql password
#define DB_NAME "testdatabase" //database name
#define CHOP(x) x[strlen(x) - 1] = ' '

MYSQL *conn; //MySQL connection
MYSQL_RES *result; //MySQL Result Set
MYSQL_ROW row; //MySQL Row data structure

void database_connect() 
{
    conn = mysql_init(NULL);
    if(!mysql_real_connect(conn,DB_HOST,DB_USER,DB_PASS,DB_NAME,0,NULL,0)) {
        fprintf(stderr,"Error in connection");
    }
}

void database_close() 
{
    mysql_free_result(result);
    mysql_close(conn);
}

void database_query(char *query)
{
    if(mysql_query(conn, query))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
}

void display_data() 
{
    int i=1;
    while(row = mysql_fetch_row(result)) {
        printf("%d: %s %s\n",i, row[0], row[1]);
        i++;
    }
}

int main(int argc, char **argv)
{
    database_connect();
    char query[100];
    printf("Enter the name of student to fetch details:\n");
    fgets(query, 100, stdin);
    CHOP(query);
    sprintf(query, "SELECT * FROM students WHERE name='%s'", query);
    database_query(query);
    result = mysql_store_result(conn);
    display_data();
    database_close();
    return 0;
}