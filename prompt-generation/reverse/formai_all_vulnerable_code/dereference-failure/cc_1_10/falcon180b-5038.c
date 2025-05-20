//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_LEN 256

// Function to compare file names (for sorting)
int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// Function to compare file sizes (for sorting)
int compare_sizes(const void *a, const void *b) {
    struct stat stat_a, stat_b;
    stat(*(char **)a, &stat_a);
    stat(*(char **)b, &stat_b);
    return difftime(stat_a.st_mtime, stat_b.st_mtime);
}

// Function to print file information
void print_file_info(char *file_name, off_t file_size) {
    printf("%-40s %10jd\n", file_name, file_size);
}

// Function to analyze disk space usage
void analyze_disk_space(char *dir_path) {
    DIR *dir;
    struct dirent *ent;
    char **files = NULL;
    int num_files = 0;

    if ((dir = opendir(dir_path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            files = realloc(files, sizeof(char *) * ++num_files);
            files[num_files - 1] = strdup(ent->d_name);
        }
        closedir(dir);

        // Sort files by name
        qsort(files, num_files, sizeof(char *), compare_names);

        // Print file list
        printf("Files sorted by name:\n");
        for (int i = 0; i < num_files; i++) {
            printf("%s\n", files[i]);
        }

        // Sort files by size
        qsort(files, num_files, sizeof(char *), compare_sizes);

        // Print file list
        printf("\nFiles sorted by size:\n");
        for (int i = 0; i < num_files; i++) {
            print_file_info(files[i], 0);
        }

        // Free memory
        for (int i = 0; i < num_files; i++) {
            free(files[i]);
        }
        free(files);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    analyze_disk_space(argv[1]);

    return 0;
}