//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 50
#define MAX_FILE_SIZE 100

typedef struct {
    char name[MAX_FILE_NAME];
    char content[MAX_FILE_SIZE];
    int size;
} File;

File files[MAX_FILES];
int num_files;

void create_file(char* name) {
    strcpy(files[num_files].name, name);
    strcpy(files[num_files].content, "");
    files[num_files].size = 0;
    num_files++;
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(&files[i], 0, sizeof(File));
            num_files--;
            break;
        }
    }
}

void rename_file(char* old_name, char* new_name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, old_name) == 0) {
            strcpy(files[i].name, new_name);
            break;
        }
    }
}

void write_to_file(char* name, char* content) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(files[i].content, content);
            files[i].size = strlen(content);
            break;
        }
    }
}

void read_from_file(char* name, char* content) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(content, files[i].content);
            break;
        }
    }
}

void list_files() {
    int i;
    printf("Files:\n");
    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    srand(time(NULL));
    create_file("test.txt");
    write_to_file("test.txt", "Hello, world!");
    read_from_file("test.txt", "content");
    printf("%s\n", "content");
    rename_file("test.txt", "hello.txt");
    list_files();
    delete_file("hello.txt");
    list_files();
    return 0;
}