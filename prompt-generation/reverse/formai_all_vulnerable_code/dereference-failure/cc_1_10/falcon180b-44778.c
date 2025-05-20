//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define MAX_VIRUS_SIZE 1000
#define VIRUS_SIGNATURE "Virus123"

// Function to read file into memory
void read_file(char* filename, char** buffer) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    if (filesize > MAX_FILE_SIZE) {
        printf("File is too large.\n");
        fclose(fp);
        exit(1);
    }

    *buffer = malloc(filesize + 1);
    if (*buffer == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fp);
        exit(1);
    }

    fread(*buffer, filesize, 1, fp);
    fclose(fp);

    (*buffer)[filesize] = '\0';
}

// Function to scan for virus signature
int scan_for_virus(char* buffer, int buffersize) {
    int i;
    for (i = 0; i < buffersize - MAX_VIRUS_SIZE; i++) {
        if (strncmp(buffer + i, VIRUS_SIGNATURE, MAX_VIRUS_SIZE) == 0) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    char* buffer;
    read_file(filename, &buffer);

    if (scan_for_virus(buffer, strlen(buffer))) {
        printf("Virus detected!\n");
        free(buffer);
        exit(1);
    } else {
        printf("No virus detected.\n");
        free(buffer);
        exit(0);
    }
}