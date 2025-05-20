//FormAI DATASET v1.0 Category: File system simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NO_FILES 10

// struct to hold file information
struct file {
    char name[MAX_NAME_LEN];
    int size;
};

// struct to hold information about file system
struct file_system {
    struct file files[MAX_NO_FILES];
    int no_files;
    int total_size;
};

// function to create new file system
struct file_system* create_file_system() {
    struct file_system* fs = (struct file_system*)malloc(sizeof(struct file_system));
    fs->no_files = 0;
    fs->total_size = 0;
    return fs;
}

// function to safely add file to file system
void add_file(struct file_system* fs, char* name, int size) {
    if(fs->no_files >= MAX_NO_FILES) {
        printf("File system is full.\n");
        return;
    }
    if(size <= 0) {
        printf("Invalid file size.\n");
        return;
    }
    if(strlen(name) > MAX_NAME_LEN) {
        printf("File name too long.\n");
        return;
    }
    for(int i=0; i<fs->no_files; i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            printf("File with this name already exists.\n");
            return;
        }
    }
    strncpy(fs->files[fs->no_files].name, name, MAX_NAME_LEN);
    fs->files[fs->no_files].size = size;
    fs->no_files++;
    fs->total_size += size;
    printf("File added successfully.\n");
}

// function to safely remove file from file system
void remove_file(struct file_system* fs, char* name) {
    for(int i=0; i<fs->no_files; i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            fs->total_size -= fs->files[i].size;
            for(int j=i; j<fs->no_files-1; j++) {
                strcpy(fs->files[j].name, fs->files[j+1].name);
                fs->files[j].size = fs->files[j+1].size;
            }
            fs->no_files--;
            printf("File removed successfully.\n");
            return;
        }
    }
    printf("File not found.\n");
}

// function to safely list files in file system
void list_files(struct file_system* fs) {
    if(fs->no_files == 0) {
        printf("File system is empty.\n");
        return;
    }
    for(int i=0; i<fs->no_files; i++) {
        printf("%s\t%d\n", fs->files[i].name, fs->files[i].size);
    }
}

int main() {
    struct file_system* fs = create_file_system();
    while(1) {
        printf("Enter command (add/remove/list/exit):\n");
        char command[10];
        scanf("%s", command);
        if(strcmp(command, "add") == 0) {
            printf("Enter file name:\n");
            char name[MAX_NAME_LEN];
            scanf("%s", name);
            printf("Enter file size:\n");
            int size;
            scanf("%d", &size);
            add_file(fs, name, size);
        }
        else if(strcmp(command, "remove") == 0) {
            printf("Enter file name:\n");
            char name[MAX_NAME_LEN];
            scanf("%s", name);
            remove_file(fs, name);
        }
        else if(strcmp(command, "list") == 0) {
            list_files(fs);
        }
        else if(strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}