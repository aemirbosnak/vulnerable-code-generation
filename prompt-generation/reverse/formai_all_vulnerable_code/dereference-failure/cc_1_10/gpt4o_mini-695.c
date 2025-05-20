//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_VIRUS_SIGN 10
#define MAX_FILENAME 256

// Example signatures of common viruses (for demonstration purposes)
const char *virus_signatures[MAX_VIRUS_SIGN] = {
    "EICAR",
    "CLEAN_ME",
    "VIRUS_1",
    "DANGEROUS_CODE",
    "TOXIC",
    "INFECTED_FILE",
    "BADBYTE",
    "PAYLOAD",
    "POTENTIAL_HAZARD",
    "MALWARE_SIGNATURE"
};

typedef struct FileNode {
    char path[MAX_PATH];
    struct FileNode *next;
} FileNode;

FileNode *head = NULL;

// Function prototypes
void scan_directory(const char *path);
void check_file_for_viruses(const char *filepath);
void add_to_file_list(const char *path);
void display_file_list();

int main(int argc, char *argv[]) {
    char *directory = ".";
    
    if (argc > 1) {
        directory = argv[1];
    }
    
    printf("Starting antivirus scan on directory: %s\n", directory);
    scan_directory(directory);
    display_file_list();
    
    return 0;
}

void scan_directory(const char *path) {
    DIR *dir;
    struct dirent *entry;
    
    if ((dir = opendir(path)) == NULL) {
        perror("Failed to open directory");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries '.' and '..'
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullpath[MAX_PATH];
            snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
            
            struct stat file_stat;
            if (stat(fullpath, &file_stat) == 0) {
                if (S_ISDIR(file_stat.st_mode)) {
                    // If it's a directory, recurse into it
                    scan_directory(fullpath);
                } else {
                    // If it's a file, check for viruses
                    check_file_for_viruses(fullpath);
                }
            } else {
                perror("Failed to get file status");
            }
        }
    }
    
    closedir(dir);
}

void check_file_for_viruses(const char *filepath) {
    FILE *file;
    char buffer[1024];
    int found = 0;
    
    if ((file = fopen(filepath, "r")) == NULL) {
        perror("Failed to open file");
        return;
    }
    
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        for (int i = 0; i < MAX_VIRUS_SIGN; i++) {
            if (strstr(buffer, virus_signatures[i]) != NULL) {
                printf("Virus found in file: %s (Signature: %s)\n", filepath, virus_signatures[i]);
                found = 1;
                break;
            }
        }
    }
    
    fclose(file);
    
    if (!found) {
        add_to_file_list(filepath);
    }
}

void add_to_file_list(const char *path) {
    FileNode *new_node = (FileNode *)malloc(sizeof(FileNode));
    if (!new_node) {
        perror("Failed to allocate memory");
        return;
    }
    strncpy(new_node->path, path, MAX_PATH);
    new_node->next = head;
    head = new_node;
}

void display_file_list() {
    if (head == NULL) {
        printf("No clean files found or all files are infected.\n");
        return;
    }
    
    printf("List of clean files:\n");
    FileNode *current = head;
    while (current != NULL) {
        printf("- %s\n", current->path);
        current = current->next;
    }
}

// Cleanup function to free the linked list
void free_file_list() {
    FileNode *current = head;
    FileNode *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}