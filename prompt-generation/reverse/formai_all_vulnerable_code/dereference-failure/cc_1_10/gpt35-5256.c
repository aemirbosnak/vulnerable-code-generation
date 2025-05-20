//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LEN 256
#define MAX_NAME_LEN 64

typedef struct file_info_t {
    char name[MAX_NAME_LEN];
    unsigned long long size;
} file_info_t;

file_info_t *get_files_in_dir(const char *dir_path, int *num_files) {
    FILE *cmd_pipe;
    char cmd[MAX_PATH_LEN];
    sprintf(cmd, "find %s -type f -print0 | xargs -0 stat --printf '%%n %%s\\n' | sort -k2nr", dir_path);
    cmd_pipe = popen(cmd, "r");

    file_info_t *files = NULL;
    int i = 0;

    if (cmd_pipe) {
        char buffer[MAX_PATH_LEN];
        while (fgets(buffer, sizeof(buffer), cmd_pipe)) {
            char *filename = strtok(buffer, " \n");
            unsigned long long int size = strtoull(strtok(NULL, " \n"), NULL, 10);

            if (strlen(filename) > MAX_NAME_LEN) {
                filename += strlen(filename) - MAX_NAME_LEN;
            }

            file_info_t *file = (file_info_t *) realloc(files, sizeof(file_info_t) * (i + 1));
            if (!file) {
                printf("Error allocating memory\n");
                exit(1);
            }

            files = file;
            strcpy(files[i].name, filename);
            files[i].size = size;
            i++;
        }
        pclose(cmd_pipe);
    } else {
        printf("Error executing command");
        exit(1);
    }

    *num_files = i;
    return files;
}

void print_file_size(unsigned long long size) {
    char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit_count = sizeof(units) / sizeof(units[0]);

    int i;
    double bytes = size;
    for (i = 0; bytes >= 1024 && i < unit_count - 1; i++) {
        bytes /= 1024;
    }
    printf("%.2f %s", bytes, units[i]);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    char *dir_path = argv[1];

    int num_files;
    file_info_t *files = get_files_in_dir(dir_path, &num_files);

    printf("Disk space usage in %s:\n", dir_path);
    printf("%-30s %s\n", "File Name", "Size");
    printf("----------------------------------------------\n");
    unsigned long long total_size = 0;
    int i = 0;
    for (i = 0; i < num_files; i++) {
        total_size += files[i].size;
        printf("%-30s ", files[i].name);
        print_file_size(files[i].size);
        printf("\n");
    }
    printf("----------------------------------------------\n");
    printf("%-30s ", "Total");
    print_file_size(total_size);
    printf("\n");

    free(files);
    return 0;
}