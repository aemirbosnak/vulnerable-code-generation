//FormAI DATASET v1.0 Category: Database querying ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main(int argc, char const *argv[])
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "localhost";
    char *user = "root";
    char *password = "password";
    char *database = "students_db";
    char query[500];
    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) 
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    printf("Enter a student name to search for: ");
    char name[20];
    fgets(name, 20, stdin);
    strtok(name, "\n");

    sprintf(query, "SELECT * FROM students WHERE name='%s'", name);
    if (mysql_query(conn, query))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_use_result(conn); 
    if (res) 
    {
        printf("Found the following students:\n");
        while ((row = mysql_fetch_row(res))) 
        {
            printf("Name: %s\nAge: %s\nGrade: %s\n\n", row[1], row[2], row[3]);
        }
    } 
    else 
    {
        printf("No students found with that name.\n");
    }

    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}