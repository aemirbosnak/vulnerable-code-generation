//FormAI DATASET v1.0 Category: File system simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining file block structure
struct file_block {
    char data[100];
    struct file_block *next;
};

// defining file structure
struct file {
    char name[50];
    struct file_block *start;
};

// defining directory structure
struct directory {
    char name[50];
    struct directory *parent;
    struct directory *subdir[50];
    struct file *files[50];
    int subdir_count, file_count;
};

// create new file block
struct file_block *create_file_block(char *data) {
    struct file_block *new_block = (struct file_block *)malloc(sizeof(struct file_block));
    strcpy(new_block->data, data);
    new_block->next = NULL;
    return new_block;
}

// create new file
void create_file(struct directory *dir) {
    char filename[50];
    printf("\nEnter file name: ");
    scanf("%s", filename);
    for(int i=0; i<dir->file_count; i++) {
        if(strcmp(dir->files[i]->name, filename) == 0) {
            printf("\nFile already exists!\n");
            return;
        }
    }
    struct file *new_file = (struct file *)malloc(sizeof(struct file));
    strcpy(new_file->name, filename);
    new_file->start = NULL;
    dir->files[dir->file_count] = new_file;
    dir->file_count++;
    printf("\nFile created successfully!\n");
}

// insert data into existing file
void insert_data(struct directory *dir) {
    char filename[50], data[100];
    printf("\nEnter file name: ");
    scanf("%s", filename);
    for(int i=0; i<dir->file_count; i++) {
        if(strcmp(dir->files[i]->name, filename) == 0) {
            printf("\nEnter data: ");
            scanf("%s", data);
            if(dir->files[i]->start == NULL) {
                struct file_block *new_block = create_file_block(data);
                dir->files[i]->start = new_block; 
            }
            else {
                struct file_block *current_block = dir->files[i]->start;
                while(current_block->next != NULL) {
                    current_block = current_block->next;
                }
                current_block->next = create_file_block(data);
            }
            printf("\nData inserted successfully!\n");
            return;
        }
    }
    printf("\nFile not found!\n");
}

// display contents of a file
void display_file(struct directory *dir) {
    char filename[50];
    printf("\nEnter file name: ");
    scanf("%s", filename);
    for(int i=0; i<dir->file_count; i++) {
        if(strcmp(dir->files[i]->name, filename) == 0) {
            struct file_block *current_block = dir->files[i]->start;
            while(current_block != NULL) {
                printf("\n%s", current_block->data);
                current_block = current_block->next;
            }
            return;
        }
    }
    printf("\nFile not found!\n");
}

// create new directory
void create_directory(struct directory *dir) {
    char dirname[50];
    printf("\nEnter directory name: ");
    scanf("%s", dirname);
    for(int i=0; i<dir->subdir_count; i++) {
        if(strcmp(dir->subdir[i]->name, dirname) == 0) {
            printf("\nDirectory already exists!\n");
            return;
        }
    }
    struct directory *new_dir = (struct directory *)malloc(sizeof(struct directory));
    strcpy(new_dir->name, dirname);
    new_dir->parent = dir;
    new_dir->subdir_count = 0;
    new_dir->file_count = 0;
    dir->subdir[dir->subdir_count] = new_dir;
    dir->subdir_count++;
    printf("\nDirectory created successfully!\n");
}

// change directory
void change_directory(struct directory **curr_dir) {
    char dirname[50];
    printf("\nEnter directory name: ");
    scanf("%s", dirname);
    if(strcmp(dirname, "..") == 0) {
        if((*curr_dir)->parent != NULL) {
            *curr_dir = (*curr_dir)->parent;
            printf("\nDirectory changed to %s\n", (*curr_dir)->name);
        }
        else {
            printf("\nAlready in root directory!\n");
        }
        return;
    }
    for(int i=0; i<(*curr_dir)->subdir_count; i++) {
        if(strcmp((*curr_dir)->subdir[i]->name, dirname) == 0) {
            *curr_dir = (*curr_dir)->subdir[i];
            printf("\nDirectory changed to %s\n", (*curr_dir)->name);
            return;
        }
    }
    printf("\nDirectory not found!\n");
}

// list contents of current directory
void list_contents(struct directory *curr_dir) {
    printf("\nDirectories: ");
    for(int i=0; i<curr_dir->subdir_count; i++) {
        printf("%s ", curr_dir->subdir[i]->name);
    }
    printf("\nFiles: ");
    for(int i=0; i<curr_dir->file_count; i++) {
        printf("%s ", curr_dir->files[i]->name);
    }
}

int main() {
    struct directory *root = (struct directory *)malloc(sizeof(struct directory));
    strcpy(root->name, "root");
    root->parent = NULL;
    root->subdir_count = 0;
    root->file_count = 0;
    struct directory *curr_dir = root;
    while(1) {
        printf("\n\nCurrent directory: %s\n", curr_dir->name);
        printf("1. Create file\n2. Insert data into file\n3. Display file\n4. Create directory\n5. Change directory\n6. List contents\n7. Exit\n\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                create_file(curr_dir);
                break;
            case 2:
                insert_data(curr_dir);
                break;
            case 3:
                display_file(curr_dir);
                break;
            case 4:
                create_directory(curr_dir);
                break;
            case 5:
                change_directory(&curr_dir);
                break;
            case 6:
                list_contents(curr_dir);
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}