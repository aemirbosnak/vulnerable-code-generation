//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

/* Function to scan a file and check if it contains the virus signature */
int scan_file(char *filename, char *virus_signature) {
    /* Open the file */
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    /* Read the file into a buffer */
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buffer = (char *)malloc(length);
    fread(buffer, 1, length, f);

    /* Check if the buffer contains the virus signature */
    int result = 0;
    if(strstr(buffer, virus_signature)) {
        printf("File %s contains the virus signature: %s\n", filename, virus_signature);
        result = 1;
    }

    /* Clean up */
    free(buffer);
    fclose(f);

    return result;
}

/* Function to scan a directory and check all files for the virus signature */
int scan_directory(char *dir_name, char *virus_signature) {
    struct dirent *entry;
    DIR *dir = opendir(dir_name);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", dir_name);
        return -1;
    }

    int result = 0;

    while ((entry = readdir(dir)) != NULL) {
        /* Ignore hidden files */
        if (entry->d_name[0] == '.') {
            continue;
        }

        /* Construct the full path of the file */
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);

        /* Check if this is a file or a directory */
        if (entry->d_type == DT_DIR) {
            /* Recursively scan the subdirectory */
            result += scan_directory(path, virus_signature);
        } else if (entry->d_type == DT_REG) {
            /* Scan the file */
            result += scan_file(path, virus_signature);
        }
    }

    /* Clean up */
    closedir(dir);

    return result;
}

/* Main function */
int main(int argc, char *argv[]) {
    /* Check the command line arguments */
    if (argc != 3) {
        printf("Usage: %s <directory> <virus_signature>\n", argv[0]);
        return -1;
    }

    /* Scan the directory for the virus signature */
    int result = scan_directory(argv[1], argv[2]);
    if (result == 0) {
        printf("No files containing the virus signature were found.\n");
    }

    return 0;
}