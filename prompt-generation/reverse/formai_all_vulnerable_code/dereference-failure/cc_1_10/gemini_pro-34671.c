//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

// Signature database
static char *signatures[] = {
    "EICAR-STANDARD-ANTIVIRUS-TEST-FILE",
    "W32.Stuxnet",
    "W32.Conficker",
    "W32.Sality",
    "W32.Zeus"
};

// Scan a single file
int scan_file(const char *filename) {
    FILE *fp;
    char *buffer;
    struct stat st;
    size_t i, len;

    // Open the file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Get the file size
    if (fstat(fileno(fp), &st) != 0) {
        perror("fstat");
        fclose(fp);
        return -1;
    }

    // Allocate a buffer to hold the file contents
    buffer = malloc(st.st_size);
    if (buffer == NULL) {
        perror("malloc");
        fclose(fp);
        return -1;
    }

    // Read the file contents into the buffer
    len = fread(buffer, 1, st.st_size, fp);
    if (len != st.st_size) {
        perror("fread");
        free(buffer);
        fclose(fp);
        return -1;
    }

    // Close the file
    fclose(fp);

    // Scan the file for signatures
    for (i = 0; i < sizeof(signatures) / sizeof(char *); i++) {
        if (strstr(buffer, signatures[i]) != NULL) {
            free(buffer);
            return 1;
        }
    }

    // No signatures found
    free(buffer);
    return 0;
}

// Scan a directory
int scan_directory(const char *dirname) {
    DIR *dir;
    struct dirent *entry;
    char *path;
    int status;

    // Open the directory
    dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    // Read the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip . and ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Allocate a buffer to hold the path
        path = malloc(strlen(dirname) + strlen(entry->d_name) + 2);
        if (path == NULL) {
            perror("malloc");
            closedir(dir);
            return -1;
        }

        // Construct the path
        sprintf(path, "%s/%s", dirname, entry->d_name);

        // Scan the file
        status = scan_file(path);
        if (status != 0) {
            printf("Virus found in file: %s\n", path);
            free(path);
            closedir(dir);
            return status;
        }

        // Free the path
        free(path);
    }

    // Close the directory
    closedir(dir);

    // No viruses found
    return 0;
}

// Main function
int main(int argc, char **argv) {
    int status;

    // Check the command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return -1;
    }

    // Scan the directory
    status = scan_directory(argv[1]);
    if (status != 0) {
        return status;
    }

    // No viruses found
    printf("No viruses found.\n");
    return 0;
}