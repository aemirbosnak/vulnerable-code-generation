//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *filename;
    FILE *fp;
    long size;
    char *buffer;
    int i, virus_count=0;

    // Check if filename argument is provided
    if (argc < 2) {
        printf("Please provide filename to scan.\n");
        return -1;
    }

    // Open file and get its size
    filename = argv[1];
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Unable to open file %s.\n", filename);
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    // Allocate buffer to hold file contents
    buffer = (char*) malloc(size);
    if (buffer == NULL) {
        printf("Unable to allocate memory for file.\n");
        fclose(fp);
        return -1;
    }

    // Read file contents to buffer
    fread(buffer, 1, size, fp);
    fclose(fp);

    // Define virus signatures
    char *virus1 = "wrm41*";
    char *virus2 = "nikusha.pm";

    // Check for virus signatures
    if (strstr(buffer, virus1) || strstr(buffer, virus2)) {
        printf("%s is infected with virus.\n", filename);
        virus_count++;
    } else {
        printf("%s is clean.\n", filename);
    }

    // Free memory allocated for buffer
    free(buffer);

    // Output virus count
    if (virus_count > 0) {
        printf("Total viruses found: %d\n", virus_count);
    } else {
        printf("No viruses found.\n");
    }

    return 0;
}