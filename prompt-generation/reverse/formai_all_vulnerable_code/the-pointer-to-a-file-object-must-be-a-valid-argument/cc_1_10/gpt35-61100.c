//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_FILENAME_LEN 256

bool check_file_exists(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    } else {
        fclose(file);
        return true;
    }
}

bool is_directory(const char* filename) {
    if (!check_file_exists(filename)) {
        // File does not exist
        return false;
    }

    char command[MAX_FILENAME_LEN+10];
    sprintf(command, "if [ -d \"%s\" ]; then printf yes; else printf no; fi", filename);

    char response[4];
    FILE *fp = popen(command, "r");
    fgets(response, 4, fp);
    pclose(fp);

    if (strcmp(response, "yes") == 0) {
        return true;
    } else {
        return false;
    }
}

void get_files_recursive(const char* dir_name, long* total_size, int* num_files) {
    char command[MAX_FILENAME_LEN+128];
    sprintf(command, "du -sb \"%s\"", dir_name);

    FILE *fp = popen(command, "r");
    char output[1024];
    fgets(output, 1024, fp);
    pclose(fp);

    char* size_str = strtok(output, "\t");
    *total_size += atol(size_str);

    char* file_name = strtok(NULL, "\t\n");
    if (file_name != NULL) {
        (*num_files)++;
    }

    if (is_directory(dir_name)) {
        sprintf(command, "ls \"%s\"", dir_name);

        fp = popen(command, "r");
        char subdir_name[MAX_FILENAME_LEN];
        while (fgets(subdir_name, MAX_FILENAME_LEN, fp) != NULL) {
            subdir_name[strcspn(subdir_name, "\r\n")] = 0;
            char full_path[MAX_FILENAME_LEN*2];
            sprintf(full_path, "%s/%s", dir_name, subdir_name);
            get_files_recursive(full_path, total_size, num_files);
        }
        pclose(fp);
    }
}

int main() {
    char directory[MAX_FILENAME_LEN];
    printf("Enter directory path: ");
    fgets(directory, MAX_FILENAME_LEN, stdin);
    directory[strcspn(directory, "\r\n")] = 0;

    if (!is_directory(directory)) {
        printf("Error: \"%s\" is not a directory\n", directory);
        return 1;
    }

    long total_size = 0;
    int num_files = 0;
    get_files_recursive(directory, &total_size, &num_files);

    printf("\nTotal size: %ld bytes\n", total_size);
    printf("Number of files: %d\n", num_files);

    return 0;
}