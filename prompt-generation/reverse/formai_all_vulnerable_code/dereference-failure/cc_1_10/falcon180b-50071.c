//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Function to count words in a string
int countWords(char* str) {
    int count = 0;
    char* word = strtok(str, ",.?!:;");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, ",.?!:;");
    }
    return count;
}

int main() {
    FILE* file;
    char ch;
    char word[100];
    int count = 0;
    int charCount = 0;
    int wordCount = 0;

    // Open file for reading
    file = fopen("example.txt", "r");

    // Check if file was successfully opened
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read file character by character and count words
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            strcpy(word, "");
            strcat(word, &ch);
            while ((ch = fgetc(file))!= EOF && isalnum(ch)) {
                strcat(word, &ch);
            }
            if (strlen(word) > 0) {
                countWords(word);
                wordCount++;
            }
        } else if (isspace(ch)) {
            charCount++;
        }
    }

    // Close file
    fclose(file);

    // Print results
    printf("Total number of characters: %d\n", charCount);
    printf("Total number of words: %d\n", wordCount);

    return 0;
}