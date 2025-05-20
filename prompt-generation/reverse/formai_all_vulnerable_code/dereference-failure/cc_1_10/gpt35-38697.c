//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define VIRUS_SIGNATURE "virus"
#define MAX_PATH 1024

int scan_file(const char*);
int scan_dir(const char*);

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Please specify a file or directory to scan.\n");
        return 1;
    }

    char* target = argv[1];
    struct stat stat_buf;
    if (stat(target, &stat_buf) != 0) {
        printf("Could not access %s\n", target);
        return 1;
    }

    if (S_ISDIR(stat_buf.st_mode)) {
        printf("Scanning directory: %s\n", target);
        int virus_count = scan_dir(target);
        printf("Scan complete.\nFound %d viruses.\n", virus_count);
    } else {
        printf("Scanning file: %s\n", target);
        int virus_count = scan_file(target);
        printf("Scan complete.\nFound %d viruses.\n", virus_count);
    }

    return 0;
}

int scan_file(const char* path) {
    int virus_count = 0;

    FILE* file;
    file = fopen(path, "r");

    if (file == NULL) {
        printf("Could not open file: %s\n", path);
        return 0;
    }

    char buffer[MAX_PATH];
    while (fgets(buffer, MAX_PATH, file)) {
        if (strstr(buffer, VIRUS_SIGNATURE)) {
            printf("Found virus in file: %s\n", path);
            virus_count++;
            break;
        }
    }

    fclose(file);
    return virus_count;
}

int scan_dir(const char* path) {
    int virus_count = 0;

    DIR* dir;
    struct dirent *dir_entry;

    dir = opendir(path);

    if (dir == NULL) {
        printf("Could not open directory: %s\n", path);
        return 0;
    }

    char buffer[MAX_PATH];
    while ((dir_entry = readdir(dir)) != NULL) {
        if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(buffer, MAX_PATH, "%s/%s", path, dir_entry->d_name);

        struct stat stat_buf;
        if (stat(buffer, &stat_buf) != 0) {
            printf("Could not access file: %s\n", buffer);
            continue;
        }

        if (S_ISDIR(stat_buf.st_mode)) {
            virus_count += scan_dir(buffer);
        } else {
            virus_count += scan_file(buffer);
        }
    }

    closedir(dir);
    return virus_count;
}