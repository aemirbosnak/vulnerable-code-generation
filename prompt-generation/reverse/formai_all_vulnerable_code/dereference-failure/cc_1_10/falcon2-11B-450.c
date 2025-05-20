//Falcon2-11B DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to read a file into a string
char* readFile(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char* data = malloc(sizeof(char) * (strlen(filename) + 1));
    fread(data, 1, strlen(filename) + 1, fp);
    fclose(fp);
    return data;
}

// Function to write a string to a file
void writeFile(const char* filename, const char* data) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fwrite(data, 1, strlen(data), fp);
    fclose(fp);
}

int main() {
    const char* filename = "example.txt";
    const char* contents = readFile(filename);

    if (strlen(contents) == 0) {
        printf("File is empty\n");
        return 0;
    }

    printf("Original contents:\n%s\n", contents);

    char* newContents = "This is the new content.";
    writeFile(filename, newContents);

    printf("New contents:\n%s\n", readFile(filename));

    return 0;
}