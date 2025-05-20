//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count words in a string
int countWords(char* str) {
    int count = 0;
    char* token;
    token = strtok(str, " ");
    while(token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to count characters in a string
int countChars(char* str) {
    int count = 0;
    while(*str!= '\0') {
        count++;
        str++;
    }
    return count;
}

// Function to count lines in a string
int countLines(char* str) {
    int count = 0;
    char* token;
    token = strtok(str, "\n");
    while(token!= NULL) {
        count++;
        token = strtok(NULL, "\n");
    }
    return count;
}

int main(int argc, char* argv[]) {
    if(argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file;
    file = fopen(argv[1], "r");
    if(file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char* buffer = NULL;
    size_t len = 0;
    ssize_t read;
    while((read = getline(&buffer, &len, file))!= -1) {
        printf("Total words: %d\n", countWords(buffer));
        printf("Total characters: %d\n", countChars(buffer));
        printf("Total lines: %d\n", countLines(buffer));
        printf("\n");
    }

    free(buffer);
    fclose(file);

    return 0;
}