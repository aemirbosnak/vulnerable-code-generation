//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sqlite3.h>
#include <string.h>

typedef struct {
    sqlite3 *db;
    sqlite3_stmt *stmt;
} db_t;

db_t *db_new(const char *path) {
    db_t *db = malloc(sizeof(db_t));
    int rc = sqlite3_open(path, &db->db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db->db));
        sqlite3_close(db->db);
        free(db);
        return NULL;
    }
    return db;
}

void db_free(db_t *db) {
    sqlite3_finalize(db->stmt);
    sqlite3_close(db->db);
    free(db);
}

int db_query(db_t *db, const char *sql, void (*callback)(void *, int, char **, char **)) {
    int rc = sqlite3_prepare_v2(db->db, sql, -1, &db->stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db->db));
        return rc;
    }
    while ((rc = sqlite3_step(db->stmt)) == SQLITE_ROW) {
        int ncol = sqlite3_column_count(db->stmt);
        char **cols = malloc(sizeof(char *) * ncol);
        char **names = malloc(sizeof(char *) * ncol);
        for (int i = 0; i < ncol; i++) {
            cols[i] = (char *)sqlite3_column_text(db->stmt, i);
            names[i] = (char *)sqlite3_column_name(db->stmt, i);
        }
        callback(db, ncol, cols, names);
        free(cols);
        free(names);
    }
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error executing statement: %s\n", sqlite3_errmsg(db->db));
        return rc;
    }
    return 0;
}

void print_row(void *db, int ncol, char **cols, char **names) {
    printf("| ");
    for (int i = 0; i < ncol; i++) {
        printf("%s: %s | ", names[i], cols[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s database.db\n", argv[0]);
        return 1;
    }
    db_t *db = db_new(argv[1]);
    if (db == NULL) {
        return 1;
    }
    db_query(db, "SELECT * FROM users", print_row);
    db_free(db);
    return 0;
}