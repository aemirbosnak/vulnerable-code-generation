//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_PATH 256
#define MAX_LINE_LENGTH 1024

int main(void)
{
    // Open a file in read-write mode
    FILE *file = fopen("example.txt", "r+");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Get the file's current position
    long int current_pos = ftell(file);

    // Jump to a specific position in the file
    fseek(file, 10, SEEK_SET);

    // Read a line from the file
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        perror("Error reading line");
        return 1;
    }

    // Replace a word in the line
    char *word = strstr(line, "old");
    if (word) {
        *word = 'n';
    }

    // Write the modified line back to the file
    if (fputs(line, file) == EOF) {
        perror("Error writing line");
        return 1;
    }

    // Jump back to the original position
    fseek(file, current_pos, SEEK_SET);

    // Close the file
    fclose(file);

    return 0;
}