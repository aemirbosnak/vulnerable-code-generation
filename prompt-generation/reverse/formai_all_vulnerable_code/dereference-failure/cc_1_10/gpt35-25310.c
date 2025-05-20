//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 50
#define MAX_VIRUS_SIZE 1024

int scan_file(char* filename, char* virus);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: ./c_antivirus <filename> <virus>\n");
        return 1;
    }
    char* filename = argv[1];
    char* virus = argv[2];
    int result = scan_file(filename, virus);
    if (result == 1) {
        printf("Virus Detected in File: %s\n", filename);
    } else {
        printf("No Virus Detected in File: %s\n", filename);
    }
    return 0;
}

int scan_file(char* filename, char* virus) {
    // open file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to Open File %s\n", filename);
        return -1;
    }

    // calculate file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // allocate memory for file buffer
    char* file_buffer = malloc(file_size);
    if (file_buffer == NULL) {
        printf("Error: Unable to Allocate Memory for File %s\n", filename);
        fclose(fp);
        return -1;
    }

    // read file into buffer
    fread(file_buffer, 1, file_size, fp);

    // close file
    fclose(fp);

    // search buffer for virus
    if (strstr(file_buffer, virus) != NULL) {
        return 1; // virus detected
    }

    // free memory and return success
    free(file_buffer);
    return 0; // no virus detected
}