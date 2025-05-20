//FormAI DATASET v1.0 Category: File Backup System ; Style: Cryptic
#define _XOPEN_SOURCE 500
#define BLOCKSIZE 4096
#define MAXPATHLEN 4096
#define ENCRYPTION_KEY "exampleKey"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>

void encrypt(char* input, char* output) {
    FILE* in = fopen(input, "rb");
    FILE* out = fopen(output, "wb");
    char buffer[BLOCKSIZE];
    size_t n;
    while ((n = fread(buffer, 1, BLOCKSIZE, in)) > 0) {
        for (int i = 0; i < n; i++) {
            buffer[i] ^= ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
        }
        fwrite(buffer, 1, n, out);
    }
    fclose(in);
    fclose(out);
}

void backup(char* source, char* dest) {
    struct stat st;
    stat(source, &st);
    if (S_ISDIR(st.st_mode)) {
        DIR* dir = opendir(source);
        mkdir(dest, st.st_mode);
        struct dirent* entry;
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            char* full_source_path = malloc(MAXPATHLEN);
            char* full_dest_path = malloc(MAXPATHLEN);
            snprintf(full_source_path, MAXPATHLEN, "%s/%s", source, entry->d_name);
            snprintf(full_dest_path, MAXPATHLEN, "%s/%s", dest, entry->d_name);
            backup(full_source_path, full_dest_path);
            free(full_source_path);
            free(full_dest_path);
        }
        closedir(dir);
    } else {
        int in = open(source, O_RDONLY);
        int out = open(dest, O_WRONLY | O_CREAT, st.st_mode);
        char buffer[BLOCKSIZE];
        ssize_t n;
        while ((n = read(in, buffer, BLOCKSIZE)) > 0) {
            write(out, buffer, n);
        }
        close(in);
        close(out);
        encrypt(dest, dest);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        exit(1);
    }
    backup(argv[1], argv[2]);
    return 0;
}