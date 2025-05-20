//Falcon-180B DATASET v1.0 Category: Database querying ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_USERNAME_LENGTH 32
#define MAX_PASSWORD_LENGTH 64
#define MAX_DATABASE_LENGTH 64
#define MAX_TABLE_LENGTH 64
#define MAX_COLUMN_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char username[MAX_USERNAME_LENGTH + 1];
    char password[MAX_PASSWORD_LENGTH + 1];
    char database[MAX_DATABASE_LENGTH + 1];
} Credentials;

int main(int argc, char *argv[]) {
    if (argc!= 7) {
        printf("Usage: %s <username> <password> <database> <table> <column> <value>\n", argv[0]);
        return 1;
    }

    Credentials creds;
    strncpy(creds.username, argv[1], MAX_USERNAME_LENGTH);
    strncpy(creds.password, argv[2], MAX_PASSWORD_LENGTH);
    strncpy(creds.database, argv[3], MAX_DATABASE_LENGTH);

    MYSQL *conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, creds.database, creds.username, creds.password, NULL, 0, NULL, 0)) {
        printf("Error: Unable to connect to database: %s\n", mysql_error(conn));
        return 1;
    }

    char query[MAX_QUERY_LENGTH];
    snprintf(query, MAX_QUERY_LENGTH, "SELECT * FROM `%s` WHERE `%s` = '%s'", argv[4], argv[5], argv[6]);

    if (mysql_query(conn, query)) {
        printf("Error: Unable to execute query: %s\n", mysql_error(conn));
        return 1;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    MYSQL_ROW row;

    if ((row = mysql_fetch_row(result))) {
        printf("Results:\n");
        while ((row = mysql_fetch_row(result))) {
            for (int i = 0; i < mysql_num_fields(result); i++) {
                printf("%s: %s\n", mysql_fetch_field(result)->name, row[i]? row[i] : "NULL");
            }
            printf("\n");
        }
    } else {
        printf("No results found.\n");
    }

    mysql_close(conn);
    return 0;
}