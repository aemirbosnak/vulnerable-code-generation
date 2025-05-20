//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_FILE_NAME 256
#define MAX_PATH 1024
#define MAX_FILES 1000
#define MAX_FOLDERS 1000

typedef struct {
    char name[MAX_FILE_NAME];
    int is_file;
    int is_folder;
} FileInfo;

typedef struct {
    char path[MAX_PATH];
    int folder_count;
    int file_count;
} FolderInfo;

void read_dir(char *path, FolderInfo *folder_info) {
    DIR *dir = opendir(path);
    struct dirent *ent;

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                char sub_path[MAX_PATH];
                strcpy(sub_path, path);
                strcat(sub_path, "/");
                strcat(sub_path, ent->d_name);
                read_dir(sub_path, folder_info);
            } else {
                FileInfo file_info;
                strcpy(file_info.name, ent->d_name);
                file_info.is_file = 1;
                file_info.is_folder = 0;
                folder_info->file_count++;
                strcat(folder_info->path, "/");
                strcat(folder_info->path, ent->d_name);
                strcat(folder_info->path, "\n");
            }
        }
        closedir(dir);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <folder_path>\n", argv[0]);
        exit(1);
    }

    char folder_path[MAX_PATH];
    strcpy(folder_path, argv[1]);

    FolderInfo folder_info;
    folder_info.folder_count = 0;
    folder_info.file_count = 0;

    char path[MAX_PATH];
    strcpy(path, folder_path);
    strcat(path, "/");

    read_dir(path, &folder_info);

    printf("Total Folders: %d\n", folder_info.folder_count);
    printf("Total Files: %d\n", folder_info.file_count);

    return 0;
}