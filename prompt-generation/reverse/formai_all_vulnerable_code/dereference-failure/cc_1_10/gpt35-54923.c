//FormAI DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

void display_directory_contents(char *path, int depth) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) { // If the entry is a directory
            char new_path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue; // Skip the . and .. directories
            }       
            snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name); // Construct the new path
            for (int i = 0; i < depth; i++) { // Display the current depth
                printf("\t");
            }
            printf("%s\n", entry->d_name); // Display the directory name
            display_directory_contents(new_path, depth + 1); // Recursively display the directory's contents
        }
        else { // If the entry is a file
            for (int i = 0; i < depth; i++) { // Display the current depth
                printf("\t");
            }
            printf("%s\n", entry->d_name); // Display the file name
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s path\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *path = argv[1];
    struct stat s;
    if (stat(path, &s) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    if (!S_ISDIR(s.st_mode)) {
        fprintf(stderr, "%s is not a directory\n", path);
        exit(EXIT_FAILURE);
    }

    printf("%s\n", path); // Display the top-level directory name
    display_directory_contents(path, 1); // Recursively display the directory's contents

    return 0;
}