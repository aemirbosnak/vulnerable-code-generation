//Falcon-180B DATASET v1.0 Category: Database querying ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    char query[100];
    Person *data = NULL;
    int num_rows = 0;
    int max_rows = 100;
    data = (Person *)malloc(max_rows * sizeof(Person));

    // Connect to database
    conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("Error initializing MySQL\n");
        exit(1);
    }

    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }

    // Query database for all rows in table
    sprintf(query, "SELECT * FROM table_name");
    if (mysql_query(conn, query)) {
        printf("Error querying database: %s\n", mysql_error(conn));
        exit(1);
    }

    // Retrieve data from query
    result = mysql_store_result(conn);
    if (result == NULL) {
        printf("Error retrieving data: %s\n", mysql_error(conn));
        exit(1);
    }

    while ((row = mysql_fetch_row(result))!= NULL) {
        if (num_rows >= max_rows) {
            printf("Error: Maximum number of rows (%d) reached.\n", max_rows);
            exit(1);
        }

        data[num_rows].name = strdup(row[0]);
        data[num_rows].age = atoi(row[1]);
        num_rows++;
    }

    // Print retrieved data
    printf("Name\tAge\n");
    for (int i = 0; i < num_rows; i++) {
        printf("%s\t%d\n", data[i].name, data[i].age);
    }

    // Free resources
    mysql_free_result(result);
    mysql_close(conn);
    for (int i = 0; i < num_rows; i++) {
        free(data[i].name);
    }
    free(data);

    return 0;
}