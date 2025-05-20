//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define ERROR_FILE "error_log.txt"
#define BUFFER_SIZE 256

void log_event(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Could not open log file");
        return;
    }
    
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline character

    fprintf(file, "[%s] EVENT: %s\n", timestamp, message);
    fclose(file);
}

void log_error(const char *message) {
    FILE *file = fopen(ERROR_FILE, "a");
    if (file == NULL) {
        perror("Could not open error log file");
        return;
    }

    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline character

    fprintf(file, "[%s] ERROR: %s\n", timestamp, message);
    fclose(file);
}

char* get_command_output(const char *command) {
    FILE *fp;
    char *result = malloc(BUFFER_SIZE);
    
    if(result == NULL) {
        log_error("Memory allocation for command output failed");
        return NULL;
    }

    fp = popen(command, "r");
    if (fp == NULL) {
        log_error("Failed to run command");
        free(result);
        return NULL;
    }

    if (fgets(result, BUFFER_SIZE, fp) != NULL) {
        result[strcspn(result, "\n")] = 0; // Remove newline character
    } else {
        log_error("No output from command");
        free(result);
        result = NULL;
    }

    pclose(fp);
    return result;
}

void simulate_logging() {
    log_event("Simulation started.");
    
    char *cpu_info = get_command_output("lscpu | grep 'Model name:'");
    if (cpu_info) {
        log_event(cpu_info);
        free(cpu_info);
    }

    char *memory_info = get_command_output("free -h | grep 'Mem:'");
    if (memory_info) {
        log_event(memory_info);
        free(memory_info);
    }
    
    log_event("Simulation completed.");
}

int main() {
    log_event("Event logger program started.");

    simulate_logging();

    log_event("Event logger program finished.");
    return 0;
}