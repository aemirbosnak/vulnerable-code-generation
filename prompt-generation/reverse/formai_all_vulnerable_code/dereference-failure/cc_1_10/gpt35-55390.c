//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void scan_directory(char*);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./antivirus <directory>");
        return 1;
    } else {
        scan_directory(argv[1]);
        return 0;
    }
}

void scan_directory(char *path) {
    struct dirent *entry;
    DIR *directory = opendir(path);
    char filepath[1024];

    if (directory == NULL) {
        printf("Error: Could not open directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        sprintf(filepath, "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            scan_directory(filepath);
        } else {
            FILE *file = fopen(filepath, "r");

            if (file == NULL) {
                printf("Unable to open file: %s", filepath);
                continue;
            }
            char c;

            while ((c = fgetc(file)) != EOF) {
                if (c == 'v' && fgetc(file) == 'i' && fgetc(file) == 'r' && fgetc(file) == 'u' && fgetc(file) == 's') {
                    printf("%s is infected with a virus!\n", filepath);
                    break;
                }
            }

            fclose(file);
        }
    }

    closedir(directory);
    return;
}