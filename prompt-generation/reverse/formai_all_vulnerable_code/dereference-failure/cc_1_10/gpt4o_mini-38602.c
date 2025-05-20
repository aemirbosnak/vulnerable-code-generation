//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define PATH_MAX 4096
#define BUFSIZE 1024

typedef struct FileNode {
    char path[PATH_MAX];
    struct stat statbuf;
    struct FileNode *next;
} FileNode;

FileNode *head = NULL;

void insert_file_node(const char *path, struct stat *statbuf) {
    FileNode *new_node = (FileNode *)malloc(sizeof(FileNode));
    if (new_node == NULL) {
        perror("Failed to allocate memory for file node");
        exit(EXIT_FAILURE);
    }
    strncpy(new_node->path, path, PATH_MAX);
    new_node->statbuf = *statbuf;
    new_node->next = head;
    head = new_node;
}

void free_file_list() {
    FileNode *current = head;
    FileNode *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void analyze_directory(const char *dirname) {
    DIR *dir;
    struct dirent *entry;
    char path[PATH_MAX];
    struct stat statbuf;

    if ((dir = opendir(dirname)) == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);
            if (stat(path, &statbuf) == -1) {
                perror("Error obtaining file stats");
                continue;
            }
            insert_file_node(path, &statbuf);
            if (S_ISDIR(statbuf.st_mode)) {
                analyze_directory(path);
            }
        }
    }
    closedir(dir);
}

void format_size(double size, char *buffer) {
    const char *units[] = { "bytes", "KB", "MB", "GB", "TB" };
    int i = 0;
    while (size >= 1024 && i < 4) {
        size /= 1024;
        i++;
    }
    snprintf(buffer, BUFSIZE, "%.2f %s", size, units[i]);
}

void print_file_info() {
    FileNode *current = head;
    double total_size = 0;

    printf("Disk Space Usage Analysis:\n");
    printf("%-50s %-15s %-15s\n", "File Path", "Size", "File Type");
    printf("-------------------------------------------------------------\n");

    while (current != NULL) {
        char size_str[BUFSIZE];
        total_size += current->statbuf.st_size;

        format_size(current->statbuf.st_size, size_str);
        const char *file_type = S_ISDIR(current->statbuf.st_mode) ? "Directory" : "File";

        printf("%-50s %-15s %-15s\n", current->path, size_str, file_type);
        current = current->next;
    }

    char total_size_str[BUFSIZE];
    format_size(total_size, total_size_str);
    printf("-------------------------------------------------------------\n");
    printf("Total Size: %s\n", total_size_str);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    analyze_directory(argv[1]);
    print_file_info();
    free_file_list();

    return EXIT_SUCCESS;
}