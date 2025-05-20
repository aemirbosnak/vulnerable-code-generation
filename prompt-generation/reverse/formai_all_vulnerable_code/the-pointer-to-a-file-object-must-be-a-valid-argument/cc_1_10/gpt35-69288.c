//FormAI DATASET v1.0 Category: Log analysis ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 200
#define MAX_ERRORS 10

/* Struct to hold each log entry */
typedef struct LogEntry {
    char date[20];
    char time[20];
    char msg[LINE_LEN];
} LogEntry;

/* Function to parse each line of the log file */
LogEntry parse_log_line(char* line) {
    LogEntry entry;
    char* date = strtok(line, " ");
    char* time = strtok(NULL, " ");
    char* msg = strtok(NULL, "");
    strcpy(entry.date, date);
    strcpy(entry.time, time);
    strcpy(entry.msg, msg);
    return entry;
}

/* Function to print a log entry */
void print_log_entry(LogEntry entry) {
    printf("%s %s: %s\n", entry.date, entry.time, entry.msg);
}

int main(int argc, char** argv) {
    FILE* fp;
    char line[LINE_LEN];
    LogEntry entries[MAX_ERRORS];
    int num_errors = 0;

    /* Open the log file */
    fp = fopen("example.log", "r");

    /* Read each line of the log file */
    while(fgets(line, LINE_LEN, fp)) {
        /* Parse the log entry */
        LogEntry entry = parse_log_line(line);

        /* Check if it's an error message */
        if(strstr(entry.msg, "ERROR")) {
            /* Add it to the errors array */
            entries[num_errors++] = entry;

            /* Check if we've hit the maximum number of errors */
            if(num_errors == MAX_ERRORS) {
                printf("Max number of errors reached\n");
                break;
            }
        }
    }

    /* Close the log file */
    fclose(fp);

    /* Print all the errors */
    printf("Found %d errors:\n", num_errors);
    for(int i=0; i<num_errors; i++) {
        print_log_entry(entries[i]);
    }

    return 0;
}