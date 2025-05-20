//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
// Define the maximum file size that the program can handle

int scan_file(const char *filename);
// Function to scan the given file for virus signatures 

int main(int argc, char *argv[]) {
    printf("============================= C Antivirus Scanner =============================\n");
    if (argc < 2) {
        printf("[ERROR] Incorrect number of arguments.\n");
        printf("[HELP] Usage: %s <filename_to_scan>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    printf("[INFO] Scanning file: %s...\n", filename);
    int result = scan_file(filename);

    if(result == 0) {
        printf("[INFO] File is safe.\n");
    } else {
        printf("[WARNING] Virus detected! Please remove the file immediately.\n");
    }
    return 0;
}

int scan_file(const char *filename) {
    FILE *file = fopen(filename, "rb");

    if(!file) {
        printf("[ERROR] Failed to open file: %s\n", filename);
        return -1;
    }

    char *buffer = (char *)malloc(MAX_FILE_SIZE);
    size_t file_size = fread(buffer, 1, MAX_FILE_SIZE, file);
    fclose(file);

    if(file_size == 0) {
        printf("[ERROR] Empty file: %s\n", filename);
        free(buffer);
        return -1;
    }

    char *signatures[] = {"v1rus", "h4x0r", "evil", "malware", "trojan"};
    // List of virus signatures to detect in the file

    int num_signatures = sizeof(signatures)/sizeof(signatures[0]);
    for(int i=0; i<num_signatures; i++) {
        char *pos = strstr(buffer, signatures[i]);
        if(pos != NULL) {
            printf("[WARNING] Virus signature found: %s\n", signatures[i]);
            free(buffer);
            return -1;
        }
    }
    free(buffer);
    return 0;
}