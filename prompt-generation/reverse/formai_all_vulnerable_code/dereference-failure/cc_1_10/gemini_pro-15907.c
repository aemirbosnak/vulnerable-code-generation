//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Entropy-inspired disk space analyzer

// Information unit
typedef struct {
    char *name;
    size_t size;
} unit_t;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    unit_t *ua = (unit_t *)a;
    unit_t *ub = (unit_t *)b;
    return (ua->size > ub->size) ?  1
         : (ua->size == ub->size) ? 0 : -1;
}

// Entropy calculation
double entropy(unit_t *units, size_t count) {
    double entropy = 0;
    for (size_t i = 0; i < count; i++) {
        double p = (double)units[i].size / (double)units[count-1].size;
        entropy -= p * log2(p);
    }
    return entropy;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Get directory size
    struct stat st;
    stat(argv[1], &st);
    size_t dir_size = st.st_size;

    // Initialize unit array
    size_t count = 0;
    unit_t *units = malloc(sizeof(unit_t) * 1000);

    // Iterate over directory
    DIR *dir = opendir(argv[1]);
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files
        if (entry->d_name[0] == '.') continue;

        // Get file size
        char path[strlen(argv[1]) + strlen(entry->d_name) + 2];
        sprintf(path, "%s/%s", argv[1], entry->d_name);
        stat(path, &st);
        size_t file_size = st.st_size;

        // Add unit to array
        units[count].name = strdup(entry->d_name);
        units[count].size = file_size;
        count++;
    }
    closedir(dir);

    // Sort units by size
    qsort(units, count, sizeof(unit_t), compare);

    // Calculate entropy
    double H = entropy(units, count);

    // Print results
    printf("Directory size: %zu bytes\n", dir_size);
    printf("Number of files: %zu\n", count);
    printf("Entropy: %.3f bits\n", H);

    // Cleanup
    for (size_t i = 0; i < count; i++) free(units[i].name);
    free(units);

    return 0;
}