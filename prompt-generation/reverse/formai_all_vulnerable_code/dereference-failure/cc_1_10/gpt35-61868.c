//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

#define KB (1024)
#define MB (KB*1024)
#define GB (MB*1024)

typedef struct {
    unsigned long int size;
    char* path;
} file_data;

int count_files = 0;
unsigned long int total_size = 0;

void print_usage() {
    printf("usage: disk_analyzer [directory]\n");
    printf("       analyze disk space usage in specified directory and print statistics\n");
}

bool is_directory(const char* path) {
    struct stat st;
    if (stat(path, &st)) {
        return false;
    }
    return (st.st_mode & S_IFMT) == S_IFDIR;
}

bool is_file(const char* path) {
    struct stat st;
    if (stat(path, &st)) {
        return false;
    }
    return (st.st_mode & S_IFMT) == S_IFREG;
}

unsigned long int get_file_size(const char* path) {
    struct stat st;
    stat(path, &st);
    return st.st_size;
}

void analyze_directory(const char* path, file_data* files) {
    DIR* d = opendir(path);
    if (d == NULL) {
        perror("opendir() failed");
        exit(EXIT_FAILURE);
    }

    struct dirent* entry;
    while ((entry = readdir(d))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char* sub_path = calloc(strlen(path) + strlen(entry->d_name) + 2, sizeof(char));
        sprintf(sub_path, "%s/%s", path, entry->d_name);
        if (is_directory(sub_path)) {
            analyze_directory(sub_path, files);
        } else if (is_file(sub_path)) {
            unsigned long int size = get_file_size(sub_path);
            files[count_files].size = size;
            files[count_files].path = sub_path;
            count_files++;
            total_size += size;
        }
    }

    closedir(d);
}

void print_results(file_data* files) {
    printf("Total size: ");

    if (total_size / GB > 0) {
        printf("%lu GB ", total_size / GB);
    }

    if (total_size / MB > 0) {
        printf("%lu MB ", (total_size % GB) / MB);
    }

    if (total_size / KB > 0) {
        printf("%lu KB ", (total_size % MB) / KB);
    }

    printf("(%lu bytes)\n", total_size);

    printf("Number of files: %d\n", count_files);
    printf("\n");

    printf("Largest files:\n");
    for (int i = 0; i < 10 && i < count_files; i++) {
        printf("%lu bytes: %s\n", files[i].size, files[i].path);
    }

    free(files);
}

int main(int argc, char* argv[]) {    
    if (argc < 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char* path = argv[1];
    if (!is_directory(path)) {
        printf("error: %s is not a directory\n", path);
        print_usage();
        return EXIT_FAILURE;
    }

    file_data* files = calloc(100000, sizeof(file_data));
    analyze_directory(path, files);
    print_results(files);

    return EXIT_SUCCESS;
}