//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char directory[1024];
    strcpy(directory, argv[1]);

    DIR *dp;
    struct dirent *entry;

    if ((dp = opendir(directory)) == NULL) {
        perror("opendir");
        exit(1);
    }

    int total_size = 0;

    while ((entry = readdir(dp))!= NULL) {
        if (entry->d_name[0]!= '.') {
            total_size += get_file_size(directory, entry->d_name);
        }
    }

    printf("Total size of files in %s: %d bytes\n", directory, total_size);

    closedir(dp);

    return 0;
}

int get_file_size(char *directory, char *filename) {
    struct stat st;

    if (stat(directory, &st) == -1) {
        perror("stat");
        exit(1);
    }

    if (st.st_mode & S_IFDIR) {
        return get_file_size(directory, filename);
    } else {
        return st.st_size;
    }
}