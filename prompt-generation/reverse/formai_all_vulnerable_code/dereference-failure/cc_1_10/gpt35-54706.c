//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // 1MB file size limit

// Virus signature database
char *virusSignatures[] = {
    "Trojan.Win32.FakeAV.a",
    "Win32.Sality.NA",
    "Worm.VB-9000",
    "Trojan.Generic.12345",
    NULL // Sentinel value to mark end of list
};

// Function to check if a given file contains a virus
bool isInfected(char *filename) {
    FILE *fp = fopen(filename, "rb"); // Open file in binary mode
    if (!fp) {
        printf("Could not open file %s\n", filename);
        return false;
    }

    // Check file size
    fseek(fp, 0L, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);
    if (fileSize > MAX_FILE_SIZE) {
        printf("File %s is too large to scan!\n", filename);
        fclose(fp);
        return false;
    }

    // Allocate buffer to hold file contents
    char *buffer = (char *)malloc(fileSize);
    if (!buffer) {
        printf("Out of memory!\n");
        fclose(fp);
        return false;
    }

    // Read file contents into buffer
    size_t bytesRead = fread(buffer, 1, fileSize, fp);
    fclose(fp);
    if (bytesRead != fileSize) {
        printf("Error reading file %s\n", filename);
        free(buffer);
        return false;
    }

    // Check if buffer matches any virus signature
    int i = 0;
    while (virusSignatures[i]) {
        if (strstr(buffer, virusSignatures[i])) {
            printf("Virus found in file %s! Signature: %s\n", filename, virusSignatures[i]);
            free(buffer);
            return true;
        }
        i++;
    }

    free(buffer);
    return false;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [file1] [file2] ...\n", argv[0]);
        return 1;
    }

    // Scan each file in command-line arguments
    for (int i = 1; i < argc; i++) {
        if (isInfected(argv[i])) {
            printf("ERROR: File %s is infected\n", argv[i]);
        } else {
            printf("File %s is clean\n", argv[i]);
        }
    }

    return 0;
}