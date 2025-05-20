//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define CONFIG_FILE "config.txt"

struct config {
    char *host;
    char *user;
    char *password;
    char *database;
    int port;
};

struct config *read_config() {
    struct config *config = malloc(sizeof(struct config));
    FILE *file = fopen(CONFIG_FILE, "r");
    if (!file) {
        perror("Could not open config file");
        return NULL;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *key, *value;
        key = strtok(line, "=");
        value = strtok(NULL, "\n");
        if (!key || !value) {
            continue;
        }

        if (!strcmp(key, "host")) {
            config->host = strdup(value);
        } else if (!strcmp(key, "user")) {
            config->user = strdup(value);
        } else if (!strcmp(key, "password")) {
            config->password = strdup(value);
        } else if (!strcmp(key, "database")) {
            config->database = strdup(value);
        } else if (!strcmp(key, "port")) {
            config->port = atoi(value);
        }
    }

    fclose(file);
    return config;
}

void free_config(struct config *config) {
    free(config->host);
    free(config->user);
    free(config->password);
    free(config->database);
    free(config);
}

int main() {
    struct config *config = read_config();
    if (!config) {
        return -1;
    }

    sqlite3 *db;
    int rc = sqlite3_open_v2(config->database, &db, SQLITE_OPEN_READONLY, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Could not open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        free_config(config);
        return -1;
    }

    char *sql = "SELECT * FROM employees WHERE salary > ?";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Could not prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        free_config(config);
        return -1;
    }

    int salary = 10000;
    sqlite3_bind_int(stmt, 1, salary);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *name = (const char *)sqlite3_column_text(stmt, 1);
        int salary = sqlite3_column_int(stmt, 2);
        printf("%d %s %d\n", id, name, salary);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    free_config(config);
    return 0;
}