//FormAI DATASET v1.0 Category: File Synchronizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_FILE_COUNT 1000

//Function to get the last modified time of a file
char *get_last_modified_time(char *file_path) {
    struct stat attr;
    stat(file_path, &attr);
    char *time_str = ctime(&attr.st_mtime);
    time_str[strlen(time_str) - 1] = '\0'; //removing newline character
    char *time_copy = (char *)malloc(strlen(time_str) + 1);
    strcpy(time_copy, time_str);
    return time_copy;
}

//Function to check if a file exists in an array
int file_exists(char *file_path, char *file_list[], int file_count) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_list[i], file_path) == 0) {
            return 1;
        }
    }
    return 0;
}

//Function to synchronize files from source to destination
void sync_files(char *src_dir, char *dst_dir) {
    //Creating file list of source directory
    char *src_file_list[MAX_FILE_COUNT];
    int src_file_count = 0;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(src_dir)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) {
                char *file_path = malloc(strlen(src_dir) + strlen(ent->d_name) + 2);
                strcpy(file_path, src_dir);
                strcat(file_path, "/");
                strcat(file_path, ent->d_name);
                src_file_list[src_file_count++] = file_path;
            }
        }
        closedir(dir);
    }
    else {
        printf("Error: Unable to open source directory.\n");
        exit(EXIT_FAILURE);
    }

    //Creating file list of destination directory
    char *dst_file_list[MAX_FILE_COUNT];
    int dst_file_count = 0;
    if ((dir = opendir(dst_dir)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) {
                char *file_path = malloc(strlen(dst_dir) + strlen(ent->d_name) + 2);
                strcpy(file_path, dst_dir);
                strcat(file_path, "/");
                strcat(file_path, ent->d_name);
                dst_file_list[dst_file_count++] = file_path;
            }
        }
        closedir(dir);
    }
    else {
        printf("Error: Unable to open destination directory.\n");
        exit(EXIT_FAILURE);
    }

    //Synchronizing files from source to destination
    for (int i = 0; i < src_file_count; i++) {
        if (!file_exists(src_file_list[i], dst_file_list, dst_file_count)) {
            //File does not exist in destination directory, copying it
            char *dst_file_path = malloc(strlen(dst_dir) + strlen(src_file_list[i]) - strlen(src_dir) + 2);
            strcpy(dst_file_path, dst_dir);
            strcat(dst_file_path, "/");
            strcat(dst_file_path, src_file_list[i] + strlen(src_dir) + 1);
            FILE *src_file, *dst_file;
            char ch;
            src_file = fopen(src_file_list[i], "r");
            dst_file = fopen(dst_file_path, "w");
            while ((ch = fgetc(src_file)) != EOF) {
                fputc(ch, dst_file);
            }
            fclose(src_file);
            fclose(dst_file);
            printf("File copied: %s\n", dst_file_path);
        }
        else {
            //File exists in destination directory, comparing modified time
            char *src_time = get_last_modified_time(src_file_list[i]);
            char *dst_time = get_last_modified_time(dst_file_list[i]);
            if (strcmp(src_time, dst_time) > 0) {
                //Source file has been modified recently, copying it
                char *dst_file_path = malloc(strlen(dst_dir) + strlen(src_file_list[i]) - strlen(src_dir) + 2);
                strcpy(dst_file_path, dst_dir);
                strcat(dst_file_path, "/");
                strcat(dst_file_path, src_file_list[i] + strlen(src_dir) + 1);
                FILE *src_file, *dst_file;
                char ch;
                src_file = fopen(src_file_list[i], "r");
                dst_file = fopen(dst_file_path, "w");
                while ((ch = fgetc(src_file)) != EOF) {
                    fputc(ch, dst_file);
                }
                fclose(src_file);
                fclose(dst_file);
                printf("File copied: %s\n", dst_file_path);
            }
            free(src_time);
            free(dst_time);
        }
    }

    //Deleting files from destination that do not exist in source
    for (int i = 0; i < dst_file_count; i++) {
        if (!file_exists(dst_file_list[i], src_file_list, src_file_count)) {
            //File does not exist in source directory, deleting it
            remove(dst_file_list[i]);
            printf("File deleted: %s\n", dst_file_list[i]);
        }
    }

    //Freeing memory allocated for file paths
    for (int i = 0; i < src_file_count; i++) {
        free(src_file_list[i]);
    }
    for (int i = 0; i < dst_file_count; i++) {
        free(dst_file_list[i]);
    }
}

int main() {
    char src_dir[100], dst_dir[100];
    printf("Enter source directory path: ");
    scanf("%s", src_dir);
    printf("Enter destination directory path: ");
    scanf("%s", dst_dir);
    sync_files(src_dir, dst_dir);
    return 0;
}