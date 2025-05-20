//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void list_files(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    
    closedir(dp);
}

void display_file_info(const char *filename) {
    struct stat fileStat;
    
    if (stat(filename, &fileStat) < 0) {
        perror("stat");
        return;
    }

    printf("File: %s\n", filename);
    printf("Size: %ld bytes\n", fileStat.st_size);
    printf("Owner: %u\n", fileStat.st_uid);
    printf("Group: %u\n", fileStat.st_gid);
    printf("Permissions: ");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    printf("Last modified: %s", ctime(&fileStat.st_mtime));
}

void create_directory(const char *dirname) {
    if (mkdir(dirname, 0755) == -1) {
        perror("mkdir");
    } else {
        printf("Directory '%s' created successfully.\n", dirname);
    }
}

void delete_file(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("remove");
    }
}

void display_help() {
    printf("Simple File Manager\n");
    printf("Usage:\n");
    printf("  list <path>          - List files in the directory\n");
    printf("  info <filename>      - Display file information\n");
    printf("  create <dirname>     - Create a new directory\n");
    printf("  delete <filename>    - Delete a file\n");
    printf("  help                 - Display this help message\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Too few arguments. Use 'help' for usage.\n");
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "list") == 0 && argc == 3) {
        list_files(argv[2]);
    } else if (strcmp(argv[1], "info") == 0 && argc == 3) {
        display_file_info(argv[2]);
    } else if (strcmp(argv[1], "create") == 0 && argc == 3) {
        create_directory(argv[2]);
    } else if (strcmp(argv[1], "delete") == 0 && argc == 3) {
        delete_file(argv[2]);
    } else if (strcmp(argv[1], "help") == 0) {
        display_help();
    } else {
        fprintf(stderr, "Invalid command. Use 'help' for usage.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}