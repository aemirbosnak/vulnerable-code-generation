//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOVE_LEVEL 5

// Structure to store log messages and their love levels
typedef struct {
    char *message;
    int love_level;
} log_message_t;

// Function to parse log messages and calculate their love levels
void analyze_log(char *log_file) {
    int i = 0;
    log_message_t messages[MAX_LOVE_LEVEL];

    // Open the log file and read its contents
    FILE *log_fp = fopen(log_file, "r");
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, log_fp) != NULL) {
        // Check if the line is a log message
        if (strlen(line) > 0 && line[0] != '#') {
            // Tokenize the line into words
            char *words[5];
            int j = 0;

            // Split the line into words using whitespace as the delimiter
            char *token = strtok(line, " ");

            while (token != NULL && j < 5) {
                words[j++] = token;
                token = strtok(NULL, " ");
            }

            // Check if the line is a love message
            if (words[0][0] == 'L' && words[1][0] == 'O' && words[2][0] == 'V' && words[3][0] == 'E') {
                // Calculate the love level based on the number of "Love" words
                int love_level = 1;

                for (int k = 2; k < 4; k++) {
                    if (words[k][0] == 'L' && words[k][1] == 'O' && words[k][2] == 'V' && words[k][3] == 'E') {
                        love_level++;
                    }
                }

                // Store the log message and its love level in the array
                messages[i].message = line;
                messages[i].love_level = love_level;
                i++;
            }
        }
    }

    // Print the analyzed log messages and their love levels
    for (int j = 0; j < i; j++) {
        printf("Log message %d: %s (%d love levels)\n", j, messages[j].message, messages[j].love_level);
    }

    // Close the log file
    fclose(log_fp);
}

int main() {
    char log_file[] = "romantic_log.txt";

    // Analyze the log file
    analyze_log(log_file);

    return 0;
}