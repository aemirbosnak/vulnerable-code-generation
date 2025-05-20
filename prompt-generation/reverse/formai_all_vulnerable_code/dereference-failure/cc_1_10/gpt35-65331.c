//FormAI DATASET v1.0 Category: File Synchronizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

void createFolder(char *path) {
    char command[100];
    sprintf(command, "mkdir -p %s", path);
    system(command);
}

void copyFile(char *src, char *dest) {
    int fd_src = open(src, O_RDONLY);
    if (fd_src == -1) return;

    int fd_dest = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd_dest == -1) return;

    char buffer[1024];
    int read_bytes, write_bytes;

    while ((read_bytes = read(fd_src, buffer, sizeof(buffer))) > 0) {
        write_bytes = write(fd_dest, buffer, read_bytes);
        if (write_bytes < read_bytes) {
            printf("Error writing to file: %s\n", dest);
            return;
        }
    }

    close(fd_src);
    close(fd_dest);
}

void synchronizeFolder(char *path_src, char *path_dest) {
    DIR *dir_src = opendir(path_src);
    if (!dir_src) return;

    DIR *dir_dest = opendir(path_dest);
    if (!dir_dest) {
        createFolder(path_dest);
        dir_dest = opendir(path_dest);
    }

    struct dirent *ent_src;
    while ((ent_src = readdir(dir_src)) != NULL) {
        if (strcmp(ent_src->d_name, ".") == 0 || strcmp(ent_src->d_name, "..") == 0) continue;

        char path_src_file[100];
        sprintf(path_src_file, "%s/%s", path_src, ent_src->d_name);

        char path_dest_file[100];
        sprintf(path_dest_file, "%s/%s", path_dest, ent_src->d_name);

        DIR *subdir_src = opendir(path_src_file);
        if (subdir_src) {
            closedir(subdir_src);
            synchronizeFolder(path_src_file, path_dest_file);
        } else {
            struct dirent *ent_dest;
            int found = 0;
            while ((ent_dest = readdir(dir_dest)) != NULL) {
                if (strcmp(ent_src->d_name, ent_dest->d_name) == 0) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                copyFile(path_src_file, path_dest_file);
                printf("Copied %s to %s\n", path_src_file, path_dest_file);
            }
        }
    }

    closedir(dir_src);
    closedir(dir_dest);
}

int main() {
    char path_src[] = "folder1";
    char path_dest[] = "folder2";
    synchronizeFolder(path_src, path_dest);

    return 0;
}