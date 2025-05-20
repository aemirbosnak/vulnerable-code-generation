//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

// Define the maximum file size to scan (in bytes)
#define MAX_FILE_SIZE (1024 * 1024)

// Define the list of known virus signatures
const char *virus_signatures[] = {
    "EICAR_TEST_FILE",
    "W32.MyDoom.A@mm",
    "W32.Sasser.E@mm",
    "W32.Blaster.A@mm",
    "W32.Sobig.F@mm"
};

// Define the number of known virus signatures
const int num_virus_signatures = sizeof(virus_signatures) / sizeof(char *);

// Function to scan a file for virus signatures
int scan_file(const char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Get the file size
    struct stat st;
    if (fstat(fileno(fp), &st) != 0) {
        perror("fstat");
        fclose(fp);
        return -1;
    }
    if (st.st_size > MAX_FILE_SIZE) {
        fprintf(stderr, "File too large to scan: %s\n", filename);
        fclose(fp);
        return -1;
    }

    // Read the file into a buffer
    char *buffer = malloc(st.st_size);
    if (buffer == NULL) {
        perror("malloc");
        fclose(fp);
        return -1;
    }
    if (fread(buffer, 1, st.st_size, fp) != st.st_size) {
        perror("fread");
        fclose(fp);
        free(buffer);
        return -1;
    }
    fclose(fp);

    // Scan the buffer for virus signatures
    for (int i = 0; i < num_virus_signatures; i++) {
        if (strstr(buffer, virus_signatures[i]) != NULL) {
            free(buffer);
            return 1;
        }
    }

    free(buffer);
    return 0;
}

// Function to scan a directory for virus-infected files
int scan_directory(const char *dirname) {
    // Open the directory
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    // Iterate over the files in the directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Skip directories
        if (entry->d_type == DT_DIR) {
            continue;
        }

        // Scan the file
        char filename[PATH_MAX];
        snprintf(filename, sizeof(filename), "%s/%s", dirname, entry->d_name);
        if (scan_file(filename) == 1) {
            printf("Virus found in file: %s\n", filename);
        }
    }

    closedir(dir);
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user provided a directory to scan
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return -1;
    }

    // Scan the directory
    if (scan_directory(argv[1]) != 0) {
        return -1;
    }

    return 0;
}