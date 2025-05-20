//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char *dir = argv[1];

    DIR *dp;
    struct dirent *ep;

    dp = opendir(dir);
    if (dp == NULL) {
        perror("opendir");
        return 1;
    }

    while ((ep = readdir(dp))) {
        if (strcmp(ep->d_name, ".") == 0 || strcmp(ep->d_name, "..") == 0) {
            continue;
        }

        char *path = malloc(strlen(dir) + strlen(ep->d_name) + 2);
        strcpy(path, dir);
        strcat(path, "/");
        strcat(path, ep->d_name);

        struct stat st;
        if (stat(path, &st) == -1) {
            perror("stat");
            free(path);
            continue;
        }

        if (S_ISREG(st.st_mode) && st.st_size > 0) {
            int fd = open(path, O_RDONLY);
            if (fd == -1) {
                perror("open");
                free(path);
                continue;
            }

            char *buffer = malloc(st.st_size);
            if (read(fd, buffer, st.st_size) == -1) {
                perror("read");
                free(path);
                free(buffer);
                close(fd);
                continue;
            }

            close(fd);

            char *magic = buffer;
            if (strncmp(magic, "SQLite format 3", 15) == 0) {
                printf("Found SQLite database: %s\n", path);
            } else if (strncmp(magic, "MySQL", 5) == 0) {
                printf("Found MySQL database: %s\n", path);
            } else if (strncmp(magic, "PostgreSQL", 9) == 0) {
                printf("Found PostgreSQL database: %s\n", path);
            } else if (strncmp(magic, "%PDF", 4) == 0) {
                printf("Found PDF document: %s\n", path);
            } else if (strncmp(magic, "GIF89a", 6) == 0) {
                printf("Found GIF image: %s\n", path);
            } else if (strncmp(magic, "PNG", 3) == 0) {
                printf("Found PNG image: %s\n", path);
            } else if (strncmp(magic, "JPEG", 4) == 0) {
                printf("Found JPEG image: %s\n", path);
            } else if (strncmp(magic, "MP4", 3) == 0) {
                printf("Found MP4 video: %s\n", path);
            } else if (strncmp(magic, "MOV", 3) == 0) {
                printf("Found MOV video: %s\n", path);
            } else if (strncmp(magic, "AVI", 3) == 0) {
                printf("Found AVI video: %s\n", path);
            } else if (strncmp(magic, "MP3", 3) == 0) {
                printf("Found MP3 audio: %s\n", path);
            } else if (strncmp(magic, "WAV", 3) == 0) {
                printf("Found WAV audio: %s\n", path);
            } else if (strncmp(magic, "OGG", 3) == 0) {
                printf("Found OGG audio: %s\n", path);
            }

            free(path);
            free(buffer);
        }
    }

    closedir(dp);

    return 0;
}