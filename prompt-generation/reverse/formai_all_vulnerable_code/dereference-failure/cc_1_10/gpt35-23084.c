//FormAI DATASET v1.0 Category: Database querying ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

typedef struct {
    sqlite3* db;
    sqlite3_stmt* stmt;
    char* query;
} Query;

void queryAsync(Query* query, void (*callback)(int, int, char**, char**)) {
    sqlite3_prepare_v2(query->db, query->query, -1, &query->stmt, NULL);
    int columnCount = sqlite3_column_count(query->stmt);
    int status;
    char* errorMsg = NULL;
    char** results = malloc(sizeof(char*) * columnCount);
    char** columnNames = malloc(sizeof(char*) * columnCount);
    for(int i = 0; i < columnCount; i++) {
        columnNames[i] = strdup(sqlite3_column_name(query->stmt, i));
    }
    int rowIndex = 0;
    while ((status = sqlite3_step(query->stmt)) == SQLITE_ROW) {
        for(int i = 0; i < columnCount; i++) {
            results[i] = strdup((char*) sqlite3_column_text(query->stmt, i));
        }
        callback(rowIndex, columnCount, columnNames, results);
        rowIndex++;
    }
    if (status != SQLITE_DONE) {
        errorMsg = strdup(sqlite3_errmsg(query->db));
    }
    sqlite3_finalize(query->stmt);
    callback(-1, columnCount, columnNames, NULL);
    for(int i = 0; i < columnCount; i++) {
        free(columnNames[i]);
    }
    if (errorMsg != NULL) {
        free(errorMsg);
    }
    free(columnNames);
    free(results);
    free(query->query);
    free(query);
}

void printResults(int rowIndex, int columnCount, char** columnNames, char** rowResults) {
    if (rowIndex == 0) {
        for(int i = 0; i < columnCount; i++) {
            printf("%s", columnNames[i]);
            if (i < columnCount - 1) {
                printf("\t");
            }
        }
        printf("\n");
    }
    if (rowResults == NULL) {
        printf("Query completed.\n");
        return;
    }
    for(int i = 0; i < columnCount; i++) {
        printf("%s", rowResults[i]);
        if (i < columnCount - 1) {
            printf("\t");
        }
    }
    printf("\n");
}

int main() {
    Query* query = malloc(sizeof(Query));
    query->db = NULL;
    sqlite3_open("example.db", &query->db);
    query->query = "SELECT * FROM my_table";
    queryAsync(query, printResults);
    sqlite3_close(query->db);
    return 0;
}