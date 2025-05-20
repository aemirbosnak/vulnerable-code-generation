//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEVELS 10
#define MAX_ENTRIES 100

struct DirectoryEntry {
    char* name;
    int size;
};

struct Directory {
    char* name;
    struct DirectoryEntry* entries[MAX_ENTRIES];
    int num_entries;
    int size;
    struct Directory* subdirs[MAX_ENTRIES];
    int num_subdirs;
    int level;
};

void add_entry(struct Directory* dir, struct DirectoryEntry* entry) {
    dir->entries[dir->num_entries] = entry;
    dir->num_entries++;
    dir->size += entry->size;
}

void add_subdir(struct Directory* dir, struct Directory* subdir) {
    dir->subdirs[dir->num_subdirs] = subdir;
    dir->num_subdirs++;
}

void analyze_directory(struct Directory* dir) {
    printf("%*.s%s/ (%d bytes)\n", dir->level * 4, "", dir->name, dir->size);
    for (int i = 0; i < dir->num_entries; i++) {
        struct DirectoryEntry* entry = dir->entries[i];
        printf("%*.s- %s (%d bytes)\n", dir->level * 4 + 2, "", entry->name, entry->size);
    }
    for (int i = 0; i < dir->num_subdirs; i++) {
        struct Directory* subdir = dir->subdirs[i];
        analyze_directory(subdir);
    }
}

void destroy_directory(struct Directory* dir) {
    for (int i = 0; i < dir->num_entries; i++) {
        struct DirectoryEntry* entry = dir->entries[i];
        free(entry->name);
        free(entry);
    }
    for (int i = 0; i < dir->num_subdirs; i++) {
        struct Directory* subdir = dir->subdirs[i];
        destroy_directory(subdir);
    }
    free(dir->name);
    free(dir);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    struct Directory* root = (struct Directory*) malloc(sizeof(struct Directory));
    root->name = strdup(argv[1]);
    root->num_entries = 0;
    root->size = 0;
    root->num_subdirs = 0;
    root->level = 0;

    struct Directory* current_dir = root;
    int levels[MAX_LEVELS];
    int num_levels = 0;
    levels[num_levels++] = 0;

    char command[100];
    sprintf(command, "dir /s /b \"%s\"", argv[1]);
    FILE* fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error: failed to execute \"%s\"\n", command);
        return 1;
    }

    char line[2000];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char* filename = strdup(line);
        filename[strcspn(filename, "\r\n")] = 0;
        int last_level = levels[num_levels-1];
        int level = 0;
        for (int i = 0; i < strlen(filename); i++) {
            if (filename[i] == '\\') level++;
        }
        levels[num_levels++] = level;
        if (level <= last_level) {
            num_levels--;
            for (int i = level; i <= last_level; i++) {
                current_dir = (struct Directory*) malloc(sizeof(struct Directory));
                current_dir->name = current_dir->entries[0]->name;
                current_dir->num_entries = 0;
                current_dir->size = 0;
                current_dir->num_subdirs = 0;
                current_dir->level = i;
                add_subdir(current_dir, current_dir);
                destroy_directory(current_dir);
                current_dir = current_dir->subdirs[current_dir->num_subdirs-1];
            }
        }
        struct DirectoryEntry* entry = (struct DirectoryEntry*) malloc(sizeof(struct DirectoryEntry));
        entry->name = filename;
        entry->size = rand() % 1000000;
        add_entry(current_dir, entry);
    }
    pclose(fp);

    analyze_directory(root);

    destroy_directory(root);

    return 0;
}