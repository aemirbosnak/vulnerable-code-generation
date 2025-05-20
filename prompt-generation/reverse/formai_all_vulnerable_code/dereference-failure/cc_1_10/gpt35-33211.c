//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// function to extract metadata
void extract_metadata(char* filepath) {

    // open the file
    FILE* file;
    file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        return;
    }

    // create variables to hold metadata values
    char* title = (char*) malloc(sizeof(char)*256);
    char* author = (char*) malloc(sizeof(char)*256);
    char* date = (char*) malloc(sizeof(char)*256);
    char* source = (char*) malloc(sizeof(char)*256);

    // read through each line of the file
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {

        // check for the metadata tags
        if (strncmp(line, "Title:", 6) == 0) {
            strcpy(title, line+7);
            title[strlen(title)-1] = '\0';
        }

        if (strncmp(line, "Author:", 7) == 0) {
            strcpy(author, line+8);
            author[strlen(author)-1] = '\0';
        }

        if (strncmp(line, "Date:", 5) == 0) {
            strcpy(date, line+6);
            date[strlen(date)-1] = '\0';
        }

        if (strncmp(line, "Source:", 7) == 0) {
            strcpy(source, line+8);
            source[strlen(source)-1] = '\0';
        }
    }

    // close the file
    fclose(file);

    // print out the metadata values
    printf("Title: %s\n", title);
    printf("Author: %s\n", author);
    printf("Date: %s\n", date);
    printf("Source: %s\n", source);

    // free memory
    free(title);
    free(author);
    free(date);
    free(source);
}

// function to search directory for files
void search_dir(char* path) {

    // open the directory
    DIR* dir;
    struct dirent* entry;
    dir = opendir(path);

    // loop through each file in directory
    while ((entry = readdir(dir)) != NULL) {

        // ignore hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        // create filepath for file
        char filepath[256];
        sprintf(filepath, "%s/%s", path, entry->d_name);

        // check if file is a text file
        if (strstr(entry->d_name, ".txt") != NULL) {
            // extract metadata from file
            printf("Found text file: %s\n", filepath);
            extract_metadata(filepath);
        }

        // check if file is a directory
        if (entry->d_type == DT_DIR) {
            // search the directory recursively
            printf("Found directory: %s\n", filepath);
            search_dir(filepath);
        }
    }

    // close the directory
    closedir(dir);
}

int main(int argc, char* argv[]) {

    // check for command line argument
    if (argc < 2) {
        printf("Usage: ./metadata_extractor [path]\n");
        exit(1);
    }

    // get path from command line argument
    char* path = argv[1];

    // search directory for files
    search_dir(path);

    return 0;
}