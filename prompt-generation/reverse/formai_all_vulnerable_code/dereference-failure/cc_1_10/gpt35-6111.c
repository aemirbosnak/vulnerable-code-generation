//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int is_virus(char* file_name) {
    FILE *fptr;
    char ch;
    int virus = 0;
    fptr = fopen(file_name, "rb");
    if (fptr == NULL) {
        return virus;
    }
    while ((ch = fgetc(fptr)) != EOF) {
        if (ch == 'v' || ch == 'i' || ch == 'r' || ch == 'u' || ch == 's') {
            virus = 1;
            break;
        }
    }
    fclose(fptr);
    return virus;
}

void scan_dir(char* dir_name) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(dir_name)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            char file_path[1024];
            sprintf(file_path, "%s/%s", dir_name, ent->d_name);
            if (ent->d_type == DT_DIR && strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                scan_dir(file_path);
            } else if (ent->d_type == DT_REG) {
                if (is_virus(file_path)) {
                    printf("Virus Detected: %s\n", file_path);
                }
            }
        }
        closedir(dir);
    } else {
        printf("Error opening directory");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    char *dir_name = argv[1];
    printf("Scanning directory: %s\n", dir_name);
    scan_dir(dir_name);
    printf("Scan complete!\n");
    return 0;
}