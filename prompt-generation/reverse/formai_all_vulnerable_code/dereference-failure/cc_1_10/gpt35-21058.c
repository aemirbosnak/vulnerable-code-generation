//FormAI DATASET v1.0 Category: File Synchronizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_FILES 50
#define MAX_FILE_NAME_SIZE 100
#define MAX_LINE_SIZE 256
#define BUFFER_SIZE 1024

struct File {
    char name[MAX_FILE_NAME_SIZE];
    int size;
    char content[BUFFER_SIZE];
};

int compareFiles(struct File file1, struct File file2) {
    if (file1.size != file2.size) {
        return 0;
    }

    if (strcmp(file1.name, file2.name) != 0) {
        return 0;
    }

    for (int i = 0; i < file1.size; i++) {
        if (file1.content[i] != file2.content[i]) {
            return 0;
        }
    }

    return 1;
}

int getFile(struct File *file, char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        return 0;
    }

    struct stat st;
    fstat(fd, &st);
    file->size = st.st_size;
    strcpy(file->name, filename);

    int n = read(fd, file->content, BUFFER_SIZE);

    close(fd);

    return 1;
}

int putFile(struct File file) {
    int fd = open(file.name, O_CREAT | O_WRONLY, 0666);
    if (fd < 0) {
        return 0;
    }

    int n = write(fd, file.content, file.size);

    close(fd);

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: sync <directory1> <directory2>\n");
        return 0;
    }

    DIR *dir1 = opendir(argv[1]);
    DIR *dir2 = opendir(argv[2]);

    if (dir1 == NULL || dir2 == NULL) {
        printf("Invalid directory\n");
        return 0;
    }

    struct dirent *dirp1;
    struct dirent *dirp2;

    struct File files1[MAX_FILES];
    struct File files2[MAX_FILES];

    int filesCount1 = 0;
    int filesCount2 = 0;

    while ((dirp1 = readdir(dir1)) != NULL) {
        if (dirp1->d_type == DT_REG) {
            char filename[MAX_FILE_NAME_SIZE];
            sprintf(filename, "%s/%s", argv[1], dirp1->d_name);

            struct File file;
            if (getFile(&file, filename)) {
                files1[filesCount1++] = file;
            }
        }
    }

    while ((dirp2 = readdir(dir2)) != NULL) {
        if (dirp2->d_type == DT_REG) {
            char filename[MAX_FILE_NAME_SIZE];
            sprintf(filename, "%s/%s", argv[2], dirp2->d_name);

            struct File file;
            if (getFile(&file, filename)) {
                files2[filesCount2++] = file;
            }
        }
    }

    int maxFiles = filesCount1 > filesCount2 ? filesCount1 : filesCount2;

    for (int i = 0; i < maxFiles; i++) {
        if (i < filesCount1) {
            int found = 0;
            for (int j = 0; j < filesCount2; j++) {
                if (compareFiles(files1[i], files2[j])) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                putFile(files1[i]);
                printf("Copied %s to %s\n", files1[i].name, argv[2]);
            }
        }

        if (i < filesCount2) {
            int found = 0;
            for (int j = 0; j < filesCount1; j++) {
                if (compareFiles(files2[i], files1[j])) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                putFile(files2[i]);
                printf("Copied %s to %s\n", files2[i].name, argv[1]);
            }
        }
    }

    closedir(dir1);
    closedir(dir2);

    return 0;
}