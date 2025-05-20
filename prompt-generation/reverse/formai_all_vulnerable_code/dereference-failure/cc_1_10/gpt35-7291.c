//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

/* Structure to hold file size and name */
struct FileInfo {
    long int size;
    char name[1000];
};

/* Function to sort the files based on their size */
void SortFiles(struct FileInfo files[], int n) {
    int i, j;
    struct FileInfo temp;

    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(files[j].size < files[j+1].size) {
                temp = files[j];
                files[j] = files[j+1];
                files[j+1] = temp;
            }
        }
    }
}

/* Function to calculate and display the disk usage */
void DiskUsage(char *path) {
    DIR *dir;
    struct dirent *ent;
    struct stat st;
    char file_path[1000];
    struct FileInfo files[1000];
    int i=0, num_files=0;
    long int total_size=0;

    /* Open the directory */
    dir = opendir(path);
    if(dir == NULL) {
        printf("Error opening directory.\n");
        return;
    }

    /* Read each file in the directory */
    while ((ent = readdir(dir)) != NULL) {
        sprintf(file_path, "%s/%s", path, ent->d_name);
        /* Ignore "." and ".." directories */
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;
        if (stat(file_path, &st) == -1)
            continue;
        /* If the file is a regular file */
        if (S_ISREG(st.st_mode)) {
            strcpy(files[i].name, ent->d_name);
            files[i].size = st.st_size;
            total_size += st.st_size;
            i++;
            num_files++;
        }
    }
    closedir(dir);

    /* Sort the files based on their size */
    SortFiles(files, num_files);

    /* Display the files in decreasing order of size */
    printf("Disk usage for directory %s:\n", path);
    printf("Total files: %d, Total size: %ld bytes\n\n", num_files, total_size);
    printf("%-30s %20s\n", "Filename", "Size (bytes)");
    for(i=0; i<num_files; i++)
        printf("%-30s %20ld\n", files[i].name, files[i].size);
}

/* Main function */
int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 0;
    }
    DiskUsage(argv[1]);
    return 0;
}