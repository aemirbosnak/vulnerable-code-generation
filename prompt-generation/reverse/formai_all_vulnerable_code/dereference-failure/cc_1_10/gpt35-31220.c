//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void scan_file(const char *filename);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [file or directory]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct dirent *dir_entry;
    DIR *dir;
    
    // check if user provided a directory or file
    if ((dir = opendir(argv[1]))) {
        // scan all files in directory
        while ((dir_entry = readdir(dir))) {
            // skip hidden files 
            if (dir_entry->d_name[0] == '.') continue;
            // pass file name to scanner
            scan_file(dir_entry->d_name);
        }
    } else if (strstr(argv[1], ".exe")) {
        // user provided a file
        scan_file(argv[1]);
    } else {
        printf("File type not supported: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    printf("Scan complete.\n");
    return EXIT_SUCCESS;
}

void scan_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    unsigned char buffer[4096];
    size_t bytes_read = 0;
    
    // read 4096 bytes at a time and scan for virus signature
    while ((bytes_read = fread(buffer, sizeof(unsigned char), sizeof(buffer), file))) {
        if (bytes_read == -1) {
            printf("Error: could not read from file %s\n", filename);
            fclose(file);
            return;
        }
        
        // compare buffer to virus signature
        if (strstr(buffer, "VIRUS_SIGNATURE")) {
            printf("Virus found in %s\n", filename);
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("No viruses found in %s\n", filename);
}