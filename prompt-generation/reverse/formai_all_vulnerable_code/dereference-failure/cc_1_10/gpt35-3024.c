//FormAI DATASET v1.0 Category: Log analysis ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the log data
typedef struct log {
    char date[20];
    char time[20];
    char message[100];
} Log;

// Function to read log data from a file and store it in an array of logs
void read_logs(char* filename, Log* logs, int* count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char line[200];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Split the line into date, time, and message
        char* token = strtok(line, " ");
        strcpy(logs[*count].date, token);
        token = strtok(NULL, " ");
        strcpy(logs[*count].time, token);
        token = strtok(NULL, "\n");
        strcpy(logs[*count].message, token);
        
        (*count)++;
    }

    fclose(file);
}

// Function to print all logs in the array
void print_logs(Log* logs, int count) {
    printf("Logs:\n");
    for (int i = 0; i < count; i++) {
        printf("Date: %s, Time: %s, Message: %s\n", logs[i].date, logs[i].time, logs[i].message);
    }
}

// Function to filter logs by date
void filter_logs_by_date(Log* logs, int count, char* date) {
    printf("Logs on %s:\n", date);
    for (int i = 0; i < count; i++) {
        if (strcmp(logs[i].date, date) == 0) {
            printf("Time: %s, Message: %s\n", logs[i].time, logs[i].message);
        }
    }
}

// Function to filter logs by message
void filter_logs_by_message(Log* logs, int count, char* message) {
    printf("Logs containing '%s':\n", message);
    for (int i = 0; i < count; i++) {
        if (strstr(logs[i].message, message) != NULL) {
            printf("Date: %s, Time: %s\n", logs[i].date, logs[i].time);
        }
    }
}

int main() {
    Log logs[100];
    int count = 0;
    char filename[] = "log.txt";
    read_logs(filename, logs, &count);

    print_logs(logs, count);

    char date[] = "2021-10-01";
    filter_logs_by_date(logs, count, date);

    char message[] = "error";
    filter_logs_by_message(logs, count, message);

    return 0;
}