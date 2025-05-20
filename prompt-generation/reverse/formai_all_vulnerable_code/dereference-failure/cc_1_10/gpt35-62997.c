//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 1000
#define MAX_FILENAME_LENGTH 100

char* scan_file(char* filename);

int main(int argc, char** argv) {

    // Check if a filename was provided
    if (argc < 2) {
        printf("Please provide a list of filenames to scan.\n");
        return 1;
    }

    // Initialize filenames array
    char** filenames = malloc(sizeof(char*) * MAX_FILES);
    int num_files = 0;

    // Add filenames to array
    for (int i = 1; i < argc; i++) {
        if (num_files == MAX_FILES) {
            printf("Maximum number of files exceeded.\n");
            break;
        }
        filenames[num_files] = argv[i];
        num_files++;
    }

    // Scan each file and print result
    for (int i = 0; i < num_files; i++) {
        char* result = scan_file(filenames[i]);
        printf("%s: %s\n", filenames[i], result);
        free(result);
    }

    // Free memory
    for (int i = 0; i < num_files; i++) {
        free(filenames[i]);
    }
    free(filenames);

    return 0;
}

char* scan_file(char* filename) {
    // Open file for reading
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return "File not found";
    }

    // Scan file for virus signature
    char buffer[MAX_FILENAME_LENGTH];
    while (fgets(buffer, MAX_FILENAME_LENGTH, fp) != NULL) {
        if (strstr(buffer, "virus_signature") != NULL) {
            fclose(fp);
            return "Virus detected!";
        }
    }

    // Close file and return result
    fclose(fp);
    return "File is clean";
}