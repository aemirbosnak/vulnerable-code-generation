//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_BUFSIZE 1024

int is_file(const char * path) {
    FILE * file;
    if (file = fopen(path, "r")) {
        fclose(file);
        return 1;
    }
    return 0;
}

void scan_dir(char * directory, char * virus) {
    DIR * dir;
    struct dirent * entry;

    if (!(dir = opendir(directory))) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[MAX_BUFSIZE];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);
            scan_dir(path, virus);
        } else {
            char path[MAX_BUFSIZE];
            snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);
            if (is_file(path) && strstr(entry->d_name, ".c") != NULL) {
                FILE * file = fopen(path, "r");
                char buffer[MAX_BUFSIZE];
                while (fgets(buffer, sizeof(buffer), file)) {
                    if (strstr(buffer, virus) != NULL) {
                        printf("Virus detected in file: %s\n", path);
                    }
                }
                fclose(file);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char * argv[]) {
    if (argc != 3) {
        printf("Usage: ./antivirus SCAN_DIRECTORY VIRUS_STRING\n");
        exit(1);
    }
    char * directory = argv[1];
    char * virus = argv[2];

    printf("Scanning directory %s for virus: %s\n", directory, virus);
    scan_dir(directory, virus);

    return 0;
}