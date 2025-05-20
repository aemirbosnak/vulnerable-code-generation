//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct dir_entry_t {
    char* path;
    long long int size;
} dir_entry;

dir_entry* scan_dir(char* path, int* len) {
    DIR* dirp = opendir(path);
    struct dirent* entry;
    struct stat info;
    dir_entry* result = NULL;
    int count = 0;
    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char new_path[strlen(path) + strlen(entry->d_name) + 2];
            sprintf(new_path, "%s/%s", path, entry->d_name);
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            dir_entry* sub_result = scan_dir(new_path, len);
            result = (dir_entry*) realloc(result, (*len + count + 1) * sizeof(dir_entry));
            count += *len;
            for (int i = 0; i < *len; i++) {
                result[count+i] = sub_result[i];
            }
            free(sub_result);
        } else if (entry->d_type == DT_REG) {
            char file_path[strlen(path) + strlen(entry->d_name) + 2];
            sprintf(file_path, "%s/%s", path, entry->d_name);
            if (stat(file_path, &info) == 0) {
                result = (dir_entry*) realloc(result, (*len + count + 1) * sizeof(dir_entry));
                result[count+*len].path = (char*) malloc((strlen(file_path)+1) * sizeof(char));
                strcpy(result[count+*len].path, file_path);
                result[count+*len].size = (long long int) info.st_size;
                (*len)++;
            }
        }
    }
    closedir(dirp);
    return result;
}

int cmp(const void* A, const void* B) {
    dir_entry* a = (dir_entry*) A;
    dir_entry* b = (dir_entry*) B;
    if (a->size < b->size)
        return 1;
    if (a->size > b->size)
        return -1;
    return 0;
}

int main() {
    char* path = (char*) malloc(1024 * sizeof(char));
    printf("Enter path to analyze: ");
    scanf("%s", path);
    int len = 0;
    dir_entry* result = scan_dir(path, &len);
    qsort(result, len, sizeof(dir_entry), cmp);
    printf("\nTop 10 largest files / directories in %s in descending order:\n\n", path);
    for (int i = 0; i < len && i < 10; i++) {
        printf("%lld bytes - %s\n", result[i].size, result[i].path);
    }
    for (int i = 0; i < len; i++) {
        free(result[i].path);
    }
    free(result);
    free(path);
    return 0;
}