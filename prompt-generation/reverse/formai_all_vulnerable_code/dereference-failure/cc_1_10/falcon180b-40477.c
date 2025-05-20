//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define MAX_WORD_LEN 50

// Function to read a line from the file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LEN * sizeof(char));
    fgets(line, MAX_LINE_LEN, file);
    return line;
}

// Function to split a line into words
char** split_line(char* line) {
    int num_words = 0;
    char* word = strtok(line, " ");
    while (word!= NULL) {
        num_words++;
        word = strtok(NULL, " ");
    }
    char** words = malloc(num_words * sizeof(char*));
    num_words = 0;
    word = strtok(line, " ");
    while (word!= NULL) {
        words[num_words++] = strdup(word);
        word = strtok(NULL, " ");
    }
    return words;
}

// Function to print the words in a line
void print_words(char** words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// Function to count the frequency of a word
int count_frequency(char** words, int num_words, char* word) {
    int frequency = 0;
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i], word) == 0) {
            frequency++;
        }
    }
    return frequency;
}

int main() {
    FILE* file = fopen("medieval_ebook.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char* line;
    while ((line = read_line(file))!= NULL) {
        char** words = split_line(line);
        int num_words = 0;
        while (words[num_words]!= NULL) {
            num_words++;
        }

        // Count the frequency of the word "knight"
        int frequency = count_frequency(words, num_words, "knight");
        printf("Frequency of 'knight': %d\n", frequency);

        // Print the words in the line
        printf("Words in line:\n");
        print_words(words, num_words);

        free(line);
        for (int i = 0; i < num_words; i++) {
            free(words[i]);
        }
        free(words);
    }

    fclose(file);
    return 0;
}