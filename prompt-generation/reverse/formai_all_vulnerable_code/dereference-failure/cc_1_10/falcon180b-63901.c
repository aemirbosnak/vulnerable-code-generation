//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_SIZE 100000
#define MAX_WORD_SIZE 50
#define MAX_WORD_COUNT 10000

// Function to split a string into words
void split_string(char* str, char* words[], int max_words) {
    int count = 0;
    char* word = strtok(str, " ");
    while (word!= NULL && count < max_words) {
        strcpy(words[count], word);
        count++;
        word = strtok(NULL, " ");
    }
}

// Function to count words
void count_words(char* str) {
    char* words[MAX_WORD_COUNT];
    int count = 0;
    split_string(str, words, MAX_WORD_COUNT);
    for (int i = 0; i < count; i++) {
        if (isalpha(words[i][0])) {
            printf("%s\t%d\n", words[i], 1);
        }
        else {
            printf("%s\t%d\n", words[i], 0);
        }
    }
}

// Function to read log file and count words
void read_log_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    char line[MAX_LOG_SIZE];
    while (fgets(line, MAX_LOG_SIZE, file)!= NULL) {
        count_words(line);
    }
    fclose(file);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }
    char* filename = argv[1];
    read_log_file(filename);
    return 0;
}