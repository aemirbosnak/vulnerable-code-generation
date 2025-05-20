//Falcon-180B DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to read a line from a file and store it in a buffer
char* read_line(FILE* file) {
    char* buffer = malloc(MAX_LINE_LENGTH);
    char* result = fgets(buffer, MAX_LINE_LENGTH, file);

    if (result == NULL) {
        fprintf(stderr, "Error reading line from file: %s\n", strerror(errno));
        exit(1);
    }

    return buffer;
}

// Function to split a line into words and store them in an array
int split_line(char* line, char** words) {
    int count = 0;
    char* token = strtok(line, " ");

    while (token!= NULL) {
        words[count] = token;
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

// Function to reverse the order of words in an array
void reverse_words(char** words, int count) {
    for (int i = 0; i < count / 2; i++) {
        char* temp = words[i];
        words[i] = words[count - i - 1];
        words[count - i - 1] = temp;
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    char* line = read_line(file);
    char* words[MAX_LINE_LENGTH / 4];
    int count = split_line(line, words);

    reverse_words(words, count);

    for (int i = 0; i < count; i++) {
        printf("%s ", words[i]);
    }

    fclose(file);
    free(line);
    return 0;
}