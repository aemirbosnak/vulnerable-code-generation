//FormAI DATASET v1.0 Category: File Synchronizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 256

typedef struct {
    char* filename;
    struct stat statbuf;
} file_info;

int compare_files(file_info* file1, file_info* file2) {
    if (strcmp(file1->filename, file2->filename) != 0 || file1->statbuf.st_size != file2->statbuf.st_size) {
        return 1;
    }
    FILE* f1 = fopen(file1->filename, "rb");
    FILE* f2 = fopen(file2->filename, "rb");
    if (!f1 || !f2) {
        return 1;
    }
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    size_t n1, n2;
    int difference = 0;
    while (1) {
        n1 = fread(buffer1, 1, BUFFER_SIZE, f1);
        n2 = fread(buffer2, 1, BUFFER_SIZE, f2);
        if (n1 != n2 || memcmp(buffer1, buffer2, n1) != 0) {
            difference = 1;
            break;
        }
        if (n1 == 0) {
            break;
        }
    }
    fclose(f1);
    fclose(f2);
    return difference;
}

int file_to_info(file_info* info, char* filename) {
    info->filename = filename;
    int r = stat(filename, &info->statbuf);
    return (r == 0);
}

void copy_file(char* source_filename, char* target_filename) {
    FILE* source = fopen(source_filename, "rb");
    FILE* target = fopen(target_filename, "wb");
    if (!source || !target) {
        return;
    }
    char buffer[BUFFER_SIZE];
    size_t n;
    while ((n = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, 1, n, target);
    }
    fclose(source);
    fclose(target);
}

int copy_file_if_needed(char* source_dir, char* target_dir, file_info* source_file_info) {
    file_info target_file_info;
    char target_filename[BUFFER_SIZE];
    strcpy(target_filename, target_dir);
    strcat(target_filename, "/");
    strcat(target_filename, source_file_info->filename + strlen(source_dir) + 1);
    if (!file_to_info(&target_file_info, target_filename) || compare_files(source_file_info, &target_file_info)) {
        copy_file(source_file_info->filename, target_filename);
        printf("Copied %s to %s\n", source_file_info->filename, target_filename);
        return 1;
    }
    return 0;
}

void sync_dirs(char* source_dir, char* target_dir) {
    DIR* dir;
    struct dirent* entry;
    file_info source_file_info;
    char source_filename[BUFFER_SIZE];
    strcpy(source_filename, source_dir);
    dir = opendir(source_dir);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }
        strcpy(source_file_info.filename, source_filename);
        strcat(source_file_info.filename, "/");
        strcat(source_file_info.filename, entry->d_name);
        file_to_info(&source_file_info, source_file_info.filename);
        if (S_ISDIR(source_file_info.statbuf.st_mode)) {
            char sub_source_dir[BUFFER_SIZE];
            strcpy(sub_source_dir, source_filename);
            strcat(sub_source_dir, "/");
            strcat(sub_source_dir, entry->d_name);
            char sub_target_dir[BUFFER_SIZE];
            strcpy(sub_target_dir, target_dir);
            strcat(sub_target_dir, "/");
            strcat(sub_target_dir, entry->d_name);
            sync_dirs(sub_source_dir, sub_target_dir);
        } else if (S_ISREG(source_file_info.statbuf.st_mode)) {
            copy_file_if_needed(source_dir, target_dir, &source_file_info);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s source_dir target_dir\n", argv[0]);
        return 1;
    }
    sync_dirs(argv[1], argv[2]);
    return 0;
}