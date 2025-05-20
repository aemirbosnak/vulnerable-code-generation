//FormAI DATASET v1.0 Category: File Synchronizer ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include <dirent.h>
#include <string.h>

void sync_dir(char *source_dir, char *target_dir)
{
    DIR *dir;
    struct dirent *entry;

    // open the source directory
    dir = opendir(source_dir);

    // return if the source cannot be opened
    if (dir == NULL) {
        printf("Could not open source directory %s\n", source_dir);
        return;
    }

    while((entry = readdir(dir)) != NULL) {
        char source_file[256], target_file[256];

        // ignore . and ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // create the absolute path of the source file
        sprintf(source_file, "%s/%s", source_dir, entry->d_name);
        sprintf(target_file, "%s/%s", target_dir, entry->d_name);

        // if the entry is a directory, recursively sync the directories
        if(entry->d_type == DT_DIR) {
            sync_dir(source_file, target_file);
        }

        // otherwise, copy the file from source to target
        else if(entry->d_type == DT_REG) {
            FILE *src_file = fopen(source_file, "r");
            FILE *tgt_file = fopen(target_file, "w");
            char buffer[4096];
            size_t n;

            // copy file contents
            while ((n = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                fwrite(buffer, 1, n, tgt_file);
            }

            // close file handles
            fclose(src_file);
            fclose(tgt_file);

            printf("Synced %s to %s\n", source_file, target_file);
        }
    }

    // close the source directory
    closedir(dir);
}

int main() {
    char source_dir[256] = "/home/user/source";
    char target_dir[256] = "/home/user/target";

    // sync the directories
    sync_dir(source_dir, target_dir);

    printf("Directory Sync Complete\n");

    return 0;
}