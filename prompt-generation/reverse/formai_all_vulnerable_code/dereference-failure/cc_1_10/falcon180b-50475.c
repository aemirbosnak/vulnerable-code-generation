//Falcon-180B DATASET v1.0 Category: Database querying ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

void shape_shift(Person *person) {
    if (person->age < 18) {
        person->name = "Teenager";
    } else if (person->age < 30) {
        person->name = "Young adult";
    } else if (person->age < 50) {
        person->name = "Adult";
    } else {
        person->name = "Senior";
    }
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    char query[100];
    sprintf(query, "SELECT * FROM people");

    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        Person person;
        person.name = strdup(row[0]);
        person.age = atoi(row[1]);
        person.email = strdup(row[2]);

        shape_shift(&person);

        printf("%s is a %d-year-old %s with email %s\n", person.name, person.age, person.name, person.email);

        free(person.name);
        free(person.email);
    }

    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}