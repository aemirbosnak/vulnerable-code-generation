//FormAI DATASET v1.0 Category: Log analysis ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_LOG_LINES 1000

struct log_entry { // define a struct to hold log entry data
    char date[20];
    char time[20];
    char message[MAX_LINE_LENGTH];
};

int main(int argc, char *argv[]) {
    // check for correct usage
    if (argc != 2) { // program expects one argument: the log file to analyze
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    // open the log file
    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) { // check if file opened successfully
        printf("Error: could not open file: %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH]; // variable to hold each line of the log file
    struct log_entry log[MAX_LOG_LINES]; // array to hold all log entries
    int num_entries = 0; // count the number of log entries
    
    // read through log file, line by line
    while(fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
        // tokenize line to extract date, time, and message
        char *date = strtok(line, " ");
        char *time = strtok(NULL, " ");
        char *message = strtok(NULL, "\n");

        // create a log entry struct and add it to the log array
        struct log_entry entry;
        strcpy(entry.date, date);
        strcpy(entry.time, time);
        strcpy(entry.message, message);
        log[num_entries] = entry;
        num_entries++;
    }

    fclose(log_file); // close the log file

    // loop through log entries and count how many contain "error"
    int num_errors = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strstr(log[i].message, "error") != NULL) {
            num_errors++;
        }
    }

    // print analysis results
    printf("Log file: %s\n", argv[1]);
    printf("Total number of log entries: %d\n", num_entries);
    printf("Entries containing 'error': %d\n", num_errors);

    return 0;
}