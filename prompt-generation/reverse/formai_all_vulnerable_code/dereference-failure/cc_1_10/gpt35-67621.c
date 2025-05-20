//FormAI DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

typedef struct node {
  char* path;
  struct node* next;
} node;

// Returns the size (in bytes) of a file
int get_file_size(char* path) {
  struct stat st;
  stat(path, &st);
  return st.st_size;
}

// Returns 1 if two files are identical, 0 otherwise
int compare_files(char* path1, char* path2) {
  if (get_file_size(path1) != get_file_size(path2)) {
    return 0;
  }
  
  int fd1 = open(path1, O_RDONLY);
  int fd2 = open(path2, O_RDONLY);

  char buf1[4096];
  char buf2[4096];

  int num_read1 = 0;
  int num_read2 = 0;
  
  while ((num_read1 = read(fd1, buf1, sizeof(buf1))) && (num_read2 = read(fd2, buf2, sizeof(buf2)))) {
    if (num_read1 != num_read2) {
      return 0;
    }
    if (memcmp(buf1, buf2, num_read1) != 0) {
      return 0;
    }
  }

  close(fd1);
  close(fd2);

  return 1;
}

// Deletes the file at the specified path
void delete_file(char* path) {
  if (unlink(path) == -1) {
    fprintf(stderr, "Error deleting %s: %s \n", path, strerror(errno));
  }
}

// Copies the file at path1 to path2
void copy_file(char* path1, char* path2) {
  int fd1 = open(path1, O_RDONLY);
  int fd2 = open(path2, O_WRONLY | O_CREAT, 0644);

  char buf[4096];
  int num_read = 0;

  while ((num_read = read(fd1, buf, sizeof(buf)))) {
    write(fd2, buf, num_read);
  }

  close(fd1);
  close(fd2);
}

// Adds a node to the end of a linked list of nodes
void add_node(node** list, char* path) {
  node* new_node = malloc(sizeof(node));
  new_node->path = path;
  new_node->next = NULL;

  if (*list == NULL) {
    *list = new_node;
  } else {
    node* curr_node = *list;
    while (curr_node->next != NULL) {
      curr_node = curr_node->next;
    }
    curr_node->next = new_node;
  }
}

// Deletes all nodes in a linked list of nodes
void delete_list(node* list) {
  while (list != NULL) {
    node* next_node = list->next;
    free(list->path);
    free(list);
    list = next_node;
  }
}

// Returns the number of nodes in a linked list of nodes
int get_list_size(node* list) {
  int size = 0;
  while (list != NULL) {
    size++;
    list = list->next;
  }
  return size;
}

// Synchronizes two directories by making sure that all files in dir1 are also in dir2
void synchronize_directories(char* dir1, char* dir2) {
  node* files_in_dir1 = NULL;
  node* files_in_dir2 = NULL;

  // Read all files in dir1 into the files_in_dir1 linked list
  DIR* dp = opendir(dir1);
  if (dp != NULL) {
    struct dirent* de;
    while ((de = readdir(dp))) {
      if (de->d_type == DT_REG) {
        char* path = malloc(strlen(dir1) + strlen(de->d_name) + 2);
        sprintf(path, "%s/%s", dir1, de->d_name);
        add_node(&files_in_dir1, path);
      }
    }
    closedir(dp);
  }

  // Read all files in dir2 into the files_in_dir2 linked list
  dp = opendir(dir2);
  if (dp != NULL) {
    struct dirent* de;
    while ((de = readdir(dp))) {
      if (de->d_type == DT_REG) {
        char* path = malloc(strlen(dir2) + strlen(de->d_name) + 2);
        sprintf(path, "%s/%s", dir2, de->d_name);
        add_node(&files_in_dir2, path);
      }
    }
    closedir(dp);
  }

  node* curr_node1 = files_in_dir1;
  while (curr_node1 != NULL) {
    char* path1 = curr_node1->path;
    int found = 0;

    // Check if file in dir1 is already in dir2
    node* curr_node2 = files_in_dir2;
    while (curr_node2 != NULL) {
      char* path2 = curr_node2->path;
      if (strcmp(path1, path2) == 0) {
        found = 1;

        // Check if files are identical, and copy over if not
        if (!compare_files(path1, path2)) {
          printf("File %s is out of sync\n", path1);
          copy_file(path1, path2);
        }
        
        // Delete the file from files_in_dir2 to mark it as processed
        delete_file(path2);
        if (curr_node2 == files_in_dir2) {
          files_in_dir2 = curr_node2->next;
        } else {
          node* prev_node = files_in_dir2;
          while (prev_node->next != curr_node2) {
            prev_node = prev_node->next;
          }
          prev_node->next = curr_node2->next;
        }
        free(path2);
        free(curr_node2);
        break;
      }
      curr_node2 = curr_node2->next;
    }

    // If file in dir1 was not found in dir2, copy it over
    if (!found) {
      printf("File %s is not in target directory\n", path1);
      char* path2 = malloc(strlen(dir2) + strlen(curr_node1->path) + 2);
      sprintf(path2, "%s/%s", dir2, curr_node1->path + strlen(dir1) + 1);
      copy_file(path1, path2);
      add_node(&files_in_dir2, path2);
    }

    // Delete the file from files_in_dir1 to mark it as processed
    curr_node1 = curr_node1->next;
    free(path1);
    free(files_in_dir1);
    files_in_dir1 = curr_node1;
  }

  // Delete all remaining files in files_in_dir2, since they were not found in dir1
  node* curr_node2 = files_in_dir2;
  while (curr_node2 != NULL) {
    printf("File %s is not in source directory\n", curr_node2->path);
    delete_file(curr_node2->path);
    curr_node2 = curr_node2->next;
    free(curr_node2);
  }

  delete_list(files_in_dir1);
  delete_list(files_in_dir2);
}

int main(int argc, char** argv) {
  // Check that two directories were provided
  if (argc < 3) {
    fprintf(stderr, "Error: Usage: %s <dir1> <dir2>\n", argv[0]);
    exit(1);
  }

  synchronize_directories(argv[1], argv[2]);

  return 0;
}