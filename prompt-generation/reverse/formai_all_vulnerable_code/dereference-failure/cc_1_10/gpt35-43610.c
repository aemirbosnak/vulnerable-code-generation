//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 1000
#define MAX_FILENAME_LENGTH 256

void scan_files(char **filenames, int num_files);
int is_infected(char *filename);

int main(int argc, char **argv) {
    // check if user provided file names
    if (argc < 2) {
        printf("Please provide file names to scan");
        exit(EXIT_FAILURE);
    }
    char **filenames = (char **) malloc(sizeof(char *) * MAX_FILES);
    int num_files = argc - 1;
    for (int i = 1; i <= num_files; i++) {
        filenames[i-1] = (char *) malloc(sizeof(char) * MAX_FILENAME_LENGTH);
        strcpy(filenames[i-1], argv[i]);
    }
    scan_files(filenames, num_files);
    return 0;
}

void scan_files(char **filenames, int num_files) {
    int infected_count = 0;
    printf("Scanning started...\n");
    for (int i = 0; i < num_files; i++) {
        if (is_infected(filenames[i])) {
            printf("%s is infected!\n", filenames[i]);
            infected_count++;
        }
    }
    printf("Scanning finished. %d infected files found.\n", infected_count);
}

int is_infected(char *filename) {
    // check if file contains the "virus" signature
    FILE *fptr;
    char ch;
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Unable to open file %s\n", filename);
        return 0;
    }
    int signature[] = {118, 105, 114, 117, 115}; // "virus" in unicode values
    int sig_len = 5;
    int sig_index = 0;
    while ((ch = fgetc(fptr)) != EOF && sig_index < sig_len) {
        if (ch == signature[sig_index]) {
            sig_index++;
        } else {
            sig_index = 0;
        }
    }
    fclose(fptr);
    return sig_index == sig_len;
}