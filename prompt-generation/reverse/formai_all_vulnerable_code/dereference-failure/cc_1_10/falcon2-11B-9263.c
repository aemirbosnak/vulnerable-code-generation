//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

// Scan all files in the current directory
void scan_files(const char *dir_name) {
    DIR *dir = opendir(dir_name);
    if (dir == NULL) {
        printf("Error: Unable to open directory '%s'!\n", dir_name);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_REG) {
            char file_path[256];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_name, entry->d_name);
            FILE *file = fopen(file_path, "r");
            if (file!= NULL) {
                fseek(file, 0, SEEK_END);
                long file_size = ftell(file);
                fseek(file, 0, SEEK_SET);

                unsigned char buffer[1024];
                int bytes_read = fread(buffer, 1, sizeof(buffer), file);
                while (bytes_read > 0) {
                    int i;
                    for (i = 0; i < bytes_read; i++) {
                        if (buffer[i] == 0x41 && buffer[i+1] == 0x6D && buffer[i+2] == 0x61 && buffer[i+3] == 0x70 && buffer[i+4] == 0x69 && buffer[i+5] == 0x2E && buffer[i+6] == 0x64 && buffer[i+7] == 0x6C && buffer[i+8] == 0x6C && buffer[i+9] == 0x6F && buffer[i+10] == 0x63) {
                            printf("Virus found in file '%s'!\n", entry->d_name);
                            break;
                        }
                    }
                    bytes_read = fread(buffer, 1, sizeof(buffer), file);
                }
                fclose(file);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    scan_files(argv[1]);
    return 0;
}