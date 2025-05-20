//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Data structure to store the directory and file sizes
typedef struct Directory {
  char *name;
  unsigned long long size;
  struct Directory *next;
} Directory;

// Function to get the file size
unsigned long long get_file_size(const char *path) {
  struct stat statbuf;
  if (stat(path, &statbuf) == -1) {
    return 0;
  }
  return statbuf.st_size;
}

// Function to get the directory size
unsigned long long get_directory_size(const char *path) {
  DIR *dir;
  struct dirent *entry;
  unsigned long long total_size = 0;

  dir = opendir(path);
  if (dir == NULL) {
    return 0;
  }

  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
    sprintf(full_path, "%s/%s", path, entry->d_name);

    if (entry->d_type == DT_DIR) {
      total_size += get_directory_size(full_path);
    } else {
      total_size += get_file_size(full_path);
    }

    free(full_path);
  }

  closedir(dir);

  return total_size;
}

// Function to add a directory to the linked list
void add_directory(Directory **head, const char *name, unsigned long long size) {
  Directory *new_directory = malloc(sizeof(Directory));
  new_directory->name = strdup(name);
  new_directory->size = size;
  new_directory->next = *head;
  *head = new_directory;
}

// Function to print the linked list of directories
void print_directories(Directory *head) {
  while (head != NULL) {
    printf("%s: %llu bytes\n", head->name, head->size);
    head = head->next;
  }
}

// Function to free the linked list of directories
void free_directories(Directory *head) {
  while (head != NULL) {
    Directory *next = head->next;
    free(head->name);
    free(head);
    head = next;
  }
}

int main() {
  // Get the root directory size
  unsigned long long root_size = get_directory_size("/");

  // Create a linked list of directories
  Directory *head = NULL;

  // Add the root directory to the linked list
  add_directory(&head, "/", root_size);

  // Print the linked list of directories
  print_directories(head);

  // Free the linked list of directories
  free_directories(head);

  return 0;
}