//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

int main() {
    DIR *d;
    struct dirent *dir;
    struct stat buf;
    char *homedir;
    struct passwd *pw;
    struct group *gr;
    
    homedir = getenv("HOME");
    if (homedir == NULL) {
        perror("getenv");
        exit(1);
    }
    
    d = opendir(homedir);
    if (d == NULL) {
        perror("opendir");
        exit(1);
    }
    
    while ((dir = readdir(d)) != NULL) {
        if (lstat(dir->d_name, &buf) == -1) {
            perror("lstat");
            continue;
        }
        
        if (S_ISDIR(buf.st_mode)) {
            printf("d");
        } else if (S_ISREG(buf.st_mode)) {
            printf("-");
        } else if (S_ISCHR(buf.st_mode)) {
            printf("c");
        } else if (S_ISBLK(buf.st_mode)) {
            printf("b");
        } else if (S_ISFIFO(buf.st_mode)) {
            printf("p");
        } else if (S_ISLNK(buf.st_mode)) {
            printf("l");
        } else if (S_ISSOCK(buf.st_mode)) {
            printf("s");
        } else {
            printf("?");
        }
        
        printf((buf.st_mode & S_IRUSR) ? "r" : "-");
        printf((buf.st_mode & S_IWUSR) ? "w" : "-");
        printf((buf.st_mode & S_IXUSR) ? "x" : "-");
        printf((buf.st_mode & S_IRGRP) ? "r" : "-");
        printf((buf.st_mode & S_IWGRP) ? "w" : "-");
        printf((buf.st_mode & S_IXGRP) ? "x" : "-");
        printf((buf.st_mode & S_IROTH) ? "r" : "-");
        printf((buf.st_mode & S_IWOTH) ? "w" : "-");
        printf((buf.st_mode & S_IXOTH) ? "x" : "-");
        
        printf(" %3ld", buf.st_nlink);
        
        pw = getpwuid(buf.st_uid);
        if (pw == NULL) {
            printf(" %s", "?");
        } else {
            printf(" %s", pw->pw_name);
        }
        
        gr = getgrgid(buf.st_gid);
        if (gr == NULL) {
            printf(" %s", "?");
        } else {
            printf(" %s", gr->gr_name);
        }
        
        printf(" %9ld %s\n", buf.st_size, dir->d_name);
    }
    
    closedir(d);
    
    return 0;
}