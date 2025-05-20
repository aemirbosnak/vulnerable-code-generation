//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

struct file {
    char *name;
    char *path;
    time_t timestamp;
};

void free_file(struct file *file) {
    free(file->name);
    free(file->path);
    free(file);
}

struct file *read_file(char *path) {
    struct stat statbuf;
    struct file *file = malloc(sizeof(struct file));
    if (file == NULL) {
        return NULL;
    }
    file->name = strdup(path);
    if (file->name == NULL) {
        free_file(file);
        return NULL;
    }
    file->path = strdup(path);
    if (file->path == NULL) {
        free_file(file);
        return NULL;
    }
    if (stat(path, &statbuf) < 0) {
        free_file(file);
        return NULL;
    }
    file->timestamp = statbuf.st_mtime;
    return file;
}

int compare_files(const void *a, const void *b) {
    struct file *file1 = *(struct file **)a;
    struct file *file2 = *(struct file **)b;
    return strcmp(file1->name, file2->name);
}

void print_files(struct file **files, int num_files) {
    for (int i = 0; i < num_files; i++) {
        printf("%s\n", files[i]->name);
    }
}

int main() {
    DIR *dir1, *dir2;
    struct dirent *ent1, *ent2;
    struct file **files1, **files2;
    int num_files1, num_files2;
    int i, j;

    dir1 = opendir("dir1");
    if (dir1 == NULL) {
        perror("opendir");
        return 1;
    }
    dir2 = opendir("dir2");
    if (dir2 == NULL) {
        perror("opendir");
        return 1;
    }

    num_files1 = 0;
    while ((ent1 = readdir(dir1)) != NULL) {
        num_files1++;
    }
    rewinddir(dir1);

    num_files2 = 0;
    while ((ent2 = readdir(dir2)) != NULL) {
        num_files2++;
    }
    rewinddir(dir2);

    files1 = malloc(sizeof(struct file *) * num_files1);
    if (files1 == NULL) {
        perror("malloc");
        return 1;
    }
    files2 = malloc(sizeof(struct file *) * num_files2);
    if (files2 == NULL) {
        perror("malloc");
        return 1;
    }

    i = 0;
    while ((ent1 = readdir(dir1)) != NULL) {
        char path[1024];
        snprintf(path, sizeof(path), "dir1/%s", ent1->d_name);
        files1[i] = read_file(path);
        if (files1[i] == NULL) {
            return 1;
        }
        i++;
    }

    j = 0;
    while ((ent2 = readdir(dir2)) != NULL) {
        char path[1024];
        snprintf(path, sizeof(path), "dir2/%s", ent2->d_name);
        files2[j] = read_file(path);
        if (files2[j] == NULL) {
            return 1;
        }
        j++;
    }

    closedir(dir1);
    closedir(dir2);

    qsort(files1, num_files1, sizeof(struct file *), compare_files);
    qsort(files2, num_files2, sizeof(struct file *), compare_files);

    printf("Files in dir1:\n");
    print_files(files1, num_files1);

    printf("Files in dir2:\n");
    print_files(files2, num_files2);

    for (i = 0; i < num_files1; i++) {
        int found = 0;
        for (j = 0; j < num_files2; j++) {
            if (strcmp(files1[i]->name, files2[j]->name) == 0) {
                if (files1[i]->timestamp != files2[j]->timestamp) {
                    printf("File %s has different timestamps in dir1 and dir2.\n", files1[i]->name);
                }
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("File %s missing in dir2.\n", files1[i]->name);
        }
    }

    for (i = 0; i < num_files2; i++) {
        int found = 0;
        for (j = 0; j < num_files1; j++) {
            if (strcmp(files2[i]->name, files1[j]->name) == 0) {
                if (files2[i]->timestamp != files1[j]->timestamp) {
                    printf("File %s has different timestamps in dir2 and dir1.\n", files2[i]->name);
                }
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("File %s missing in dir1.\n", files2[i]->name);
        }
    }

    for (i = 0; i < num_files1; i++) {
        free_file(files1[i]);
    }
    free(files1);

    for (i = 0; i < num_files2; i++) {
        free_file(files2[i]);
    }
    free(files2);

    return 0;
}