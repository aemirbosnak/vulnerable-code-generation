//FormAI DATASET v1.0 Category: Log analysis ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read a line from the log file
int read_line(FILE *file, char *line_buffer) {
    char ch;
    int char_count = 0;

    while ((ch = getc(file)) != EOF && ch != '\n' && char_count < MAX_LINE_LENGTH) {
        line_buffer[char_count++] = ch;
    }
    line_buffer[char_count] = '\0';

    return char_count;
}

// Function to parse the line and retrieve the relevant information
void parse_line(char *line, char *date_time, char *log_level, char *message) {
    char *temp;

    // Date time information is at the beginning of the line
    temp = strtok(line, " ");
    strcpy(date_time, temp);

    // Log level information is enclosed in square brackets
    temp = strtok(NULL, "[");
    temp = strtok(NULL, "]");
    strcpy(log_level, temp);

    // The message comes after the log level in the line
    temp = strtok(NULL, "");
    strcpy(message, temp);
}

int main() {
    char *log_file_path = "example.log";
    FILE *file;
    char line_buffer[MAX_LINE_LENGTH];
    char date_time[MAX_LINE_LENGTH], log_level[MAX_LINE_LENGTH], message[MAX_LINE_LENGTH];

    file = fopen(log_file_path, "r");

    if (file == NULL) {
        printf("Error opening log file");
        exit(1);
    }

    printf("Date Time\t\tLog Level\t\tMessage\n");

    // Read each line of the log file and parse it
    while (read_line(file, line_buffer) != 0) {
        parse_line(line_buffer, date_time, log_level, message);
        printf("%s\t%s\t\t%s\n", date_time, log_level, message);
    }

    fclose(file);

    return 0;
}