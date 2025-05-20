//FormAI DATASET v1.0 Category: Database querying ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LEN 2048

int main(int argc, char **argv)
{
    MYSQL *conn = mysql_init(NULL);

    if (conn == NULL)
    {
        fprintf(stderr, "Failed to create MySQL handle.\n");
        exit(1);
    }

    const char *host = "localhost";
    const char *user = "root";
    const char *password = "password";
    const char *db = "mydatabase";

    if (mysql_real_connect(conn, host, user, password, db, 0, NULL, 0) == NULL)
    {
        fprintf(stderr, "Failed to connect to database.\n");
        mysql_close(conn);
        exit(1);
    }

    char query[MAX_QUERY_LEN];

    snprintf(query, MAX_QUERY_LEN, "SELECT * FROM users WHERE username='%s'", argv[1]);

    if (mysql_query(conn, query) != 0)
    {
        fprintf(stderr, "Failed to execute query.\n");
        mysql_close(conn);
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL)
    {
        fprintf(stderr, "Failed to store result set.\n");
        mysql_close(conn);
        exit(1);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)))
    {
        for (int i = 0; i < num_fields; i++)
        {
            printf("%s\t", row[i]);
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}