//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

#define MAX_DIR_LENGTH 1024
#define MAX_LINE_LENGTH 256

void list_files(const char* dir_path);
void get_file_info(const char* file_path);
void copy_file(const char* source, const char* destination);
void display_help();

int main(int argc, char* argv[]) {
    if (argc < 2) {
        display_help();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "list") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Please provide a directory path.\n");
            return EXIT_FAILURE;
        }
        list_files(argv[2]);
    } else if (strcmp(argv[1], "info") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Please provide a file path.\n");
            return EXIT_FAILURE;
        }
        get_file_info(argv[2]);
    } else if (strcmp(argv[1], "copy") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Please provide a source and destination file path.\n");
            return EXIT_FAILURE;
        }
        copy_file(argv[2], argv[3]);
    } else {
        display_help();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void display_help() {
    printf("Usage:\n");
    printf("  sysadmin_tool list <directory_path>   - List files in the specified directory\n");
    printf("  sysadmin_tool info <file_path>        - Get information about the specified file\n");
    printf("  sysadmin_tool copy <source> <dest>    - Copy a file from source to destination\n");
}

void list_files(const char* dir_path) {
    struct dirent* entry;
    DIR* dp = opendir(dir_path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Listing files in directory: %s\n", dir_path);
    while ((entry = readdir(dp))) {
        if (entry->d_name[0] != '.') {  // Skip hidden files
            printf("  - %s\n", entry->d_name);
        }
    }
    closedir(dp);
}

void get_file_info(const char* file_path) {
    struct stat file_stat;
    if (stat(file_path, &file_stat) < 0) {
        perror("stat");
        return;
    }

    struct passwd* pw = getpwuid(file_stat.st_uid);
    struct group* gr = getgrgid(file_stat.st_gid);
    
    printf("File: %s\n", file_path);
    printf("Size: %lld bytes\n", (long long)file_stat.st_size);
    printf("Owner: %s (UID: %d)\n", pw ? pw->pw_name : "unknown", file_stat.st_uid);
    printf("Group: %s (GID: %d)\n", gr ? gr->gr_name : "unknown", file_stat.st_gid);
    printf("Permissions: %o\n", file_stat.st_mode & 0777);
    printf("Last modified: %s", ctime(&file_stat.st_mtime));
}

void copy_file(const char* source, const char* destination) {
    FILE* src_file = fopen(source, "rb");
    if (src_file == NULL) {
        perror("fopen source");
        return;
    }

    FILE* dest_file = fopen(destination, "wb");
    if (dest_file == NULL) {
        fclose(src_file);
        perror("fopen destination");
        return;
    }

    char buffer[BUFSIZ];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    printf("Copied file from %s to %s\n", source, destination);
}