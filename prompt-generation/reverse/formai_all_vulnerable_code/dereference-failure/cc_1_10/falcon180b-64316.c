//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10MB
#define SYNC_INTERVAL 5000 // 5 seconds

typedef struct {
    char name[256];
    char path[256];
    int size;
    int last_synced;
} file_t;

typedef struct {
    int num_files;
    file_t *files;
} sync_t;

sync_t *sync_init() {
    sync_t *s = malloc(sizeof(sync_t));
    s->num_files = 0;
    s->files = NULL;
    return s;
}

void sync_add_file(sync_t *s, char *name, char *path, int size) {
    file_t *f = malloc(sizeof(file_t));
    strncpy(f->name, name, 256);
    strncpy(f->path, path, 256);
    f->size = size;
    f->last_synced = 0;
    s->files = realloc(s->files, sizeof(file_t) * ++s->num_files);
    s->files[s->num_files - 1] = *f;
    free(f);
}

void sync_remove_file(sync_t *s, int index) {
    s->num_files--;
    s->files = realloc(s->files, sizeof(file_t) * s->num_files);
}

void sync_update_file(sync_t *s, int index, int size) {
    s->files[index].size = size;
    s->files[index].last_synced = 0;
}

int sync_get_file_index(sync_t *s, char *name) {
    for (int i = 0; i < s->num_files; i++) {
        if (strcmp(s->files[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void sync_loop(sync_t *s) {
    while (1) {
        sleep(SYNC_INTERVAL);
        for (int i = 0; i < s->num_files; i++) {
            if (s->files[i].last_synced + SYNC_INTERVAL < time(NULL)) {
                sync_update_file(s, i, 0);
            }
        }
    }
}

int main() {
    sync_t *s = sync_init();
    sync_add_file(s, "example.txt", "/path/to/example.txt", 100);
    sync_loop(s);
    return 0;
}