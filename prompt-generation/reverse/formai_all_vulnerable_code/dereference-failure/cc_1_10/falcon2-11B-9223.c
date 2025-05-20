//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

void scanDirectory(const char *path) {
    DIR *dir;
    struct dirent *ent;
    int fd;

    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                scanDirectory(ent->d_name);
            } else {
                char *filename = malloc(strlen(ent->d_name) + 1);
                strcpy(filename, ent->d_name);
                fd = open(filename, O_RDONLY);
                if (fd >= 0) {
                    size_t filesize = lseek(fd, 0, SEEK_END);
                    if (filesize > 0) {
                        char *buffer = malloc(filesize + 1);
                        if (buffer!= NULL) {
                            if (read(fd, buffer, filesize) > 0) {
                                if (buffer[filesize] == 0) {
                                    if (buffer[filesize - 1] == 0x55 && buffer[filesize - 2] == 0xAA) {
                                        free(buffer);
                                        printf("%s is a PE file\n", ent->d_name);
                                        free(filename);
                                        close(fd);
                                        continue;
                                    }
                                } else {
                                    free(buffer);
                                    free(filename);
                                    close(fd);
                                    continue;
                                }
                            } else {
                                free(buffer);
                                free(filename);
                                close(fd);
                                continue;
                            }
                        } else {
                            free(filename);
                            close(fd);
                            continue;
                        }
                    } else {
                        free(filename);
                        close(fd);
                        continue;
                    }
                } else {
                    free(filename);
                    close(fd);
                    continue;
                }
            }
        }
        closedir(dir);
    }
}

int main() {
    const char *path = ".";
    scanDirectory(path);
    return 0;
}