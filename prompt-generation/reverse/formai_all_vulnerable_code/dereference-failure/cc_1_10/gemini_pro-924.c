//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our two star-crossed lovers
struct {
    char *name;
    char *log;
} romeo, juliet;

// A function to read a log file into a string
char *read_log(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char *log = malloc(size + 1);
    if (log == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    fread(log, 1, size, file);
    log[size] = '\0';

    fclose(file);

    return log;
}

// A function to parse a log string and count the number of times a certain string appears
int count_occurrences(char *log, char *string) {
    int count = 0;
    char *ptr = log;
    while ((ptr = strstr(ptr, string)) != NULL) {
        count++;
        ptr++;
    }
    return count;
}

// A function to print a report on the log analysis
void print_report(char *romeo_log, char *juliet_log) {
    int romeo_errors = count_occurrences(romeo_log, "ERROR");
    int juliet_errors = count_occurrences(juliet_log, "ERROR");

    printf("Romeo and Juliet Log Analysis\n");
    printf("=============================\n");
    printf("Romeo's Log:\n");
    printf("-------------\n");
    printf("Number of errors: %d\n", romeo_errors);
    printf("Romeo's Log:\n");
    printf("-------------\n");
    printf("Number of errors: %d\n", juliet_errors);
}

int main() {
    // Read the log files into strings
    romeo.name = "Romeo";
    romeo.log = read_log("romeo.log");
    juliet.name = "Juliet";
    juliet.log = read_log("juliet.log");

    // Parse the log strings and count the number of errors
    int romeo_errors = count_occurrences(romeo.log, "ERROR");
    int juliet_errors = count_occurrences(juliet.log, "ERROR");

    // Print a report on the log analysis
    print_report(romeo.log, juliet.log);

    // Free the memory allocated for the log strings
    free(romeo.log);
    free(juliet.log);

    return 0;
}