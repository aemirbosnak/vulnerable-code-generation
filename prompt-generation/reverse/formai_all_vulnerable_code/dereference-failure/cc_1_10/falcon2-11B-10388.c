//Falcon2-11B DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

// Function to count the occurrences of each word in a file
int countWords(const char* filename, char* words[], int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("File not found");
        exit(EXIT_FAILURE);
    }

    int i, count_per_word = 0;
    for (i = 0; i < 10; i++) {
        words[i] = '\0';
    }
    while (fscanf(file, "%s", words[count_per_word])!= EOF) {
        count_per_word++;
    }
    fclose(file);

    for (i = 0; i < count_per_word; i++) {
        count[i] = 0;
    }

    file = fopen(filename, "r");
    if (!file) {
        perror("File not found");
        exit(EXIT_FAILURE);
    }

    int j = 0;
    while (fscanf(file, "%s", words[j])!= EOF) {
        for (i = 0; i < count_per_word; i++) {
            if (strcmp(words[i], words[j]) == 0) {
                count[i]++;
                break;
            }
        }
        j++;
    }
    fclose(file);

    return count_per_word;
}

// Function to write the result to a file
void writeResults(const char* filename, char* words[], int count[], int count_per_word) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("File not found");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count_per_word; i++) {
        fprintf(file, "%s %d\n", words[i], count[i]);
    }
    fclose(file);
}

int main() {
    char* words[10];
    int count[10];
    int count_per_word = countWords("input.txt", words, count);
    if (count_per_word == 0) {
        printf("No words found in the file\n");
        return 0;
    }

    writeResults("output.txt", words, count, count_per_word);
    printf("Number of words: %d\n", count_per_word);
    return 0;
}