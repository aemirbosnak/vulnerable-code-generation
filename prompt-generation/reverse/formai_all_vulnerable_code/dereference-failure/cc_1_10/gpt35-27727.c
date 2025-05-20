//FormAI DATASET v1.0 Category: Text processing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct to hold information about text files */
typedef struct FileData {
    char filename[100];
    char *contents;
} FileData;

/* Define a function to read the contents of a file */
char *readFile(char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *contents = (char *)malloc(size + 1);
    fread(contents, 1, size, f);
    fclose(f);
    contents[size] = '\0';
    return contents;
}

/* Define a function to print the results of text processing */
void printResults(FileData *fileData, int numFiles, char *searchTerm) {
    printf("SEARCH TERMS:\n");
    printf("%s\n\n", searchTerm);
    for (int i = 0; i < numFiles; i++) {
        printf("FILE #%d: %s\n", i+1, fileData[i].filename);
        printf("RESULTS:\n");
        char *searchPtr;
        searchPtr = strstr(fileData[i].contents, searchTerm);
        int count = 0;
        while (searchPtr != NULL) {
            printf("%.*s\n", 50, searchPtr);
            count++;
            searchPtr = strstr(searchPtr + 1, searchTerm);
        }
        if (count == 0) {
            printf("None\n");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    /* Parse command line arguments */
    if (argc < 3) {
        printf("Usage: %s <search_term> <file1> [<file2> ...]\n", argv[0]);
        exit(1);
    }
    char *searchTerm = argv[1];
    int numFiles = argc - 2;
    FileData *fileData = (FileData *)malloc(numFiles * sizeof(FileData));
    for (int i = 0; i < numFiles; i++) {
        strcpy(fileData[i].filename, argv[i+2]);
        fileData[i].contents = readFile(argv[i+2]);
    }
    /* Print the results of text processing */
    printResults(fileData, numFiles, searchTerm);
    /* Free dynamically allocated memory */
    for (int i = 0; i < numFiles; i++) {
        free(fileData[i].contents);
    }
    free(fileData);
    return 0;
}