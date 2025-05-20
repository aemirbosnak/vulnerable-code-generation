//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

// Function to get the file size in bytes
long long get_file_size(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        perror("stat");
        return -1;
    }
    return statbuf.st_size;
}

// Function to get the file type
char get_file_type(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        perror("stat");
        return -1;
    }
    if (S_ISREG(statbuf.st_mode)) {
        return 'f';
    } else if (S_ISDIR(statbuf.st_mode)) {
        return 'd';
    } else if (S_ISBLK(statbuf.st_mode)) {
        return 'b';
    } else if (S_ISCHR(statbuf.st_mode)) {
        return 'c';
    } else if (S_ISLNK(statbuf.st_mode)) {
        return 'l';
    } else if (S_ISFIFO(statbuf.st_mode)) {
        return 'p';
    } else if (S_ISSOCK(statbuf.st_mode)) {
        return 's';
    } else {
        return '?';
    }
}

// Function to get the file permissions
char *get_file_permissions(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        perror("stat");
        return NULL;
    }
    static char permissions[11];
    permissions[0] = (statbuf.st_mode & S_IRUSR) ? 'r' : '-';
    permissions[1] = (statbuf.st_mode & S_IWUSR) ? 'w' : '-';
    permissions[2] = (statbuf.st_mode & S_IXUSR) ? 'x' : '-';
    permissions[3] = (statbuf.st_mode & S_IRGRP) ? 'r' : '-';
    permissions[4] = (statbuf.st_mode & S_IWGRP) ? 'w' : '-';
    permissions[5] = (statbuf.st_mode & S_IXGRP) ? 'x' : '-';
    permissions[6] = (statbuf.st_mode & S_IROTH) ? 'r' : '-';
    permissions[7] = (statbuf.st_mode & S_IWOTH) ? 'w' : '-';
    permissions[8] = (statbuf.st_mode & S_IXOTH) ? 'x' : '-';
    permissions[9] = '\0';
    return permissions;
}

// Function to get the file owner and group
char *get_file_owner_and_group(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        perror("stat");
        return NULL;
    }
    struct passwd *pw = getpwuid(statbuf.st_uid);
    struct group *gr = getgrgid(statbuf.st_gid);
    static char owner_and_group[50];
    snprintf(owner_and_group, sizeof(owner_and_group), "%s:%s", pw->pw_name, gr->gr_name);
    return owner_and_group;
}

// Function to get the file last modified time
char *get_file_last_modified_time(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        perror("stat");
        return NULL;
    }
    struct tm *tm = localtime(&statbuf.st_mtime);
    static char last_modified_time[26];
    strftime(last_modified_time, sizeof(last_modified_time), "%Y-%m-%d %H:%M:%S", tm);
    return last_modified_time;
}

// Function to print the file information
void print_file_info(const char *path) {
    printf("%c %10lld %s %s %s %s %s\n",
        get_file_type(path),
        get_file_size(path),
        get_file_permissions(path),
        get_file_owner_and_group(path),
        get_file_last_modified_time(path),
        path,
        realpath(path, NULL));
}

// Function to scan a directory and print the file information
void scan_directory(const char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char full_path[PATH_MAX];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        print_file_info(full_path);
    }
    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }
    scan_directory(argv[1]);
    return 0;
}