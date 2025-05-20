//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_PATH 1024

void display_help() {
    printf("Usage: sysadmin_tool [command] [options]\n");
    printf("Commands:\n");
    printf("  list - List files in a directory\n");
    printf("  create - Create a new file\n");
    printf("  delete - Delete a file\n");
    printf("  info - Show file information\n");
    printf("  help - Display this help message\n");
}

void list_files(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Files in directory '%s':\n", path);
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] != '.') { // Skip hidden files
            printf("  %s\n", entry->d_name);
        }
    }
    
    closedir(dp);
}

void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("fopen");
        return;
    }
    fprintf(file, "File created: %s\n", filename);
    fclose(file);
    printf("File '%s' created successfully.\n", filename);
}

void delete_file(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("remove");
    }
}

void show_file_info(const char *filename) {
    struct stat file_stat;

    if (stat(filename, &file_stat) != 0) {
        perror("stat");
        return;
    }

    printf("File: %s\n", filename);
    printf("Size: %lld bytes\n", (long long)file_stat.st_size);
    printf("Permissions: ( %o / %s )\n", file_stat.st_mode & 0777, 
            (file_stat.st_mode & S_IFDIR) ? "directory" : "file");
    printf("Last modified: %s", ctime(&file_stat.st_mtime));
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No command specified.\n");
        display_help();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "help") == 0) {
        display_help();
    } else if (strcmp(argv[1], "list") == 0) {
        const char *path = (argc >= 3) ? argv[2] : ".";
        list_files(path);
    } else if (strcmp(argv[1], "create") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Error: No filename provided for create command.\n");
            return EXIT_FAILURE;
        }
        create_file(argv[2]);
    } else if (strcmp(argv[1], "delete") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Error: No filename provided for delete command.\n");
            return EXIT_FAILURE;
        }
        delete_file(argv[2]);
    } else if (strcmp(argv[1], "info") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Error: No filename provided for info command.\n");
            return EXIT_FAILURE;
        }
        show_file_info(argv[2]);
    } else {
        fprintf(stderr, "Error: Unknown command '%s'.\n", argv[1]);
        display_help();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}