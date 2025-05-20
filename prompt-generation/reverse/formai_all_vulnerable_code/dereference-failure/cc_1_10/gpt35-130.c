//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Claude Shannon
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 256
#define MAX_KEYWORD_LEN 20

// Define your antivirus keywords here
char keywords[][MAX_KEYWORD_LEN] = {"virus", "malware", "trojan", "worm"};

bool is_file_infected(const char *filename) {
    FILE *fp;
    char c;

    fp = fopen(filename, "r");

    // Read through file character by character 
    while ((c = getc(fp)) != EOF) {
        for(int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
            // If keyword found in file, return true
            if(strstr(&c, keywords[i]) != NULL) {
                fclose(fp);
                return true;
            }
        }
    }

    fclose(fp);
    return false;
}

void scan_directory(const char *dir) {
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;

    // Open directory stream
    if((dp = opendir(dir)) == NULL) {
        fprintf(stderr, "Cannot open directory: %s\n", dir);
        return;
    }

    chdir(dir);
    // Traverse all files in directory
    while((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name, &statbuf);

        // If directory, skip recursion on '.' and '..'
        if(S_ISDIR(statbuf.st_mode)) {
            if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0 ) {
                continue;
            } else {
                scan_directory(entry->d_name);
            }
        } else {
            // If file, check if infected
            if(is_file_infected(entry->d_name)) {
                printf("File infected: %s/%s\n", dir, entry->d_name);
            }
        }
    }
    chdir("..");
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s DIRECTORY", argv[0]);
        exit(1);
    }

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);

    return 0;
}