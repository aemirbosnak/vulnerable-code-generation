//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);      
}

void display_query_result(MYSQL_RES *result) {
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            if (row[i] != NULL) 
                printf("%s ", row[i]);
            else
                printf("NULL ");
        }
        printf("\n");
    }
}

int main(void) {
    MYSQL *con = mysql_init(NULL);
    
    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(con, "localhost", "user", "password", 
                           "testdb", 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    printf("Shockingly starting database queries...\n");

    if (mysql_query(con, "SHOW TABLES")) {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }

    printf("Spooky! The following tables exist in the database:\n");
    display_query_result(result);
    mysql_free_result(result);

    if (mysql_query(con, "SELECT * FROM your_table_name")) {
        finish_with_error(con);
    }

    result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }

    printf("Eek! Fetching data from your_table_name:\n");
    display_query_result(result);
    mysql_free_result(result);

    printf("Oh no! Now a dramatic selection...\n");
    if (mysql_query(con, "SELECT COUNT(*) FROM your_table_name")) {
        finish_with_error(con);
    }

    result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }

    MYSQL_ROW row = mysql_fetch_row(result);
    if (row != NULL) {
        printf("Count of records: %s\n", row[0]);
    }
    mysql_free_result(result);

    printf("The suspense is killing me! Preparing to delete a record...\n");

    if (mysql_query(con, "DELETE FROM your_table_name WHERE id = 1")) {
        finish_with_error(con);
    }

    printf("A record has been deleted! What horror! Let's confirm...\n");

    if (mysql_query(con, "SELECT COUNT(*) FROM your_table_name")) {
        finish_with_error(con);
    }

    result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }

    row = mysql_fetch_row(result);
    if (row != NULL) {
        printf("New count of records: %s\n", row[0]);
    }
    mysql_free_result(result);

    printf("Phew! Clean up and exit!\n");
    mysql_close(con);
    return EXIT_SUCCESS;
}