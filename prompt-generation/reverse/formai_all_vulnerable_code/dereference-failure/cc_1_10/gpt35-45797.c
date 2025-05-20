//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {

    // Initialize variables
    char *filename;
    char *author;
    char *description;
    struct tm *ctime;
    time_t curr_time;

    // Check for correct usage
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open file for reading
    filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        return 1;
    }

    // Read file line by line
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp)) != -1) {

        // Find author
        if (strstr(line, "// Author:") != NULL) {
            author = strtok(line, ":");
            author = strtok(NULL, "\n");
            printf("Author: %s\n", author);
        }

        // Find creation time
        if (strstr(line, "// Created on:") != NULL) {
            ctime = malloc(sizeof(struct tm));
            char *time_str = strtok(line, ":");
            time_str = strtok(NULL, "\n");
            strptime(time_str, "%Y-%m-%d %H:%M:%S", ctime);
            printf("Creation time: %s", asctime(ctime));
        }

        // Find file description
        if (strstr(line, "// Description:") != NULL) {
            description = strtok(line, ":");
            description = strtok(NULL, "\n");
            printf("File description: %s\n", description);
        }
    }

    // Cleanup
    if (line) {
        free(line);
    }
    fclose(fp);
    free(ctime);

    return 0;
}