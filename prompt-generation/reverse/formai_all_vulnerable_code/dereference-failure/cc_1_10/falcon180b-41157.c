//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: satisfied
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Function to remove leading and trailing spaces from a string
void trim(char *str) {
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        if (!isspace(str[i])) {
            strcpy(str, &str[i]);
            break;
        }
    }
    for (i = strlen(str) - 1; i >= 0; i--) {
        if (!isspace(str[i])) {
            str[i + 1] = '\0';
            break;
        }
    }
}

// Function to count words in a string
int countWords(char *str) {
    int count = 0;
    char *word;
    word = strtok(str, " \t\n\r\f\v");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " \t\n\r\f\v");
    }
    return count;
}

int main() {
    FILE *fp;
    char ch;
    char *str = (char *) malloc(10000 * sizeof(char));
    int count = 0;
    int wordCount = 0;
    int charCount = 0;

    // Open file for reading
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read file character by character
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            str[charCount] = '\0';
            count += countWords(str);
            wordCount += countWords(str);
            charCount = 0;
            memset(str, 0, strlen(str));
        } else {
            str[charCount++] = ch;
        }
    }

    // Add last line to count
    str[charCount] = '\0';
    count += countWords(str);
    wordCount += countWords(str);

    // Close file
    fclose(fp);

    // Display results
    printf("Total characters: %d\n", count);
    printf("Total words: %d\n", wordCount);

    return 0;
}