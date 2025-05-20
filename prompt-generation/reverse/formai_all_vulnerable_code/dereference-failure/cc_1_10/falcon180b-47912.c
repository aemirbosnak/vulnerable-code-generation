//Falcon-180B DATASET v1.0 Category: Database querying ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

struct Record {
    char id[10];
    char name[50];
    char age[5];
    char gender[10];
};

void display_record(struct Record record) {
    printf("ID: %s\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Age: %s\n", record.age);
    printf("Gender: %s\n", record.gender);
    printf("\n");
}

int main() {
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    struct Record record;

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        printf("Error: Unable to connect to MySQL: %s\n", mysql_error(conn));
        exit(1);
    }

    if (mysql_query(conn, "SELECT * FROM table_name")) {
        printf("Error: Query execution failed: %s\n", mysql_error(conn));
        exit(1);
    }

    result = mysql_store_result(conn);
    while ((row = mysql_fetch_row(result))!= NULL) {
        strcpy(record.id, row[0]);
        strcpy(record.name, row[1]);
        strcpy(record.age, row[2]);
        strcpy(record.gender, row[3]);
        display_record(record);
    }

    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}