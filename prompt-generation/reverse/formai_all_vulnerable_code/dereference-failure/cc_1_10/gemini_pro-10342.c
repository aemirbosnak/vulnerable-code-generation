//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

// Structure to store file information
typedef struct file_info {
    char *name;
    long size;
    struct file_info *next;
} file_info;

// Function to get the size of a file
long get_file_size(char *file_name) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    return size;
}

// Function to add a file to the linked list
void add_file(file_info **head, char *name, long size) {
    file_info *new_file = malloc(sizeof(file_info));
    new_file->name = name;
    new_file->size = size;
    new_file->next = *head;
    *head = new_file;
}

// Function to print the linked list of files
void print_list(file_info *head) {
    file_info *curr = head;
    while (curr != NULL) {
        printf("%s: %ld bytes\n", curr->name, curr->size);
        curr = curr->next;
    }
}

// Function to scan a directory and add all files to the linked list
void scan_dir(char *dir_name, file_info **head) {
    DIR *dir = opendir(dir_name);
    if (dir == NULL) {
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Recursively scan subdirectories
            char *sub_dir_name = malloc(strlen(dir_name) + strlen(entry->d_name) + 2);
            sprintf(sub_dir_name, "%s/%s", dir_name, entry->d_name);
            scan_dir(sub_dir_name, head);
            free(sub_dir_name);
        } else {
            // Add files to the linked list
            char *file_name = malloc(strlen(dir_name) + strlen(entry->d_name) + 1);
            sprintf(file_name, "%s/%s", dir_name, entry->d_name);
            long size = get_file_size(file_name);
            if (size >= 0) {
                add_file(head, file_name, size);
            }
            free(file_name);
        }
    }
    closedir(dir);
}

int main() {
    // Scan the current directory
    file_info *head = NULL;
    scan_dir(".", &head);

    // Sort the linked list by file size
    file_info *sorted_head = NULL;
    file_info *curr = head;
    while (curr != NULL) {
        // Find the correct position for the current file in the sorted list
        file_info *prev = NULL;
        file_info *next = sorted_head;
        while (next != NULL && curr->size > next->size) {
            prev = next;
            next = next->next;
        }

        // Insert the current file into the sorted list
        if (prev == NULL) {
            sorted_head = curr;
        } else {
            prev->next = curr;
        }
        curr->next = next;

        // Move to the next file in the original list
        curr = curr->next;
    }

    // Print the sorted linked list of files
    print_list(sorted_head);

    return 0;
}