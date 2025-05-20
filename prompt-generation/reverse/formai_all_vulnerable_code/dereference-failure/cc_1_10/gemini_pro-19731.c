//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

static const unsigned long KB = 1024;
static const unsigned long MB = KB * KB;
static const unsigned long GB = MB * KB;

static void print_dir(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char fullpath[PATH_MAX];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (lstat(fullpath, &statbuf) == -1) {
            perror("lstat");
            continue;
        }

        printf("%s %s %s %ld ", entry->d_name,
               getpwuid(statbuf.st_uid)->pw_name,
               getgrgid(statbuf.st_gid)->gr_name,
               statbuf.st_mtime);

        switch (statbuf.st_mode & S_IFMT) {
            case S_IFDIR:  printf("dir\n"); break;
            case S_IFREG:  printf("%ld bytes\n", statbuf.st_size); break;
            case S_IFLNK:  printf("link\n"); break;
            case S_IFIFO:  printf("fifo\n"); break;
            case S_IFSOCK: printf("socket\n"); break;
            default:       printf("unknown\n"); break;
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    char path[PATH_MAX];
    if (argc > 1) {
        strncpy(path, argv[1], sizeof(path));
    } else {
        getcwd(path, sizeof(path));
    }

    print_dir(path);
    return 0;
}