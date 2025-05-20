//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_VIRUS_LENGTH 512

int scan_file(char *filename, char *virus_signature);

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s [filename] [virus_signature]\n", argv[0]);
        return -1;
    }

    char *filename = argv[1]; 
    char *virus_signature = argv[2];

    if (sizeof(filename) > MAX_FILENAME_LENGTH) {
        printf("Error: Filename length exceeds maximum length.\n");
        return -1;
    }

    char *filename_lowercase = calloc(MAX_FILENAME_LENGTH, sizeof(char));
    for (int i = 0; i < strlen(filename); i++) {
        filename_lowercase[i] = tolower(filename[i]);
    }

    int infected = scan_file(filename_lowercase, virus_signature);

    if (infected) {
        printf("Warning: Virus detected in file %s.\n", filename);
    } else {
        printf("File %s is clean.\n", filename);
    }

    free(filename_lowercase);

    return 0;
}

int scan_file(char *filename, char *virus_signature) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return 0;
    }
    char buffer[MAX_VIRUS_LENGTH];
    while (fread(buffer, MAX_VIRUS_LENGTH, 1, file)) {
        if (strstr(buffer, virus_signature) != NULL) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}