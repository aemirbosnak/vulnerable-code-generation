//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <sys/utsname.h>
#include <time.h>

void print_file_info(const char *filename) {
    struct stat fileStat;
    
    if (stat(filename, &fileStat) < 0) {
        perror("Could not get file info");
        return;
    }

    printf("File: %s\n", filename);
    printf("Size: %lld bytes\n", (long long) fileStat.st_size);
    printf("Owner: %d\n", fileStat.st_uid);
    printf("Group: %d\n", fileStat.st_gid);
    printf("Permissions: %o\n", fileStat.st_mode & 0777);
    printf("Last accessed: %s", ctime(&fileStat.st_atime));
    printf("Last modified: %s", ctime(&fileStat.st_mtime));
    printf("Last status change: %s\n", ctime(&fileStat.st_ctime));
}

void list_directory(const char *dir_name) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);

    if (dp == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] != '.') { // Skip hidden files
            print_file_info(entry->d_name);
        }
    }
    closedir(dp);
}

void get_system_info() {
    struct utsname sys_info;
    if (uname(&sys_info) < 0) {
        perror("Could not get system info");
        return;
    }
    
    printf("System Name: %s\n", sys_info.sysname);
    printf("Node Name: %s\n", sys_info.nodename);
    printf("Release: %s\n", sys_info.release);
    printf("Version: %s\n", sys_info.version);
    printf("Machine: %s\n", sys_info.machine);
    
    // Get current user info
    struct passwd *pw = getpwuid(getuid());
    struct group *gr = getgrgid(getgid());

    if (pw != NULL && gr != NULL) {
        printf("Current User: %s (UID: %d)\n", pw->pw_name, pw->pw_uid);
        printf("Current Group: %s (GID: %d)\n", gr->gr_name, gr->gr_gid);
    }

    printf("Current Time: %s", ctime(&(time_t){time(NULL)}));
}

void print_help() {
    printf("Usage: sysadmin_util [OPTION]\n");
    printf("Options:\n");
    printf("   -l, --list <directory>     List files in the specified directory\n");
    printf("   -si, --system-info         Display system information\n");
    printf("   -h, --help                 Show this help message\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_help();
        return 1;
    }

    if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0) {
        list_directory(argv[2]);
    } else if (strcmp(argv[1], "-si") == 0 || strcmp(argv[1], "--system-info") == 0) {
        get_system_info();
    } else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_help();
    } else {
        fprintf(stderr, "Unknown option: %s\n", argv[1]);
        print_help();
        return 1;
    }

    return 0;
}