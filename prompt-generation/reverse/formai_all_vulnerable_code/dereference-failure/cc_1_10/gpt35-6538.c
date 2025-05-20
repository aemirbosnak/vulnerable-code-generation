//FormAI DATASET v1.0 Category: Database querying ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "password"
#define DATABASE "test"

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

int main()
{
    MYSQL *con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }

    if (mysql_query(con, "CREATE TABLE Books(Id INT PRIMARY KEY AUTO_INCREMENT, Title TEXT, Author TEXT, Price INT)"))
    {
        finish_with_error(con);
    }

    if (mysql_query(con, "INSERT INTO Books(Title, Author, Price) VALUES('1984', 'George Orwell', 30)"))
    {
        finish_with_error(con);
    }

    if (mysql_query(con, "INSERT INTO Books(Title, Author, Price) VALUES('To Kill a Mockingbird', 'Harper Lee', 25)"))
    {
        finish_with_error(con);
    }

    if (mysql_query(con, "INSERT INTO Books(Title, Author, Price) VALUES('The Great Gatsby', 'F. Scott Fitzgerald', 20)"))
    {
        finish_with_error(con);
    }

    if (mysql_query(con, "SELECT * FROM Books"))
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
        for(int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(con);

    return 0;
}