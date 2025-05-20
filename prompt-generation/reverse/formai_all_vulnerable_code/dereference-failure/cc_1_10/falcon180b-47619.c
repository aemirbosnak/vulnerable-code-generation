//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define MAX_FILE_SIZE 1024*1024*1024

char* file_type(char* filename) {
    char* ext = strrchr(filename, '.');
    if(!ext) return "unknown";
    return ext+1;
}

void print_file(char* filename, char* data, int size) {
    char* ext = file_type(filename);
    printf("File: %s\nSize: %d bytes\nType: %s\n", filename, size, ext);
    printf("Contents:\n%s", data);
}

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    DIR* dir = opendir(argv[1]);
    if(!dir) {
        printf("Error opening directory.\n");
        return 1;
    }

    struct dirent* ent;
    while((ent = readdir(dir))!= NULL) {
        char path[1024];
        sprintf(path, "%s/%s", argv[1], ent->d_name);

        struct stat st;
        if(stat(path, &st) == -1) {
            printf("Error getting file info.\n");
            continue;
        }

        if(S_ISDIR(st.st_mode)) {
            printf("Directory: %s\n", ent->d_name);
        } else if(S_ISREG(st.st_mode)) {
            FILE* fp = fopen(path, "rb");
            if(!fp) {
                printf("Error opening file.\n");
                continue;
            }

            fseek(fp, 0, SEEK_END);
            int size = ftell(fp);
            rewind(fp);

            char* data = malloc(size+1);
            fread(data, size, 1, fp);
            fclose(fp);

            print_file(path, data, size);
            free(data);
        }
    }

    closedir(dir);
    return 0;
}