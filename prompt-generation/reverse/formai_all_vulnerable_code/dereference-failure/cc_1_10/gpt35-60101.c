//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// function to scan the disk space
void scan_disk_space(char* directory, int depth, int* dir_count, int* file_count, long* total_size) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;

    // open the directory
    if(!(dir = opendir(directory))) {
        printf("Could not open directory %s\n", directory);
        return;
    }

    // read the directory entries
    while((entry = readdir(dir)) != NULL) {
        // skip the current and parent directories
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // create the complete path of the entry
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

        // get the file/directory information
        if(lstat(path, &st) == -1) {
            printf("Could not get information about %s\n", path);
            continue;
        }

        // check if the entry is a directory
        if(S_ISDIR(st.st_mode)) {
            (*dir_count)++;
            scan_disk_space(path, depth + 1, dir_count, file_count, total_size); // recurse into the directory
        } else {
            (*file_count)++;
            (*total_size) += st.st_size; // add the file size
        }
    }

    // close the directory
    closedir(dir);
}

int main() {
    char directory[1024];
    printf("Enter the directory to scan: ");
    scanf("%s", directory);

    int dir_count = 0, file_count = 0;
    long total_size = 0;
    scan_disk_space(directory, 0, &dir_count, &file_count, &total_size);

    printf("\nScanning complete! Results:\n");
    printf("Directories: %d\n", dir_count);
    printf("Files: %d\n", file_count);
    printf("Total size: %ld bytes\n", total_size);

    return 0;
}