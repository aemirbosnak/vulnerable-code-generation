//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define VIRUS_SIGNATURE "cuddlebug"

void scan_directory(char *path);
void scan_file(char *filename);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ./c_antivirus <directory or file to scan>\n");
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        char *path = argv[i];
        DIR *dir = opendir(path);

        if (dir == NULL) {
            scan_file(path);
        } else {
            scan_directory(path);
            closedir(dir);
        }
    }

    printf("Scan complete!\n");

    return 0;
}

void scan_directory(char *path) {
    DIR *dir = opendir(path);
    struct dirent *dir_entry;

    if (dir) {
        while ((dir_entry = readdir(dir)) != NULL) {
            if (strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0) {
                char filepath[512];

                sprintf(filepath, "%s/%s", path, dir_entry->d_name);

                if (dir_entry->d_type == DT_DIR) {
                    scan_directory(filepath);
                } else {
                    scan_file(filepath);
                }
            }
        }
    }
}

void scan_file(char *filename) {
    FILE *fp;
    char buffer[512];

    fp = fopen(filename, "r");

    if (fp != NULL) {
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            if (strstr(buffer, VIRUS_SIGNATURE) != NULL) {
                printf("Found virus signature in %s\n", filename);
                break;
            }
        }

        fclose(fp);
    }
}