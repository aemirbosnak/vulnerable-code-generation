//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_PATH_LENGTH 1024

int is_file_executable(const char* filename) {
    int fd;
    struct stat st;
    if ((fd = open(filename, O_RDONLY)) == -1) {
        return -1;
    }
    if (fstat(fd, &st) == -1) {
        close(fd);
        return -1;
    }
    close(fd);
    return S_IXUSR & st.st_mode;
}

int is_file_virus(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* buffer = (char*)malloc(size);
    if (!buffer) {
        fclose(fp);
        return -1;
    }
    fread(buffer, size, 1, fp);
    fclose(fp);
    if (strstr(buffer, "virus")!= NULL) {
        return 1;
    }
    return 0;
}

int scan_directory(const char* path, const char* virus_signature) {
    DIR* dir = opendir(path);
    if (!dir) {
        return -1;
    }
    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        const char* filename = entry->d_name;
        if (strlen(filename) > MAX_FILE_NAME_LENGTH) {
            continue;
        }
        char full_path[MAX_FILE_PATH_LENGTH];
        snprintf(full_path, MAX_FILE_PATH_LENGTH, "%s/%s", path, filename);
        if (is_file_executable(full_path) && is_file_virus(full_path)) {
            printf("%s is infected with virus!\n", filename);
        }
    }
    closedir(dir);
    return 0;
}

int main() {
    const char* virus_signature = "virus";
    const char* directory_path = "./";
    scan_directory(directory_path, virus_signature);
    return 0;
}