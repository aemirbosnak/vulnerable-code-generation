//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define MAX_LEVEL 100
#define MAX_PATH 256

// Structure to hold information about a directory or a file
typedef struct node {
    char name[MAX_PATH];
    off_t size;
    struct node* next;
} Node;

// Recursive function to scan a directory and get the total size of its files
void scan_dir(char* path, Node** head, int level) {
    DIR *d = opendir(path);
    struct dirent *dir;
    struct stat st;

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            char name[MAX_PATH], full_path[MAX_PATH];
            memset(full_path, 0, sizeof(full_path));

            // Skip hidden files and directories
            if (dir->d_name[0] == '.') {
                continue;
            }

            strcpy(name, dir->d_name);
            sprintf(full_path, "%s/%s", path, name);

            if (stat(full_path, &st) == 0) {
                // Check if we have a directory
                if (S_ISDIR(st.st_mode)) {
                    if (level < MAX_LEVEL) {
                        scan_dir(full_path, head, level + 1);
                    }
                } else {
                    // Allocate memory and insert file information to linked list 
                    Node* new_node = malloc(sizeof(Node));
                    strcpy(new_node->name, name);
                    new_node->size = st.st_size;

                    Node* curr = *head;

                    if (curr == NULL) {
                        *head = new_node;
                    } else {
                        while (curr->next) {
                            curr = curr->next;
                        }
                        curr->next = new_node;
                    }
                }
            }
        }
        closedir(d);
    }
}

// Function to print out the list of directories and files with their sizes
void print_list(Node* head) {
    Node* curr = head;

    while (curr) {
        printf("%-30s %ld bytes\n", curr->name, curr->size);
        curr = curr->next;
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* path = argv[1];
    Node* head = NULL;

    scan_dir(path, &head, 0);
    print_list(head);

    Node* curr = head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    
    return 0;
}