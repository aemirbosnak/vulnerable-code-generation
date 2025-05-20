//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define KILOBYTE 1024
#define MEGABYTE 1048576
#define GIGABYTE 1073741824

typedef struct file_info {
    char name[1024];
    double size;
    bool is_directory;
} file_info;

int compare(const void *a, const void *b) {
    file_info *file_a = (file_info *) a;
    file_info *file_b = (file_info *) b;
    return (int) (file_b->size - file_a->size);
}

double calculate_size(char *path) {
    FILE *fp = popen("du -sb", "r");
    char output[2048];
    double total_size = 0.0;

    while (fgets(output, sizeof(output), fp) != NULL) {
        char *token = strtok(output, "\t");
        char filename[1024];
        strcpy(filename, token);
        token = strtok(NULL, "\t");
        double size = atoi(token);
        if (strstr(filename, path) != NULL) {
            total_size += size;
        }
    }

    pclose(fp);
    return total_size;
}

void list_files(char *path, file_info *files, int *num_files) {
    FILE *fp = popen("ls -lAh", "r");
    char output[2048];

    while (fgets(output, sizeof(output), fp) != NULL) {
        char *token = strtok(output, " ");
        char permissions[11];
        char owner[11];
        char group[11];
        char size_str[11];
        char filename[1024];
        char *temp = NULL;
        
        for (int i = 0; i < 10; ++i) {
            strcpy(permissions + i, token);
            token = strtok(NULL, " ");
        }

        strtok(NULL, " ");
        strcpy(owner, strtok(NULL, " "));
        strcpy(group, strtok(NULL, " "));
        strcpy(size_str, strtok(NULL, " "));
        double size;
        if (strstr(size_str, "K") != NULL) {
            strtok(size_str, "K");
            size = atof(size_str) * KILOBYTE;
        } else if (strstr(size_str, "M") != NULL) {
            strtok(size_str, "M");
            size = atof(size_str) * MEGABYTE;
        } else if (strstr(size_str, "G") != NULL) {
            strtok(size_str, "G");
            size = atof(size_str) * GIGABYTE;
        } else {
            size = atoi(size_str);
        }
        temp = strtok(NULL, " ");
        if (temp != NULL) {
            for (int i = 0; i < 1024; ++i) {
                if (temp[i] != '\n') {
                    filename[i] = temp[i];
                } else {
                    filename[i] = '\0';
                    break;
                }
            }
        }

        if (strstr(filename, path) != NULL) {
            file_info file;
            strcpy(file.name, filename);
            file.size = size;
            file.is_directory = permissions[0] == 'd';
            files[(*num_files)++] = file;
        }
    }

    pclose(fp);
}

int main() {
    char path[1024];
    printf("Enter path to analyze: ");
    scanf("%s", path);

    double total_size = calculate_size(path);
    printf("Total size of %s: %.2fGB\n", path, total_size / GIGABYTE);

    int num_files = 0;
    file_info files[1024];
    list_files(path, files, &num_files);
    printf("Number of files: %d\n", num_files);

    qsort(files, num_files, sizeof(file_info), compare);

    printf("Largest files:\n");
    for (int i = 0; i < 10 && i < num_files; ++i) {
        if (!files[i].is_directory) {
            printf("%s (%.2fMB)\n", files[i].name, files[i].size / MEGABYTE);
        }
    }

    return 0;
}