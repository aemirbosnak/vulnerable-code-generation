//Falcon-180B DATASET v1.0 Category: Database querying ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <mysql/mysql.h>

typedef struct {
    char *name;
    int id;
} Person;

void *query_thread(void *arg) {
    Person *person = (Person *) arg;
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    char query[100];
    sprintf(query, "SELECT * FROM people WHERE name='%s'", person->name);

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Failed to connect to MySQL: %s\n", mysql_error(conn));
        exit(1);
    }

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error querying MySQL: %s\n", mysql_error(conn));
        exit(1);
    }

    result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "No results found.\n");
        exit(1);
    }

    row = mysql_fetch_row(result);
    if (row == NULL) {
        fprintf(stderr, "No results found.\n");
        exit(1);
    }

    person->id = atoi(row[0]);
    mysql_free_result(result);
    mysql_close(conn);
}

int main() {
    pthread_t threads[3];
    Person people[3] = {{"Alice", 0}, {"Bob", 0}, {"Charlie", 0}};

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, query_thread, (void *) &people[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < 3; i++) {
        printf("Name: %s, ID: %d\n", people[i].name, people[i].id);
    }

    return 0;
}