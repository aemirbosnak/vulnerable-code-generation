//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

typedef struct node {
    char *name;
    char *value;
    struct node *next;
} node;

typedef struct query {
    char *sql;
    node *params;
    struct query *next;
} query;

sqlite3 *db;
query *queries;

void execute_query(query *q) {
    sqlite3_stmt *stmt;
    int rc;

    rc = sqlite3_prepare_v2(db, q->sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "sqlite3_prepare_v2: %s\n", sqlite3_errmsg(db));
        return;
    }

    node *param = q->params;
    while (param != NULL) {
        rc = sqlite3_bind_text(stmt, param->name, param->value, -1, SQLITE_TRANSIENT);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "sqlite3_bind_text: %s\n", sqlite3_errmsg(db));
            return;
        }
        param = param->next;
    }

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        fprintf(stderr, "sqlite3_step: %s\n", sqlite3_errmsg(db));
        return;
    }

    int column_count = sqlite3_column_count(stmt);
    for (int i = 0; i < column_count; i++) {
        const char *column_name = sqlite3_column_name(stmt, i);
        const char *column_value = sqlite3_column_text(stmt, i);
        printf("%s: %s\n", column_name, column_value);
    }

    rc = sqlite3_finalize(stmt);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "sqlite3_finalize: %s\n", sqlite3_errmsg(db));
        return;
    }
}

void execute_queries() {
    query *q = queries;
    while (q != NULL) {
        execute_query(q);
        q = q->next;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s database.db\n", argv[0]);
        return 1;
    }

    int rc = sqlite3_open(argv[1], &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "sqlite3_open: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    queries = NULL;

    query *q = malloc(sizeof(query));
    q->sql = "SELECT * FROM users WHERE name = ?";
    q->params = NULL;
    q->next = NULL;
    queries = q;

    q = malloc(sizeof(query));
    q->sql = "SELECT * FROM posts WHERE user_id = ?";
    q->params = NULL;
    q->next = NULL;
    queries = q;

    execute_queries();

    sqlite3_close(db);

    return 0;
}