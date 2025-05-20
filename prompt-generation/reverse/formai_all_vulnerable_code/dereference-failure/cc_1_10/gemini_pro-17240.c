//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

struct Entry {
    char *path;
    size_t size;
};

int compare(const void *a, const void *b) {
    const struct Entry *e1 = a;
    const struct Entry *e2 = b;
    return e2->size - e1->size;
}

int main() {
    char *path = ".";
    size_t total = 0;
    size_t largest = 0;
    char *largest_path = NULL;

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir failed");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char *entry_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(entry_path, "%s/%s", path, entry->d_name);

        struct stat st;
        if (stat(entry_path, &st) == -1) {
            perror("stat failed");
            free(entry_path);
            continue;
        }

        if (st.st_mode & S_IFDIR) {
            continue;
        }

        struct Entry e = {
            .path = entry_path,
            .size = st.st_size
        };

        total += e.size;
        if (e.size > largest) {
            largest = e.size;
            largest_path = e.path;
        }
    }

    closedir(dir);

    printf("Total size: %lu\n", total);
    printf("Largest file: %s (%lu bytes)\n", largest_path, largest);

    return 0;
}