//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#define MAX_PATH 1024
#define BOLD "\033[1m"
#define RESET "\033[0m"

void list_files(const char *dirname) {
    struct dirent *entry;
    DIR *dp = opendir(dirname);

    if (dp == NULL) {
        fprintf(stderr, "Error opening directory %s: %s\n", dirname, strerror(errno));
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {
            printf(BOLD "%s" RESET "\n", entry->d_name);
        } else if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                printf("[DIR] %s\n", entry->d_name);
            }
        }
    }

    closedir(dp);
}

void create_directory(const char *dirname) {
    if (mkdir(dirname, 0755) == -1) {
        fprintf(stderr, "Error creating directory %s: %s\n", dirname, strerror(errno));
    } else {
        printf("Directory created: %s\n", dirname);
    }
}

void delete_file(const char *filename) {
    if (remove(filename) == 0) {
        printf("Deleted file: %s\n", filename);
    } else {
        fprintf(stderr, "Error deleting file %s: %s\n", filename, strerror(errno));
    }
}

void display_help() {
    printf(BOLD "System Administration Tool v1.0" RESET "\n");
    printf("Usage:\n");
    printf("  list [directory]    List files in [directory]. Default is current directory.\n");
    printf("  create [directory]  Create a new directory named [directory].\n");
    printf("  delete [file]       Delete the specified [file].\n");
    printf("  help                Display this help message.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "No command provided. Use 'help' for instructions.\n");
        return EXIT_FAILURE;
    }

    char command[10];
    strncpy(command, argv[1], sizeof(command) - 1);
    command[sizeof(command) - 1] = '\0';

    if (strcmp(command, "list") == 0) {
        const char *dirname = (argc > 2) ? argv[2] : ".";
        printf("Listing files in: %s\n", dirname);
        list_files(dirname);
    } else if (strcmp(command, "create") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Directory name required for create command.\n");
            return EXIT_FAILURE;
        }
        create_directory(argv[2]);
    } else if (strcmp(command, "delete") == 0) {
        if (argc < 3) {
            fprintf(stderr, "File name required for delete command.\n");
            return EXIT_FAILURE;
        }
        delete_file(argv[2]);
    } else if (strcmp(command, "help") == 0) {
        display_help();
    } else {
        fprintf(stderr, "Unknown command: %s. Use 'help' for instructions.\n", command);
    }

    return EXIT_SUCCESS;
}