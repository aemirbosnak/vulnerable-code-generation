//FormAI DATASET v1.0 Category: File system simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 20
#define MAX_FILE_SIZE 100

typedef struct {
    char filename[MAX_FILENAME_SIZE];
    char content[MAX_FILE_SIZE];
    int size;
} File;

typedef struct {
    File* files;
    int num_files;
} FileSystem;

void create_file(FileSystem* fs, char* filename) {
    if (fs->num_files == 0) {
        fs->files = malloc(sizeof(File));
    } else {
        fs->files = realloc(fs->files, (fs->num_files + 1) * sizeof(File));
    }

    strncpy(fs->files[fs->num_files].filename, filename, MAX_FILENAME_SIZE);
    fs->files[fs->num_files].size = 0;
    fs->num_files += 1;

    printf("File '%s' created!\n", filename);
}

void delete_file(FileSystem* fs, char* filename) {
    int file_index = -1;

    for (int i = 0; i < fs->num_files; i++) {
        if (strncmp(fs->files[i].filename, filename, MAX_FILENAME_SIZE) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("File '%s' not found!\n", filename);
        return;
    }

    for (int i = file_index + 1; i < fs->num_files; i++) {
        fs->files[i-1] = fs->files[i];
    }

    fs->num_files -= 1;
    fs->files = realloc(fs->files, fs->num_files * sizeof(File));

    printf("File '%s' deleted!\n", filename);
}

void print_file(File file) {
    printf("Filename: %s\n", file.filename);
    printf("Size: %d bytes\n", file.size);
    printf("Content:\n");
    printf("%s\n", file.content);
}

void list_files(FileSystem fs) {
    printf("Files in filesystem:\n");

    for (int i = 0; i < fs.num_files; i++) {
        printf("%d. %s\n", i+1, fs.files[i].filename);
    }

    if (fs.num_files == 0) {
        printf("(none)\n");
    }
}

int main() {
    FileSystem fs = {NULL, 0};
    int choice;

    do {
        printf("\nFile system simulation:\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. Print file\n");
        printf("4. List files\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    char filename[MAX_FILENAME_SIZE];
                    printf("Enter filename: ");
                    scanf("%s", filename);
                    create_file(&fs, filename);
                    break;
                }
            case 2:
                {
                    char filename[MAX_FILENAME_SIZE];
                    printf("Enter filename: ");
                    scanf("%s", filename);
                    delete_file(&fs, filename);
                    break;
                }
            case 3:
                {
                    char filename[MAX_FILENAME_SIZE];
                    printf("Enter filename: ");
                    scanf("%s", filename);

                    int file_index = -1;

                    for (int i = 0; i < fs.num_files; i++) {
                        if (strncmp(fs.files[i].filename, filename, MAX_FILENAME_SIZE) == 0) {
                            file_index = i;
                            break;
                        }
                    }

                    if (file_index == -1) {
                        printf("File '%s' not found!\n", filename);
                    } else {
                        print_file(fs.files[file_index]);
                    }

                    break;
                }
            case 4:
                {
                    list_files(fs);
                    break;
                }
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    for (int i = 0; i < fs.num_files; i++) {
        free(fs.files[i].content);
    }

    free(fs.files);

    return 0;
}