//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_CONTENT_LENGTH 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    int size;
} file_t;

void create_file(file_t *file, char *name) {
    strncpy(file->name, name, MAX_FILE_NAME_LENGTH);
    file->size = 0;
    file->content[0] = '\0';
}

void open_file(file_t *file, char *name) {
    int i;
    for (i = 0; i < MAX_FILE_NAME_LENGTH; i++) {
        if (name[i] == '\0') {
            strncpy(file->name, name, i);
            break;
        }
    }
    file->size = strlen(file->content);
}

void write_file(file_t *file, char *content) {
    int new_size = strlen(content);
    if (new_size > MAX_FILE_CONTENT_LENGTH - file->size) {
        printf("Error: Content is too large.\n");
        return;
    }
    strcat(file->content, content);
    file->size += new_size;
}

void close_file(file_t *file) {
    file->size = 0;
    file->content[0] = '\0';
}

void delete_file(file_t *file) {
    strcpy(file->name, "");
    strcpy(file->content, "");
    file->size = 0;
}

void list_files(file_t *files, int num_files) {
    int i;
    for (i = 0; i < num_files; i++) {
        printf("%s - %d bytes\n", files[i].name, files[i].size);
    }
}

int main() {
    file_t files[10];
    int num_files = 0;

    while (1) {
        printf("1. Create file\n");
        printf("2. Open file\n");
        printf("3. Write file\n");
        printf("4. Close file\n");
        printf("5. Delete file\n");
        printf("6. List files\n");
        printf("7. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_FILE_NAME_LENGTH];
                printf("Enter file name: ");
                scanf("%s", name);
                create_file(&files[num_files], name);
                num_files++;
                break;
            }
            case 2: {
                char name[MAX_FILE_NAME_LENGTH];
                printf("Enter file name: ");
                scanf("%s", name);
                open_file(&files[num_files], name);
                num_files++;
                break;
            }
            case 3: {
                char content[MAX_FILE_CONTENT_LENGTH];
                printf("Enter file content: ");
                scanf("%s", content);
                write_file(&files[num_files - 1], content);
                break;
            }
            case 4: {
                close_file(&files[num_files - 1]);
                break;
            }
            case 5: {
                delete_file(&files[num_files - 1]);
                num_files--;
                break;
            }
            case 6: {
                list_files(files, num_files);
                break;
            }
            case 7: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}