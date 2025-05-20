//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KB (1024)
#define MB (1024 * KB)
#define GB (1024 * MB)

typedef struct {
    char *name;
    unsigned long long size;
} file_t;

int compare_files(const void *a, const void *b) {
    const file_t *fa = (const file_t *)a;
    const file_t *fb = (const file_t *)b;
    return fa->size - fb->size;
}

int main() {
    char *path = ".";
    unsigned long long total_space = 0;
    unsigned long long free_space = 0;
    unsigned long long used_space = 0;
    int num_files = 0;
    file_t *files = NULL;

    // Get disk space information
    if (system("df -h > disk_space.txt") == -1) {
        perror("system");
        return EXIT_FAILURE;
    }

    // Open the disk space information file
    FILE *f = fopen("disk_space.txt", "r");
    if (f == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the first line of the file, which contains the header
    char line[1024];
    if (fgets(line, sizeof(line), f) == NULL) {
        perror("fgets");
        return EXIT_FAILURE;
    }

    // Read the second line of the file, which contains the disk space information
    if (fgets(line, sizeof(line), f) == NULL) {
        perror("fgets");
        return EXIT_FAILURE;
    }

    // Parse the disk space information
    char *start = line;
    char *end = line;
    while (*end != '\0') {
        if (*end == ' ') {
            *end = '\0';
            total_space = atoll(start);
            start = end + 1;
        } else if (*end == '%') {
            *end = '\0';
            used_space = atoll(start);
            free_space = total_space - used_space;
            break;
        }
        end++;
    }

    // Close the disk space information file
    fclose(f);

    // Get the files in the directory
    char cmd[1024];
    sprintf(cmd, "find %s -type f -printf \"%%f\\n%%s\\n\"", path);
    FILE *p = popen(cmd, "r");
    if (p == NULL) {
        perror("popen");
        return EXIT_FAILURE;
    }

    // Read the files from the pipe
    char *name = NULL;
    unsigned long long size = 0;
    while (fscanf(p, "%s %llu\n", name, &size) != EOF) {
        files = realloc(files, (num_files + 1) * sizeof(file_t));
        files[num_files].name = strdup(name);
        files[num_files].size = size;
        num_files++;
    }

    // Close the pipe
    pclose(p);

    // Sort the files by size
    qsort(files, num_files, sizeof(file_t), compare_files);

    // Print the files
    printf("Disk Space Analyzer\n");
    printf("Total space: %llu GB\n", total_space / GB);
    printf("Free space: %llu GB\n", free_space / GB);
    printf("Used space: %llu GB\n", used_space / GB);
    printf("Number of files: %d\n\n", num_files);
    for (int i = 0; i < num_files; i++) {
        printf("%-50s %7llu GB\n", files[i].name, files[i].size / GB);
    }

    // Free the allocated memory
    for (int i = 0; i < num_files; i++) {
        free(files[i].name);
    }
    free(files);

    return EXIT_SUCCESS;
}