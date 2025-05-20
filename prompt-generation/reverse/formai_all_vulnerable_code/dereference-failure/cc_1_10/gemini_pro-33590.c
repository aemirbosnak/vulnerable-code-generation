//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Define the maximum size of a file to be scanned
#define MAX_FILE_SIZE 1024 * 1024

// Define the list of known virus signatures
static const char *virus_signatures[] = {
    "EICAR_TEST_FILE",
    "W32.Sobig.F@mm",
    "W32.Mydoom.A@mm",
    "W32.Sasser.E@mm",
    "W32.Blaster.B@mm",
    "W32.Nachi.A@mm",
    "W32.Sircam.A@mm",
    "W32.CodeRed.II@mm",
    "W32.Nimda.A@mm",
};

// Function to scan a file for viruses
int scan_file(const char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Check if the file is too large to scan
    if (file_size > MAX_FILE_SIZE) {
        fprintf(stderr, "File %s is too large to scan\n", filename);
        fclose(fp);
        return -1;
    }

    // Read the file into a buffer
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        perror("malloc");
        fclose(fp);
        return -1;
    }
    fread(buffer, 1, file_size, fp);
    fclose(fp);

    // Scan the buffer for virus signatures
    int i;
    for (i = 0; i < sizeof(virus_signatures) / sizeof(char *); i++) {
        if (strstr(buffer, virus_signatures[i]) != NULL) {
            free(buffer);
            return 1;
        }
    }

    // No virus signatures found
    free(buffer);
    return 0;
}

// Function to scan a directory for viruses
int scan_directory(const char *dirname) {
    // Open the directory
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    // Scan each file in the directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Get the full path to the file
        char filename[PATH_MAX];
        snprintf(filename, sizeof(filename), "%s/%s", dirname, entry->d_name);

        // Scan the file
        int result = scan_file(filename);
        if (result == 1) {
            printf("Virus found in file %s\n", filename);
        } else if (result == -1) {
            perror("scan_file");
            closedir(dir);
            return -1;
        }
    }

    // Close the directory
    closedir(dir);

    // No viruses found
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if a directory was specified
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Scan the directory for viruses
    int result = scan_directory(argv[1]);
    if (result == 1) {
        printf("Viruses found in directory %s\n", argv[1]);
    } else if (result == -1) {
        perror("scan_directory");
        return 1;
    } else {
        printf("No viruses found in directory %s\n", argv[1]);
    }

    return 0;
}