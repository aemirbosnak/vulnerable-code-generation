//FormAI DATASET v1.0 Category: File Synchronizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

/* Function to synchronize two directories recursively */
void sync_directories(char* src_dir, char* dest_dir) {
    struct dirent *de, *de_dest;
    DIR *dr = opendir(src_dir);
    DIR *dr_dest = opendir(dest_dir);
    
    if (dr == NULL) {
        printf("Could not open %s directory\n", src_dir);
        return;
    }
    if (dr_dest == NULL) {
        printf("Could not open %s directory\n", dest_dir);
        return;
    }

    while ((de = readdir(dr)) != NULL) { /* read source directory */
        char src_path[1000], dest_path[1000];
        struct stat st, st_dest;
        sprintf(src_path, "%s/%s", src_dir, de->d_name);
        
        /* Ignore . and .. */
        if(strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
            continue;
        }
        
        /* Check if file/directory exists in destination directory */
        if(stat(src_path, &st) == -1) {
            printf("Error reading file %s\n", src_path);
            continue;
        }

        /* if it's a directory, create it in destination and recursively sync the two */
        if(S_ISDIR(st.st_mode)) {
            sprintf(dest_path, "%s/%s", dest_dir, de->d_name);
            if(stat(dest_path, &st_dest) == -1) { /* if does not exist */
                mkdir(dest_path, 0777); /* create directory */
                printf("Created directory %s\n", dest_path);
            }
            sync_directories(src_path, dest_path);
        }
        else { /* otherwise check if file exists in destination */
            int exists = 0;
            while ((de_dest = readdir(dr_dest)) != NULL) { /* read destination directory */
                if(strcmp(de_dest->d_name, de->d_name) == 0) { /* file exists */
                    exists = 1;
                    break;
                }           
            }
            /* if not exists or file is newer, copy to destination*/
            if((!exists) || (st.st_mtime > st_dest.st_mtime)){
                sprintf(dest_path, "%s/%s", dest_dir, de->d_name);
                FILE* src_file = fopen(src_path, "rb");
                if(src_file == NULL) {
                    printf("Could not open source file: %s\n", src_path);
                    continue;
                }
                FILE* dest_file = fopen(dest_path, "w+b");
                if(dest_file == NULL) {
                    printf("Could not open destination file: %s\n", dest_path);
                    fclose(src_file);
                    continue;
                }
                /* copy contents from source to destination */
                char buffer[1024];
                size_t read_size;
                while((read_size = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                    fwrite(buffer, 1, read_size, dest_file);
                }
                chown(dest_path, st.st_uid, st.st_gid);
                chmod(dest_path, st.st_mode);
                printf("Copied file %s to %s\n", src_path, dest_path);
                fclose(src_file);
                fclose(dest_file);
            }
        }
        rewinddir(dr_dest); /* reset destination directory stream */
    }
    closedir(dr); /* close source directory */
    closedir(dr_dest); /* close destination directory */
}

int main() {
    sync_directories("src", "dest");
    return 0;
}