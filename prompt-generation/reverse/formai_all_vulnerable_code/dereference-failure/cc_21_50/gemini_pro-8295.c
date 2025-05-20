//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>

// Define the maximum length of a file name
#define MAX_FILE_NAME_LENGTH 256

// Define the maximum number of files to display
#define MAX_FILES 100

// Define the format strings for printing the file information
#define FILE_FORMAT_STRING "%-20s %-8s %-8s %-12s %s\n"
#define DIR_FORMAT_STRING "%-20s %-8s %-8s %-12s %s/\n"

// Declare the main function
int main(int argc, char **argv) {
    // Check if the user has specified a directory to list
    if (argc < 2) {
        // If not, use the current working directory
        argv[1] = ".";
    }

    // Open the directory
    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        // If the directory could not be opened, print an error message and exit
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Get the current working directory
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        // If the current working directory could not be obtained, print an error message and exit
        perror("getcwd");
        return EXIT_FAILURE;
    }

    // Allocate memory for the file names
    char **files = malloc(sizeof(char *) * MAX_FILES);
    if (files == NULL) {
        // If the memory could not be allocated, print an error message and exit
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Read the directory entries
    int num_files = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Ignore hidden files
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Allocate memory for the file name
        files[num_files] = malloc(strlen(entry->d_name) + 1);
        if (files[num_files] == NULL) {
            // If the memory could not be allocated, print an error message and exit
            perror("malloc");
            return EXIT_FAILURE;
        }

        // Copy the file name
        strcpy(files[num_files], entry->d_name);

        // Increment the number of files
        num_files++;

        // Check if the maximum number of files has been reached
        if (num_files >= MAX_FILES) {
            break;
        }
    }

    // Close the directory
    closedir(dir);

    // Sort the file names
    qsort(files, num_files, sizeof(char *), strcmp);

    // Print the file information
    printf("Directory: %s\n", cwd);
    printf("--------------------------------------------------------------------------------\n");
    printf(FILE_FORMAT_STRING, "Name", "Size", "Type", "Modified", "Permissions");
    for (int i = 0; i < num_files; i++) {
        // Get the file status
        struct stat st;
        if (lstat(files[i], &st) == -1) {
            // If the file status could not be obtained, print an error message
            perror("lstat");
            continue;
        }

        // Get the file size
        char size[16];
        if (st.st_size < 1024) {
            snprintf(size, sizeof(size), "%ld bytes", st.st_size);
        } else if (st.st_size < 1024 * 1024) {
            snprintf(size, sizeof(size), "%.1f KB", (double)st.st_size / 1024);
        } else if (st.st_size < 1024 * 1024 * 1024) {
            snprintf(size, sizeof(size), "%.1f MB", (double)st.st_size / (1024 * 1024));
        } else {
            snprintf(size, sizeof(size), "%.1f GB", (double)st.st_size / (1024 * 1024 * 1024));
        }

        // Get the file type
        char type;
        if (S_ISREG(st.st_mode)) {
            type = '-';
        } else if (S_ISDIR(st.st_mode)) {
            type = 'd';
        } else if (S_ISLNK(st.st_mode)) {
            type = 'l';
        } else if (S_ISBLK(st.st_mode)) {
            type = 'b';
        } else if (S_ISCHR(st.st_mode)) {
            type = 'c';
        } else if (S_ISFIFO(st.st_mode)) {
            type = 'p';
        } else if (S_ISSOCK(st.st_mode)) {
            type = 's';
        } else {
            type = '?';
        }

        // Get the file modification time
        char mtime[32];
        strftime(mtime, sizeof(mtime), "%Y-%m-%d %H:%M:%S", localtime(&st.st_mtime));

        // Get the file permissions
        char perms[11];
        perms[0] = (st.st_mode & S_IRUSR) ? 'r' : '-';
        perms[1] = (st.st_mode & S_IWUSR) ? 'w' : '-';
        perms[2] = (st.st_mode & S_IXUSR) ? 'x' : '-';
        perms[3] = (st.st_mode & S_IRGRP) ? 'r' : '-';
        perms[4] = (st.st_mode & S_IWGRP) ? 'w' : '-';
        perms[5] = (st.st_mode & S_IXGRP) ? 'x' : '-';
        perms[6] = (st.st_mode & S_IROTH) ? 'r' : '-';
        perms[7] = (st.st_mode & S_IWOTH) ? 'w' : '-';
        perms[8] = (st.st_mode & S_IXOTH) ? 'x' : '-';
        perms[9] = '\0';

        // Print the file information
        if (type == 'd') {
            printf(DIR_FORMAT_STRING, files[i], size, perms, mtime, files[i]);
        } else {
            printf(FILE_FORMAT_STRING, files[i], size, &type, mtime, perms);
        }

        // Free the memory for the file name
        free(files[i]);
    }

    // Free the memory for the file names
    free(files);

    // Return success
    return EXIT_SUCCESS;
}