//FormAI DATASET v1.0 Category: File system simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_SIZE 1024

// Define the file structure
typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size;
    char* data;
} file_t;

// Define the file system structure
typedef struct {
    file_t** files;
    int num_files;
} file_system_t;

// Forward declarations
void ls(file_system_t* fs);
void create(file_system_t* fs, char* name, char* data);
void read(file_system_t* fs, char* name);
void write(file_system_t* fs, char* name, char* data);
void delete(file_system_t* fs, char* name);
int find_file(file_system_t* fs, char* name);

int main() {
    file_system_t fs;
    fs.files = NULL;
    fs.num_files = 0;

    char cmd[50];
    while (1) {
        printf("Enter a command: ");
        fgets(cmd, 50, stdin);

        // Strip the newline character at the end of the command
        int len = strlen(cmd);
        if (cmd[len - 1] == '\n') {
            cmd[len - 1] = '\0';
        }

        // Parse the command
        char* name = NULL;
        char* data = NULL;
        char* ptr = strtok(cmd, " ");
        if (strcmp(ptr, "ls") == 0) {
            ls(&fs);
        } else if (strcmp(ptr, "create") == 0) {
            name = strtok(NULL, " ");
            data = strtok(NULL, "");
            create(&fs, name, data);
        } else if (strcmp(ptr, "read") == 0) {
            name = strtok(NULL, "");
            read(&fs, name);
        } else if (strcmp(ptr, "write") == 0) {
            name = strtok(NULL, " ");
            data = strtok(NULL, "");
            write(&fs, name, data);
        } else if (strcmp(ptr, "delete") == 0) {
            name = strtok(NULL, "");
            delete(&fs, name);
        } else if (strcmp(ptr, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    // Free the memory used by the files
    for (int i = 0; i < fs.num_files; i++) {
        free(fs.files[i]->data);
        free(fs.files[i]);
    }
    free(fs.files);

    return 0;
}

void ls(file_system_t* fs) {
    printf("Files:\n");
    for (int i = 0; i < fs->num_files; i++) {
        printf("%s (%d bytes)\n", fs->files[i]->name, fs->files[i]->size);
    }
}

void create(file_system_t* fs, char* name, char* data) {
    // Check if the file already exists
    int idx = find_file(fs, name);
    if (idx != -1) {
        printf("%s already exists\n", name);
        return;
    }

    // Create the file
    file_t* file = malloc(sizeof(file_t));
    strcpy(file->name, name);
    file->size = strlen(data) + 1;
    file->data = malloc(file->size);
    strcpy(file->data, data);

    // Add the file to the file system
    fs->files = realloc(fs->files, (fs->num_files + 1) * sizeof(file_t*));
    fs->files[fs->num_files] = file;
    fs->num_files++;
}

void read(file_system_t* fs, char* name) {
    // Find the file
    int idx = find_file(fs, name);
    if (idx == -1) {
        printf("%s does not exist\n", name);
        return;
    }

    // Print the contents of the file
    printf("%s contents:\n%s\n", name, fs->files[idx]->data);
}

void write(file_system_t* fs, char* name, char* data) {
    // Find the file
    int idx = find_file(fs, name);
    if (idx == -1) {
        printf("%s does not exist\n", name);
        return;
    }

    // Update the data in the file
    strcpy(fs->files[idx]->data, data);
    fs->files[idx]->size = strlen(data) + 1;
}

void delete(file_system_t* fs, char* name) {
    // Find the file
    int idx = find_file(fs, name);
    if (idx == -1) {
        printf("%s does not exist\n", name);
        return;
    }

    // Free the memory used by the file
    free(fs->files[idx]->data);
    free(fs->files[idx]);

    // Remove the file from the file system
    for (int i = idx; i < fs->num_files - 1; i++) {
        fs->files[i] = fs->files[i + 1];
    }
    fs->num_files--;
    fs->files = realloc(fs->files, fs->num_files * sizeof(file_t*));
}

int find_file(file_system_t* fs, char* name) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            return i;
        }
    }
    return -1;
}