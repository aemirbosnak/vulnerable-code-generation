//FormAI DATASET v1.0 Category: File system simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_SIZE 20
#define MAX_FILE_SIZE 1024

struct file {
    char *name;
    int size;
    char *content;
};

struct file_system {
    int num_files;
    struct file *files[100];
};

void create_file(struct file_system *fs, char *name) {
    if (fs->num_files == 100) {
        printf("Error: file system full\n");
        return;
    }
    struct file *new_file = malloc(sizeof(struct file));
    new_file->name = malloc(strlen(name) + 1);
    strcpy(new_file->name, name);
    new_file->size = 0;
    new_file->content = malloc(MAX_FILE_SIZE);
    fs->files[fs->num_files++] = new_file;
    printf("File %s created\n", name);
}

void delete_file(struct file_system *fs, char *name) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (!strcmp(fs->files[i]->name, name)) {
            free(fs->files[i]->name);
            free(fs->files[i]->content);
            free(fs->files[i]);
            for (; i < fs->num_files - 1; i++) {
                fs->files[i] = fs->files[i+1];
            }
            fs->num_files--;
            printf("File %s deleted\n", name);
            return;
        }
    }
    printf("Error: file not found\n");
}

void write_file(struct file_system *fs, char *name, char *content) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (!strcmp(fs->files[i]->name, name)) {
            if (strlen(content) > MAX_FILE_SIZE - 1) {
                printf("Error: file too large\n");
                return;
            }
            strcpy(fs->files[i]->content, content);
            fs->files[i]->size = strlen(content);
            printf("File %s written\n", name);
            return;
        }
    }
    printf("Error: file not found\n");
}

void read_file(struct file_system *fs, char *name) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (!strcmp(fs->files[i]->name, name)) {
            printf("File %s content:\n", name);
            printf("%s\n", fs->files[i]->content);
            return;
        }
    }
    printf("Error: file not found\n");
}

int main() {
    struct file_system fs;
    fs.num_files = 0;
    int choice;
    char name[FILE_NAME_SIZE];
    char content[MAX_FILE_SIZE];

    while (1) {
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. Write to file\n");
        printf("4. Read from file\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter file name: ");
            scanf("%s", name);
            create_file(&fs, name);
            break;
        case 2:
            printf("Enter file name: ");
            scanf("%s", name);
            delete_file(&fs, name);
            break;
        case 3:
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter content: ");
            getchar();
            fgets(content, MAX_FILE_SIZE, stdin);
            write_file(&fs, name, content);
            break;
        case 4:
            printf("Enter file name: ");
            scanf("%s", name);
            read_file(&fs, name);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}