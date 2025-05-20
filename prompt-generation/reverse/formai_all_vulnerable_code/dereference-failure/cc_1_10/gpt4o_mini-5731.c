//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

void print_metadata(const char *filename) {
    struct stat buf;
    if (stat(filename, &buf) == -1) {
        perror("Could not get file status");
        return;
    }

    printf("File: %s\n", filename);
    printf("Size: %ld bytes\n", buf.st_size);
    printf("Permissions: ");
    printf((S_ISDIR(buf.st_mode)) ? "d" : "-");
    printf((buf.st_mode & S_IRUSR) ? "r" : "-");
    printf((buf.st_mode & S_IWUSR) ? "w" : "-");
    printf((buf.st_mode & S_IXUSR) ? "x" : "-");
    printf((buf.st_mode & S_IRGRP) ? "r" : "-");
    printf((buf.st_mode & S_IWGRP) ? "w" : "-");
    printf((buf.st_mode & S_IXGRP) ? "x" : "-");
    printf((buf.st_mode & S_IROTH) ? "r" : "-");
    printf((buf.st_mode & S_IWOTH) ? "w" : "-");
    printf((buf.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    printf("Last Access Time: %s", ctime(&buf.st_atime));
    printf("Last Modified Time: %s", ctime(&buf.st_mtime));
    printf("Last Status Change Time: %s", ctime(&buf.st_ctime));
    printf("\n-----------------------------------\n");
}

void explore_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);

    if (dp == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] == '.') {
            continue; // skip hidden files
        }

        char filepath[1024];
        snprintf(filepath, sizeof(filepath), "%s/%s", dir_path, entry->d_name);

        print_metadata(filepath);
    }

    closedir(dp);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Welcome to the Metadata Extractor! 🎉\n");
    printf("Let's explore the excitement of files in the directory: %s\n", argv[1]);
    printf("============================================\n");

    explore_directory(argv[1]);

    printf("Adventure Completed! Thanks for using the Metadata Extractor! 🌟\n");

    return EXIT_SUCCESS;
}