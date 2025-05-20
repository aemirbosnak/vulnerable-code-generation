//Falcon2-11B DATASET v1.0 Category: Text processing ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* This function replaces all occurrences of a specific substring in a string with a new string. */
void replaceSubstring(char* str, const char* substring, const char* replacement) {
    int len = strlen(substring);
    int start = 0;
    while ((start = strstr(str, substring))!= NULL) {
        str[start] = replacement[0];
        str[start + len] = replacement[1];
        str[start + len + 1] = '\0';
        start += 2;
    }
}

/* This function takes a file name as input, opens the file, and reads its contents into a character array. */
char* readFileContents(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    char* buffer = malloc(1024 * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    fread(buffer, 1024, 1, file);
    fclose(file);
    return buffer;
}

/* This function writes a modified version of the source code to a new file. */
void writeModifiedFile(const char* filename, const char* newFilename, char* sourceCode) {
    FILE* file = fopen(newFilename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error creating file: %s\n", newFilename);
        exit(1);
    }

    fwrite(sourceCode, strlen(sourceCode), 1, file);
    fclose(file);
}

/* The main function. */
int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <filename> <newFilename>\n", argv[0]);
        exit(1);
    }

    char* sourceCode = readFileContents(argv[1]);
    if (sourceCode == NULL) {
        return 1;
    }

    replaceSubstring(sourceCode, "Hello World!", "Introspection");

    writeModifiedFile(argv[1], argv[2], sourceCode);
    free(sourceCode);

    return 0;
}