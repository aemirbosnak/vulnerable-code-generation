//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

// Function to calculate the size of a directory and its contents
long calculate_directory_size(const char *path) {
    struct stat st;
    long total_size = 0;
    DIR *dir = opendir(path);
    
    if (dir == NULL) {
        perror("Failed to open directory");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[256];
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
            
            if (stat(full_path, &st) == 0) {
                if (S_ISDIR(st.st_mode)) {
                    // Recursively calculate size of subdirectory
                    long subdir_size = calculate_directory_size(full_path);
                    if (subdir_size != -1) {
                        total_size += subdir_size;
                    }
                } else {
                    total_size += st.st_size;
                }
            } else {
                perror("Failed to get file status");
            }
        }
    }
    
    closedir(dir);
    return total_size;
}

// Function to display the size of specified path
void display_size(const char *path) {
    long size = calculate_directory_size(path);
    
    if (size != -1) {
        printf("Total size of '%s': %ld bytes\n", path, size);
    }
}

// Function to search for files by extension
void search_file_by_extension(const char *path, const char *extension) {
    DIR *dir = opendir(path);
    
    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    struct dirent *entry;
    printf("Files with extension '%s' in '%s':\n", extension, path);
    
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            if (strstr(entry->d_name, extension) != NULL) {
                printf("Found: %s/%s\n", path, entry->d_name);
            }
        }
    }
    
    closedir(dir);
}

// Function to copy a file
void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");
    
    if (src == NULL || dest == NULL) {
        perror("Failed to open file");
        if (src) fclose(src);
        if (dest) fclose(dest);
        return;
    }

    char buffer[BUFSIZ];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) != 0) {
        fwrite(buffer, 1, bytes, dest);
    }
    
    fclose(src);
    fclose(dest);
    printf("Copied '%s' to '%s'\n", source, destination);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <command> <args...>\n", argv[0]);
        fprintf(stderr, "Commands:\n");
        fprintf(stderr, "  size <path>\n");
        fprintf(stderr, "  search <path> <extension>\n");
        fprintf(stderr, "  copy <source> <destination>\n");
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "size") == 0) {
        display_size(argv[2]);
    } else if (strcmp(argv[1], "search") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Please provide a file extension.\n");
            return EXIT_FAILURE;
        }
        search_file_by_extension(argv[2], argv[3]);
    } else if (strcmp(argv[1], "copy") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Please provide a destination path.\n");
            return EXIT_FAILURE;
        }
        copy_file(argv[2], argv[3]);
    } else {
        fprintf(stderr, "Unknown command: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}