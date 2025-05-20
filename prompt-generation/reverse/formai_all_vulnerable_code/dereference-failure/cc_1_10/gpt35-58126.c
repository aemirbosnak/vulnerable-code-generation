//FormAI DATASET v1.0 Category: File system simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

/* Define necessary data structures for file system */
struct file {
    char name[50];
    int size;
    char* data;
};

struct directory {
    char name[50];
    int num_files;
    struct file* files;
};

struct file_server {
    char name[50];
    int num_directories;
    struct directory* directories;
};

/* Define necessary functions for file system operations */
int create_file(struct directory* dir, char* filename, int size);
int delete_file(struct directory* dir, char* filename);
int read_file(struct directory* dir, char* filename, char* data, int size);
int write_file(struct directory* dir, char* filename, char* data, int size);

/* Define main function of program */
int main() {
    /* Create file servers and directories for file system */
    struct file_server server1 = {"Server 1", 2, NULL};
    struct file_server server2 = {"Server 2", 2, NULL};
    
    server1.directories = (struct directory*) malloc(server1.num_directories * sizeof(struct directory));
    server2.directories = (struct directory*) malloc(server2.num_directories * sizeof(struct directory));
    
    struct directory server1_dir1 = {"Directory 1", 2, NULL};
    struct directory server1_dir2 = {"Directory 2", 2, NULL};
    struct directory server2_dir1 = {"Directory 1", 2, NULL};
    struct directory server2_dir2 = {"Directory 2", 2, NULL};
    
    server1.directories[0] = server1_dir1;
    server1.directories[1] = server1_dir2;
    server2.directories[0] = server2_dir1;
    server2.directories[1] = server2_dir2;
    
    server1_dir1.files = (struct file*) malloc(server1_dir1.num_files * sizeof(struct file));
    server1_dir2.files = (struct file*) malloc(server1_dir2.num_files * sizeof(struct file));
    server2_dir1.files = (struct file*) malloc(server2_dir1.num_files * sizeof(struct file));
    server2_dir2.files = (struct file*) malloc(server2_dir2.num_files * sizeof(struct file));
    
    /* Add, modify, and delete files in file system */
    create_file(&server1.directories[0], "file1.txt", 10);
    char data[] = "Hello, world!";
    write_file(&server1.directories[0], "file1.txt", data, 13);
    char* read_data = (char*) malloc(13 * sizeof(char));
    read_file(&server1.directories[0], "file1.txt", read_data, 13);
    printf("%s\n", read_data);
    free(read_data);
    delete_file(&server1.directories[0], "file1.txt");
    
    /* Free memory allocated for file system */
    free(server1.directories[0].files);
    free(server1.directories[1].files);
    free(server2.directories[0].files);
    free(server2.directories[1].files);
    
    free(server1.directories);
    free(server2.directories);
    
    return 0;
}

int create_file(struct directory* dir, char* filename, int size) {
    dir->num_files++;
    dir->files = (struct file*) realloc(dir->files, dir->num_files * sizeof(struct file));
    
    struct file new_file = {filename, size, NULL};
    dir->files[dir->num_files-1] = new_file;
    
    return 1;
}

int delete_file(struct directory* dir, char* filename) {
    int index = -1;
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, filename) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        return 0;
    }
    
    free(dir->files[index].data);
    for (int i = index; i < dir->num_files-1; i++) {
        dir->files[i] = dir->files[i+1];
    }
    
    dir->num_files--;
    dir->files = (struct file*) realloc(dir->files, dir->num_files * sizeof(struct file));
    
    return 1;
}

int read_file(struct directory* dir, char* filename, char* data, int size) {
    int index = -1;
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, filename) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1 || dir->files[index].data == NULL) {
        return 0;
    }
    
    if (dir->files[index].size >= size) {
        memcpy(data, dir->files[index].data, size);
    } else {
        memcpy(data, dir->files[index].data, dir->files[index].size);
    }
    
    return 1;
}

int write_file(struct directory* dir, char* filename, char* data, int size) {
    int index = -1;
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, filename) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        return 0;
    }
    
    if (dir->files[index].size >= size) {
        memcpy(dir->files[index].data, data, size);
    } else {
        dir->files[index].data = (char*) realloc(dir->files[index].data, size * sizeof(char));
        memcpy(dir->files[index].data, data, size);
    }
    
    return 1;
}