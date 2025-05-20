//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGTH 256
#define VIRUS_SIGNATURE "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define VIRUS_SIGNATURE_LENGTH strlen(VIRUS_SIGNATURE)

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int infected;
} FileInfo;

void scan_directory(const char* directory, int* num_infected_files) {
    DIR* dir = opendir(directory);
    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_REG) {
            char path[MAX_FILE_NAME_LENGTH];
            sprintf(path, "%s/%s", directory, entry->d_name);
            int fd = open(path, O_RDONLY);
            if (fd >= 0) {
                char buffer[1024];
                int bytes_read;
                while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
                    for (int i = 0; i < bytes_read; i++) {
                        if (isalpha(buffer[i]) && strchr(VIRUS_SIGNATURE, tolower(buffer[i]))) {
                            printf("Virus found in file: %s\n", path);
                            fclose(fd);
                            return;
                        }
                    }
                }
                fclose(fd);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }
    int num_infected_files = 0;
    scan_directory(argv[1], &num_infected_files);
    if (num_infected_files == 0) {
        printf("No viruses found.\n");
    }
    return 0;
}