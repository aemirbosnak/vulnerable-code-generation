//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_FILES 100
#define FILE_NAME_LENGTH 50
#define BUFFER_SIZE 256

typedef struct {
    char name[FILE_NAME_LENGTH];
    int size;
    char *data;
} File;

typedef struct {
    File *files[MAX_FILES];
    int count;
} FileSystem;

FileSystem *create_file_system() {
    FileSystem *fs = (FileSystem *)malloc(sizeof(FileSystem));
    fs->count = 0;
    return fs;
}

void paranoid_delete_file(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            free(fs->files[i]->data);
            free(fs->files[i]);
            fs->files[i] = fs->files[fs->count - 1];
            fs->count--;
            printf("File '%s' deleted successfully.\n", name);
            return;
        }
    }
    printf("Error: File '%s' not found for deletion.\n", name);
}

void paranoid_create_file(FileSystem *fs, const char *name, const char *data) {
    if (fs->count >= MAX_FILES) {
        printf("Error: Maximum file limit reached. Cannot create file '%s'.\n", name);
        return;
    }
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            printf("Error: File with name '%s' already exists!\n", name);
            return;
        }
    }

    File *new_file = (File *)malloc(sizeof(File));
    strncpy(new_file->name, name, FILE_NAME_LENGTH);
    new_file->size = strlen(data);
    new_file->data = (char *)malloc(new_file->size + 1);
    strcpy(new_file->data, data);
    
    fs->files[fs->count++] = new_file;
    printf("File '%s' created successfully.\n", name);
}

void paranoid_read_file(FileSystem *fs, const char *name) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            printf("Reading file '%s':\n%s\n", name, fs->files[i]->data);
            return;
        }
    }
    printf("Error: File '%s' not found for reading.\n", name);
}

void paranoid_display_files(FileSystem *fs) {
    printf("Total files in the system: %d\n", fs->count);
    for (int i = 0; i < fs->count; i++) {
        printf("File %d: %s (%d bytes)\n", i + 1, fs->files[i]->name, fs->files[i]->size);
    }
}

void paranoid_write_file(FileSystem *fs, const char *name, const char *data) {
    for (int i = 0; i < fs->count; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            free(fs->files[i]->data);
            fs->files[i]->size = strlen(data);
            fs->files[i]->data = (char *)malloc(fs->files[i]->size + 1);
            strcpy(fs->files[i]->data, data);
            printf("File '%s' written successfully.\n", name);
            return;
        }
    }
    printf("Error: File '%s' not found for writing.\n", name);
}

int main() {
    FileSystem *fs = create_file_system();
    char buffer[BUFFER_SIZE];

    while (1) {
        printf("\nFile System Simulator:\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Write File\n");
        printf("4. Delete File\n");
        printf("5. Display Files\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        
        fgets(buffer, sizeof(buffer), stdin);
        int choice = atoi(buffer);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;  // Remove trailing newline
                printf("Enter file data: ");
                char data[BUFFER_SIZE];
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = 0; // Remove trailing newline
                paranoid_create_file(fs, buffer, data);
                break;
            case 2:
                printf("Enter file name to read: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0; 
                paranoid_read_file(fs, buffer);
                break;
            case 3:
                printf("Enter file name to write: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0; 
                printf("Enter new data: ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = 0; 
                paranoid_write_file(fs, buffer, data);
                break;
            case 4:
                printf("Enter file name to delete: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0; 
                paranoid_delete_file(fs, buffer);
                break;
            case 5:
                paranoid_display_files(fs);
                break;
            case 6:
                printf("Exiting program...\n");
                for (int i = 0; i < fs->count; i++) {
                    free(fs->files[i]->data);
                    free(fs->files[i]);
                }
                free(fs);
                return 0;
            default:
                printf("Invalid option. Try again!\n");
                break;
        }
    }
    return 0;
}