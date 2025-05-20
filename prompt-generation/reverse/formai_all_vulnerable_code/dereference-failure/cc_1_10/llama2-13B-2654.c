//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 1000
#define MIN_LENGTH 50
#define THRESHOLD 0.5

// Function to calculate the similarity between two strings
int similarity(char *str1, char *str2) {
    int i, j, len1 = strlen(str1), len2 = strlen(str2);
    int diff = 0;

    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                diff++;
            }
        }
    }

    return (diff / (len1 + len2 - diff));
}

// Function to generate a new text based on the original input
char *generate_text(char *input) {
    int i, j, len = strlen(input);
    char *new_text = malloc(len * 2);
    char *words[5];

    // Tokenize the input text
    words[0] = strtok(input, " ");
    words[1] = strtok(NULL, " ");
    words[2] = strtok(NULL, " ");
    words[3] = strtok(NULL, " ");
    words[4] = strtok(NULL, " ");

    // Calculate the similarity between each pair of words
    int similarities[5][5];
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            similarities[i][j] = similarity(words[i], words[j]);
        }
    }

    // Generate a new text based on the similarities
    int k = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (similarities[i][j] > THRESHOLD) {
                new_text[k] = words[i][0];
                k++;
            }
        }
    }

    // Add a period at the end of the new text
    new_text[k] = '.';

    return new_text;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a text (max %d characters): ", MAX_LENGTH);
    fgets(input, MAX_LENGTH, stdin);

    // Trim the input text
    char *trimmed = malloc(strlen(input));
    for (int i = 0; i < strlen(input); i++) {
        if (isspace(input[i])) {
            trimmed[i] = '\0';
        } else {
            trimmed[i] = input[i];
        }
    }

    // Generate a new text based on the trimmed input
    char *new_text = generate_text(trimmed);

    // Print the new text
    printf("Generated text: %s\n", new_text);

    return 0;
}