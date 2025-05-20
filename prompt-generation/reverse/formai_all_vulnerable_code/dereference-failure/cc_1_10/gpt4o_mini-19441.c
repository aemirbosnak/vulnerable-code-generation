//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void search_for_clue(MYSQL *con, const char *clue) {
    char query[256];
    sprintf(query, "SELECT * FROM clues WHERE description LIKE '%%%s%%'", clue);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    printf("Sherlock Holmes carefully examines the clues:\n");
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("Field %d: %s\n", i + 1, row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    mysql_free_result(result);
}

void analyze_case(MYSQL *con, const char *case_name) {
    char query[256];
    sprintf(query, "SELECT * FROM cases WHERE name='%s'", case_name);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        printf("Investigating case: %s\n", row[1]);
        printf("Details: %s\n", row[2]);
        printf("Status: %s\n\n", row[3]);
    }
    mysql_free_result(result);
}

void add_clue(MYSQL *con, const char *description) {
    char query[256];
    sprintf(query, "INSERT INTO clues (description) VALUES ('%s')", description);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }
}

int main() {
    MYSQL *con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "user", "password", "sherlock_holmes_db", 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    printf("Ah, Watson! We are faced with an intriguing mystery!\n");

    analyze_case(con, "The Hound of the Baskervilles");

    add_clue(con, "A large paw print found near the site.");
    add_clue(con, "An unusual howl at midnight.");

    search_for_clue(con, "paw print");
    search_for_clue(con, "howl");

    printf("The clues must be pieced together! What a fascinating case!\n");

    mysql_close(con);
    return 0;
}