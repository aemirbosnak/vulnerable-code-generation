//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

#define BUF_SIZE 4096
#define MAX_PATH 256

char *get_file_extension(const char *filename) {
    char *dot = strrchr(filename, '.');
    if (dot == NULL) return "";
    return dot + 1;
}

void copy_file(const char *src, const char *dest) {
    FILE *fin, *fout;
    char buf[BUF_SIZE];
    int n;

    fin = fopen(src, "rb");
    if (fin == NULL) {
        perror("fopen(src)");
        return;
    }

    fout = fopen(dest, "wb");
    if (fout == NULL) {
        perror("fopen(dest)");
        fclose(fin);
        return;
    }

    while ((n = fread(buf, 1, BUF_SIZE, fin)) > 0) {
        fwrite(buf, 1, n, fout);
    }

    fclose(fin);
    fclose(fout);
}

void backup_directory(const char *src, const char *dest) {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH];

    dir = opendir(src);
    if (dir == NULL) {
        perror("opendir(src)");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, MAX_PATH, "%s/%s", src, entry->d_name);

        if (entry->d_type == DT_DIR) {
            backup_directory(path, dest);
        } else {
            char dest_path[MAX_PATH];
            char timestamp[32];
            time_t t = time(NULL);
            strftime(timestamp, 32, "%Y-%m-%d_%H-%M-%S", localtime(&t));
            snprintf(dest_path, MAX_PATH, "%s/%s.%s.%s", dest, entry->d_name, get_file_extension(entry->d_name), timestamp);
            copy_file(path, dest_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src> <dest>\n", argv[0]);
        return EXIT_FAILURE;
    }

    backup_directory(argv[1], argv[2]);

    return EXIT_SUCCESS;
}