//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

// Generate a random string of length n.
char *random_string(size_t n) {
    char *str = malloc(n + 1);
    for (size_t i = 0; i < n; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[n] = '\0';
    return str;
}

// Create a directory with a random name.
char *create_directory() {
    char *dir_name = random_string(10);
    mkdir(dir_name, 0755);
    return dir_name;
}

// Copy a file to a directory.
void copy_file(char *file_name, char *dir_name) {
    char *new_file_name = malloc(strlen(dir_name) + strlen(file_name) + 2);
    strcpy(new_file_name, dir_name);
    strcat(new_file_name, "/");
    strcat(new_file_name, file_name);
    FILE *src_file = fopen(file_name, "r");
    FILE *dst_file = fopen(new_file_name, "w");
    char buffer[1024];
    while (fread(buffer, 1, 1024, src_file) > 0) {
        fwrite(buffer, 1, 1024, dst_file);
    }
    fclose(src_file);
    fclose(dst_file);
    free(new_file_name);
}

// Backup all files in a directory.
void backup_directory(char *dir_name) {
    DIR *dir = opendir(dir_name);
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char *file_name = malloc(strlen(dir_name) + strlen(entry->d_name) + 2);
        strcpy(file_name, dir_name);
        strcat(file_name, "/");
        strcat(file_name, entry->d_name);
        copy_file(file_name, create_directory());
        free(file_name);
    }
    closedir(dir);
}

int main() {
    srand(time(NULL));
    backup_directory(".");
    return 0;
}