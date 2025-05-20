//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[256];
    unsigned long long size;
} Entry;

int compare_entries(const void *a, const void *b) {
    const Entry *e1 = a;
    const Entry *e2 = b;
    return e2->size - e1->size;
}

void print_entries(Entry *entries, int count) {
    printf("Name\t\tSize\n");
    printf("----------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-256s\t%llu\n", entries[i].name, entries[i].size);
    }
}

void analyze_directory(const char *path, Entry *entries, int *count) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Error: could not open directory '%s'\n", path);
        exit(1);
    }

    struct dirent *dent;
    while ((dent = readdir(dir))!= NULL) {
        if (*count >= MAX_ENTRIES) {
            fprintf(stderr, "Error: too many entries in directory '%s'\n", path);
            exit(1);
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, dent->d_name);

        struct stat st;
        if (stat(full_path, &st)!= 0) {
            fprintf(stderr, "Error: could not stat file '%s'\n", full_path);
            exit(1);
        }

        if (S_ISDIR(st.st_mode)) {
            analyze_directory(full_path, entries, count);
        } else {
            entries[*count].size = st.st_size;
            strncpy(entries[*count].name, dent->d_name, sizeof(entries[*count].name));
            entries[*count].name[sizeof(entries[*count].name) - 1] = '\0';
            (*count)++;
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    Entry entries[MAX_ENTRIES];
    int count = 0;

    analyze_directory(argv[1], entries, &count);

    qsort(entries, count, sizeof(Entry), compare_entries);
    print_entries(entries, count);

    return 0;
}