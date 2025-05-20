//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024*1024*1024) // 1 GB

typedef struct {
    char *filename;
    unsigned char *data;
    size_t size;
} file_t;

typedef struct {
    file_t *files;
    size_t count;
    size_t capacity;
} file_list_t;

void file_list_init(file_list_t *list) {
    list->files = NULL;
    list->count = 0;
    list->capacity = 0;
}

void file_list_add(file_list_t *list, const char *filename, const unsigned char *data, size_t size) {
    if (list->count >= list->capacity) {
        list->capacity += 10;
        list->files = realloc(list->files, sizeof(file_t) * list->capacity);
    }

    file_t *file = &list->files[list->count];
    file->filename = strdup(filename);
    file->data = malloc(size);
    file->size = size;
    memcpy(file->data, data, size);

    list->count++;
}

void file_list_free(file_list_t *list) {
    for (size_t i = 0; i < list->count; i++) {
        free(list->files[i].filename);
        free(list->files[i].data);
    }

    free(list->files);
}

void file_list_print(const file_list_t *list) {
    for (size_t i = 0; i < list->count; i++) {
        printf("Filename: %s\nSize: %zu bytes\n", list->files[i].filename, list->files[i].size);
    }
}

int main() {
    file_list_t list;
    file_list_init(&list);

    // Example usage
    file_list_add(&list, "example.txt", "Hello, world!", 13);
    file_list_add(&list, "example2.txt", "This is an example file.", 28);

    file_list_print(&list);

    return 0;
}