//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void scan_directory(char *directory);

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    scan_directory(argv[1]);

    printf("Scan complete!\n");

    return 0;
}

void scan_directory(char *directory) {
    DIR *dp;
    struct dirent *entry;
    char path[1024];

    dp = opendir(directory);
    if (dp == NULL) {
        fprintf(stderr, "Cannot open directory: %s\n", directory);
        return;
    }

    while((entry = readdir(dp))) {
        if(entry->d_type & DT_DIR) {
            // Directory detected, recursively scan
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            sprintf(path, "%s/%s", directory, entry->d_name);
            scan_directory(path);
        } else {
            // File detected, perform virus check
            FILE *f = fopen(entry->d_name, "r");
            if(f == NULL) {
                fprintf(stderr, "Cannot open file: %s\n", entry->d_name);
                continue;
            }

            // Iterate through file and perform virus check
            char buffer[1024];
            while(fgets(buffer, sizeof(buffer), f) != NULL) {
                if(strstr(buffer, "virus") != NULL) {
                    printf("Virus detected in %s\n", entry->d_name);
                    break;
                }
            }

            fclose(f);
        }
    }

    closedir(dp);
}