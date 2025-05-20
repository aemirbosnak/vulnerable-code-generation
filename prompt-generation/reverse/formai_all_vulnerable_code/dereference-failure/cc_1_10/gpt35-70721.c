//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>

// Structure to store file details
struct file {
    char *name;
    char *path;
    struct stat *st;
};

// Structure to store list of files
struct file_list {
    struct file f;
    struct file_list *next;
};

// Global variables
struct file_list *source_list = NULL, *target_list = NULL;
pthread_mutex_t source_lock = PTHREAD_MUTEX_INITIALIZER, target_lock = PTHREAD_MUTEX_INITIALIZER;

// Function declarations
void *sync_files(void *arg);
void add_file(struct file_list **head, char *name, char *path, struct stat *st);
void display_files(struct file_list *head);
void free_list(struct file_list *head);

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_directory target_directory\n", argv[0]);
        exit(1);
    }

    DIR *source_dir, *target_dir;
    struct dirent *entry;
    struct stat st;
    char source_path[1024], target_path[1024];

    // Open source and target directories
    if ((source_dir = opendir(argv[1])) == NULL) {
        perror("opendir");
        exit(1);
    }
    if ((target_dir = opendir(argv[2])) == NULL) {
        perror("opendir");
        exit(1);
    }

    // Initialize thread variables
    pthread_t threads[100];
    int thread_count = 0;

    // Read files from source directory
    while ((entry = readdir(source_dir)) != NULL) {
        if (entry->d_name[0] == '.') continue;

        sprintf(source_path, "%s/%s", argv[1], entry->d_name);
        if (stat(source_path, &st) == -1) continue;

        add_file(&source_list, entry->d_name, source_path, &st);
    }

    // Read files from target directory
    while ((entry = readdir(target_dir)) != NULL) {
        if (entry->d_name[0] == '.') continue;

        sprintf(target_path, "%s/%s", argv[2], entry->d_name);
        if (stat(target_path, &st) == -1) continue;

        add_file(&target_list, entry->d_name, target_path, &st);
    }

    // Display all source files
    printf("Source files:\n");
    display_files(source_list);
    printf("\n");

    // Display all target files
    printf("Target files:\n");
    display_files(target_list);
    printf("\n");

    // Synchronize source and target files
    struct file_list *curr = source_list;
    while (curr != NULL) {
        // Check if source file exists in target
        struct file_list *target_file = target_list;
        while (target_file != NULL) {
            if (strcmp(curr->f.name, target_file->f.name) == 0) {
                // Check if source file is newer than target file
                if (curr->f.st->st_mtime > target_file->f.st->st_mtime) {
                    printf("Synchronizing %s...\n", curr->f.name);

                    // Create thread to synchronize files
                    pthread_create(&threads[thread_count], NULL, sync_files, curr);
                    thread_count++;
                }
                break;
            }
            target_file = target_file->next;
        }
        curr = curr->next;
    }

    // Wait for all threads to complete
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    free_list(source_list);
    free_list(target_list);
    closedir(source_dir);
    closedir(target_dir);

    return 0;
}

// Function to synchronize files
void *sync_files(void *arg) {
    struct file_list *source_file = (struct file_list *)arg;
    struct file_list *target_file = target_list;

    // Search for matching file in target list
    while (target_file != NULL) {
        if (strcmp(source_file->f.name, target_file->f.name) == 0) {
            // Lock target file
            pthread_mutex_lock(&target_lock);

            // Remove target file
            if (remove(target_file->f.path) == -1) {
                perror("remove");
                exit(1);
            }

            // Copy source file to target
            if (link(source_file->f.path, target_file->f.path) == -1) {
                perror("link");
                exit(1);
            }

            // Update target file stats
            if (stat(target_file->f.path, target_file->f.st) == -1) {
                perror("stat");
                exit(1);
            }

            // Unlock target file
            pthread_mutex_unlock(&target_lock);

            break;
        }
        target_file = target_file->next;
    }

    return NULL;
}

// Function to add file to list
void add_file(struct file_list **head, char *name, char *path, struct stat *st) {
    struct file_list *new_file = malloc(sizeof(struct file_list));
    new_file->f.name = strdup(name);
    new_file->f.path = strdup(path);
    new_file->f.st = st;
    new_file->next = NULL;

    if (*head == NULL) {
        *head = new_file;
    }
    else {
        struct file_list *curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_file;
    }
}

// Function to display files in list
void display_files(struct file_list *head) {
    while (head != NULL) {
        printf("%s (%li bytes)\n", head->f.name, head->f.st->st_size);
        head = head->next;
    }
}

// Function to free memory used by list
void free_list(struct file_list *head) {
    while (head != NULL) {
        struct file_list *temp = head;
        head = head->next;
        free(temp->f.name);
        free(temp->f.path);
        free(temp->f.st);
        free(temp);
    }
}