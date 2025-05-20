//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

// Function to remove the leading and trailing white spaces from a string
void trim(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;

    while (isspace(*start))
        start++;

    while (isspace(*end))
        end--;

    if (start < end) {
        strncpy(str, start, end - start + 1);
        str[end - start + 1] = '\0';
    } else {
        str[0] = '\0';
    }
}

// Function to split a string into words
int split(char* line, char** words) {
    char* token = strtok(line, " \t\r\n\f\v");
    int count = 0;

    while (token!= NULL) {
        words[count] = malloc(MAX_WORD_SIZE * sizeof(char));
        strncpy(words[count], token, MAX_WORD_SIZE - 1);
        words[count][MAX_WORD_SIZE - 1] = '\0';
        count++;

        token = strtok(NULL, " \t\r\n\f\v");
    }

    return count;
}

// Function to count the frequency of each word in the log file
void count_words(char** words, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                break;
            }
        }

        if (j == i) {
            printf("%s: 1\n", words[i]);
        }
    }
}

int main() {
    FILE* file;
    char line[MAX_LINE_SIZE];
    char** words;
    int num_words;

    // Open the log file for reading
    file = fopen("logfile.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    // Allocate memory for the words array
    words = malloc(MAX_LINE_SIZE * sizeof(char*));

    // Read the log file line by line
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        // Remove the leading and trailing white spaces from the line
        trim(line);

        // Split the line into words
        num_words = split(line, words);

        // Count the frequency of each word
        count_words(words, num_words);

        // Free the memory allocated for the words array
        for (int i = 0; i < num_words; i++) {
            free(words[i]);
        }
    }

    // Close the log file
    fclose(file);

    return 0;
}