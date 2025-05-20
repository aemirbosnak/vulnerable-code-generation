//LLAMA2-13B DATASET v1.0 Category: Data recovery tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_NAME_LEN 256
#define MAX_DEPTH 5

typedef struct {
    char name[MAX_NAME_LEN];
    char path[MAX_NAME_LEN];
    int depth;
} dir_entry_t;

dir_entry_t* dir_enumerate(const char* path);
void dir_free(dir_entry_t** entries);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    dir_entry_t** entries = dir_enumerate(argv[1]);
    if (!entries) {
        printf("Failed to enumerate directory %s\n", argv[1]);
        return 2;
    }

    printf("Found %d files and directories in %s\n", sizeof(*entries), argv[1]);

    for (int i = 0; i < sizeof(*entries); i++) {
        dir_entry_t* entry = entries[i];
        if (entry->depth > MAX_DEPTH) {
            continue;
        }

        printf("%d:%s\n", entry->depth, entry->name);
    }

    dir_free(entries);

    return 0;
}

dir_entry_t* dir_enumerate(const char* path) {
    DIR* dirp = opendir(path);
    if (!dirp) {
        perror(path);
        return NULL;
    }

    dir_entry_t* entries = calloc(1, sizeof(*entries));
    if (!entries) {
        closedir(dirp);
        return NULL;
    }

    struct dirent* dirent;
    while ((dirent = readdir(dirp)) != NULL) {
        char* name = dirent->d_name;
        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) {
            continue;
        }

        dir_entry_t* entry = calloc(1, sizeof(*entry));
        if (!entry) {
            free(entries);
            closedir(dirp);
            return NULL;
        }

        strcpy(entry->name, name);
        strcpy(entry->path, path);
        entry->depth = 0;
        entries = realloc(entries, (sizeof(*entries) * (1 + sizeof(*entry))));
        if (!entries) {
            free(entry);
            closedir(dirp);
            return NULL;
        }

        entries[sizeof(*entries) - 1] = *entry;
    }

    closedir(dirp);
    return entries;
}

void dir_free(dir_entry_t** entries) {
    for (int i = 0; i < sizeof(*entries); i++) {
        if (entries[i]) {
            free(entries[i]->name);
            free(entries[i]->path);
            free(entries[i]);
        }
    }

    free(entries);
}