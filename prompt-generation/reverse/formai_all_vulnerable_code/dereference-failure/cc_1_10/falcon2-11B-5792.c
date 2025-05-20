//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

void print_files(char *dir) {
    DIR *dp;
    struct dirent *ep;
    char buff[256];

    dp = opendir(dir);
    if (dp == NULL) {
        perror("opendir");
        exit(1);
    }

    while ((ep = readdir(dp))!= NULL) {
        strcpy(buff, ep->d_name);
        printf("%s\n", buff);
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    char *source_dir, *dest_dir;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        exit(1);
    }

    source_dir = argv[1];
    dest_dir = argv[2];

    if (chdir(source_dir)!= 0) {
        perror("chdir");
        exit(1);
    }

    print_files(source_dir);

    if (chdir(dest_dir)!= 0) {
        perror("chdir");
        exit(1);
    }

    print_files(dest_dir);

    return 0;
}