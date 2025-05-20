//FormAI DATASET v1.0 Category: Database querying ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <mysql/mysql.h>

// struct to hold connection details
typedef struct {
    const char *server;
    const char *user;
    const char *password;
    const char *database;
} DBConnection;

// struct to hold query result
typedef struct {
    int id;
    char name[50];
    char email[50];
} Result;

// function to execute query
void *queryDB(void *param) {
    DBConnection *conn = (DBConnection *)param;
    MYSQL *mysql = mysql_init(NULL);

    if (!mysql_real_connect(mysql, conn->server, conn->user, conn->password, conn->database, 0, NULL, 0)) {
        fprintf(stderr, "Failed to connect to database: Error: %s\n", mysql_error(mysql));
        return NULL;
    }

    if (mysql_query(mysql, "SELECT * FROM users")) {
        fprintf(stderr, "Failed to execute query: Error: %s\n", mysql_error(mysql));
        return NULL;
    }

    MYSQL_RES *result = mysql_store_result(mysql);
    if (!result) {
        fprintf(stderr, "Failed to store result: Error: %s\n", mysql_error(mysql));
        return NULL;
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        Result *res = (Result *)malloc(sizeof(Result));
        res->id = atoi(row[0]);
        strncpy(res->name, row[1], 50);
        strncpy(res->email, row[2], 50);

        printf("ID: %d, Name: %s, Email: %s\n", res->id, res->name, res->email);

        free(res);
    }

    mysql_free_result(result);
    mysql_close(mysql);

    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    DBConnection conn1 = {"localhost", "root", "password", "database1"};
    DBConnection conn2 = {"localhost", "root", "password", "database2"};

    pthread_create(&thread1, NULL, queryDB, &conn1);
    pthread_create(&thread2, NULL, queryDB, &conn2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}