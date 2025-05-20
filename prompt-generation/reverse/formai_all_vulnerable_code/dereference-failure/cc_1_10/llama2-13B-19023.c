//LLAMA2-13B DATASET v1.0 Category: Data recovery tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_NAME_LEN 256
#define MAX_FILE_LEN 4096

struct dir_ent {
    char name[MAX_NAME_LEN];
    char path[MAX_FILE_LEN];
};

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;
    char file_path[MAX_FILE_LEN];
    char name[MAX_NAME_LEN];

    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("Failed to open directory");
        return 2;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            // Get the file name and path
            strcpy(name, entry->d_name);
            strcat(file_path, entry->d_name);

            // Recover the file data
            FILE *file = fopen(file_path, "r");
            if (file == NULL) {
                perror("Failed to open file");
                continue;
            }

            // Read the file data
            char buffer[4096];
            int bytes_read = fread(buffer, 1, sizeof(buffer), file);
            if (bytes_read < 0) {
                perror("Failed to read file data");
                fclose(file);
                continue;
            }

            // Print the file data
            printf("%s\n", buffer);

            // Close the file
            fclose(file);
        }
    }

    closedir(dir);
    return 0;
}