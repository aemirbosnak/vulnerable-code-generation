//FormAI DATASET v1.0 Category: File system simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct {
    char* name;
    int size;
    char* data;
} file;

typedef struct {
    char* name;
    file* files[MAX_FILES];
    int num_files;
} folder;

typedef struct {
    folder* current_folder;
} file_system;

int count_chars(char* string, char target) {
    int count = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == target) {
            count++;
        }
    }
    return count;
}

void print_folder(folder* current_folder) {
    printf("Folder: %s\n", current_folder->name);
    printf("Files (%d/%d):\n", current_folder->num_files, MAX_FILES);
    for (int i = 0; i < current_folder->num_files; i++) {
        printf("- %s (%d bytes)\n", current_folder->files[i]->name, current_folder->files[i]->size);
    }
}

void create_file(file_system *fs, char* file_str) {
    char file_name[50];
    int file_size;
    sscanf(file_str, "%s %d", file_name, &file_size);

    // check if file already exists
    if (fs->current_folder->num_files >= MAX_FILES) {
        printf("Can't create file: Folder is full\n");
        return;
    }
    for (int i = 0; i < fs->current_folder->num_files; i++) {
        if (strcmp(fs->current_folder->files[i]->name, file_name) == 0) {
            printf("Can't create file: File already exists\n");
            return;
        }
    }

    // create the file
    file* new_file = malloc(sizeof(file));
    new_file->name = malloc(strlen(file_name) + 1);
    new_file->size = file_size;
    new_file->data = malloc(file_size + 1);
    memset(new_file->data, 0, file_size + 1);
    strcpy(new_file->name, file_name);

    // add file to folder
    fs->current_folder->files[fs->current_folder->num_files++] = new_file;
    printf("File created successfully\n");
}

void write_file(file_system* fs, char* file_str) {
    char file_name[50];
    int file_offset, data_len;
    sscanf(file_str, "%s %d %d", file_name, &file_offset, &data_len);

    // find the file
    int file_index = -1;
    for (int i = 0; i < fs->current_folder->num_files; i++) {
        if (strcmp(fs->current_folder->files[i]->name, file_name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index < 0) {
        printf("Can't write file: File not found\n");
        return;
    }

    // check data length
    if ((file_offset + data_len) > fs->current_folder->files[file_index]->size) {
        printf("Can't write file: Not enough space in file\n");
        return;
    }

    // copy data into file
    char* file_data = fs->current_folder->files[file_index]->data;
    char* new_data = malloc(strlen(file_data) + data_len + 1);
    memset(new_data, 0, strlen(file_data) + data_len + 1);
    memcpy(new_data, file_data, file_offset);
    memcpy(new_data + file_offset, &file_str[strlen(file_name)], data_len);
    memcpy(new_data + file_offset + data_len, file_data + file_offset + data_len, strlen(file_data) - file_offset - data_len + 1);
    free(file_data);
    fs->current_folder->files[file_index]->data = new_data;
    printf("%d bytes written to file\n", data_len);
}

void read_file(file_system* fs, char* file_name) {
    // find the file
    int file_index = -1;
    for (int i = 0; i < fs->current_folder->num_files; i++) {
        if (strcmp(fs->current_folder->files[i]->name, file_name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index < 0) {
        printf("Can't read file: File not found\n");
        return;
    }

    // print file contents
    char* file_data = fs->current_folder->files[file_index]->data;
    printf("File contents:\n---\n%s\n---\n", file_data);
}

void move_folder(file_system* fs, char* folder_name) {
    // find the folder
    folder* new_folder = NULL;
    for (int i = 0; i < fs->current_folder->num_files; i++) {
        if (strcmp(fs->current_folder->files[i]->name, folder_name) == 0 && fs->current_folder->files[i]->data == NULL) {
            new_folder = (folder*)fs->current_folder->files[i];
            break;
        }
    }
    if (new_folder == NULL) {
        printf("Can't move folder: Folder not found\n");
        return;
    }

    // move to the new folder
    fs->current_folder = new_folder;
    printf("Moved to folder: %s\n", new_folder->name);
}

void create_folder(file_system* fs, char* folder_name) {
    // check if folder already exists
    for (int i = 0; i < fs->current_folder->num_files; i++) {
        if (strcmp(fs->current_folder->files[i]->name, folder_name) == 0 && fs->current_folder->files[i]->data == NULL) {
            printf("Can't create folder: Folder already exists\n");
            return;
        }
    }

    // create the folder
    folder* new_folder = malloc(sizeof(folder));
    new_folder->name = malloc(strlen(folder_name) + 1);
    new_folder->num_files = 0;
    memset(new_folder->files, 0, sizeof(new_folder->files));
    strcpy(new_folder->name, folder_name);

    // add the folder to the current folder
    if (fs->current_folder->num_files >= MAX_FILES) {
        printf("Can't create folder: Folder is full\n");
        free(new_folder);
        return;
    }
    fs->current_folder->files[fs->current_folder->num_files++] = (file*)new_folder;
    printf("Folder created successfully\n");
}

int main() {
    // create the root folder
    folder* root_folder = malloc(sizeof(folder));
    root_folder->name = "root";
    root_folder->num_files = 0;
    memset(root_folder->files, 0, sizeof(root_folder->files));

    // create the file system
    file_system* fs = malloc(sizeof(file_system));
    fs->current_folder = root_folder;

    // start the loop
    char line[100];
    while (1) {
        printf("> ");
        fgets(line, sizeof(line), stdin);

        // remove trailing newline
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // check the command
        if (strncmp(line, "create ", 7) == 0) {
            create_file(fs, &line[7]);
        } else if (strncmp(line, "write ", 6) == 0) {
            write_file(fs, &line[6]);
        } else if (strncmp(line, "read ", 5) == 0) {
            read_file(fs, &line[5]);
        } else if (strncmp(line, "mkdir ", 6) == 0) {
            create_folder(fs, &line[6]);
        } else if (strncmp(line, "cd ", 3) == 0) {
            move_folder(fs, &line[3]);
        } else if (strcmp(line, "ls") == 0) {
            print_folder(fs->current_folder);
        } else if (strcmp(line, "exit") == 0) {
            printf("Goodbye\n");
            break;
        } else {
            printf("Unknown command: %s\n", line);
        }
    }

    // clean up
    free(root_folder);
    free(fs);

    return 0;
}