//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 256
#define FILE_CONTENT_LENGTH 1024

typedef struct {
    char name[FILENAME_LENGTH];
    char content[FILE_CONTENT_LENGTH];
    int is_allocated;
} File;

typedef struct {
    File *files[MAX_FILES];
    int file_count;
} FileSystem;

FileSystem* init_file_system() {
    FileSystem *fs = malloc(sizeof(FileSystem));
    fs->file_count = 0;
    for(int i = 0; i < MAX_FILES; i++) {
        fs->files[i] = NULL;
    }
    return fs;
}

File* create_file(FileSystem *fs, const char *name) {
    if (fs->file_count >= MAX_FILES) {
        printf("File system full, cannot create more files.\n");
        return NULL;
    }

    File *file = malloc(sizeof(File));
    strncpy(file->name, name, FILENAME_LENGTH);
    file->content[0] = '\0'; // Empty content
    file->is_allocated = 1;

    fs->files[fs->file_count++] = file;
    printf("File '%s' created successfully.\n", name);
    return file;
}

void write_file(File *file, const char *content) {
    if (file->is_allocated) {
        strncpy(file->content, content, FILE_CONTENT_LENGTH);
        printf("Content written to file '%s'.\n", file->name);
    } else {
        printf("Error: File '%s' is not allocated.\n", file->name);
    }
}

void read_file(File *file) {
    if (file->is_allocated) {
        printf("Reading file '%s':\n%s\n", file->name, file->content);
    } else {
        printf("Error: File '%s' is not allocated.\n", file->name);
    }
}

void delete_file(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (fs->files[i] != NULL && strcmp(fs->files[i]->name, name) == 0) {
            free(fs->files[i]);
            printf("File '%s' deleted successfully.\n", name);
            fs->files[i] = NULL;
            return;
        }
    }
    printf("Error: File '%s' not found.\n", name);
}

void list_files(FileSystem *fs) {
    printf("Listing files in the file system:\n");
    for (int i = 0; i < fs->file_count; i++) {
        if (fs->files[i] != NULL) {
            printf("- %s\n", fs->files[i]->name);
        }
    }
}

void free_file_system(FileSystem *fs) {
    for (int i = 0; i < fs->file_count; i++) {
        if (fs->files[i] != NULL) {
            free(fs->files[i]);
        }
    }
    free(fs);
    printf("File system cleaned up.\n");
}

int main() {
    FileSystem *fs = init_file_system();
    int choice;
    char filename[FILENAME_LENGTH];
    char content[FILE_CONTENT_LENGTH];

    do {
        printf("\nSimple File System Simulation:\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read File\n");
        printf("4. Delete File\n");
        printf("5. List Files\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                fgets(filename, FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline
                create_file(fs, filename);
                break;

            case 2:
                printf("Enter filename: ");
                fgets(filename, FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline
                printf("Enter content: ");
                fgets(content, FILE_CONTENT_LENGTH, stdin);
                content[strcspn(content, "\n")] = '\0'; // Remove newline
                for (int i = 0; i < fs->file_count; i++) {
                    if (fs->files[i] != NULL && strcmp(fs->files[i]->name, filename) == 0) {
                        write_file(fs->files[i], content);
                        break;
                    }
                }
                break;

            case 3:
                printf("Enter filename: ");
                fgets(filename, FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline
                for (int i = 0; i < fs->file_count; i++) {
                    if (fs->files[i] != NULL && strcmp(fs->files[i]->name, filename) == 0) {
                        read_file(fs->files[i]);
                        break;
                    }
                }
                break;

            case 4:
                printf("Enter filename: ");
                fgets(filename, FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline
                delete_file(fs, filename);
                break;

            case 5:
                list_files(fs);
                break;

            case 6:
                free_file_system(fs);
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}