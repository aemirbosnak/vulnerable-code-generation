//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

#define MAX_PATH_LENGTH 1024
#define BUFFER_SIZE 256

void print_file_info(const char *filepath) {
    struct stat file_info;
    if (stat(filepath, &file_info) != 0) {
        perror("stat");
        return;
    }

    printf("File: %s\n", filepath);
    printf("Type: %s\n", S_ISDIR(file_info.st_mode) ? "Directory" : "File");
    printf("Size: %lld bytes\n", (long long)file_info.st_size);
    printf("Owner: %s (UID: %d)\n", getpwuid(file_info.st_uid)->pw_name, file_info.st_uid);
    printf("Group: %s (GID: %d)\n", getgrgid(file_info.st_gid)->gr_name, file_info.st_gid);
    printf("Permissions: ");
    printf((file_info.st_mode & S_IRUSR) ? "r" : "-");
    printf((file_info.st_mode & S_IWUSR) ? "w" : "-");
    printf((file_info.st_mode & S_IXUSR) ? "x" : "-");
    printf((file_info.st_mode & S_IRGRP) ? "r" : "-");
    printf((file_info.st_mode & S_IWGRP) ? "w" : "-");
    printf((file_info.st_mode & S_IXGRP) ? "x" : "-");
    printf((file_info.st_mode & S_IROTH) ? "r" : "-");
    printf((file_info.st_mode & S_IWOTH) ? "w" : "-");
    printf((file_info.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}

void list_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Listing directory: %s\n", dir_path);
    while ((entry = readdir(dp)) != NULL) {
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        print_file_info(full_path);
        printf("\n");
    }
    
    closedir(dp);
}

void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("fopen");
        return;
    }
    fputs("This is a new file created by the C System Administration Program.\n", file);
    fclose(file);
    printf("File created: %s\n", filename);
}

void remove_file(const char *filename) {
    if (remove(filename) == 0) {
        printf("File removed: %s\n", filename);
    } else {
        perror("remove");
    }
}

void display_help() {
    printf("C System Administration Program\n");
    printf("Usage:\n");
    printf("  list <directory>\tList all files in the specified directory.\n");
    printf("  create <filename>\tCreate a new file with the given filename.\n");
    printf("  remove <filename>\tRemove an existing file with the given filename.\n");
    printf("  help\t\t\tDisplay this help message.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Insufficient arguments. Use 'help' to see usage info.\n");
        return 1;
    }

    if (strcmp(argv[1], "list") == 0 && argc == 3) {
        list_directory(argv[2]);
    } else if (strcmp(argv[1], "create") == 0 && argc == 3) {
        create_file(argv[2]);
    } else if (strcmp(argv[1], "remove") == 0 && argc == 3) {
        remove_file(argv[2]);
    } else if (strcmp(argv[1], "help") == 0) {
        display_help();
    } else {
        printf("Invalid command. Use 'help' to see usage info.\n");
    }

    return 0;
}