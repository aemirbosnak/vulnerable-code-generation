//FormAI DATASET v1.0 Category: Log analysis ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *log_file; // pointer to the log file
    int log_length; // length of the log file
    char *log_buffer; // buffer to hold the log contents

    // open the log file for reading
    log_file = fopen("example.log", "r");

    // check if the file was successfully opened
    if (log_file == NULL) {
        printf("Error: could not open log file");
        return 1;
    }

    // get the length of the log file
    fseek(log_file, 0, SEEK_END);
    log_length = ftell(log_file);
    fseek(log_file, 0, SEEK_SET);

    // allocate memory for the log buffer
    log_buffer = (char*) malloc(log_length);

    // read the log file into the buffer
    fread(log_buffer, log_length, 1, log_file);

    // close the log file
    fclose(log_file);

    // find the number of occurrences of each log level
    int num_debug = 0, num_info = 0, num_warn = 0, num_error = 0;
    char *log_line = strtok(log_buffer, "\n");
    while (log_line != NULL) {
        if (strstr(log_line, "DEBUG") != NULL) {
            num_debug++;
        } else if (strstr(log_line, "INFO") != NULL) {
            num_info++;
        } else if (strstr(log_line, "WARN") != NULL) {
            num_warn++;
        } else if (strstr(log_line, "ERROR") != NULL) {
            num_error++;
        }
        log_line = strtok(NULL, "\n");
    }

    // print the results
    printf("Log analysis:\n");
    printf("DEBUG messages: %d\n", num_debug);
    printf("INFO messages: %d\n", num_info);
    printf("WARN messages: %d\n", num_warn);
    printf("ERROR messages: %d\n", num_error);

    // free the log buffer
    free(log_buffer);

    return 0;
}