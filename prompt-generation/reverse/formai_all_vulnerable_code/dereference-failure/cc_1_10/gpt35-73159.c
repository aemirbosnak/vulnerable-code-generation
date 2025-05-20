//FormAI DATASET v1.0 Category: File Synchronizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

/* Struct to represent a file */
typedef struct {
    char name[200];
    unsigned long int size;
    char last_modified[30];
} File;

/* Function to get the name of a file from a path */
char* get_file_name(char* path) {
    char* name = strrchr(path, '/');
    if (name == NULL) {
        return path;
    } else {
        return name + 1;
    }
}

/* Function to get the last modified time of a file as a string */
void get_last_modified(File* file, struct stat info) {
    time_t last_modified_time = info.st_mtime;
    strftime(file->last_modified, 30, "%Y-%m-%d %H:%M:%S", localtime(&last_modified_time));
}

/* Function to get the size of a file */
unsigned long int get_file_size(char* path) {
    FILE* file = fopen(path, "r");
    fseek(file, 0, SEEK_END);
    unsigned long int size = ftell(file);
    fclose(file);
    return size;
}

/* Function to check if two files are the same */
int files_equal(File* file1, File* file2) {
    if (strcmp(file1->name, file2->name) == 0 &&
        file1->size == file2->size &&
        strcmp(file1->last_modified, file2->last_modified) == 0) {
        return 1;
    } else {
        return 0;
    }
}

/* Function to synchronize two files */
int synchronize_files(char* path1, char* path2) {
    File file1, file2;
    struct stat info1, info2;

    /* Get file information */
    stat(path1, &info1);
    stat(path2, &info2);

    /* Fill in file structs */
    strcpy(file1.name, get_file_name(path1));
    file1.size = get_file_size(path1);
    get_last_modified(&file1, info1);

    strcpy(file2.name, get_file_name(path2));
    file2.size = get_file_size(path2);
    get_last_modified(&file2, info2);

    /* Check if files are the same */
    if (files_equal(&file1, &file2)) {
        printf("%s and %s are already synchronized.\n", path1, path2);
        return 0;
    }

    /* Determine which file is newer */
    if (info1.st_mtime > info2.st_mtime) {
        printf("%s is newer.\n", path1);
        remove(path2);
        rename(path1, path2);
    } else if (info1.st_mtime < info2.st_mtime) {
        printf("%s is newer.\n", path2);
        remove(path1);
        rename(path2, path1);
    } else {
        printf("Both files have the same modification time. Manual intervention needed.\n");
        return 1;
    }

    printf("%s and %s synchronized successfully.\n", path1, path2);
    return 0;
}

/* Function to synchronize two directories */
int synchronize_directories(char* path1, char* path2) {
    DIR* dir1 = opendir(path1);
    DIR* dir2 = opendir(path2);
    struct dirent* entry;
    char file_path1[300], file_path2[300];

    /* Check if directories are valid */
    if (dir1 == NULL) {
        printf("Could not open directory %s.\n", path1);
        return 1;
    }
    if (dir2 == NULL) {
        printf("Could not open directory %s.\n", path2);
        return 1;
    }

    /* Synchronize files that are in both directories */
    while ((entry = readdir(dir1)) != NULL) {
        if (entry->d_type != DT_DIR) {
            sprintf(file_path1, "%s/%s", path1, entry->d_name);
            sprintf(file_path2, "%s/%s", path2, entry->d_name);
            synchronize_files(file_path1, file_path2);
        }
    }
    rewinddir(dir1);
    while ((entry = readdir(dir2)) != NULL) {
        if (entry->d_type != DT_DIR) {
            sprintf(file_path1, "%s/%s", path1, entry->d_name);
            sprintf(file_path2, "%s/%s", path2, entry->d_name);
            synchronize_files(file_path1, file_path2);
        }
    }

    /* Synchronize directories that are in both directories */
    rewinddir(dir1);
    while ((entry = readdir(dir1)) != NULL) {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            sprintf(file_path1, "%s/%s", path1, entry->d_name);
            sprintf(file_path2, "%s/%s", path2, entry->d_name);
            printf("Synchronizing directories %s and %s...\n", file_path1, file_path2);
            synchronize_directories(file_path1, file_path2);
        }
    }

    closedir(dir1);
    closedir(dir2);
    return 0;
}

/* Main function */
int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <directory1> <directory2>\n", argv[0]);
        return 1;
    }

    printf("Synchronizing directories %s and %s...\n", argv[1], argv[2]);
    synchronize_directories(argv[1], argv[2]);

    return 0;
}