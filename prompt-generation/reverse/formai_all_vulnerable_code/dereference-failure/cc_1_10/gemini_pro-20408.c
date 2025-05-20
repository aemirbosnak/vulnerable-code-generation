//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Signature database
static const char *signatures[] = {
    "55 48 89 E5 83 EC 20 89 7D F8 89 75 FC",
    "4D 5A 90 00 03 00 00 00 04 00 00 00 FF FF FF FF",
    "33 C0 C3"
};

// Scan a single file
static int scan_file(const char *filename) {
    int fd, ret = 0;
    unsigned char buffer[4096];
    size_t bytes_read;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            for (int j = 0; j < sizeof(signatures) / sizeof(signatures[0]); j++) {
                if (memcmp(buffer + i, signatures[j], strlen(signatures[j]) / 3) == 0) {
                    printf("Found virus in file %s\n", filename);
                    ret = -1;
                    break;
                }
            }
            if (ret == -1) {
                break;
            }
        }
    }

    close(fd);

    return ret;
}

// Scan a directory
static int scan_dir(const char *dirname) {
    DIR *dir;
    struct dirent *entry;
    int ret = 0;

    dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *pathname = malloc(strlen(dirname) + strlen(entry->d_name) + 2);
        strcpy(pathname, dirname);
        strcat(pathname, "/");
        strcat(pathname, entry->d_name);

        struct stat statbuf;
        if (lstat(pathname, &statbuf) == -1) {
            perror("lstat");
            free(pathname);
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            ret = scan_dir(pathname);
            if (ret == -1) {
                break;
            }
        } else if (S_ISREG(statbuf.st_mode)) {
            ret = scan_file(pathname);
            if (ret == -1) {
                break;
            }
        }

        free(pathname);
    }

    closedir(dir);

    return ret;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return -1;
    }

    return scan_dir(argv[1]);
}