//FormAI DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX_PATH_LEN 1024
#define BUFF_SIZE 4096

char *src_dir;
char *dest_dir;

void *backup_thread(void *arg) {
    char pathname[MAX_PATH_LEN];
    char buffer[BUFF_SIZE];
    int src, dest, n;

    strcpy(pathname, (char *) arg);

    // Construct source and destination paths
    char *src_path = (char *) malloc(strlen(src_dir) + strlen(pathname) + 2);
    sprintf(src_path, "%s/%s", src_dir, pathname);

    char *dest_path = (char *) malloc(strlen(dest_dir) + strlen(pathname) + 2);
    sprintf(dest_path, "%s/%s", dest_dir, pathname);

    // Open source and destination files
    src = open(src_path, O_RDONLY);
    dest = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);

    // Copy source file to destination file
    while ((n = read(src, buffer, BUFF_SIZE)) > 0) {
        write(dest, buffer, n);
    }
    close(src);
    close(dest);

    // Free allocated memory
    free(src_path);
    free(dest_path);

    // Exit thread
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    pthread_t threads[1024];
    int i = 0;

    // Check command line arguments
    if (argc != 3) {
        printf("Usage: backup src_dir dest_dir\n");
        return 1;
    }
    src_dir = argv[1];
    dest_dir = argv[2];

    // Create destination directory
    mkdir(dest_dir, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);

    // Open source directory
    DIR *dir = opendir(src_dir);
    if (!dir) {
        printf("Error: Source directory '%s' not found\n", src_dir);
        return 1;
    }

    // Read source directory contents and backup files
    struct dirent *entry;
    while ((entry = readdir(dir))) {
        // Skip '.' and '..' directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        // Create and start backup thread
        pthread_create(&threads[i++], NULL, backup_thread, entry->d_name);
    }

    // Wait for all backup threads to complete
    for (int j = 0; j < i; j++) {
        pthread_join(threads[j], NULL);
    }
    closedir(dir);
    return 0;
}