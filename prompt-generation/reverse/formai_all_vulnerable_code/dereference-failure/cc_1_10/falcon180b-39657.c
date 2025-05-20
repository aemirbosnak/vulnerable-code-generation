//Falcon-180B DATASET v1.0 Category: System event logger ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define LOG_FILE "system_log.txt"

typedef struct {
    time_t timestamp;
    char message[256];
} log_entry_t;

log_entry_t log_entries[MAX_LOG_ENTRIES];
int num_log_entries = 0;

void log_message(const char* message) {
    time_t current_time = time(NULL);
    strftime(message, 256, "%Y-%m-%d %H:%M:%S", localtime(&current_time));
    strcat(message, " - ");
    strcat(message, message);
    strcat(message, "\n");

    if (num_log_entries >= MAX_LOG_ENTRIES) {
        printf("Log is full, oldest entry removed.\n");
        num_log_entries = MAX_LOG_ENTRIES - 1;
    }

    log_entries[num_log_entries].timestamp = current_time;
    strcpy(log_entries[num_log_entries].message, message);
    num_log_entries++;

    FILE* log_file = fopen(LOG_FILE, "a");
    if (log_file!= NULL) {
        fprintf(log_file, "%s", message);
        fclose(log_file);
    }
}

void print_log() {
    printf("=== System Log ===\n");
    for (int i = 0; i < num_log_entries; i++) {
        printf("%s", log_entries[i].message);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    log_message("System started.");

    int random_number = rand() % 100;
    printf("Random number: %d\n", random_number);

    log_message("Random number generated.");

    print_log();

    return 0;
}