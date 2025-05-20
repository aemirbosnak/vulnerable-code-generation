//GEMINI-pro DATASET v1.0 Category: System administration ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <libgen.h>
#include <string.h>

// A few handy macros
#define CHECK(expr, msg) if (!(expr)) { perror(msg); exit(EXIT_FAILURE); }
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

// Prototypes
char *my_basename(const char *path);
char *my_dirname(const char *path);
void print_file_info(const char *path);

int main(int argc, char **argv) {
    // Check if we have enough arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the file's information
    struct stat file_info;
    CHECK(stat(argv[1], &file_info) == 0, "stat");

    // Print the file's information
    printf("File: %s\n", argv[1]);
    printf("Size: %ld bytes\n", file_info.st_size);
    printf("Permissions: %03o\n", file_info.st_mode & 0777);
    printf("Owner: %s\n", getpwuid(file_info.st_uid)->pw_name);
    printf("Group: %s\n", getgrgid(file_info.st_gid)->gr_name);
    printf("Last modified: %s", ctime(&file_info.st_mtime));

    // Print the file's basename and dirname
    printf("Basename: %s\n", my_basename(argv[1]));
    printf("Dirname: %s\n", my_dirname(argv[1]));

    return EXIT_SUCCESS;
}

// Returns the basename of a path
char *my_basename(const char *path) {
    char *base;

    base = basename(path);
    if (base == NULL) {
        perror("basename");
        exit(EXIT_FAILURE);
    }

    return base;
}

// Returns the dirname of a path
char *my_dirname(const char *path) {
    char *dir;

    dir = dirname(path);
    if (dir == NULL) {
        perror("dirname");
        exit(EXIT_FAILURE);
    }

    return dir;
}