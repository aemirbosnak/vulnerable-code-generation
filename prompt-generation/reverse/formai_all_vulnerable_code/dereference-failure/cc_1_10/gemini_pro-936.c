//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10MB

struct file_info {
    char name[256];
    size_t size;
    time_t last_modified;
};

struct backup_system {
    char *name;
    char *path;
    struct file_info files[MAX_FILES];
    int num_files;
};

struct backup_system *create_backup_system(char *name, char *path) {
    struct backup_system *bs = malloc(sizeof(struct backup_system));
    bs->name = strdup(name);
    bs->path = strdup(path);
    bs->num_files = 0;
    return bs;
}

void destroy_backup_system(struct backup_system *bs) {
    free(bs->name);
    free(bs->path);
    free(bs);
}

int add_file_to_backup_system(struct backup_system *bs, char *name, size_t size, time_t last_modified) {
    if (bs->num_files >= MAX_FILES) {
        return -1;
    }

    struct file_info *fi = &bs->files[bs->num_files++];
    strcpy(fi->name, name);
    fi->size = size;
    fi->last_modified = last_modified;

    return 0;
}

int remove_file_from_backup_system(struct backup_system *bs, char *name) {
    int i;

    for (i = 0; i < bs->num_files; i++) {
        if (strcmp(bs->files[i].name, name) == 0) {
            break;
        }
    }

    if (i == bs->num_files) {
        return -1;
    }

    memmove(&bs->files[i], &bs->files[i + 1], (bs->num_files - i - 1) * sizeof(struct file_info));
    bs->num_files--;

    return 0;
}

int backup_file(struct backup_system *bs, char *name) {
    FILE *src, *dst;
    char buf[MAX_FILE_SIZE];
    size_t n;

    src = fopen(name, "rb");
    if (src == NULL) {
        return -1;
    }

    dst = fopen(bs->path, "wb");
    if (dst == NULL) {
        fclose(src);
        return -1;
    }

    while ((n = fread(buf, 1, MAX_FILE_SIZE, src)) > 0) {
        fwrite(buf, 1, n, dst);
    }

    fclose(src);
    fclose(dst);

    return 0;
}

int restore_file(struct backup_system *bs, char *name) {
    FILE *src, *dst;
    char buf[MAX_FILE_SIZE];
    size_t n;

    src = fopen(bs->path, "rb");
    if (src == NULL) {
        return -1;
    }

    dst = fopen(name, "wb");
    if (dst == NULL) {
        fclose(src);
        return -1;
    }

    while ((n = fread(buf, 1, MAX_FILE_SIZE, src)) > 0) {
        fwrite(buf, 1, n, dst);
    }

    fclose(src);
    fclose(dst);

    return 0;
}

int main(int argc, char **argv) {
    struct backup_system *bs;
    struct dirent *dirent;
    DIR *dir;
    int i;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <backup-name> <backup-path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    bs = create_backup_system(argv[1], argv[2]);

    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    while ((dirent = readdir(dir)) != NULL) {
        struct stat st;

        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        if (stat(dirent->d_name, &st) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISREG(st.st_mode)) {
            add_file_to_backup_system(bs, dirent->d_name, st.st_size, st.st_mtime);
        }
    }

    closedir(dir);

    for (i = 0; i < bs->num_files; i++) {
        printf("%s %ld %ld\n", bs->files[i].name, bs->files[i].size, bs->files[i].last_modified);
    }

    destroy_backup_system(bs);

    return EXIT_SUCCESS;
}