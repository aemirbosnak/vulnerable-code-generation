//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void scan_file(char *file_name) {
    FILE *file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Could not open file: %s.\n", file_name);
        return;
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char *buffer = (char *)malloc(file_size * sizeof(char));
    fread(buffer, file_size, 1, file);
    fclose(file);
    for (int i = 0; i < file_size - 3; i++) {
        if (buffer[i] == 'v' && buffer[i+1] == 'i' && buffer[i+2] == 'r' && buffer[i+3] == 'u') {
            printf("Virus found in file: %s.\n", file_name);
            free(buffer);
            return;
        }
    }
    free(buffer);
}

void scan_directory(char *dir_path) {
    DIR *dir;
    struct dirent *entry;
    dir = opendir(dir_path);
    if (dir == NULL) {
        printf("Could not open directory: %s.\n", dir_path);
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char file_path[1000];
            strcpy(file_path, dir_path);
            strcat(file_path, "/");
            strcat(file_path, entry->d_name);
            scan_file(file_path);
        } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char sub_dir_path[1000];
            strcpy(sub_dir_path, dir_path);
            strcat(sub_dir_path, "/");
            strcat(sub_dir_path, entry->d_name);
            scan_directory(sub_dir_path);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s directory\n", argv[0]);
        exit(1);
    }
    char *dir_path = argv[1];
    scan_directory(dir_path);
    printf("Scanning complete.\n");
    return 0;
}