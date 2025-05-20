//FormAI DATASET v1.0 Category: File Backup System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILE_SIZE 10000

char file_list[1000][100]; // array to store file names
int num_files = 0; // keep track of number of files

void copy_file(char* src_file, char* dest_file) {
    FILE *src, *dest;
    char buffer[MAX_FILE_SIZE];

    src = fopen(src_file, "rb");
    dest = fopen(dest_file, "wb");

    // read file in chunks and write to destination
    while(fread(buffer, 1, sizeof(buffer), src) > 0) {
        fwrite(buffer, 1, sizeof(buffer), dest);
    }

    fclose(src);
    fclose(dest);
}

void backup_files(char* source_dir, char* dest_dir) {
    DIR *source;
    struct dirent *entry;
    char full_path[100];

    source = opendir(source_dir);

    // loop through directory and backup all files
    while((entry = readdir(source))) {
        if(entry->d_type == DT_REG) { // if it's a regular file
            // create full path of source and destination file
            sprintf(full_path, "%s/%s", source_dir, entry->d_name);
            char dest_file[100];
            sprintf(dest_file, "%s/%s", dest_dir, entry->d_name);

            copy_file(full_path, dest_file);
            strcpy(file_list[num_files], entry->d_name); // add file name to list
            num_files++;
        }
    }

    closedir(source);
}

int main() {
    char source_dir[100], dest_dir[100];

    printf("Enter source directory: ");
    scanf("%s", source_dir);
    printf("Enter destination directory: ");
    scanf("%s", dest_dir);

    backup_files(source_dir, dest_dir);

    // print list of backed up files
    printf("\n%d files backed up:\n", num_files);
    for(int i = 0; i < num_files; i++) {
        printf("%s\n", file_list[i]);
    }

    return 0;
}