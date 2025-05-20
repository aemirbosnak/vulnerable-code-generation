//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define MAX_PATH_LEN 256
#define MAX_CMD_LEN 1024

void print_help() {
    printf("Usage: sysadmin_tool [OPTIONS]\n");
    printf("Options:\n");
    printf("  -p, --processes     List all running processes\n");
    printf("  -d, --disk-space    Show disk space usage\n");
    printf("  -u, --user-info     Show user information\n");
    printf("  -h, --help          Display this help message\n");
}

void list_processes() {
    FILE *fp;
    char path[MAX_CMD_LEN];
    printf("\n--- Running Processes ---\n");
    // Use the ps command to get running processes
    fp = popen("ps aux", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }
    while (fgets(path, sizeof(path), fp) != NULL) {
        printf("%s", path);
    }
    pclose(fp);
}

void display_disk_usage() {
    printf("\n--- Disk Usage ---\n");
    // Use the df command to check disk space
    system("df -h");
}

void user_info() {
    printf("\n--- User Information ---\n");
    struct passwd *pw = getpwuid(getuid());
    printf("User ID: %d\n", getuid());
    printf("User Name: %s\n", pw->pw_name);
    printf("Home Directory: %s\n", pw->pw_dir);
    printf("Shell: %s\n", pw->pw_shell);
}

void create_backup(const char *source, const char *backup) {
    FILE *src, *dest;
    char buffer[BUFSIZ];
    size_t n;

    // Try opening the source file for reading
    src = fopen(source, "rb");
    if (src == NULL) {
        perror("Failed to open source file");
        return;
    }
    
    // Try opening the destination file for writing
    dest = fopen(backup, "wb");
    if (dest == NULL) {
        perror("Failed to open backup file");
        fclose(src);
        return;
    }

    // Copy the contents from source to backup
    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dest);
    }
    
    fclose(src);
    fclose(dest);
    printf("Backup of '%s' created as '%s'\n", source, backup);
}

void clean_temp_files() {
    const char *temp_dir = "/tmp";
    DIR *dir;
    struct dirent *entry;

    printf("\n--- Cleaning Temporary Files ---\n");
    dir = opendir(temp_dir);
    if (dir == NULL) {
        perror("Error opening temp directory");
        return;
    }

    // Iterate over all entries in the temp directory
    while ((entry = readdir(dir)) != NULL) {
        char filepath[MAX_PATH_LEN];
        snprintf(filepath, sizeof(filepath), "%s/%s", temp_dir, entry->d_name);

        // Skip current and parent directory entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            if (remove(filepath) == 0) {
                printf("Deleted: %s\n", filepath);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No options provided.\n");
        print_help();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        print_help();
    } else if (strcmp(argv[1], "--processes") == 0 || strcmp(argv[1], "-p") == 0) {
        list_processes();
    } else if (strcmp(argv[1], "--disk-space") == 0 || strcmp(argv[1], "-d") == 0) {
        display_disk_usage();
    } else if (strcmp(argv[1], "--user-info") == 0 || strcmp(argv[1], "-u") == 0) {
        user_info();
    } else if (strcmp(argv[1], "--backup") == 0) {
        if (argc != 4) {
            fprintf(stderr, "Usage: sysadmin_tool --backup [source] [backup]\n");
            return EXIT_FAILURE;
        }
        create_backup(argv[2], argv[3]);
    } else if (strcmp(argv[1], "--clean-temp") == 0) {
        clean_temp_files();
    } else {
        fprintf(stderr, "Error: Unknown option '%s'\n", argv[1]);
        print_help();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}