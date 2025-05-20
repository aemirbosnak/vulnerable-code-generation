//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define BUFFER_SIZE 256

void log_event(const char *event) {
    FILE *logfile = fopen(LOG_FILE, "a");
    if (!logfile) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }

    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    if (timestamp) {
        timestamp[strlen(timestamp) - 1] = '\0';  // Remove newline
    }

    fprintf(logfile, "[%s] %s\n", timestamp, event);
    fclose(logfile);
}

void display_log() {
    FILE *logfile = fopen(LOG_FILE, "r");
    if (!logfile) {
        perror("Could not open log file");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), logfile)) {
        printf("%s", buffer);
    }
    
    fclose(logfile);
}

void clear_log() {
    if (remove(LOG_FILE) == 0) {
        printf("Log file cleared.\n");
    } else {
        perror("Error clearing log file");
    }
}

void simulate_events() {
    const char *events[] = {
        "System started.",
        "User logged in.",
        "File opened: config.txt.",
        "Database connection established.",
        "User performed an action.",
        "User logged out.",
        "System shutdown initiated."
    };

    for (int i = 0; i < 7; ++i) {
        log_event(events[i]);
        sleep(1);  // Wait for a second to simulate time passing
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [log|display|clear|simulate]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "log") == 0) {
        char *event = "Custom event registered."; 
        log_event(event);
        printf("Event logged: %s\n", event);
    } else if (strcmp(argv[1], "display") == 0) {
        display_log();
    } else if (strcmp(argv[1], "clear") == 0) {
        clear_log();
    } else if (strcmp(argv[1], "simulate") == 0) {
        printf("Simulating events...\n");
        simulate_events();
    } else {
        fprintf(stderr, "Unknown command: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}