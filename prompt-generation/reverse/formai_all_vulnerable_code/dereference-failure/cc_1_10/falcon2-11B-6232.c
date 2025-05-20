//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read text file and store its contents in an array
void readFile(const char* filename, char** contents) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* buffer = (char*)malloc(size + 1);
    fread(buffer, 1, size, file);
    buffer[size] = '\0';
    fclose(file);
    *contents = strdup(buffer);
}

// Function to count the occurrences of a word in a text file
int countWord(const char* word, char** contents) {
    int count = 0;
    char* current = *contents;
    while (*current!= '\0') {
        if (strcmp(word, current) == 0) {
            count++;
            current += strlen(word) + 1;
        } else {
            current += 1;
        }
    }
    return count;
}

// Function to search for a pattern in a text file
int searchPattern(const char* pattern, char** contents) {
    int count = 0;
    char* current = *contents;
    while (*current!= '\0') {
        if (strstr(current, pattern)!= NULL) {
            count++;
            current += strlen(pattern) + 1;
        } else {
            current += 1;
        }
    }
    return count;
}

int main() {
    char* filename = "textfile.txt";
    char** contents = (char**)malloc(1 * sizeof(char*));
    *contents = NULL;

    // Read the contents of the text file into an array
    readFile(filename, contents);

    // Count the occurrences of the word "cyberpunk"
    int wordCount = countWord("cyberpunk", contents);
    printf("Number of occurrences of 'cyberpunk': %d\n", wordCount);

    // Search for the pattern "AI" in the text file
    int patternCount = searchPattern("AI", contents);
    printf("Number of occurrences of 'AI': %d\n", patternCount);

    free(contents);
    return 0;
}