//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>

void syncFiles(char* src, char* dest);
int compareFiles(FILE *fp1, FILE *fp2);

int main(int argc, char** argv)
{
    if(argc!=3)
    {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    syncFiles(argv[1], argv[2]);

    printf("Files synchronized successfully!\n");

    exit(EXIT_SUCCESS);
}

void syncFiles(char* src, char* dest)
{
    DIR *dir;
    struct dirent *entry;
    if(!(dir = opendir(src)))
        return;
    while((entry = readdir(dir)) != NULL)
    {
        char path[1024];
        sprintf(path, "%s/%s", src, entry->d_name);
        struct stat statbuf;
        if(!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
            continue;
        if(stat(path, &statbuf) == -1)
            continue;
        if(S_ISDIR(statbuf.st_mode))
        {
            char *sub_src = malloc(strlen(src) + strlen(entry->d_name) + 2);
            sprintf(sub_src, "%s/%s", src, entry->d_name);
            char *sub_dest = malloc(strlen(dest) + strlen(entry->d_name) + 2);
            sprintf(sub_dest, "%s/%s", dest, entry->d_name);
            syncFiles(sub_src, sub_dest);
        }
        else
        {
            char *src_file = malloc(strlen(src) + strlen(entry->d_name) + 2);
            sprintf(src_file, "%s/%s", src, entry->d_name);
            char *dest_file = malloc(strlen(dest) + strlen(entry->d_name) + 2);
            sprintf(dest_file, "%s/%s", dest, entry->d_name);
            struct stat dest_statbuf;
            if(stat(dest_file, &dest_statbuf) == -1)
            {
                // destination file does not exist, create one
                fclose(fopen(dest_file, "w"));
            }
            FILE *src_fp = fopen(src_file, "rb");
            FILE *dest_fp = fopen(dest_file, "rb");
            if(compareFiles(src_fp, dest_fp))
            {
                // files are identical, no action required
                fclose(src_fp);
                fclose(dest_fp);
                continue;
            }
            fclose(dest_fp);   
            remove(dest_file);
            link(src_file, dest_file);
            fclose(src_fp);
            printf("File synchronized: %s\n", entry->d_name); 
        }
    }
    closedir(dir);
}

int compareFiles(FILE *fp1, FILE *fp2)
{
    int ch1, ch2;
    while(1)
    {
        ch1 = getc(fp1);
        ch2 = getc(fp2);
        if(ch1 == EOF || ch2 == EOF)
            break;
        if(ch1 != ch2)
        {
            return 0; // files differ
        }
    }
    if(ch1 == ch2)
        return 1; // files are identical
    else 
        return 0; // files differ
}