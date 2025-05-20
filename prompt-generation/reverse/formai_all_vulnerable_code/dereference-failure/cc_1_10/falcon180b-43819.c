//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_NAME 1024
#define MAX_FILE_PATH 2048

typedef struct {
    char *name;
    int is_file;
} FileInfo;

void scan_directory(const char *path, int level) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Could not open directory %s\n", path);
        return;
    }

    char file_path[MAX_FILE_PATH];
    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            snprintf(file_path, MAX_FILE_PATH, "%s/%s", path, ent->d_name);
            scan_directory(file_path, level + 1);
        } else {
            FileInfo file_info;
            file_info.name = strdup(ent->d_name);
            file_info.is_file = 1;

            char file_name[MAX_FILE_NAME];
            strcpy(file_name, ent->d_name);
            for (int i = 0; i < strlen(file_name); i++) {
                if (isalpha(file_name[i])) {
                    file_name[i] = tolower(file_name[i]);
                }
            }

            if (strcmp(file_name, "virus.exe") == 0) {
                printf("Virus found: %s\n", file_info.name);
            }

            free(file_info.name);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    scan_directory(argv[1], 0);

    return 0;
}