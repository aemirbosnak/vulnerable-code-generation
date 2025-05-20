//FormAI DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 256

void print_usage()
{
    printf("Usage: sysadmin [command] [argument]\n");
    printf("\n");
    printf("Commands:\n");
    printf("         create [dir/file] [path] - create a directory or file at specified path\n");
    printf("         delete [dir/file] [path] - delete a directory or file at specified path\n");
    printf("         move [src] [dst] - move a file or directory from source path to destination path\n");
    printf("         copy [src] [dst] - copy a file or directory from source path to destination path\n");
    printf("         info [path] - print information about specified file or directory\n");
}

void print_info(const char *path)
{
    struct stat st;
    if (stat(path, &st) != 0) {
        printf("Could not get information about '%s'\n", path);
        return;
    }

    if (S_ISREG(st.st_mode))
        printf("Type: Regular file\n");
    else if (S_ISDIR(st.st_mode))
        printf("Type: Directory\n");
    else
        printf("Type: Other\n");

    printf("Size: %zd bytes\n", st.st_size);
    printf("Owner: %d\n", st.st_uid);
    printf("Group: %d\n", st.st_gid);
    printf("Permissions: %o\n", st.st_mode & 0777);
}

void create_file(const char *path)
{
    FILE *fp = fopen(path, "w");
    if (fp == NULL) {
        printf("Failed to create file at '%s'\n", path);
        return;
    }

    fclose(fp);
    printf("Created file at '%s'\n", path);
}

void create_dir(const char *path)
{
    if (mkdir(path, 0777) != 0) {
        printf("Failed to create directory at '%s'\n", path);
        return;
    }

    printf("Created directory at '%s'\n", path);
}

void delete_file(const char *path)
{
    if (remove(path) != 0) {
        printf("Failed to delete file at '%s'\n", path);
        return;
    }

    printf("Deleted file at '%s'\n", path);
}

void delete_dir(const char *path)
{
    if (rmdir(path) != 0) {
        printf("Failed to delete directory at '%s'\n", path);
        return;
    }

    printf("Deleted directory at '%s'\n", path);
}

void move_file(const char *src, const char *dst)
{
    if (rename(src, dst) != 0) {
        printf("Failed to move file from '%s' to '%s'\n", src, dst);
        return;
    }

    printf("Moved file from '%s' to '%s'\n", src, dst);
}

void copy_file(const char *src, const char *dst)
{
    FILE *src_fp = fopen(src, "r");
    FILE *dst_fp = fopen(dst, "w");
    if (src_fp == NULL || dst_fp == NULL) {
        printf("Failed to copy file from '%s' to '%s'\n", src, dst);
        return;
    }

    char buffer[1024];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), src_fp)) > 0) {
        if (fwrite(buffer, 1, n, dst_fp) != n) {
            printf("Failed to copy file from '%s' to '%s'\n", src, dst);
            fclose(src_fp);
            fclose(dst_fp);
            return;
        }
    }

    fclose(src_fp);
    fclose(dst_fp);
    printf("Copied file from '%s' to '%s'\n", src, dst);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        print_usage();
        return 1;
    }

    if (strcmp(argv[1], "create") == 0) {
        if (argc != 4) {
            printf("create command requires two arguments: type and path\n");
            return 1;
        }

        char path[MAX_PATH_LEN];
        if (realpath(argv[3], path) == NULL) {
            printf("Invalid path: '%s'\n", argv[3]);
            return 1;
        }

        if (strcmp(argv[2], "dir") == 0)
            create_dir(path);
        else if (strcmp(argv[2], "file") == 0)
            create_file(path);
        else {
            printf("Invalid create type: '%s'\n", argv[2]);
            return 1;
        }
    } else if (strcmp(argv[1], "delete") == 0) {
        if (argc != 4) {
            printf("delete command requires two arguments: type and path\n");
            return 1;
        }

        char path[MAX_PATH_LEN];
        if (realpath(argv[3], path) == NULL) {
            printf("Invalid path: '%s'\n", argv[3]);
            return 1;
        }

        if (strcmp(argv[2], "dir") == 0)
            delete_dir(path);
        else if (strcmp(argv[2], "file") == 0)
            delete_file(path);
        else {
            printf("Invalid delete type: '%s'\n", argv[2]);
            return 1;
        }
    } else if (strcmp(argv[1], "move") == 0) {
        if (argc != 4) {
            printf("move command requires two arguments: src and dst\n");
            return 1;
        }

        char src[MAX_PATH_LEN], dst[MAX_PATH_LEN];
        if (realpath(argv[2], src) == NULL || realpath(argv[3], dst) == NULL) {
            printf("Invalid path: '%s' or '%s'\n", argv[2], argv[3]);
            return 1;
        }

        move_file(src, dst);
    } else if (strcmp(argv[1], "copy") == 0) {
        if (argc != 4) {
            printf("copy command requires two arguments: src and dst\n");
            return 1;
        }

        char src[MAX_PATH_LEN], dst[MAX_PATH_LEN];
        if (realpath(argv[2], src) == NULL || realpath(argv[3], dst) == NULL) {
            printf("Invalid path: '%s' or '%s'\n", argv[2], argv[3]);
            return 1;
        }

        copy_file(src, dst);
    } else if (strcmp(argv[1], "info") == 0) {
        if (argc != 3) {
            printf("info command requires one argument: path\n");
            return 1;
        }

        char path[MAX_PATH_LEN];
        if (realpath(argv[2], path) == NULL) {
            printf("Invalid path: '%s'\n", argv[2]);
            return 1;
        }

        print_info(path);
    } else {
        printf("Invalid command: '%s'\n", argv[1]);
        print_usage();
        return 1;
    }

    return 0;
}