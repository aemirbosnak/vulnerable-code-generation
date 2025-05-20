//FormAI DATASET v1.0 Category: File Backup System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void backup(char *source_dir, char *dest_dir)
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(source_dir);
    if (!dir){
        perror("Failed to open directory");
        return;
    }

    while((entry = readdir(dir)) != NULL){
        char path[1000];
        snprintf(path, sizeof(path), "%s/%s", source_dir, entry->d_name);
        if(entry->d_type == DT_DIR){
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            backup(path, dest_dir);
        }
        else{
            char new_path[1000];
            snprintf(new_path, sizeof(path), "%s/%s", dest_dir, entry->d_name);

            FILE *source_file = fopen(path, "rb");
            FILE *dest_file = fopen(new_path, "wb");

            if(!source_file || !dest_file){
                printf("Failed to open the create file for: %s\n", entry->d_name);
            }
            else{
                int c;
                while ((c = fgetc(source_file)) != EOF){
                    fputc(c, dest_file);
                }
                fclose(source_file);
                fclose(dest_file);

                printf("Backup created for the file: %s/%s\n", source_dir, entry->d_name);
            }
        }
    }

    closedir(dir);
}

int main(){
    char source_dir[1000], dest_dir[1000];

    printf("Enter the path of source directory to backup:\n");
    scanf("%[^\n]%*c", source_dir);

    printf("Enter the path of destination directory for backup:\n");
    scanf("%[^\n]%*c", dest_dir);

    backup(source_dir, dest_dir);

    return 0;
}