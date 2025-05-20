//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/sysinfo.h>

typedef struct {
    char name[256];
    off_t size;
} file;

file files[1024];
int num_files = 0;

void read_dir(char *path) {
    DIR *dir;
    struct dirent *entry;
    int i = 0;

    dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(files[i].name, sizeof(files[i].name), "%s/%s", path, entry->d_name);
        files[i].size = 0;

        if (S_ISDIR(entry->d_type)) {
            read_dir(files[i].name);
            continue;
        }

        int fd = open(files[i].name, O_RDONLY);
        if (fd < 0) {
            perror("open");
            continue;
        }

        files[i].size = lseek(fd, 0, SEEK_END);
        close(fd);

        i++;
        if (i >= 1024) {
            fprintf(stderr, "Too many files\n");
            break;
        }
    }

    closedir(dir);
}

int main() {
    struct stat st;
    char cwd[128];

    if (stat(".", &st) < 0) {
        perror("stat");
        return 1;
    }

    snprintf(cwd, sizeof(cwd), "%s/.", getcwd(NULL, 0));

    read_dir(cwd);

    printf("Path\tSize\n");
    printf("----\t----\n");

    for (int i = 0; i < num_files; i++) {
        off_t size = files[i].size;
        double perc = ((double) files[i].size / ((double) st.st_size)) * 100.0;

        if (size > 0)
            printf("%s\t%llu bytes (%0.2f%%)\n", files[i].name, size, perc);
        else
            printf("%s\t<0 bytes\n", files[i].name);
    }

    return 0;
}