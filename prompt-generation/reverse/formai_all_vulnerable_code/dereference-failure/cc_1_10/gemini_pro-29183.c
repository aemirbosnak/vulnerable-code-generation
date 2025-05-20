//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Signature database
char *signatures[] = {
    "EICAR_Test_File",
    "W32.Beagle.A",
    "W32.Sality.AE",
    "W32.Sircam.A",
    "W32.Netsky.A"
};

// Scan a file for known viruses
int scan_file(char *filename) {
    FILE *f;
    char buffer[512];
    int i;

    // Open the file
    f = fopen(filename, "rb");
    if (f == NULL) {
        return -1;
    }

    // Read the file into a buffer
    fread(buffer, 512, 1, f);

    // Compare the buffer to each signature in the database
    for (i = 0; i < sizeof(signatures) / sizeof(char *); i++) {
        if (strstr(buffer, signatures[i]) != NULL) {
            fclose(f);
            return 1;
        }
    }

    // No virus found
    fclose(f);
    return 0;
}

// Scan a directory for viruses
int scan_directory(char *dirname) {
    DIR *d;
    struct dirent *dir;
    char path[512];
    int i;

    // Open the directory
    d = opendir(dirname);
    if (d == NULL) {
        return -1;
    }

    // Iterate over the directory entries
    while ((dir = readdir(d)) != NULL) {
        // Skip hidden files and directories
        if (dir->d_name[0] == '.') {
            continue;
        }

        // Construct the full path to the file
        snprintf(path, sizeof(path), "%s/%s", dirname, dir->d_name);

        // Check if the file is a directory
        struct stat statbuf;
        if (stat(path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) {
            // Recursively scan the directory
            scan_directory(path);
        } else {
            // Scan the file for viruses
            i = scan_file(path);
            if (i == 1) {
                printf("Virus found in file %s\n", path);
            } else if (i == -1) {
                printf("Error scanning file %s\n", path);
            }
        }
    }

    // Close the directory
    closedir(d);

    // Return 0 if no viruses were found, or 1 if a virus was found
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Scan the specified directory for viruses
    int i = scan_directory(argv[1]);

    // Print the results
    if (i == 0) {
        printf("No viruses found\n");
    } else if (i == 1) {
        printf("Viruses found\n");
    } else {
        printf("Error scanning directory\n");
    }

    return 0;
}