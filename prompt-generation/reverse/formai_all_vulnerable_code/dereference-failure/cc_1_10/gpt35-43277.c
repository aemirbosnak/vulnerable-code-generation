//FormAI DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

#define MAX_ENTRIES 1000
#define MAX_FILENAME 256

char entries[MAX_ENTRIES][MAX_FILENAME];

int main(int argc, char* argv[]) {
    int i = 0, j = 0;
    DIR* dir;
    struct dirent* entry;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char backup_dir[MAX_FILENAME];
    sprintf(backup_dir, "%d-%02d-%02d_backup", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    // Create backup directory if it doesn't exist
    if(mkdir(backup_dir, 0777) == -1) {
        printf("Error: Failed to create backup directory!\n");
        return 1;
    }

    // Open directory and read entries
    dir = opendir(".");
    while((entry = readdir(dir)) != NULL) {
        if(entry->d_type == DT_REG) { // Only consider regular files
            strncpy(entries[i], entry->d_name, MAX_FILENAME);
            i++;
        }
    }
    closedir(dir);

    // Copy files to backup directory
    for(j = 0; j < i; j++) {
        char source[MAX_FILENAME], dest[MAX_FILENAME];
        sprintf(source, "%s", entries[j]);
        sprintf(dest, "%s/%s", backup_dir, source);
        printf("Copying %s to %s...\n", source, dest);
        if(system(NULL) == 0) {
            printf("Error: Command processor not available!\n");
            return 1;
        }
        char command[MAX_FILENAME + 20];
        sprintf(command, "cp %s %s", source, dest);
        int result = system(command);
        if(result != 0) {
            printf("Error: Failed to copy %s to %s! Error code: %d\n", source, dest, result);
        }
    }

    printf("Backup complete!\n");
    return 0;
}