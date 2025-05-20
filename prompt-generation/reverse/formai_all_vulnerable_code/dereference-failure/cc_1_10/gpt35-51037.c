//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 256

void print_usage() {
    printf("Usage: ./shapeshifter -<option> <path>\n");
    printf("<option>:\n");
    printf("-f - Analyze a file.\n");
    printf("-d - Analyze a directory (displays size of all files).\n");
    printf("<path>:\n");
    printf("Specify path to the file/directory to analyze.\n");
}

long long get_file_size(const char* filename) {
    struct stat st;
    if (stat(filename, &st) != -1) {
        return st.st_size;
    }
    return 0;
}

void analyze_file(char* filename) {
    long long file_size = get_file_size(filename);
    printf("%s: %lld bytes\n", filename, file_size);
}

void analyze_directory(char* directory) {
    DIR* dir = opendir(directory);
    if (dir) {
        struct dirent* entry;
        while ((entry = readdir(dir)) != NULL) {
            char* filename = entry->d_name;
            if (strcmp(filename, ".") == 0 || strcmp(filename, "..") == 0) {
                continue;
            }
            char buffer[BUFFER_SIZE];
            snprintf(buffer, BUFFER_SIZE, "%s/%s", directory, filename);
            long long file_size = get_file_size(buffer);
            printf("%s/%s: %lld bytes\n", directory, filename, file_size);
        }
        closedir(dir);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }
    char* option = argv[1];
    char* path = argv[2];
    if (strcmp(option, "-f") == 0) {
        analyze_file(path);
    } else if (strcmp(option, "-d") == 0) {
        analyze_directory(path);
    } else {
        printf("Invalid option!\n");
        return 1;
    }
    return 0;
}