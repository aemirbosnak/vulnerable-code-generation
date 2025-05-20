//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

// Function to remove leading and trailing spaces from a string
void trim(char *str) {
    int i = 0, j = strlen(str) - 1;
    while (isspace(str[i])) {
        i++;
    }
    while (isspace(str[j])) {
        str[j] = '\0';
        j--;
    }
}

// Function to split a string into words
void split(char *str, char *words[], int num_words) {
    char *token;
    int i = 0;
    token = strtok(str, " ");
    while (token!= NULL && i < num_words) {
        trim(token);
        strcpy(words[i], token);
        i++;
        token = strtok(NULL, " ");
    }
}

// Function to count the frequency of each word
void count_words(char *filename, char *words[], int num_words) {
    FILE *file;
    char line[MAX_LINE_SIZE];
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strstr(line, words[i])!= NULL) {
                words[i][0] = toupper(words[i][0]);
            }
        }
    }
    fclose(file);
}

// Function to print the word frequency table
void print_table(char *filename, char *words[], int num_words) {
    FILE *file;
    int i;
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not create file %s\n", filename);
        exit(1);
    }
    fprintf(file, "Word\tFrequency\n");
    for (i = 0; i < num_words; i++) {
        fprintf(file, "%s\t%d\n", words[i], words[i][0] == '\0'? 0 : 1);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <word1> <word2>...\n", argv[0]);
        exit(1);
    }
    int num_words = argc - 2;
    char *filename = argv[1];
    char *words[num_words];
    strcpy(words[0], argv[2]);
    strcpy(words[1], argv[3]);
    for (int i = 2; i < num_words; i++) {
        strcpy(words[i], argv[i + 2]);
    }
    count_words(filename, words, num_words);
    print_table("word_frequency.txt", words, num_words);
    return 0;
}