//FormAI DATASET v1.0 Category: File Synchronizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Define maximum length of strings for file and folder names
#define MAX_NAME_LEN 256

// Create a struct for holding file and folder information (name, path, size, and last modified time)
typedef struct {
    char name[MAX_NAME_LEN];
    char path[MAX_NAME_LEN];
    long size;
    time_t modified_time;
} FileSystemObject;

// Function to get the last modified time of a file or folder
time_t get_modified_time(char *path) {
    struct stat file_stat;
    stat(path, &file_stat);
    return file_stat.st_mtime;
}

// Function to recursively traverse a directory and add file and folder information to an array
void traverse_directory(char *directory, FileSystemObject **fs_objects, int *num_fs_objects) {
    DIR *dir;
    struct dirent *entry;
    char filepath[MAX_NAME_LEN];
    dir = opendir(directory);
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        snprintf(filepath, MAX_NAME_LEN, "%s/%s", directory, entry->d_name);
        FileSystemObject *fs_object = malloc(sizeof(FileSystemObject));
        strcpy(fs_object->name, entry->d_name);
        strcpy(fs_object->path, filepath);
        fs_object->modified_time = get_modified_time(filepath);
        if (entry->d_type == DT_DIR) {
            fs_object->size = 0;
            traverse_directory(filepath, fs_objects, num_fs_objects);
        } else {
            FILE *file = fopen(filepath, "r");
            fseek(file, 0, SEEK_END);
            fs_object->size = ftell(file);
            fclose(file);
        }
        fs_objects[*num_fs_objects] = fs_object;
        (*num_fs_objects)++;
    }
    closedir(dir);
}

// Function to synchronize two directories by copying files that exist in one directory but not the other
void synchronize_directories(char *src_dir, char *dest_dir) {
    FileSystemObject *src_fs_objects[MAX_NAME_LEN];
    FileSystemObject *dest_fs_objects[MAX_NAME_LEN];
    int num_src_fs_objects = 0;
    int num_dest_fs_objects = 0;
    traverse_directory(src_dir, src_fs_objects, &num_src_fs_objects);
    traverse_directory(dest_dir, dest_fs_objects, &num_dest_fs_objects);
    for (int i = 0; i < num_src_fs_objects; i++) {
        int found = 0;
        for (int j = 0; j < num_dest_fs_objects; j++) {
            if (strcmp(src_fs_objects[i]->name, dest_fs_objects[j]->name) == 0) {
                if (src_fs_objects[i]->modified_time > dest_fs_objects[j]->modified_time) {
                    char command[MAX_NAME_LEN*2];
                    sprintf(command, "cp %s %s", src_fs_objects[i]->path, dest_fs_objects[j]->path);
                    system(command);
                }
                found = 1;
                break;
            }
        }
        if (!found) {
            char command[MAX_NAME_LEN*2];
            sprintf(command, "cp -R %s %s", src_fs_objects[i]->path, dest_dir);
            system(command);
        }
    }
    for (int i = 0; i < num_src_fs_objects; i++) {
        free(src_fs_objects[i]);
    }
    for (int i = 0; i < num_dest_fs_objects; i++) {
        free(dest_fs_objects[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: cfsync <source directory> <destination directory>\n");
        exit(1);
    }
    synchronize_directories(argv[1], argv[2]);
    printf("Directories synchronized successfully!\n");
    return 0;
}