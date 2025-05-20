//FormAI DATASET v1.0 Category: Database querying ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql/mysql.h>

int main(){
    printf("Oh my god, I just can't believe it, I've never queried a database before...\n");

    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;

    int fetch_row_num;
    const char *server = "<server_name>";
    const char *user = "<username>";
    const char *password = "<password>";
    const char *database = "<database_name>";

    conn = mysql_init(NULL);

    if(!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)){
        printf("What in the world is happening? Connection error - %s\n", mysql_error(conn));
        exit(1);
    }
    else{
        printf("Hallelujah, I have connected to the database server successfully!\n");
    }
    
    char query[100];
    sprintf(query, "SELECT * FROM students");

    if(mysql_query(conn, query)){
        printf("Oh no, something went wrong while executing query - %s\n", mysql_error(conn));
        exit(1);
    }

    result = mysql_store_result(conn);
    fetch_row_num = mysql_num_rows(result);

    printf("%d rows in set:\n\n", fetch_row_num);
    printf("+----------+----------------------+--------+\n");
    printf("| Roll No. |        Name          |  Age   |\n");
    printf("+----------+----------------------+--------+\n");

    while((row = mysql_fetch_row(result))){
        printf("|  %-6s  | %-20s |  %-4s |\n", row[0], row[1], row[2]);
    }

    printf("\n+----------+----------------------+--------+\n");

    mysql_free_result(result);
    mysql_close(conn);

    printf("\nYahoooo, I executed the query successfully and fetched results from the database\n");

    return 0;
}