//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME 50

typedef struct {
    char name[MAX_FILENAME];
    int size; // Size in bytes
    char content[256];
} File;

typedef struct {
    char name[MAX_FILENAME];
    File *files[MAX_FILES];
    int file_count;
} Directory;

Directory *create_directory(const char *name) {
    Directory *dir = (Directory *)malloc(sizeof(Directory));
    strncpy(dir->name, name, MAX_FILENAME);
    dir->file_count = 0;
    return dir;
}

File *create_file(const char *name, int size, const char *content) {
    File *file = (File *)malloc(sizeof(File));
    strncpy(file->name, name, MAX_FILENAME);
    file->size = size;
    strncpy(file->content, content, sizeof(file->content));
    return file;
}

void add_file_to_directory(Directory *dir, File *file) {
    if (dir->file_count < MAX_FILES) {
        dir->files[dir->file_count++] = file;
    } else {
        printf("Oh dear! The directory \"%s\" is full!\n", dir->name);
    }
}

void list_files(Directory *dir) {
    printf("In the realm of \"%s\" are the following scrolls:\n", dir->name);
    for (int i = 0; i < dir->file_count; i++) {
        printf("  - %s (Size: %d bytes)\n", dir->files[i]->name, dir->files[i]->size);
    }
}

void read_file(File *file) {
    printf("Behold the content of the file \"%s\":\n", file->name);
    printf("%s\n", file->content);
}

void free_directory(Directory *dir) {
    for (int i = 0; i < dir->file_count; i++) {
        free(dir->files[i]);
    }
    free(dir);
}

int main() {
    printf("In fair Verona, where we lay our scene...\n");

    // Creating a directory for our star-crossed lovers
    Directory *loveLetters = create_directory("Love Letters");

    // Creating files with the musings of the lovers
    File *letter1 = create_file("Letter to Juliet", 150, "O my love, my heart is bound to thine.");
    File *letter2 = create_file("Letter from Romeo", 160, "To be or not to be, that is the question.");

    // Adding files to the directory
    add_file_to_directory(loveLetters, letter1);
    add_file_to_directory(loveLetters, letter2);

    // Elizabeth's frantic realization
    list_files(loveLetters);

    // Reading the letters aloud
    read_file(letter1);
    read_file(letter2);

    // As the evening fades, the directory closure must happen
    free_directory(loveLetters);

    printf("Thus concludes the tale of love eternal...\n");
    return 0;
}