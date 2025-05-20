//FormAI DATASET v1.0 Category: System process viewer ; Style: Claude Shannon
/* 
* System Process Viewer Program
* By: Claude Shannon
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define PATH "/proc/"

int main() {
    DIR* dir;
    struct dirent* entry;
    char buf[256], path[256], line[256];
    FILE* fp;

    // open directory /proc
    dir = opendir(PATH);
    if (!dir) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    // iterate through directory
    while ((entry = readdir(dir)) != NULL) {
        // check if current entry is a directory and contains only numeric values
        if (entry->d_type == DT_DIR && atoi(entry->d_name) != 0) {
            strcpy(path, PATH);
            strcat(path, entry->d_name);

            // open status file
            strcat(path, "/status");
            fp = fopen(path, "r");
            if (fp == NULL) {
                perror("Error opening file");
                exit(EXIT_FAILURE);
            }
            
            // read the first line of status file (name of process)
            fgets(line, sizeof(line), fp);

            // print process information
            printf("Process: %s\n", line + 6);

            // close status file
            fclose(fp);

            // open cmdline file
            strcpy(path, PATH);
            strcat(path, entry->d_name);
            strcat(path, "/cmdline");
            fp = fopen(path, "r");
            if (fp == NULL) {
                perror("Error opening file");
                exit(EXIT_FAILURE);
            }

            // read command line of process
            fgets(line, sizeof(line), fp);
            
            // print command line
            printf("Command line: %s\n", line);

            // close cmdline file
            fclose(fp);

            // print separator
            printf("----------------------------------\n");
        }
    }

    // close directory
    closedir(dir);

    return 0;
}