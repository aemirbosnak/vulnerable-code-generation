//FormAI DATASET v1.0 Category: Database querying ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

/* Struct to hold the database query result */
typedef struct db_result {
    int num_fields;     // Number of fields in the result
    MYSQL_RES *res;     // The mysql result object
    MYSQL_ROW row;      // The current row being processed
} db_result_t;

/* Connects to the database with the given credentials */
int connect_to_database(MYSQL *conn, const char *host, const char *user, const char *pass, const char *db)
{
    if(!mysql_real_connect(conn, host, user, pass, db, 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
        return 0;
    }

    return 1;
}

/* Executes a SELECT query and returns the result */
db_result_t query_database(MYSQL *conn, const char *sql)
{
    db_result_t result;
    result.num_fields = 0;
    result.res = NULL;

    if(mysql_query(conn, sql)) {
        fprintf(stderr, "Error running query: %s\n", mysql_error(conn));
        return result;
    }

    result.res = mysql_store_result(conn);
    if(result.res == NULL) {
        fprintf(stderr, "Error retrieving result: %s\n", mysql_error(conn));
        return result;
    }

    result.num_fields = mysql_num_fields(result.res);

    return result;
}

int main(int argc, char **argv)
{
    MYSQL *conn = mysql_init(NULL);

    if(conn == NULL) {
        fprintf(stderr, "Error initializing mysql: %s\n", mysql_error(conn));
        return 1;
    }

    /* Connect to the database */
    if(!connect_to_database(conn, "localhost", "root", "password", "mydb")) {
        mysql_close(conn);
        return 1;
    }

    /* Query the database */
    db_result_t result = query_database(conn, "SELECT * FROM users");

    /* Print out the results */
    while((result.row = mysql_fetch_row(result.res))) {
        for(int i = 0; i < result.num_fields; i++) {
            printf("%s\t", result.row[i] ? result.row[i] : "NULL");
        }
        printf("\n");
    }

    /* Free the result object */
    mysql_free_result(result.res);

    /* Close the database connection */
    mysql_close(conn);

    return 0;
}