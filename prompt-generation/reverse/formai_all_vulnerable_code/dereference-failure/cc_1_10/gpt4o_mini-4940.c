//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void list_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dp);
}

void display_file_info(const char *file_path) {
    struct stat file_stat;
    
    if (stat(file_path, &file_stat) == -1) {
        perror("stat");
        return;
    }

    printf("File: %s\n", file_path);
    printf("Size: %ld bytes\n", file_stat.st_size);
    printf("Permissions: ");

    printf((S_ISDIR(file_stat.st_mode)) ? "d" : "-");
    printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
    printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
    printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
    printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
    printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
    printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    struct passwd *pw = getpwuid(file_stat.st_uid);
    struct group *gr = getgrgid(file_stat.st_gid);
    char timebuf[80];
    struct tm *tm_info;

    tm_info = localtime(&file_stat.st_mtime);
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tm_info);

    printf("Owner: %s\n", (pw != NULL) ? pw->pw_name : "Unknown");
    printf("Group: %s\n", (gr != NULL) ? gr->gr_name : "Unknown");
    printf("Last modified: %s\n", timebuf);
    printf("\n");
}

void create_file(const char *file_name) {
    FILE *file = fopen(file_name, "w");
    if (file != NULL) {
        fprintf(file, "This is a test file.\n");
        fclose(file);
        printf("File '%s' created successfully.\n", file_name);
    } else {
        perror("Error creating file");
    }
}

void delete_file(const char *file_name) {
    if (remove(file_name) == 0) {
        printf("File '%s' deleted successfully.\n", file_name);
    } else {
        perror("Error deleting file");
    }
}

void display_help() {
    printf("Minimalist System Administration Program:\n");
    printf("Usage:\n");
    printf("  list <directory>           - List files in the directory\n");
    printf("  info <file>                - Display information about the file\n");
    printf("  create <file>              - Create a file\n");
    printf("  delete <file>              - Delete a file\n");
    printf("  help                       - Display this help message\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Insufficient arguments. Use 'help' for more information.\n");
        return 1;
    }

    if (strcmp(argv[1], "list") == 0 && argc == 3) {
        list_directory(argv[2]);
    } else if (strcmp(argv[1], "info") == 0 && argc == 3) {
        display_file_info(argv[2]);
    } else if (strcmp(argv[1], "create") == 0 && argc == 3) {
        create_file(argv[2]);
    } else if (strcmp(argv[1], "delete") == 0 && argc == 3) {
        delete_file(argv[2]);
    } else if (strcmp(argv[1], "help") == 0) {
        display_help();
    } else {
        printf("Invalid command. Use 'help' for more information.\n");
    }

    return 0;
}