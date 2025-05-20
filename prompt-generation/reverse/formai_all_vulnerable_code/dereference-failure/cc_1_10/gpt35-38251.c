//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

// Function to read the contents of a file into a buffer
char *read_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    // Determine size of the file
    fseek(fp, 0L, SEEK_END);
    long int file_size = ftell(fp);
    rewind(fp);

    // Allocate buffer for file contents
    char *buffer = (char *) malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Error allocating buffer for file: %s\n", filename);
        exit(1);
    }

    // Read file contents into buffer
    fread(buffer, file_size, 1, fp);
    buffer[file_size] = '\0';

    fclose(fp);
    return buffer;
}

int main() {
    char *filename = "input.txt";

    // Read file contents into buffer
    char *file_contents = read_file(filename);

    // Convert all characters to lowercase
    char *p = file_contents;
    while (*p) {
        *p = tolower(*p);
        p++;
    }

    int n = strlen(file_contents);
    int i, j, count;

    // Initialize array to store frequency of each word
    int freq_table[n][2];
    for (i = 0; i < n; i++)
        freq_table[i][1] = 0;

    // Parse file contents and count frequency of each word
    i = 0;
    while (i < n) {
        // Skip non-alphanumeric characters
        while (i < n && !isalnum(file_contents[i]))
            i++;

        // Check if current word starts at current position
        if (isalnum(file_contents[i])) {
            char word[MAX_WORD_LEN] = {'\0'};
            j = 0;

            // Copy word into buffer
            while (i < n && isalnum(file_contents[i])) {
                word[j++] = file_contents[i++];
            }

            // Check if word already exists in freq_table
            count = 0;
            for (j = 0; j < i; j++) {
                if (strcmp(word, &(file_contents[freq_table[j][0]])) == 0) {
                    freq_table[j][1]++;
                    count++;
                    break;
                }
            }

            // If word does not exist, add it to freq_table
            if (count == 0) {
                freq_table[i][0] = (int) (word - file_contents);
                freq_table[i][1]++;
            }
        }
    }

    // Print frequency of each word
    printf("Word\t\tFrequency\n");
    printf("========================\n");
    for (i = 0; i < n; i++) {
        if (freq_table[i][0] != 0)
            printf("%s\t\t%d\n", &(file_contents[freq_table[i][0]]), freq_table[i][1]);
    }

    free(file_contents);
    return 0;
}