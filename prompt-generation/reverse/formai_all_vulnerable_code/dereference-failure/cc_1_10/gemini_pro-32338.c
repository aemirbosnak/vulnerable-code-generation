//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

// Colors for printing
#define COLOR_RESET "\x1b[0m"
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_WHITE "\x1b[37m"

// File types
#define FILE_TYPE_DIR "d"
#define FILE_TYPE_FILE "-"
#define FILE_TYPE_LINK "l"
#define FILE_TYPE_FIFO "p"
#define FILE_TYPE_SOCK "s"
#define FILE_TYPE_BLK "b"
#define FILE_TYPE_CHR "c"

// File permissions
#define FILE_PERM_OWNER_READ "r"
#define FILE_PERM_OWNER_WRITE "w"
#define FILE_PERM_OWNER_EXECUTE "x"
#define FILE_PERM_GROUP_READ "r"
#define FILE_PERM_GROUP_WRITE "w"
#define FILE_PERM_GROUP_EXECUTE "x"
#define FILE_PERM_OTHER_READ "r"
#define FILE_PERM_OTHER_WRITE "w"
#define FILE_PERM_OTHER_EXECUTE "x"

// Function to get the file size in a human-readable format
char *get_file_size(off_t size) {
    char *units[] = {"B", "KB", "MB", "GB", "TB", "PB"};
    int i = 0;
    while (size >= 1024 && i < 5) {
        size /= 1024;
        i++;
    }
    char *result = malloc(sizeof(char) * 10);
    sprintf(result, "%.1f %s", (double)size, units[i]);
    return result;
}

// Function to print the file information
void print_file_info(const char *pathname, struct stat *statbuf) {
    char *file_type;
    switch (statbuf->st_mode & S_IFMT) {
        case S_IFDIR:
            file_type = FILE_TYPE_DIR;
            break;
        case S_IFREG:
            file_type = FILE_TYPE_FILE;
            break;
        case S_IFLNK:
            file_type = FILE_TYPE_LINK;
            break;
        case S_IFIFO:
            file_type = FILE_TYPE_FIFO;
            break;
        case S_IFSOCK:
            file_type = FILE_TYPE_SOCK;
            break;
        case S_IFBLK:
            file_type = FILE_TYPE_BLK;
            break;
        case S_IFCHR:
            file_type = FILE_TYPE_CHR;
            break;
        default:
            file_type = "?";
            break;
    }

    // Get the file permissions
    char file_perms[11];
    file_perms[0] = file_type;
    file_perms[1] = (statbuf->st_mode & S_IRUSR) ? FILE_PERM_OWNER_READ : '-';
    file_perms[2] = (statbuf->st_mode & S_IWUSR) ? FILE_PERM_OWNER_WRITE : '-';
    file_perms[3] = (statbuf->st_mode & S_IXUSR) ? FILE_PERM_OWNER_EXECUTE : '-';
    file_perms[4] = (statbuf->st_mode & S_IRGRP) ? FILE_PERM_GROUP_READ : '-';
    file_perms[5] = (statbuf->st_mode & S_IWGRP) ? FILE_PERM_GROUP_WRITE : '-';
    file_perms[6] = (statbuf->st_mode & S_IXGRP) ? FILE_PERM_GROUP_EXECUTE : '-';
    file_perms[7] = (statbuf->st_mode & S_IROTH) ? FILE_PERM_OTHER_READ : '-';
    file_perms[8] = (statbuf->st_mode & S_IWOTH) ? FILE_PERM_OTHER_WRITE : '-';
    file_perms[9] = (statbuf->st_mode & S_IXOTH) ? FILE_PERM_OTHER_EXECUTE : '-';
    file_perms[10] = '\0';

    // Get the file owner and group
    struct passwd *pw = getpwuid(statbuf->st_uid);
    struct group *gr = getgrgid(statbuf->st_gid);

    // Print the file information
    printf("%s %s %s %u %s %s %s\n",
        file_perms,
        pw->pw_name,
        gr->gr_name,
        (unsigned int)statbuf->st_size,
        ctime(&statbuf->st_mtime),
        pathname,
        (statbuf->st_mode & S_ISUID) ? COLOR_RED "suid" COLOR_RESET : "",
        (statbuf->st_mode & S_ISGID) ? COLOR_GREEN "sgid" COLOR_RESET : "",
        (statbuf->st_mode & S_ISVTX) ? COLOR_BLUE "sticky" COLOR_RESET : "");
}

// Function to scan the directory and print the file information
void scan_directory(const char *dirname) {
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char *pathname = malloc(strlen(dirname) + strlen(entry->d_name) + 2);
        sprintf(pathname, "%s/%s", dirname, entry->d_name);

        struct stat statbuf;
        if (lstat(pathname, &statbuf) == -1) {
            perror("lstat");
            continue;
        }

        print_file_info(pathname, &statbuf);

        free(pathname);
    }

    closedir(dir);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);

    return EXIT_SUCCESS;
}