//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// function to extract metadata from a file
void extractMetadata(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return;
    }

    char line[256];
    char author[256], title[256], date[256];
    int count = 0;

    // read each line of the file
    while (fgets(line, sizeof(line), file)) {
        // extract author if it exists
        if (strstr(line, "AUTHOR:") != NULL) {
            strcpy(author, strchr(line, ':') + 1);
            count++;
        }
        // extract title if it exists
        if (strstr(line, "TITLE:") != NULL) {
            strcpy(title, strchr(line, ':') + 1);
            count++;
        }
        // extract date if it exists
        if (strstr(line, "DATE:") != NULL) {
            strcpy(date, strchr(line, ':') + 1);
            count++;
        }

        // exit the loop if all three metadata have been found
        if (count == 3) {
            break;
        }
    }

    // print the metadata
    printf("\nMetadata for file %s:\n", filename);
    printf("Author: %s", author);
    printf("Title: %s", title);
    printf("Date: %s", date);

    // close the file
    fclose(file);
}

// function to recursively search for files with a given extension in a directory
void searchDir(char *dirPath, char *extension) {
    DIR *dir = opendir(dirPath);
    if (dir == NULL) {
        printf("Error: Could not open directory %s.\n", dirPath);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // ignore the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // check if the entry is a directory
        if (entry->d_type == DT_DIR) {
            // recursively search the directory
            char path[256];
            sprintf(path, "%s/%s", dirPath, entry->d_name);
            searchDir(path, extension);
        }
        else {
            // check if the entry has the desired extension
            char *ext = strrchr(entry->d_name, '.');
            if (ext != NULL && strcmp(ext, extension) == 0) {
                // extract metadata from the file
                char path[256];
                sprintf(path, "%s/%s", dirPath, entry->d_name);
                extractMetadata(path);
            }
        }
    }

    // close the directory
    closedir(dir);
}

// main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s directory extension\n", argv[0]);
        return 0;
    }

    char *dirPath = argv[1];
    char *extension = argv[2];

    printf("Searching for files with extension %s in directory %s...\n", extension, dirPath);

    searchDir(dirPath, extension);

    return 0;
}