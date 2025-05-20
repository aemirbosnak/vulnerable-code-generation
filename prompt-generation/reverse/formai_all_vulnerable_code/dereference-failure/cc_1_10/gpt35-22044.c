//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1000
#define VIRUS_SIGNATURE "virus"

int is_virus(char* filename) {
    FILE* fptr;
    char ch;
    int found = 0;

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fptr)) != EOF) {
        if (ch == VIRUS_SIGNATURE[found]) {
            found++;
        } else {
            found = 0;
        }
        if (found == strlen(VIRUS_SIGNATURE)) {
            fclose(fptr);
            return 1;
        }
    }

    fclose(fptr);
    return 0;
}

void scan_dir(char* path) {
    DIR* dir;
    struct dirent* entry;
    struct stat info;
    char full_path[MAX_PATH_LENGTH];

    dir = opendir(path);
    if (dir == NULL) {
        printf("Unable to open directory.\n");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);
        if (lstat(full_path, &info) == -1) {
            printf("Unable to get file information.\n");
            continue;
        }

        if (S_ISDIR(info.st_mode)) {
            scan_dir(full_path);
        } else {
            if (is_virus(full_path)) {
                printf("Virus detected in file: %s\n", full_path);
                // you can implement virus removal or quarantining here
            }
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    char* path;

    if (argc < 2) {
        printf("Usage: ./antivirus [directory]\n");
        exit(EXIT_FAILURE);
    }

    path = argv[1];
    scan_dir(path);

    printf("Scanning complete.\n");

    return 0;
}