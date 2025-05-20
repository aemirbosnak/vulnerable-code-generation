//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the frequency of each word in the text
void countWords(char* text) {
    int words[1000]; // Array to store the frequency of each word
    int i, j, k;
    char* token;
    char* delimiters = ",.?!;:\"'()[]{}<>"; // Delimiters used to separate words
    int numDelimiters = strlen(delimiters);

    // Initialize all words to 0
    for (i = 0; i < 1000; i++) {
        words[i] = 0;
    }

    // Tokenize the text
    token = strtok(text, delimiters);
    while (token!= NULL) {
        // Convert the token to lowercase
        for (i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        // Increment the frequency of the word
        for (j = 0; j < 1000; j++) {
            if (strcmp(token, words[j]) == 0) {
                words[j]++;
                break;
            }
        }
        if (j == 1000) { // Word not found, add it to the array
            strcpy(words[k], token);
            words[k] = 1;
            k++;
        }
        token = strtok(NULL, delimiters);
    }

    // Print the frequency of each word
    for (i = 0; i < 1000; i++) {
        if (words[i] > 0) {
            printf("%s: %d\n", words[i], words[i]);
        }
    }
}

int main() {
    char* text;
    FILE* file;
    int i;

    // Open the text file
    file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Read the text from the file
    text = malloc(10000 * sizeof(char));
    if (text == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }
    fread(text, 10000, 1, file);
    fclose(file);

    // Count the frequency of each word
    countWords(text);

    // Free memory
    free(text);

    return 0;
}