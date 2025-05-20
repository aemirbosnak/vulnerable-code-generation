//Falcon-180B DATASET v1.0 Category: Database querying ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <mysql/mysql.h>

#define MAX_QUERIES 10
#define MAX_THREADS 5

struct query_data {
    char *query;
    int result_index;
};

void *run_query(void *arg) {
    struct query_data *data = (struct query_data *) arg;
    MYSQL *conn = mysql_init(NULL);
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;

    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }

    if (mysql_query(conn, data->query)) {
        printf("Error executing query: %s\n", mysql_error(conn));
        exit(1);
    }

    result = mysql_store_result(conn);
    if (result == NULL) {
        printf("No results found\n");
    } else {
        while ((row = mysql_fetch_row(result))) {
            printf("%s\n", row[data->result_index]);
        }
    }

    mysql_close(conn);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    struct query_data queries[MAX_QUERIES];

    queries[0].query = "SELECT * FROM table1";
    queries[0].result_index = 0;

    queries[1].query = "SELECT * FROM table2";
    queries[1].result_index = 0;

    // Add more queries as needed

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, run_query, &queries[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}