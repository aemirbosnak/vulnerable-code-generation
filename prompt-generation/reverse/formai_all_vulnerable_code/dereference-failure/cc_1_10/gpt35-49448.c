//FormAI DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

void backup(char *path, char *dest){
    // Get current date and time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    // Create destination directory
    char dirname[100];
    sprintf(dirname, "%s/%04d-%02d-%02d_%02d-%02d-%02d", dest, t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    mkdir(dirname, 0777);

    // Traverse source directory and copy files
    DIR *dir = opendir(path);
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL){
        if (entry->d_type == DT_REG){ // regular file
            // Get file information
            char filepath[1000];
            sprintf(filepath, "%s/%s", path, entry->d_name);
            struct stat sb;
            stat(filepath, &sb);

            // Create destination file
            char destpath[1000];
            sprintf(destpath, "%s/%s", dirname, entry->d_name);
            FILE *dst = fopen(destpath, "wb");
            FILE *src = fopen(filepath, "rb");
            if (src == NULL || dst == NULL){
                printf("Error copying file: %s\n", entry->d_name);
                continue;
            }

            // Copy contents of file
            char buffer[1024];
            size_t nread;
            while ((nread = fread(buffer, 1, sizeof(buffer), src)) > 0){
                fwrite(buffer, 1, nread, dst);
            }

            // Set file permissions
            chmod(destpath, sb.st_mode);

            fclose(src);
            fclose(dst);
        }
        else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){ // subdirectory
            // Copy subdirectory recursively
            char subdirpath[1000];
            sprintf(subdirpath, "%s/%s", path, entry->d_name);
            backup(subdirpath, dirname);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]){
    if (argc < 3){
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        exit(1);
    }

    char *src = argv[1];
    char *dest = argv[2];
    backup(src, dest);
    printf("Backup complete.\n");

    return 0;
}