//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sqlite3.h>

#define MAX_AP 100
#define BUFFER_SIZE 1024

typedef struct {
    char ssid[32]; // SSID of the Wi-Fi access point
    int signal_strength; // Signal strength in dBm
} AccessPoint;

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void execute_sql(sqlite3 *db, const char *sql) {
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

void create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS SignalStrength ("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "SSID TEXT NOT NULL, "
                      "Strength INTEGER NOT NULL);";
    execute_sql(db, sql);
}

void insert_record(sqlite3 *db, AccessPoint *ap) {
    char sql[BUFFER_SIZE];
    snprintf(sql, sizeof(sql), "INSERT INTO SignalStrength (SSID, Strength) VALUES ('%s', %d);",
             ap->ssid, ap->signal_strength);
    execute_sql(db, sql);
}

void scan_wifi(AccessPoint ap_list[], int *count) {
    FILE *fp = popen("nmcli -t -f SSID,SIGNAL dev wifi", "r");
    if (fp == NULL) {
        handle_error("Failed to run command");
    }

    char line[BUFFER_SIZE];
    *count = 0;

    while (fgets(line, sizeof(line) - 1, fp) != NULL && *count < MAX_AP) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character

        char *ssid = strtok(line, ":");
        char *signal_str = strtok(NULL, ":");
        int signal_strength = atoi(signal_str);

        strncpy(ap_list[*count].ssid, ssid, sizeof(ap_list[*count].ssid) - 1);
        ap_list[*count].signal_strength = signal_strength;

        (*count)++;
    }

    if (pclose(fp) == -1) {
        perror("pclose failed");
    }
}

void display_results(AccessPoint ap_list[], int count) {
    printf("\n---- Wi-Fi Signal Strengths ----\n");
    printf("%-32s %s\n", "SSID", "Signal Strength (dBm)");
    printf("-------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-32s %d\n", ap_list[i].ssid, ap_list[i].signal_strength);
    }
    printf("-------------------------------------\n");
}

int main(void) {
    printf("🎉 Welcome to the Wi-Fi Signal Strength Analyzer! 🎉\n");
    
    AccessPoint ap_list[MAX_AP];
    int ap_count = 0;
    
    // Create database connection
    sqlite3 *db;
    if (sqlite3_open("wifi_signals.db", &db)) {
        handle_error("Can't open database");
    }
    
    create_table(db);

    // Scan for available networks
    scan_wifi(ap_list, &ap_count);
    
    // Display the results
    display_results(ap_list, ap_count);

    // Insert results into database
    for (int i = 0; i < ap_count; i++) {
        insert_record(db, &ap_list[i]);
    }

    // Close database connection
    sqlite3_close(db);
    
    printf("✨ Data saved successfully into database! ✨\n");
    return 0;
}