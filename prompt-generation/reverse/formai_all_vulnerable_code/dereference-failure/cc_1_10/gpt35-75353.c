//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_METADATA_SIZE 500

// function to extract metadata from a string
char* extract_metadata(char* str) {
    char* metadata = (char*) malloc(MAX_METADATA_SIZE * sizeof(char));
    int i, j;

    // iterate through string until '@' is found
    for (i = 0; str[i] != '@'; i++) {
        if (str[i] == '\0') {
            fprintf(stderr, "Error: No metadata found in string.\n");
            return NULL;
        }
    }

    // iterate through string after '@' and copy metadata into new string
    for (j = 0; str[i] != '\0'; i++, j++) {
        if (str[i] == ';') {
            break;
        } else if (!isdigit(str[i]) && !isalpha(str[i]) && str[i] != '-') {
            fprintf(stderr, "Error: Invalid character found in metadata.\n");
            return NULL;
        }
        metadata[j] = str[i];
    }
    metadata[j] = '\0';

    // if no metadata was found, return error message
    if (metadata[0] == '\0') {
        fprintf(stderr, "Error: No metadata found in string.\n");
        return NULL;
    }

    return metadata;
}

int main(int argc, char** argv) {
    char* str1 = "This string has no metadata.";
    char* str2 = "This string contains metadata @name:John;age:25;gender:-;";
    char* str3 = "Invalid metadata characters @name:John Doe;age:45;gender:Male!";

    // test case 1: no metadata found
    char* metadata1 = extract_metadata(str1);
    if (metadata1 == NULL) {
        fprintf(stderr, "Failed test case 1: no metadata found.\n");
    } else {
        printf("Test case 1 passed: %s\n", metadata1);
        free(metadata1);
    }

    // test case 2: metadata found
    char* metadata2 = extract_metadata(str2);
    if (metadata2 == NULL) {
        fprintf(stderr, "Failed test case 2: metadata not found.\n");
    } else {
        printf("Test case 2 passed: %s\n", metadata2);
        free(metadata2);
    }

    // test case 3: invalid metadata characters found
    char* metadata3 = extract_metadata(str3);
    if (metadata3 == NULL) {
        fprintf(stderr, "Passed test case 3: invalid metadata characters.\n");
    } else {
        printf("Failed test case 3: should have thrown error\n");
        free(metadata3);
    }

    return 0;
}