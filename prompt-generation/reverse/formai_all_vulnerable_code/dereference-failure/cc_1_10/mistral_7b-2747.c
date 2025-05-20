//MISTRAL-7B DATASET v1.0 Category: Antivirus scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1MB
#define BUF_SIZE 1024
#define SIGNATURE_LENGTH 16

typedef struct {
    char name[256];
    char signature[SIGNATURE_LENGTH];
    off_t file_size;
} FileSignature;

typedef struct {
    FileSignature files[1024];
    int count;
} SignatureDatabase;

int check_signature(const char *buf, const char *signature) {
    for (int i = 0; i < SIGNATURE_LENGTH; i++) {
        if (buf[i] != signature[i]) {
            return 0;
        }
    }
    return 1;
}

int scan_file(const char *path, SignatureDatabase *db) {
    int fd;
    struct stat st;

    if ((fd = open(path, O_RDONLY)) < 0) {
        perror("open");
        return -1;
    }

    if (fstat(&fd, &st) < 0) {
        perror("fstat");
        close(fd);
        return -1;
    }

    if (st.st_size > MAX_FILE_SIZE) {
        printf("Skipping '%s' (size %lld bytes)\n", path, (long long)st.st_size);
        close(fd);
        return 0;
    }

    char buf[BUF_SIZE];
    off_t pos = 0;

    while (pos < st.st_size) {
        int bytes_read = read(fd, buf, BUF_SIZE);
        if (bytes_read <= 0) {
            break;
        }

        for (int i = 0; i < db->count; i++) {
            if (check_signature(buf, db->files[i].signature)) {
                printf("Virus detected in '%s' (%s)\n", path, db->files[i].name);
                close(fd);
                return -1;
            }
        }

        pos += bytes_read;
    }

    close(fd);
    return 0;
}

void load_signatures(SignatureDatabase *db) {
    FILE *fp = fopen("signatures.dat", "rb");

    if (!fp) {
        perror("open");
        return;
    }

    while (fread(&db->files[db->count], sizeof(FileSignature), 1, fp) > 0) {
        db->count++;
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    SignatureDatabase db;

    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    load_signatures(&db);

    if (scan_file(argv[1], &db) < 0) {
        return 1;
    }

    printf("'%s' is clean\n", argv[1]);
    return 0;
}