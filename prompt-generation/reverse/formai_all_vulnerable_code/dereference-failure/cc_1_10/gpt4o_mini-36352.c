//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void splitString(const char* str, const char* delimiter);
char* concatenateStrings(const char* str1, const char* str2);
int findSubstring(const char* str, const char* substr);
void printUsage(const char* programName);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    // Example string manipulation based on command line arguments
    const char* action = argv[1];
    
    if (strcmp(action, "split") == 0 && argc == 4) {
        splitString(argv[2], argv[3]);
    } else if (strcmp(action, "concat") == 0 && argc == 4) {
        char* result = concatenateStrings(argv[2], argv[3]);
        printf("Concatenated Result: %s\n", result);
        free(result);
    } else if (strcmp(action, "find") == 0 && argc == 4) {
        int position = findSubstring(argv[2], argv[3]);
        if (position != -1) {
            printf("Substring found at position: %d\n", position);
        } else {
            printf("Substring not found!\n");
        }
    } else {
        printUsage(argv[0]);
    }

    return EXIT_SUCCESS;
}

void splitString(const char* str, const char* delimiter) {
    char* token;
    char* stringCopy = strdup(str); // Duplicate the string to avoid modifying the original
    printf("Splitting string: '%s' using delimiter '%s'\n", str, delimiter);
    
    token = strtok(stringCopy, delimiter);
    while (token != NULL) {
        printf("Token: '%s'\n", token);
        token = strtok(NULL, delimiter);
    }
    
    free(stringCopy);
}

char* concatenateStrings(const char* str1, const char* str2) {
    size_t length1 = strlen(str1);
    size_t length2 = strlen(str2);
    char* result = (char*)malloc(length1 + length2 + 1); // +1 for null-terminator
    
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strcpy(result, str1);
    strcat(result, str2);
    
    return result;
}

int findSubstring(const char* str, const char* substr) {
    char* position = strstr(str, substr);
    return (position != NULL) ? (position - str) : -1; // Return the position or -1 if not found
}

void printUsage(const char* programName) {
    printf("Usage: %s <action> <string1> [<string2>]\n", programName);
    printf("Actions:\n");
    printf("  split <string> <delimiter>     - Splits a string by a delimiter\n");
    printf("  concat <string1> <string2>     - Concatenates two strings\n");
    printf("  find <string> <substring>       - Finds a substring in a string\n");
}