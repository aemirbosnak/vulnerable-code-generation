//Falcon-180B DATASET v1.0 Category: File handling ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *filename;
    FILE *file;
    char line[MAX_LINE_SIZE];
} FileHandle;

int main() {
    FileHandle file1, file2;
    char *filename1 = "file1.txt";
    char *filename2 = "file2.txt";
    char *line;
    char *token;
    int count = 0;

    // Open the files
    file1.filename = filename1;
    file1.file = fopen(filename1, "r");
    if (file1.file == NULL) {
        printf("Error opening file %s\n", filename1);
        exit(1);
    }

    file2.filename = filename2;
    file2.file = fopen(filename2, "w");
    if (file2.file == NULL) {
        printf("Error opening file %s\n", filename2);
        exit(1);
    }

    // Read file1 and write to file2
    while ((line = fgets(file1.line, MAX_LINE_SIZE, file1.file))!= NULL) {
        // Reverse the line
        for (int i = strlen(line) - 1; i >= 0; i--) {
            line[i] = tolower(line[i]);
        }
        // Count the number of words
        int num_words = 0;
        token = strtok(line, " ");
        while (token!= NULL) {
            num_words++;
            token = strtok(NULL, " ");
        }
        // Write the line to file2
        fprintf(file2.file, "%s (%d words)\n", line, num_words);
        count++;
        if (count == 10) {
            break;
        }
    }

    // Close the files
    fclose(file1.file);
    fclose(file2.file);

    printf("Finished processing %d lines\n", count);
    return 0;
}