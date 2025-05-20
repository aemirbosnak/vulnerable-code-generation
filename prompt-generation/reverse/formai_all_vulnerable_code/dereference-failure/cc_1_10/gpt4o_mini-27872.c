//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024
#define BLOCK_SIZE 512

// Structure to hold the information of a directory
typedef struct DiskInfo {
    char path[MAX_PATH_LENGTH];
    unsigned long total_blocks;
    unsigned long free_blocks;
    unsigned long used_blocks;
    struct DiskInfo *next;
} DiskInfo;

// Function to get disk usage statistics of a specific path
void get_disk_usage(DiskInfo *disk_info) {
    struct statvfs stat;
    
    if (statvfs(disk_info->path, &stat) != 0) {
        perror("statvfs error");
        return;
    }

    disk_info->total_blocks = stat.f_blocks * (stat.f_frsize / BLOCK_SIZE);
    disk_info->free_blocks = stat.f_bfree * (stat.f_frsize / BLOCK_SIZE);
    disk_info->used_blocks = disk_info->total_blocks - disk_info->free_blocks;
}

// Function to create and initialize a new DiskInfo node
DiskInfo *create_disk_info(const char *path) {
    DiskInfo *new_disk_info = malloc(sizeof(DiskInfo));
    if (new_disk_info == NULL) {
        perror("Memory allocation error");
        return NULL;
    }
    strncpy(new_disk_info->path, path, MAX_PATH_LENGTH);
    new_disk_info->path[MAX_PATH_LENGTH - 1] = '\0'; // Ensure null termination
    new_disk_info->next = NULL;
    return new_disk_info;
}

// Function to append disk info nodes to the linked list
void append_disk_info(DiskInfo **head, DiskInfo *new_disk_info) {
    if (*head == NULL) {
        *head = new_disk_info;
    } else {
        DiskInfo *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_disk_info;
    }
}

// Function to display disk usage details
void display_disk_usage(DiskInfo *disk_info) {
    while (disk_info != NULL) {
        printf("Path: %s\n", disk_info->path);
        printf("Total Blocks: %lu\n", disk_info->total_blocks);
        printf("Used Blocks: %lu\n", disk_info->used_blocks);
        printf("Free Blocks: %lu\n", disk_info->free_blocks);
        printf("\n");
        disk_info = disk_info->next;
    }
}

// Recursively visit directories and gather disk usage details
void analyze_directory(const char *dir_path, DiskInfo **list_head) {
    DIR *dir = opendir(dir_path);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Couldn't open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Skip current and parent directory entries
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char full_path[MAX_PATH_LENGTH];
                snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
                DiskInfo *new_info = create_disk_info(full_path);
                if (new_info != NULL) {
                    append_disk_info(list_head, new_info);
                    analyze_directory(full_path, list_head);
                }
            }
        }
    }
    
    closedir(dir);
}

// Entry point of the program
int main(int argc, char *argv[]) {
    DiskInfo *disk_info_list = NULL;
    const char *path_to_analyze = (argc > 1) ? argv[1] : "."; // Default to current directory if none provided

    analyze_directory(path_to_analyze, &disk_info_list);
    
    DiskInfo *current = disk_info_list;
    while (current != NULL) {
        get_disk_usage(current);
        current = current->next;
    }

    printf("Disk Space Analysis for: %s\n", path_to_analyze);
    printf("===================================\n");
    display_disk_usage(disk_info_list);

    // Free memory
    while (disk_info_list != NULL) {
        DiskInfo *temp = disk_info_list;
        disk_info_list = disk_info_list->next;
        free(temp);
    }

    return 0;
}