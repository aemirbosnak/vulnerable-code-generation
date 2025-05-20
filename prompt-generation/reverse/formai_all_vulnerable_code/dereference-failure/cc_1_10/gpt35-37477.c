//FormAI DATASET v1.0 Category: File system simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file {
    char name[20];
    int size;
};

typedef struct {
    struct file *files;
    int num_files;
    int capacity;
} file_system;

void display_menu() {
    printf("\n");
    printf("============================================\n");
    printf("               FILE SYSTEM MENU\n");
    printf("============================================\n");
    printf("1. List files\n");
    printf("2. Add file\n");
    printf("3. Delete file\n");
    printf("4. Exit\n");
    printf("\n");
}

void list_files(file_system *fs) {
    printf("Files:\n");
    for (int i = 0; i < fs->num_files; i++) {
        printf("%s (%d bytes)\n", fs->files[i].name, fs->files[i].size);
    }
}

void add_file(file_system *fs) {
    char name[20];
    int size;

    printf("Enter file name (max 19 characters):\n");
    scanf("%19s", name);

    printf("Enter file size:\n");
    scanf("%d", &size);

    if (fs->num_files >= fs->capacity) {
        fs->capacity *= 2;
        fs->files = realloc(fs->files, fs->capacity * sizeof(struct file));
    }

    strcpy(fs->files[fs->num_files].name, name);
    fs->files[fs->num_files].size = size;

    fs->num_files++;

    printf("Added file '%s' (%d bytes)\n", name, size);
}

void delete_file(file_system *fs) {
    char name[20];
    int found = 0;

    printf("Enter file name to delete:\n");
    scanf("%19s", name);

    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < fs->num_files - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->num_files--;
            printf("Deleted file '%s'\n", name);
            break;
        }
    }

    if (!found) {
        printf("File not found\n");
    }
}

int main() {
    file_system fs;
    fs.num_files = 0;
    fs.capacity = 1;
    fs.files = malloc(sizeof(struct file));

    int choice;

    do {
        display_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            list_files(&fs);
            break;
        case 2:
            add_file(&fs);
            break;
        case 3:
            delete_file(&fs);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice, please try again\n");
        }

    } while (choice != 4);

    return 0;
}