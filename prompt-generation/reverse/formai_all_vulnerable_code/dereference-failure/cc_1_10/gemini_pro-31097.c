//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct file_system {
    char *name;
    int size;
    char *type;
    char *data;
};

struct directory {
    char *name;
    struct file_system *files[100];
    int num_files;
};

struct disk {
    struct directory *directories[100];
    int num_directories;
};

struct disk disk;

void create_disk() {
    disk.num_directories = 0;
}

void create_directory(char *name) {
    struct directory *directory = malloc(sizeof(struct directory));
    directory->name = strdup(name);
    directory->num_files = 0;
    disk.directories[disk.num_directories++] = directory;
}

void create_file(char *name, int size, char *type, char *data) {
    struct file_system *file = malloc(sizeof(struct file_system));
    file->name = strdup(name);
    file->size = size;
    file->type = strdup(type);
    file->data = strdup(data);
    disk.directories[0]->files[disk.directories[0]->num_files++] = file;
}

void ls() {
    for (int i = 0; i < disk.num_directories; i++) {
        printf("Directory: %s\n", disk.directories[i]->name);
        for (int j = 0; j < disk.directories[i]->num_files; j++) {
            printf("  File: %s\n", disk.directories[i]->files[j]->name);
        }
    }
}

void cat(char *name) {
    for (int i = 0; i < disk.num_directories; i++) {
        for (int j = 0; j < disk.directories[i]->num_files; j++) {
            if (strcmp(disk.directories[i]->files[j]->name, name) == 0) {
                printf("%s\n", disk.directories[i]->files[j]->data);
                return;
            }
        }
    }
    printf("File not found.\n");
}

int main() {
    create_disk();
    create_directory("My Documents");
    create_file("love.txt", 100, "text", "I love you more than words can say.");
    create_file("our_song.mp3", 10000, "audio", "Our song is the soundtrack to our love.");
    create_file("our_photos.jpg", 100000, "image", "Our photos capture the moments we'll cherish forever.");
    ls();
    cat("love.txt");
    return 0;
}