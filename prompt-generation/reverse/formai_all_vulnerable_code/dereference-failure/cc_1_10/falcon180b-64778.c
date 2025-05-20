//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_FIELD_LENGTH 1024
#define MAX_ROWS 1000

typedef struct {
    char *name;
    int id;
} Person;

static int callback(void *data, int argc, char **argv, char **azColName) {
    Person *person = (Person *)data;

    if (argc > 0) {
        strncpy(person->name, argv[0], MAX_FIELD_LENGTH);
        person->name[MAX_FIELD_LENGTH - 1] = '\0';
    }

    if (argc > 1) {
        person->id = atoi(argv[1]);
    }

    return 0;
}

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[MAX_QUERY_LENGTH];
    int num_rows = 0;

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, "localhost", "username", "password", "database", 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }

    sprintf(query, "SELECT name, id FROM people");

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error querying database: %s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_store_result(conn);

    while ((row = mysql_fetch_row(res))!= NULL) {
        Person *person = (Person *)malloc(sizeof(Person));

        if (num_rows >= MAX_ROWS) {
            fprintf(stderr, "Maximum number of rows exceeded\n");
            break;
        }

        memset(person, 0, sizeof(Person));
        person->name = (char *)malloc(MAX_FIELD_LENGTH);

        mysql_field_seek(res, 0);
        mysql_field_tell(res);
        while (mysql_fetch_field(res)) {
            if (mysql_field_seek(res, 0)) {
                fprintf(stderr, "Error seeking field\n");
                exit(1);
            }

            if (mysql_fetch_field(res)) {
                if (num_rows >= MAX_ROWS) {
                    fprintf(stderr, "Maximum number of rows exceeded\n");
                    break;
                }

                strncpy(person->name, row[0], MAX_FIELD_LENGTH);
                person->name[MAX_FIELD_LENGTH - 1] = '\0';

                person->id = atoi(row[1]);

                num_rows++;
            }
        }

        free(person->name);
        free(person);
    }

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}