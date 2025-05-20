//FormAI DATASET v1.0 Category: File Synchronizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_LINE_LENGTH 1024

struct file {
    char filename[MAX_FILENAME_LENGTH];
    char checksum[33];
};

// Function to calculate the checksum of a file
char *calculate_checksum(char *filename) {
    char *checksum = malloc(sizeof(char) * 33);
    char buffer[MAX_LINE_LENGTH];
    unsigned char hash[20];
    int i;
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Initialize hash to zeros
    memset(hash, 0x00, 20);

    // Read file content and update hash
    while (fgets(buffer, MAX_LINE_LENGTH, fp)) {
        for (i = 0; i < strlen(buffer); i++) {
            hash[((i+1) % 20)] ^= buffer[i];
        }
    }

    // Convert hash to hexadecimal string
    for (i = 0; i < 20; i++) {
        sprintf(checksum + i*2, "%02x", hash[i]);
    }

    fclose(fp);
    return checksum;
}

// Function to synchronize two files
int synchronize_files(char *filename1, char *filename2) {
    char *checksum1 = calculate_checksum(filename1);
    char *checksum2 = calculate_checksum(filename2);
    struct file file1, file2;

    if (checksum1 == NULL || checksum2 == NULL) {
        printf("Unable to calculate checksum of one or more files\n");
        return -1;
    }

    // Fill in information about files
    strcpy(file1.filename, filename1);
    strcpy(file1.checksum, checksum1);
    strcpy(file2.filename, filename2);
    strcpy(file2.checksum, checksum2);

    // Compare checksums to determine if files are the same
    if (strcmp(checksum1, checksum2) == 0) {
        printf("Files %s and %s are already in sync\n", filename1, filename2);
        free(checksum1);
        free(checksum2);
        return 0;
    }

    // Copy file1 to file2 if it's newer
    if (file1.checksum > file2.checksum) {
        FILE *fp1 = fopen(file1.filename, "r");
        FILE *fp2 = fopen(file2.filename, "w");
        char buffer[MAX_LINE_LENGTH];

        if (fp1 == NULL || fp2 == NULL) {
            printf("Unable to open files %s and %s for synchronization\n", filename1, filename2);
            free(checksum1);
            free(checksum2);
            return -1;
        }

        printf("Copying file %s to %s...\n", file1.filename, file2.filename);

        // Copy contents from fp1 to fp2
        while (fgets(buffer, MAX_LINE_LENGTH, fp1)) {
            fputs(buffer, fp2);
        }

        fclose(fp1);
        fclose(fp2);
    } else { // Copy file2 to file1 if it's newer
        FILE *fp1 = fopen(file1.filename, "w");
        FILE *fp2 = fopen(file2.filename, "r");
        char buffer[MAX_LINE_LENGTH];

        if (fp1 == NULL || fp2 == NULL) {
            printf("Unable to open files %s and %s for synchronization\n", filename1, filename2);
            free(checksum1);
            free(checksum2);
            return -1;
        }

        printf("Copying file %s to %s...\n", file2.filename, file1.filename);

        // Copy contents from fp2 to fp1
        while (fgets(buffer, MAX_LINE_LENGTH, fp2)) {
            fputs(buffer, fp1);
        }

        fclose(fp1);
        fclose(fp2);
    }

    free(checksum1);
    free(checksum2);
    printf("Successfully synchronized files %s and %s\n", filename1, filename2);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename1> <filename2>\n", argv[0]);
        return -1;
    }

    if (synchronize_files(argv[1], argv[2]) < 0) {
        printf("Error synchronizing files %s and %s\n", argv[1], argv[2]);
        return -1;
    }

    return 0;
}