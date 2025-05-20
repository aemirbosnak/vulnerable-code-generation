//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

// Function to compare two files
int compare_files(char *file1, char *file2) {
    FILE *fp1, *fp2;
    char ch1, ch2;
    int flag = 0;

    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error: File not found!\n");
        return -1;
    }

    while ((ch1 = fgetc(fp1))!= EOF && (ch2 = fgetc(fp2))!= EOF) {
        if (ch1!= ch2) {
            flag = 1;
            break;
        }
    }

    fclose(fp1);
    fclose(fp2);

    if (flag == 0) {
        printf("Files are identical.\n");
    } else {
        printf("Files are different.\n");
    }

    return 0;
}

// Function to sync files in a directory
void sync_files(char *dir, char *dest_dir) {
    DIR *dp;
    struct dirent *dirp;
    char src_file[1024], dest_file[1024];

    dp = opendir(dir);

    if (dp == NULL) {
        printf("Error: Directory not found!\n");
        return;
    }

    while ((dirp = readdir(dp))!= NULL) {
        if (dirp->d_type == DT_REG) {
            strcpy(src_file, dir);
            strcat(src_file, "/");
            strcat(src_file, dirp->d_name);

            strcpy(dest_file, dest_dir);
            strcat(dest_file, "/");
            strcat(dest_file, dirp->d_name);

            compare_files(src_file, dest_file);
        }
    }

    closedir(dp);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./program source_directory destination_directory\n");
        return -1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}