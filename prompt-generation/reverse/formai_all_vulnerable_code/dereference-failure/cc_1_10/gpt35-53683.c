//FormAI DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char* argv[]) {
    char* log_file_path;
    int num_lines_to_process;

    // check that the correct number of command-line arguments were passed in
    if (argc != 3) {
        printf("Usage: %s [log_file_path] [num_lines_to_process]\n", argv[0]);
        return 1;
    }

    // set the log file path and number of lines to process from the command-line arguments
    log_file_path = argv[1];
    num_lines_to_process = atoi(argv[2]);

    // open the log file for reading
    FILE* log_file = fopen(log_file_path, "r");

    // check that the file was opened successfully
    if (log_file == NULL) {
        printf("Error: Unable to open log file at %s\n", log_file_path);
        return 1;
    }

    int line_count = 0;

    // loop through the file, reading and analyzing lines until we reach the end of the file or the desired number of lines
    while (line_count < num_lines_to_process || num_lines_to_process == -1) {
        // read in a line from the file
        char line[MAX_LINE_LENGTH];
        if (fgets(line, MAX_LINE_LENGTH, log_file) == NULL) {
            // if we've reached the end of the file, break out of the loop
            break;
        }

        // check if the line contains a message with level "ERROR"
        if (strstr(line, "ERROR") != NULL) {
            printf("Line %d: %s", line_count+1, line);
        }

        line_count++;
    }

    // close the log file
    fclose(log_file);

    return 0;
}