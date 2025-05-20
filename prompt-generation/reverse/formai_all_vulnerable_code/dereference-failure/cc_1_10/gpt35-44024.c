//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

void sync_files(char *src_path, char *dest_path){
    DIR *src_dir, *dest_dir;
    struct dirent *src_dir_entry, *dest_dir_entry;
    struct stat src_file_stat, dest_file_stat;
    char src_file_path[100], dest_file_path[100];

    src_dir = opendir(src_path);
    dest_dir = opendir(dest_path);

    if(src_dir == NULL || dest_dir == NULL){
        printf("Error: Could not open directories\n");
        return;
    }

    // Sync files from source directory to destination directory
    while((src_dir_entry = readdir(src_dir)) != NULL){
        if(strcmp(src_dir_entry->d_name, ".") == 0 || 
            strcmp(src_dir_entry->d_name, "..") == 0){
            continue;
        }

        sprintf(src_file_path, "%s/%s", src_path, src_dir_entry->d_name);
        sprintf(dest_file_path, "%s/%s", dest_path, src_dir_entry->d_name);

        if(stat(src_file_path, &src_file_stat) < 0){
            printf("Error: Could not get file info for %s\n", src_file_path);
            continue;
        }

        if(S_ISDIR(src_file_stat.st_mode)){
            // Recursively sync subdirectories
            sync_files(src_file_path, dest_file_path);
        }
        else if(stat(dest_file_path, &dest_file_stat) < 0){
            // File does not exist in destination directory
            printf("Copying %s to %s\n", src_file_path, dest_file_path);
            FILE *src_file, *dest_file;
            src_file = fopen(src_file_path, "r");
            dest_file = fopen(dest_file_path, "w");
            char ch;
            while((ch = fgetc(src_file)) != EOF){
                fputc(ch, dest_file);
            }
            fclose(src_file);
            fclose(dest_file);
        }
        else if(src_file_stat.st_mtime > dest_file_stat.st_mtime){
            // Source file has been modified more recently
            printf("Updating %s in %s\n", src_file_path, dest_file_path);
            FILE *src_file, *dest_file;
            src_file = fopen(src_file_path, "r");
            dest_file = fopen(dest_file_path, "w");
            char ch;
            while((ch = fgetc(src_file)) != EOF){
                fputc(ch, dest_file);
            }
            fclose(src_file);
            fclose(dest_file);
        }
    }

    // Delete files in destination directory that do not exist in source directory
    while((dest_dir_entry = readdir(dest_dir)) != NULL){
        if(strcmp(dest_dir_entry->d_name, ".") == 0 || 
            strcmp(dest_dir_entry->d_name, "..") == 0){
            continue;
        }

        sprintf(dest_file_path, "%s/%s", dest_path, dest_dir_entry->d_name);

        if(stat(dest_file_path, &dest_file_stat) < 0){
            printf("Error: Could not get file info for %s\n", dest_file_path);
            continue;
        }

        if(S_ISDIR(dest_file_stat.st_mode)){
            // Recursively delete subdirectories
            char subdir_src_path[100], subdir_dest_path[100];
            sprintf(subdir_src_path, "%s/%s", src_path, dest_dir_entry->d_name);
            sprintf(subdir_dest_path, "%s/%s", dest_path, dest_dir_entry->d_name);
            sync_files(subdir_src_path, subdir_dest_path);
        }
        else{
            // Delete file
            printf("Deleting %s\n", dest_file_path);
            remove(dest_file_path);
        }
    }

    closedir(src_dir);
    closedir(dest_dir);
}

int main(){
    char src_path[100] = "source";
    char dest_path[100] = "destination";
    sync_files(src_path, dest_path);
    return 0;
}