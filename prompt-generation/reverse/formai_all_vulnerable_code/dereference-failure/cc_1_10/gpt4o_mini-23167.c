//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define HASH_SIZE 32

typedef struct FileNode {
    char *name;
    unsigned long size;
    char hash[HASH_SIZE];
    struct FileNode *next;
} FileNode;

FileNode *head = NULL;

// Function to calculate the size of a file
unsigned long get_file_size(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    } else {
        perror("Could not obtain file size");
        return 0;
    }
}

// Function to compute a simple hash of file contents
void compute_hash(const char *filename, char *hash_output) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file for hashing");
        strcpy(hash_output, "ERROR");
        return;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;
    unsigned long hash = 5381; // Basis for djb2
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        for (size_t i = 0; i < bytesRead; ++i) {
            hash = ((hash << 5) + hash) + buffer[i]; // hash * 33 + c
        }
    }
    fclose(file);
    sprintf(hash_output, "%lx", hash);
}

// Function to add a file to the linked list
void add_file(const char *filename) {
    FileNode *newNode = malloc(sizeof(FileNode));
    newNode->name = strdup(filename);
    newNode->size = get_file_size(filename);
    compute_hash(filename, newNode->hash);
    newNode->next = head;
    head = newNode;
}

// Function to check if a file should be synchronized
int should_sync(FileNode *file_node, const char *filename) {
    unsigned long current_size = get_file_size(filename);
    char current_hash[HASH_SIZE];
    compute_hash(filename, current_hash);

    return (file_node->size != current_size || strcmp(file_node->hash, current_hash) != 0);
}

// Function to synchronize files from source to destination directory
void sync_files(const char *source_dir, const char *dest_dir) {
    DIR *dir = opendir(source_dir);
    struct dirent *entry;

    if (!dir) {
        perror("Could not open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Check if it is a regular file
            char source_path[BUFFER_SIZE];
            char dest_path[BUFFER_SIZE];

            snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

            FileNode *current = head;
            while (current) {
                if (strcmp(current->name, source_path) == 0) {
                    if (should_sync(current, source_path)) {
                        // Sync the file
                        FILE *src = fopen(source_path, "rb");
                        FILE *dst = fopen(dest_path, "wb");
                        if (src && dst) {
                            unsigned char buffer[BUFFER_SIZE];
                            size_t bytesRead;

                            while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
                                fwrite(buffer, 1, bytesRead, dst);
                            }
                        }
                        fclose(src);
                        fclose(dst);
                    }
                    break;
                }
                current = current->next;
            }
            if (!current) { 
                // File not found in the list, it is new - just copy it
                FILE *src = fopen(source_path, "rb");
                FILE *dst = fopen(dest_path, "wb");
                if (src && dst) {
                    unsigned char buffer[BUFFER_SIZE];
                    size_t bytesRead;

                    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
                        fwrite(buffer, 1, bytesRead, dst);
                    }
                }
                fclose(src);
                fclose(dst);
                add_file(source_path); // Add new file to the list
            }
        }
    }
    closedir(dir);
}

// Function to free the linked list
void free_file_list() {
    FileNode *current = head;
    while (current) {
        FileNode *temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source-directory> <destination-directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sync_files(argv[1], argv[2]);
    free_file_list();

    return EXIT_SUCCESS;
}