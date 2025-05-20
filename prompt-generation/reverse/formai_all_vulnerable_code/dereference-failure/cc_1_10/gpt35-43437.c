//FormAI DATASET v1.0 Category: Log analysis ; Style: interoperable
/* 
Interoperable C program for analyzing log files 
The program reads a log file line by line and returns the number
of occurrences of a specific keyword. 
The program can process both Linux and Windows style line endings.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024  // Maximum allowed length of each line in log file

// Helper function to remove the trailing '\n' character from a string
void chomp(char *str) {
    int len = strlen(str);
    if(str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Ensure there are enough input arguments
    if (argc < 3) {
        printf("Usage: %s <log_file_path> <keyword>", argv[0]);
        exit(1);
    }

    // Open the log file in read-only mode
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening log file: %s", argv[1]);
        exit(1);
    }

    // Read through the log file and count the number of times the keyword appears
    char buffer[MAX_LINE_SIZE];
    const char *keyword = argv[2];
    int keyword_len = strlen(keyword);
    int count = 0;
    while (fgets(buffer, MAX_LINE_SIZE, fp)) {
        chomp(buffer);  // Remove trailing '\n' if present

        // Check for keyword match (case-insensitive)
        if (strcasestr(buffer, keyword) != NULL) {
            count++;
        }
    }

    // Print the result
    printf("The keyword '%s' appeared %d times in log file: %s", keyword, count, argv[1]);

    // Close the file
    fclose(fp);

    return 0;
}