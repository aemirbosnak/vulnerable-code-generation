//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum size of a file system object
#define MAX_OBJECT_SIZE 1024

// Define the maximum number of file system objects
#define MAX_OBJECTS 100

// Define the file system object types
typedef enum {
  FS_FILE,
  FS_DIRECTORY
} fs_object_type;

// Define the file system object structure
typedef struct {
  fs_object_type type;
  char *name;
  int size;
  time_t created;
  time_t modified;
} fs_object;

// Define the file system structure
typedef struct {
  fs_object *objects;
  int num_objects;
} fs;

// Create a new file system
fs *fs_new() {
  fs *fs = malloc(sizeof(fs));
  fs->objects = malloc(sizeof(fs_object) * MAX_OBJECTS);
  fs->num_objects = 0;
  return fs;
}

// Free a file system
void fs_free(fs *fs) {
  for (int i = 0; i < fs->num_objects; i++) {
    free(fs->objects[i].name);
  }
  free(fs->objects);
  free(fs);
}

// Add a file to the file system
int fs_add_file(fs *fs, char *name, int size) {
  if (fs->num_objects >= MAX_OBJECTS) {
    return -1;
  }

  fs_object *object = &fs->objects[fs->num_objects];
  object->type = FS_FILE;
  object->name = strdup(name);
  object->size = size;
  object->created = time(NULL);
  object->modified = time(NULL);

  fs->num_objects++;

  return 0;
}

// Add a directory to the file system
int fs_add_directory(fs *fs, char *name) {
  if (fs->num_objects >= MAX_OBJECTS) {
    return -1;
  }

  fs_object *object = &fs->objects[fs->num_objects];
  object->type = FS_DIRECTORY;
  object->name = strdup(name);
  object->size = 0;
  object->created = time(NULL);
  object->modified = time(NULL);

  fs->num_objects++;

  return 0;
}

// Find a file or directory in the file system
fs_object *fs_find(fs *fs, char *name) {
  for (int i = 0; i < fs->num_objects; i++) {
    fs_object *object = &fs->objects[i];
    if (strcmp(object->name, name) == 0) {
      return object;
    }
  }

  return NULL;
}

// Print the file system
void fs_print(fs *fs) {
  for (int i = 0; i < fs->num_objects; i++) {
    fs_object *object = &fs->objects[i];
    switch (object->type) {
      case FS_FILE:
        printf("%s (file, %d bytes)\n", object->name, object->size);
        break;
      case FS_DIRECTORY:
        printf("%s (directory)\n", object->name);
        break;
    }
  }
}

// Main function
int main() {
  // Create a new file system
  fs *fs = fs_new();

  // Add some files and directories to the file system
  fs_add_file(fs, "file1.txt", 1024);
  fs_add_file(fs, "file2.txt", 2048);
  fs_add_directory(fs, "directory1");
  fs_add_file(fs, "directory1/file3.txt", 4096);

  // Print the file system
  fs_print(fs);

  // Free the file system
  fs_free(fs);

  return 0;
}