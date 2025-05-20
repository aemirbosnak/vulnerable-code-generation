//FormAI DATASET v1.0 Category: Word Count Tool ; Style: ultraprecise
// A simple program to count the occurrence of a given word in a text file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 // Maximum word length

// Function to check if two strings are equal
int strcmpi(char* s1, char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (tolower(s1[i]) != tolower(s2[i])) {
            return -1;
        }
        i++;
    }
    if (s1[i] != '\0' || s2[i] != '\0') {
        return -1;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    FILE* fp;
    char* word;
    char buffer[MAX_WORD_LENGTH];
    int count = 0;

    if (argc != 3) {
        printf("Usage: %s <filename> <word>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    word = argv[2];

    while (fscanf(fp, "%s", buffer) != EOF) {
        if (strcmpi(buffer, word) == 0) {
            count++;
        }
    }

    printf("The word '%s' occurs %d times in the file '%s'.\n", word, count, argv[1]);

    fclose(fp);

    return 0;
}