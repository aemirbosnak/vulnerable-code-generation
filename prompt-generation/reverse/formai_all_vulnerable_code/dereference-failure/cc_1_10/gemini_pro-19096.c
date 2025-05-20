//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BUF_SIZE 4096
#define MAX_FILES 100

struct file_info {
    char name[256];
    time_t timestamp;
    size_t size;
};

struct backup_system {
    char *backup_dir;
    struct file_info files[MAX_FILES];
    int num_files;
};

struct backup_system *init_backup_system(char *backup_dir) {
    struct backup_system *bs = malloc(sizeof(struct backup_system));
    if (bs == NULL) {
        perror("malloc");
        return NULL;
    }

    bs->backup_dir = strdup(backup_dir);
    if (bs->backup_dir == NULL) {
        perror("strdup");
        free(bs);
        return NULL;
    }

    bs->num_files = 0;

    return bs;
}

void destroy_backup_system(struct backup_system *bs) {
    free(bs->backup_dir);
    free(bs);
}

int add_file_to_backup(struct backup_system *bs, char *file_name) {
    if (bs->num_files >= MAX_FILES) {
        return -1;
    }

    struct file_info *fi = &bs->files[bs->num_files++];

    strcpy(fi->name, file_name);
    fi->timestamp = time(NULL);
    fi->size = 0;

    return 0;
}

int backup_file(struct backup_system *bs, char *file_name) {
    FILE *src = fopen(file_name, "rb");
    if (src == NULL) {
        perror("fopen");
        return -1;
    }

    char backup_file[256];
    snprintf(backup_file, sizeof(backup_file), "%s/%s", bs->backup_dir, file_name);

    FILE *dst = fopen(backup_file, "wb");
    if (dst == NULL) {
        perror("fopen");
        fclose(src);
        return -1;
    }

    char buf[BUF_SIZE];
    size_t n;
    while ((n = fread(buf, 1, BUF_SIZE, src)) > 0) {
        fwrite(buf, 1, n, dst);
    }

    fclose(src);
    fclose(dst);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <backup_dir>\n", argv[0]);
        return 1;
    }

    struct backup_system *bs = init_backup_system(argv[1]);
    if (bs == NULL) {
        return 1;
    }

    for (int i = 2; i < argc; i++) {
        if (add_file_to_backup(bs, argv[i]) != 0) {
            fprintf(stderr, "Error adding file %s to backup\n", argv[i]);
            destroy_backup_system(bs);
            return 1;
        }
    }

    for (int i = 0; i < bs->num_files; i++) {
        if (backup_file(bs, bs->files[i].name) != 0) {
            fprintf(stderr, "Error backing up file %s\n", bs->files[i].name);
            destroy_backup_system(bs);
            return 1;
        }
    }

    destroy_backup_system(bs);

    return 0;
}