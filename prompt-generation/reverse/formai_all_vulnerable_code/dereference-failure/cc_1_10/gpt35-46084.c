//FormAI DATASET v1.0 Category: File system simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 20

// Structure to store information about a file
struct file {
    char name[MAX_NAME_LENGTH];
    int size;
};

// Structure to store information about a directory
struct directory {
    char name[MAX_NAME_LENGTH];
    struct directory *subdirs[MAX_FILES];
    struct file *files[MAX_FILES];
    int num_subdirs;
    int num_files;
};

// Recursively create a directory and any subdirectories
void create_directory(struct directory *dir) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of directory: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    strtok(name, "\n"); // remove newline character
    strncpy(dir->name, name, MAX_NAME_LENGTH);
    dir->num_subdirs = 0;
    dir->num_files = 0;

    char choice;
    do {
        printf("Create subdirectory? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // consume newline character

        if (choice == 'y') {
            if (dir->num_subdirs >= MAX_FILES) {
                printf("Maximum number of subdirectories reached.\n");
                continue;
            }

            struct directory *subdir = malloc(sizeof(struct directory));
            create_directory(subdir);
            dir->subdirs[dir->num_subdirs++] = subdir;
        }
    } while (choice == 'y');

    do {
        printf("Add file? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // consume newline character

        if (choice == 'y') {
            if (dir->num_files >= MAX_FILES) {
                printf("Maximum number of files reached.\n");
                continue;
            }

            struct file *file = malloc(sizeof(struct file));
            printf("Enter name of file: ");
            fgets(file->name, MAX_NAME_LENGTH, stdin);
            strtok(file->name, "\n"); // remove newline character
            printf("Enter size of file: ");
            scanf("%d", &file->size);
            getchar(); // consume newline character

            dir->files[dir->num_files++] = file;
        }
    } while (choice == 'y');
}

// Recursively print the directory structure and file sizes
void print_directory(struct directory *dir, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s/\n", dir->name);

    for (int i = 0; i < dir->num_files; i++) {
        for (int j = 0; j < depth + 1; j++) {
            printf("  ");
        }
        printf("- %s (%d bytes)\n", dir->files[i]->name, dir->files[i]->size);
    }

    for (int i = 0; i < dir->num_subdirs; i++) {
        print_directory(dir->subdirs[i], depth + 1);
    }
}

// Recursively free memory for directories and files
void free_directory(struct directory *dir) {
    for (int i = 0; i < dir->num_files; i++) {
        free(dir->files[i]);
    }

    for (int i = 0; i < dir->num_subdirs; i++) {
        free_directory(dir->subdirs[i]);
    }

    free(dir);
}

int main() {
    struct directory *root_dir = malloc(sizeof(struct directory));
    create_directory(root_dir);
    printf("\nDirectory structure:\n");
    print_directory(root_dir, 0);
    free_directory(root_dir);

    return 0;
}