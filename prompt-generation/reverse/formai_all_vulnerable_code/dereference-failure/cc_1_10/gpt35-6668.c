//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>

void display_files(char *path, char *search_term);

int main(int argc, char *argv[]) {
    char *search_term = "";
    char *path = "./";

    if (argc > 1) {
      search_term = argv[1];
    }

    if (argc > 2) {
      path = argv[2];
    }

    display_files(path, search_term);

    return 0;
}

void display_files(char *path, char *search_term) {
    DIR *dir = opendir(path);
    struct dirent *dp;

    if (!dir) {
        perror("opendir");
        exit(1);
    }

    while ((dp = readdir(dir)) != NULL) {
        if (dp->d_name[0] == '.') {
            continue; // skip hidden files/dirs
        }

        char full_path[1024];
        sprintf(full_path, "%s/%s", path, dp->d_name);

        if (dp->d_type == DT_DIR) {
            // recurse into subdirectory
            display_files(full_path, search_term);
        } else if (strstr(dp->d_name, search_term)) {
            // print file name if it contains search term
            printf("%s/%s\n", path, dp->d_name);
        }
    }

    closedir(dir);
}