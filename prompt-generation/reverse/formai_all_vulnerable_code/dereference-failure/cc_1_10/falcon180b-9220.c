//Falcon-180B DATASET v1.0 Category: Database querying ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <mysql/mysql.h>

#define MAX_QUERIES 10
#define MAX_THREADS 5

typedef struct query_t {
    char *sql;
    int result;
} query_t;

void *run_query(void *arg) {
    query_t *query = (query_t *) arg;
    MYSQL *conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database", 0, NULL, 0)) {
        printf("Error: Unable to connect to MySQL: %s\n", mysql_error(conn));
        exit(1);
    }
    if (mysql_query(conn, query->sql)) {
        printf("Error: Unable to execute query: %s\n", mysql_error(conn));
        exit(1);
    }
    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        printf("Error: No result set returned.\n");
        exit(1);
    }
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))!= NULL) {
        printf("%s\n", row[0]);
    }
    mysql_free_result(result);
    mysql_close(conn);
    query->result = 1;
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    query_t queries[MAX_QUERIES];

    // Initialize queries
    queries[0].sql = "SELECT * FROM table1";
    queries[1].sql = "SELECT * FROM table2";
    queries[2].sql = "SELECT * FROM table3";
    queries[3].sql = "SELECT * FROM table4";
    queries[4].sql = "SELECT * FROM table5";

    // Start threads
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, run_query, &queries[i % MAX_QUERIES]);
    }

    // Join threads
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}