//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int scan_file(const char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return -1;
    }
    
    char buffer[1024];
    int bytes_read = read(fd, buffer, sizeof(buffer));
    
    if (bytes_read == -1) {
        perror("Failed to read file");
        return -1;
    }
    
    int virus_found = 0;
    for (int i = 0; i < bytes_read; i++) {
        if (buffer[i] == 0x55 && buffer[i+1] == 0xAA && buffer[i+2] == 0x7F && buffer[i+3] == 0x55 && buffer[i+4] == 0xAA) {
            virus_found = 1;
            printf("Virus found in %s at byte %d\n", filename, i);
            break;
        }
    }
    
    close(fd);
    return virus_found;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return -1;
    }
    
    DIR* dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("Failed to open directory");
        return -1;
    }
    
    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        const char* filename = entry->d_name;
        if (strstr(filename, ".exe") || strstr(filename, ".com") || strstr(filename, ".bat") || strstr(filename, ".dll")) {
            if (scan_file(filename) == 1) {
                printf("Virus found: %s\n", filename);
            }
        }
    }
    
    closedir(dir);
    return 0;
}