//FormAI DATASET v1.0 Category: Log analysis ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 10000

int num_lines_read = 0;
char lines[MAX_NUM_LINES][MAX_LINE_LENGTH];

// A struct to hold a log message and its corresponding numerical value
typedef struct {
    char *message;
    int value;
} LogMessage;

// A function that takes a log message and returns its numerical value
int parse_log_message(LogMessage lm) {
    int value = 0;
    char *tok = strtok(lm.message, " ");
    while (tok != NULL) {
        if (strcmp(tok, "ERROR") == 0) {
            value -= 10;
        } else if (strcmp(tok, "WARNING") == 0) {
            value -= 5;
        } else {
            value += strlen(tok);
        }
        tok = strtok(NULL, " ");
    }
    return value;
}

// A function that reads log lines from a file and stores them in an array
void read_log_lines(char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        strcpy(lines[num_lines_read++], line);
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    read_log_lines(argv[1]);

    // Create an array to hold the parsed log messages
    LogMessage log_messages[MAX_NUM_LINES];
    int num_parsed_messages = 0;
    for (int i = 0; i < num_lines_read; i++) {
        LogMessage lm;
        lm.message = lines[i];
        lm.value = parse_log_message(lm);
        log_messages[num_parsed_messages++] = lm;
    }

    // Sort the messages by their numerical value
    for (int i = 0; i < num_parsed_messages - 1; i++) {
        for (int j = i + 1; j < num_parsed_messages; j++) {
            if (log_messages[i].value < log_messages[j].value) {
                LogMessage temp = log_messages[i];
                log_messages[i] = log_messages[j];
                log_messages[j] = temp;
            }
        }
    }

    // Print out the top 10 log messages
    for (int i = 0; i < 10 && i < num_parsed_messages; i++) {
        printf("%d: %s", log_messages[i].value, log_messages[i].message);
    }

    return 0;
}