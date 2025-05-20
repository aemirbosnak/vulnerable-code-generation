//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#define DB_NAME "mystic_database.db"
#define QUERY_LENGTH 256

void create_table(sqlite3 *db) {
    char *err_msg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS DreamJournals("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "Dream TEXT NOT NULL,"
                      "Date TEXT NOT NULL,"
                      "Mood TEXT NOT NULL);";

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

void insert_dream(sqlite3 *db, const char *dream, const char *date, const char *mood) {
    char *err_msg = 0;
    char sql[QUERY_LENGTH];

    snprintf(sql, sizeof(sql), "INSERT INTO DreamJournals(Dream, Date, Mood) VALUES('%s', '%s', '%s');",
             dream, date, mood);

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Dream inserted successfully: %s\n", dream);
    }
}

void query_dreams(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM DreamJournals ORDER BY DATE(Date) DESC;";
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch dreams: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("\n--- Mystical Dream Journal Entries ---\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *dream = sqlite3_column_text(stmt, 1);
        const unsigned char *date = sqlite3_column_text(stmt, 2);
        const unsigned char *mood = sqlite3_column_text(stmt, 3);

        printf("Entry %d: %s | Date: %s | Mood: %s\n", id, dream, date, mood);
    }
    sqlite3_finalize(stmt);
}

void delete_dream(sqlite3 *db, int id) {
    char *err_msg = 0;
    char sql[QUERY_LENGTH];
    snprintf(sql, sizeof(sql), "DELETE FROM DreamJournals WHERE ID=%d;", id);

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Dream entry %d deleted successfully!\n", id);
    }
}

int main(int argc, char *argv[]) {
    sqlite3 *db;
    int exit_code = sqlite3_open(DB_NAME, &db);
    
    if (exit_code) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return exit_code;
    }
    create_table(db);

    if (argc < 5) {
        fprintf(stderr, "Usage: %s <insert|query|delete> <dream_text> <date(YYYY-MM-DD)> <mood>\n", argv[0]);
        sqlite3_close(db);
        return -1;
    }

    if (strcmp(argv[1], "insert") == 0) {
        insert_dream(db, argv[2], argv[3], argv[4]);
    }
    else if (strcmp(argv[1], "query") == 0) {
        query_dreams(db);
    }
    else if (strcmp(argv[1], "delete") == 0) {
        int id = atoi(argv[2]);
        delete_dream(db, id);
    }
    else {
        fprintf(stderr, "Unknown command: %s\n", argv[1]);
    }

    sqlite3_close(db);
    return 0;
}