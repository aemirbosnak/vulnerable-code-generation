//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_FILES 100
#define MAX_PATH_LENGTH 256

void displayHelp() {
    printf("Usage: sysadmin_tool [OPTION]\n");
    printf("Options:\n");
    printf("  -l, --list          List files in the given directory\n");
    printf("  -d, --delete <file> Delete a specified file\n");
    printf("  -c, --create <name> Create a new file with the specified name\n");
    printf("  -h, --help          Display this help message\n");
}

void listFiles(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Listing files in directory: %s\n", directory);
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) // Regular file
            printf("%s\n", entry->d_name);
    }
    closedir(dp);
}

void deleteFile(const char *filepath) {
    if (remove(filepath) == 0) {
        printf("File %s deleted successfully.\n", filepath);
    } else {
        perror("Error deleting file");
    }
}

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "This is a new file named %s\n", filename);
        fclose(file);
        printf("File %s created successfully.\n", filename);
    } else {
        perror("Error creating file");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No option provided.\n");
        displayHelp();
        return EXIT_FAILURE;
    }

    if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)) {
        displayHelp();
        return EXIT_SUCCESS;
    }

    if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0) {
        char path[MAX_PATH_LENGTH];
        if (argc >= 3) {
            strncpy(path, argv[2], MAX_PATH_LENGTH - 1);
            path[MAX_PATH_LENGTH - 1] = '\0'; // Ensure null termination
        } else {
            getcwd(path, sizeof(path));
        }
        listFiles(path);
    } else if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--delete") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Error: No file specified for deletion.\n");
            return EXIT_FAILURE;
        }
        deleteFile(argv[2]);
    } else if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--create") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Error: No filename specified to create.\n");
            return EXIT_FAILURE;
        }
        createFile(argv[2]);
    } else {
        fprintf(stderr, "Error: Unknown option: %s\n", argv[1]);
        displayHelp();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}