//FormAI DATASET v1.0 Category: File Synchronizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 512
#define MAX_BUFFER_SIZE 2048

void copy_file(char *src_filename, char *dst_filename);
void sync_dir(char *src_dirname, char *dst_dirname);
void sync_files(char *src_dirname, char *dst_dirname, struct dirent *pdir);

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s [source directory] [destination directory]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char src_dirname[MAX_PATH_LENGTH];
    char dst_dirname[MAX_PATH_LENGTH];
    strncpy(src_dirname, argv[1], MAX_PATH_LENGTH - 1);
    strncpy(dst_dirname, argv[2], MAX_PATH_LENGTH - 1);

    sync_dir(src_dirname, dst_dirname);
    
    return EXIT_SUCCESS;
}

void sync_dir(char *src_dirname, char *dst_dirname)
{
    DIR *src_dir = opendir(src_dirname);
    DIR *dst_dir = opendir(dst_dirname);
    struct dirent *src_pdir;
    struct dirent *dst_pdir;
    
    if (src_dir == NULL)
    {
        printf("Error opening source directory '%s': %s\n", src_dirname, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    if (dst_dir == NULL)
    {
        printf("Error opening destination directory '%s': %s\n", dst_dirname, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    while ((src_pdir = readdir(src_dir)) != NULL)
    {
        if (strcmp(src_pdir->d_name, ".") == 0 || strcmp(src_pdir->d_name, "..") == 0)
        {
            continue;
        }
        
        rewinddir(dst_dir);
        
        while ((dst_pdir = readdir(dst_dir)) != NULL)
        {
            if (strcmp(dst_pdir->d_name, ".") == 0 || strcmp(dst_pdir->d_name, "..") == 0)
            {
                continue;
            }
            
            if (strcmp(src_pdir->d_name, dst_pdir->d_name) == 0)
            {
                char src_path[MAX_PATH_LENGTH];
                char dst_path[MAX_PATH_LENGTH];
                
                snprintf(src_path, MAX_PATH_LENGTH, "%s/%s", src_dirname, src_pdir->d_name);
                snprintf(dst_path, MAX_PATH_LENGTH, "%s/%s", dst_dirname, dst_pdir->d_name);
                
                struct stat src_stat_buf;
                struct stat dst_stat_buf;
                
                if (stat(src_path, &src_stat_buf) == -1)
                {
                    printf("Error getting file status for '%s': %s\n", src_path, strerror(errno));
                    exit(EXIT_FAILURE);
                }
                
                if (stat(dst_path, &dst_stat_buf) == -1)
                {
                    printf("Error getting file status for '%s': %s\n", dst_path, strerror(errno));
                    exit(EXIT_FAILURE);
                }
                
                if (src_stat_buf.st_mtime > dst_stat_buf.st_mtime)
                {
                    copy_file(src_path, dst_path);
                    printf("'%s' copied to '%s'.\n", src_path, dst_path);
                }
                
                break;
            }
        }
        
        if (dst_pdir == NULL)
        {
            char src_path[MAX_PATH_LENGTH];
            char dst_path[MAX_PATH_LENGTH];
            
            snprintf(src_path, MAX_PATH_LENGTH, "%s/%s", src_dirname, src_pdir->d_name);
            snprintf(dst_path, MAX_PATH_LENGTH, "%s/%s", dst_dirname, src_pdir->d_name);
            
            if (src_pdir->d_type == DT_DIR)
            {
                mkdir(dst_path, 0755);
                sync_dir(src_path, dst_path);
            }
            else
            {
                copy_file(src_path, dst_path);
                printf("'%s' copied to '%s'.\n", src_path, dst_path);
            }
        }
    }
    
    closedir(src_dir);
    closedir(dst_dir);
}

void copy_file(char *src_filename, char *dst_filename)
{
    FILE *src_file = fopen(src_filename, "rb");
    FILE *dst_file = fopen(dst_filename, "wb");
    char buffer[MAX_BUFFER_SIZE];
    size_t read_size;
    
    if (src_file == NULL)
    {
        printf("Error opening source file '%s': %s\n", src_filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    if (dst_file == NULL)
    {
        printf("Error opening destination file '%s': %s\n", dst_filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    while ((read_size = fread(buffer, 1, MAX_BUFFER_SIZE, src_file)) > 0)
    {
        if (fwrite(buffer, 1, read_size, dst_file) != read_size)
        {
            printf("Error writing to file '%s': %s\n", dst_filename, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
    
    fclose(src_file);
    fclose(dst_file);
}