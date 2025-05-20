//FormAI DATASET v1.0 Category: File Synchronizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Declaration of the function to synchronize files
int file_synchronizer(const char *src_path, const char *dest_path);

int main(int argc, char *argv[])
{
    if(argc !=3){
        printf("Usage: %s source_folder destination_folder\n", argv[0]);
        exit(1);
    }
    file_synchronizer(argv[1], argv[2]);
    printf("Successfully synchronized files!\n");
    return 0;
}

/* This function synchronizes files from a source folder to a destination folder.
 * The function returns 0 on success and -1 on failure.
 * src_path - The path of the source folder.
 * dest_path - The path of the destination folder.
 */
int file_synchronizer(const char *src_path, const char *dest_path)
{
    DIR *src_dir, *dest_dir;
    struct dirent *src_dent, *dest_dent;
    struct stat src_stat, dest_stat;
    char src_file_name[256], dest_file_name[256];
    char src_file_path[512], dest_file_path[512];
    int src_fd, dest_fd, n;
    ssize_t len;
    unsigned char src_buf[BUFSIZ], dest_buf[BUFSIZ];

    // Open source directory
    src_dir = opendir(src_path);
    if (src_dir == NULL) {
        printf("Error opening source directory: %s\n", src_path);
        return -1;
    }

    // Open destination directory
    dest_dir = opendir(dest_path);
    if (dest_dir == NULL) {
        printf("Error opening destination directory: %s\n", dest_path);
        closedir(src_dir);
        return -1;
    }

    // Loop through files in source directory
    while ((src_dent = readdir(src_dir))) {
        // Skip parent and current directory
        if (strcmp(src_dent->d_name, "..") == 0 || strcmp(src_dent->d_name, ".") == 0) continue;

        // Construct path to source file
        snprintf(src_file_path, sizeof(src_file_path), "%s/%s", src_path, src_dent->d_name);

        // Get stat information on the source file
        if (stat(src_file_path, &src_stat) == -1) {
            printf("Error getting stat on source file: %s\n", src_file_path);
            continue;
        }

        // Construct path to destination file
        snprintf(dest_file_path, sizeof(dest_file_path), "%s/%s", dest_path, src_dent->d_name);

        // Check if destination file already exists
        if (stat(dest_file_path, &dest_stat) != -1) {
            // Check if source file is older than destination file
            if (src_stat.st_mtime <= dest_stat.st_mtime) continue;

            // Delete destination file
            if (unlink(dest_file_path) != 0) {
                printf("Error deleting destination file: %s\n", dest_file_path);
                continue;
            }
        }

        // Open source file
        src_fd = open(src_file_path, O_RDONLY);
        if (src_fd == -1) {
            printf("Error opening source file: %s\n", src_file_path);
            continue;
        }

        // Open destination file
        dest_fd = open(dest_file_path, O_CREAT | O_WRONLY | O_TRUNC, src_stat.st_mode);
        if (dest_fd == -1) {
            printf("Error opening destination file: %s\n", dest_file_path);
            close(src_fd);
            continue;
        }

        // Loop through file contents
        while ((len = read(src_fd, src_buf, BUFSIZ)) > 0) {
            for (n = 0; n < len; n = n + write(dest_fd, dest_buf + n, len - n));
        }

        // Close source file
        close(src_fd);

        // Close destination file
        close(dest_fd);
    }

    // Close source directory
    closedir(src_dir);

    // Close destination directory
    closedir(dest_dir);

    return 0;
}