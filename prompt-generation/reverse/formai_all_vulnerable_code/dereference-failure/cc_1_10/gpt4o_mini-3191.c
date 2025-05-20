//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 4096

void list_files(const char *dir) {
    struct dirent *entry;
    DIR *dp = opendir(dir);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Files in directory %s:\n", dir);
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            printf("  %s\n", entry->d_name);
        }
    }
    closedir(dp);
}

void create_file(const char *path) {
    FILE *fp = fopen(path, "w");
    if (fp == NULL) {
        perror("Failed to create file");
        return;
    }
    fprintf(fp, "This file was created by a custom C program.\n");
    fclose(fp);
    printf("File created: %s\n", path);
}

void read_file(const char *path) {
    char buffer[256];
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }
    printf("Contents of %s:\n", path);
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    fclose(fp);
}

void delete_file(const char *path) {
    if (remove(path) == 0) {
        printf("File deleted: %s\n", path);
    } else {
        perror("Failed to delete file");
    }
}

void show_help() {
    printf("Usage: sysadmin_tool <command> [options]\n");
    printf("Commands:\n");
    printf("  list <directory>  - List files in the specified directory.\n");
    printf("  create <filename> - Create a new file with some contents.\n");
    printf("  read <filename>   - Read and display the contents of a file.\n");
    printf("  delete <filename> - Delete the specified file.\n");
    printf("  help              - Show this help message.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No command provided.\n");
        show_help();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "list") == 0 && argc == 3) {
        list_files(argv[2]);
    } else if (strcmp(argv[1], "create") == 0 && argc == 3) {
        create_file(argv[2]);
    } else if (strcmp(argv[1], "read") == 0 && argc == 3) {
        read_file(argv[2]);
    } else if (strcmp(argv[1], "delete") == 0 && argc == 3) {
        delete_file(argv[2]);
    } else {
        show_help();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}