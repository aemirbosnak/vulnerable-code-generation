//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILE_LENGTH 512

void scan_file(const char *filename);
void scan_directory(const char *dirname);

void scan_file(const char *filename) {
    FILE *fp;
    char buffer[MAX_FILE_LENGTH];
    int len;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("%s is not accessible\n", filename);
        return;
    }

    while ((len = fread(buffer, 1, MAX_FILE_LENGTH, fp)) > 0) {
        if (memcmp(buffer, "virus", 5) == 0) {
            printf("%s contains a virus!\n", filename);
            fclose(fp);
            return;
        }
    }

    fclose(fp);
}

void scan_directory(const char *dirname) {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_PATH_LENGTH];

    dir = opendir(dirname);
    if (dir == NULL) {
        printf("%s is not accessible\n", dirname);
        return;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_name[0] == '.') {
            continue;
        }

        snprintf(path, MAX_PATH_LENGTH, "%s/%s", dirname, ent->d_name);
        if (ent->d_type == DT_DIR) {
            scan_directory(path);
        } else if (ent->d_type == DT_REG) {
            scan_file(path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    scan_directory(argv[1]);

    printf("Scan complete\n");

    return 0;
}