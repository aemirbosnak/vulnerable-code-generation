//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size to scan

// Function to read a file into memory
char* read_file(FILE* fp, int* size) {
    char* buffer = malloc(MAX_FILE_SIZE);
    char ch;
    int count = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (count >= MAX_FILE_SIZE) {
            fprintf(stderr, "File is too large to scan.\n");
            exit(1);
        }
        buffer[count++] = ch;
    }

    if (count == 0) {
        fprintf(stderr, "File is empty.\n");
        exit(1);
    }

    *size = count;
    return buffer;
}

// Function to scan for viruses
int scan_for_viruses(char* buffer, int size) {
    char* virus_signature = "SherlockHolmesVirus";
    int signature_length = strlen(virus_signature);

    char* current_position = buffer;
    while ((current_position = strstr(current_position, virus_signature))) {
        printf("Virus detected at position %d.\n", current_position - buffer);
        return 1;
    }

    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE* fp = fopen(argv[1], "rb");
    if (!fp) {
        fprintf(stderr, "Could not open file.\n");
        exit(1);
    }

    char* buffer;
    int size;
    buffer = read_file(fp, &size);
    fclose(fp);

    int result = scan_for_viruses(buffer, size);
    free(buffer);

    if (result) {
        printf("File is infected with the SherlockHolmesVirus.\n");
    } else {
        printf("File is clean.\n");
    }

    return 0;
}