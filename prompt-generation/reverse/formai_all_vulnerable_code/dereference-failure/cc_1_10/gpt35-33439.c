//FormAI DATASET v1.0 Category: File Synchronizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

/* Function to get the absolute path of the file */
char *get_absolute_path(const char *base_path, const char *file_name) {
    char *absolute_path = NULL;
    
    if (file_name[0] == '/') {
        absolute_path = strdup(file_name);
    } else {
        absolute_path = (char *) malloc(MAX_PATH_LENGTH * sizeof(char));
        snprintf(absolute_path, MAX_PATH_LENGTH, "%s/%s", base_path, file_name);
    }
    
    return absolute_path;
}

/* Function to check if a directory exists */
int dir_exists(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    
    if (dir) {
        closedir(dir);
        return 1;
    } else if (ENOENT == errno) {
        return 0;
    } else {
        return -1;
    }
}

/* Function to check if a file exists */
int file_exists(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    
    if (file) {
        fclose(file);
        return 1;
    } else {
        return 0;
    }
}

/* Function to recursively copy a directory */
void copy_directory(const char *src_dir_path, const char *dest_dir_path) {
    DIR *src_dir = opendir(src_dir_path);
    struct dirent *dirent = NULL;
    
    while ((dirent = readdir(src_dir)) != NULL) {
        if ((strcmp(dirent->d_name, ".") == 0) || (strcmp(dirent->d_name, "..") == 0)) {
            continue;
        }
        
        char *src_file_path = (char *) malloc(MAX_PATH_LENGTH * sizeof(char));
        snprintf(src_file_path, MAX_PATH_LENGTH, "%s/%s", src_dir_path, dirent->d_name);
        
        char *dest_file_path = (char *) malloc(MAX_PATH_LENGTH * sizeof(char));
        snprintf(dest_file_path, MAX_PATH_LENGTH, "%s/%s", dest_dir_path, dirent->d_name);
        
        struct stat stat_buf;
        if (stat(src_file_path, &stat_buf) == -1) {
            fprintf(stderr, "Error while getting file info: %s\n", strerror(errno));
            continue;
        }
        
        if (S_ISDIR(stat_buf.st_mode)) {
            if (!dir_exists(dest_file_path)) {
                if (mkdir(dest_file_path, stat_buf.st_mode) == -1) {
                    fprintf(stderr, "Error while creating directory: %s\n", strerror(errno));
                }
            }
            copy_directory(src_file_path, dest_file_path);
        } else {
            FILE *src_file = fopen(src_file_path, "r");
            FILE *dest_file = fopen(dest_file_path, "w+");
            
            if (!src_file) {
                fprintf(stderr, "Error while opening source file: %s\n", strerror(errno));
                continue;
            }
            
            if (!dest_file) {
                fprintf(stderr, "Error while opening destination file: %s\n", strerror(errno));
                fclose(src_file);
                continue;
            }
            
            char buffer[4096];
            size_t bytes_read = 0;
            while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), src_file)) > 0) {
                fwrite(buffer, sizeof(char), bytes_read, dest_file);
            }
            
            fclose(src_file);
            fclose(dest_file);
            free(src_file_path);
            free(dest_file_path);
        }
    }
    
    closedir(src_dir);
}

/* Function to synchronize two directories */
void synchronize_directories(const char *src_dir_path, const char *dest_dir_path) {
    DIR *src_dir = opendir(src_dir_path);
    struct dirent *dirent = NULL;
    
    while ((dirent = readdir(src_dir)) != NULL) {
        if ((strcmp(dirent->d_name, ".") == 0) || (strcmp(dirent->d_name, "..") == 0)) {
            continue;
        }
        
        char *src_file_path = (char *) malloc(MAX_PATH_LENGTH * sizeof(char));
        snprintf(src_file_path, MAX_PATH_LENGTH, "%s/%s", src_dir_path, dirent->d_name);
        
        char *dest_file_path = (char *) malloc(MAX_PATH_LENGTH * sizeof(char));
        snprintf(dest_file_path, MAX_PATH_LENGTH, "%s/%s", dest_dir_path, dirent->d_name);
        
        struct stat stat_buf;
        if (stat(src_file_path, &stat_buf) == -1) {
            fprintf(stderr, "Error while getting file info: %s\n", strerror(errno));
            continue;
        }
        
        if (S_ISDIR(stat_buf.st_mode)) {
            if (!dir_exists(dest_file_path)) {
                if (mkdir(dest_file_path, stat_buf.st_mode) == -1) {
                    fprintf(stderr, "Error while creating directory: %s\n", strerror(errno));
                }
            }
            synchronize_directories(src_file_path, dest_file_path);
        } else {
            if (file_exists(dest_file_path)) {
                struct stat dest_stat_buf;
                if (stat(dest_file_path, &dest_stat_buf) == -1) {
                    fprintf(stderr, "Error while getting file info: %s\n", strerror(errno));
                    continue;
                }
                
                if (stat_buf.st_mtime > dest_stat_buf.st_mtime) {
                    FILE *src_file = fopen(src_file_path, "r");
                    FILE *dest_file = fopen(dest_file_path, "w+");
                    
                    if (!src_file) {
                        fprintf(stderr, "Error while opening source file: %s\n", strerror(errno));
                        continue;
                    }
                    
                    if (!dest_file) {
                        fprintf(stderr, "Error while opening destination file: %s\n", strerror(errno));
                        fclose(src_file);
                        continue;
                    }
                    
                    char buffer[4096];
                    size_t bytes_read = 0;
                    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), src_file)) > 0) {
                        fwrite(buffer, sizeof(char), bytes_read, dest_file);
                    }
                    
                    fclose(src_file);
                    fclose(dest_file);
                }
            } else {
                FILE *src_file = fopen(src_file_path, "r");
                FILE *dest_file = fopen(dest_file_path, "w+");
                
                if (!src_file) {
                    fprintf(stderr, "Error while opening source file: %s\n", strerror(errno));
                    continue;
                }
                
                if (!dest_file) {
                    fprintf(stderr, "Error while opening destination file: %s\n", strerror(errno));
                    fclose(src_file);
                    continue;
                }
                
                char buffer[4096];
                size_t bytes_read = 0;
                while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), src_file)) > 0) {
                    fwrite(buffer, sizeof(char), bytes_read, dest_file);
                }
                
                fclose(src_file);
                fclose(dest_file);
            }
            free(src_file_path);
            free(dest_file_path);
        }
    }
    
    closedir(src_dir);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *src_dir_path = get_absolute_path(".", argv[1]);
    char *dest_dir_path = get_absolute_path(".", argv[2]);
    
    if (!dir_exists(src_dir_path)) {
        fprintf(stderr, "Error: Source directory does not exist\n");
        exit(EXIT_FAILURE);
    }
    
    if (!dir_exists(dest_dir_path)) {
        if (mkdir(dest_dir_path, 0777) == -1) {
            fprintf(stderr, "Error while creating destination directory: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
    
    synchronize_directories(src_dir_path, dest_dir_path);
    
    free(src_dir_path);
    free(dest_dir_path);
    
    return 0;
}