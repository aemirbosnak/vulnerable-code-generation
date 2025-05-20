//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>


// Structure to store file/folder details
typedef struct {
    char* name;
    long size;
    int is_file;
} Item;

// Compare function for sorting by size
int cmp_size(const void* a, const void* b) {
    Item* item1 = (Item*) a;
    Item* item2 = (Item*) b;
    return (item2->size - item1->size);
}

// Compare function for sorting by name
int cmp_name(const void* a, const void* b) {
    Item* item1 = (Item*) a;
    Item* item2 = (Item*) b;
    return strcmp(item1->name, item2->name);
}

// Calculates the total size of a given file/folder
long get_size(const char* path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        if ((st.st_mode & S_IFMT) == S_IFREG) {
            return st.st_size;
        }
        else if ((st.st_mode & S_IFMT) == S_IFDIR) {
            long total_size = 0;
            DIR* dir = opendir(path);
            struct dirent* entry;
            while ((entry = readdir(dir)) != NULL) {
                if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                    char subpath[1024];
                    sprintf(subpath, "%s/%s", path, entry->d_name);
                    total_size += get_size(subpath);
                }
            }
            closedir(dir);
            return total_size;
        }
    }
    return 0;
}

// Prints the result of the analysis
void print_result(Item* items, int num_items, long total_size) {
    printf("\n%-50s %10s\n", "Name", "Size");
    printf("%-50s %10s\n", "----", "----");
    for (int i = 0; i < num_items; i++) {
        char* name_size = (char*) malloc(32 * sizeof(char));
        sprintf(name_size, "%s (%.2f MB)", items[i].name, (float) items[i].size / (1024 * 1024));
        printf("%-50s %10ld\n", name_size, items[i].size);
        free(name_size);
    }
    char* total_size_str = (char*) malloc(32 * sizeof(char));
    sprintf(total_size_str, "Total (%.2f GB)", (float) total_size / (1024 * 1024 * 1024));
    printf("%-50s %10ld\n", total_size_str, total_size);
    free(total_size_str);
}

// Main function
int main(int argc, char* argv[]) {
    char* path;
    if (argc > 1) {
        path = argv[1];
    }
    else {
        path = (char*) malloc(1024 * sizeof(char));
        printf("Enter the path: ");
        scanf("%s", path);
    }

    long total_size = get_size(path);

    Item* items = (Item*) malloc(sizeof(Item) * 1000);
    int num_items = 0;

    DIR* dir = opendir(path);
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        char subpath[1024];
        sprintf(subpath, "%s/%s", path, entry->d_name);
        long size = get_size(subpath);
        if (size > 0) {
            items[num_items].name = (char*) malloc(256 * sizeof(char));
            strcpy(items[num_items].name, entry->d_name);
            items[num_items].size = size;
            items[num_items].is_file = ((size > 0) && ((entry->d_type == DT_REG) || (entry->d_type == DT_LNK)));
            num_items++;
        }
    }
    closedir(dir);

    qsort(items, num_items, sizeof(Item), cmp_size);
    Item* largest_files = (Item*) malloc(sizeof(Item) * 100);
    int num_largest_files = 0;
    for (int i = 0; i < num_items && num_largest_files < 100; i++) {
        if (items[i].is_file && ((float) items[i].size / (1024 * 1024) >= 0.1)) {
            largest_files[num_largest_files] = items[i];
            num_largest_files++;
        }
    }

    qsort(items, num_items, sizeof(Item), cmp_name);

    printf("\nC Disk Space Analyzer\n");
    printf("----------------------\n");
    printf("Path: %s\n", path);
    printf("Total Size: %.2f GB\n", (float) total_size / (1024 * 1024 * 1024));
    printf("Number of Files/Folders Analyzed: %d\n", num_items);
    printf("Number of Largest Files: %d\n", num_largest_files);
    if (num_largest_files > 0) {
        printf("\n%-50s %10s\n", "Name", "Size");
        printf("%-50s %10s\n", "----", "----");
        for (int i = 0; i < num_largest_files; i++) {
            char* name_size = (char*) malloc(32 * sizeof(char));
            sprintf(name_size, "%s (%.2f MB)", largest_files[i].name, (float) largest_files[i].size / (1024 * 1024));
            printf("%-50s %10ld\n", name_size, largest_files[i].size);
            free(name_size);
        }
    }
    printf("\n");
    print_result(items, num_items, total_size);

    for (int i = 0; i < num_items; i++) {
        free(items[i].name);
    }
    free(items);
    free(largest_files);

    return 0;
}