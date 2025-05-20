//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a file system object (file or directory)
#define MAX_OBJECT_SIZE 1024

// Define the maximum number of file system objects
#define MAX_OBJECTS 100

// Define the maximum number of characters in a file system object name
#define MAX_OBJECT_NAME_LENGTH 32

// Define the file system object types
typedef enum {
  FILE_TYPE,
  DIRECTORY_TYPE
} object_type_t;

// Define the file system object structure
typedef struct {
  char name[MAX_OBJECT_NAME_LENGTH];
  object_type_t type;
  size_t size;
  char data[MAX_OBJECT_SIZE];
} object_t;

// Define the file system structure
typedef struct {
  object_t objects[MAX_OBJECTS];
  int num_objects;
} file_system_t;

// Create a new file system
file_system_t *create_file_system() {
  file_system_t *fs = malloc(sizeof(file_system_t));
  if (fs == NULL) {
    return NULL;
  }

  fs->num_objects = 0;

  return fs;
}

// Destroy a file system
void destroy_file_system(file_system_t *fs) {
  if (fs == NULL) {
    return;
  }

  free(fs);
}

// Create a new file system object
object_t *create_object(const char *name, object_type_t type, size_t size) {
  object_t *obj = malloc(sizeof(object_t));
  if (obj == NULL) {
    return NULL;
  }

  strncpy(obj->name, name, MAX_OBJECT_NAME_LENGTH);
  obj->type = type;
  obj->size = size;

  return obj;
}

// Destroy a file system object
void destroy_object(object_t *obj) {
  if (obj == NULL) {
    return;
  }

  free(obj);
}

// Add a file system object to the file system
int add_object_to_file_system(file_system_t *fs, object_t *obj) {
  if (fs == NULL || obj == NULL) {
    return -1;
  }

  if (fs->num_objects >= MAX_OBJECTS) {
    return -1;
  }

  fs->objects[fs->num_objects++] = *obj;

  return 0;
}

// Remove a file system object from the file system
int remove_object_from_file_system(file_system_t *fs, object_t *obj) {
  if (fs == NULL || obj == NULL) {
    return -1;
  }

  for (int i = 0; i < fs->num_objects; i++) {
    if (strcmp(fs->objects[i].name, obj->name) == 0) {
      fs->objects[i] = fs->objects[fs->num_objects - 1];
      fs->num_objects--;
      return 0;
    }
  }

  return -1;
}

// Get a file system object by name
object_t *get_object_from_file_system(file_system_t *fs, const char *name) {
  if (fs == NULL || name == NULL) {
    return NULL;
  }

  for (int i = 0; i < fs->num_objects; i++) {
    if (strcmp(fs->objects[i].name, name) == 0) {
      return &fs->objects[i];
    }
  }

  return NULL;
}

// Print the file system
void print_file_system(file_system_t *fs) {
  if (fs == NULL) {
    return;
  }

  for (int i = 0; i < fs->num_objects; i++) {
    printf("%s (%s, %lu bytes)\n", fs->objects[i].name,
           fs->objects[i].type == FILE_TYPE ? "file" : "directory",
           fs->objects[i].size);
  }
}

int main() {
  // Create a new file system
  file_system_t *fs = create_file_system();
  if (fs == NULL) {
    return -1;
  }

  // Add some objects to the file system
  object_t *obj1 = create_object("file1", FILE_TYPE, 1024);
  if (obj1 == NULL) {
    return -1;
  }
  if (add_object_to_file_system(fs, obj1) != 0) {
    return -1;
  }

  object_t *obj2 = create_object("directory1", DIRECTORY_TYPE, 0);
  if (obj2 == NULL) {
    return -1;
  }
  if (add_object_to_file_system(fs, obj2) != 0) {
    return -1;
  }

  object_t *obj3 = create_object("file2", FILE_TYPE, 2048);
  if (obj3 == NULL) {
    return -1;
  }
  if (add_object_to_file_system(fs, obj3) != 0) {
    return -1;
  }

  // Print the file system
  print_file_system(fs);

  // Destroy the file system
  destroy_file_system(fs);

  return 0;
}