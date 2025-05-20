//FormAI DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

// function to remove non-alphabetic characters
void removeNonAlpha(char* str) {
    char* src = str;
    char* dst = str;
    while (*src != '\0') {
        if (isalpha((unsigned char)*src)) {
            *dst++ = tolower((unsigned char)*src);
        }
        src++;
    }
    *dst = '\0';
}

// function to check if a given word is present in the dictionary
int checkSpelling(char* word, char** dictionary, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        // check for exact match
        if (strcmp(word, dictionary[i]) == 0) {
            printf("%s is spelled correctly.\n", word);
            return 1;
        }
    }
    printf("%s is spelled incorrectly. Suggestions:\n", word);
    // check for suggestions
    for (i = 0; i < numWords; i++) {
        if (strlen(dictionary[i]) - strlen(word) == 1 || strlen(dictionary[i]) - strlen(word) == -1) {
            char temp[MAX_WORD_LENGTH];
            strcpy(temp, word);
            int j, k;
            for (j = 0, k = 0; j < strlen(dictionary[i]) && k < strlen(word);) {
                if (dictionary[i][j] == word[k]) {
                    j++;
                    k++;
                }
                else if (dictionary[i][j+1] == word[k]) {
                    strcpy(temp+j+1, word+k);
                    if (strcmp(temp, dictionary[i]) == 0) {
                        printf("%s\n", dictionary[i]);
                        break;
                    }
                    else {
                        j = strlen(dictionary[i]);
                    }
                }
                else if (dictionary[i][j] == word[k+1]) {
                    strcpy(temp+k+1, word+j);
                    if (strcmp(temp, dictionary[i]) == 0) {
                        printf("%s\n", dictionary[i]);
                        break;
                    }
                    else {
                        j = strlen(dictionary[i]);
                    }
                }
                else {
                    j = strlen(dictionary[i]);
                }
            }
        }
        else if (strlen(dictionary[i]) == strlen(word)) {
            int diff = 0;
            int j;
            for (j = 0; j < strlen(word); j++) {
                if (word[j] != dictionary[i][j]) {
                    diff++;
                }
            }
            if (diff == 1) {
                printf("%s\n", dictionary[i]);
            }
        }
    }
    return 0;
}

int main() {
    char** dictionary = NULL;
    int numWords = 0;
    char word[MAX_WORD_LENGTH];

    // open dictionary file
    FILE* dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    // read dictionary file into memory
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, dictFile)) != -1) {
        line[strcspn(line, "\r\n")] = 0; // remove newline characters
        dictionary = realloc(dictionary, (numWords+1) * sizeof(char*));
        dictionary[numWords] = malloc((strlen(line)+1) * sizeof(char));
        strcpy(dictionary[numWords], line);
        removeNonAlpha(dictionary[numWords]);
        numWords++;
    }
    free(line);
    fclose(dictFile);

    // main loop for input and spell checking
    printf("Type 'exit' to quit.\n");
    while (1) {
        printf("Enter a word to check: ");
        scanf("%s", word);
        if (strcmp(word, "exit") == 0) {
            break;
        }
        removeNonAlpha(word);
        if (strlen(word) == 0) {
            printf("Please enter a valid word.\n");
            continue;
        }
        checkSpelling(word, dictionary, numWords);
    }

    // free allocated memory
    int i;
    for (i = 0; i < numWords; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}