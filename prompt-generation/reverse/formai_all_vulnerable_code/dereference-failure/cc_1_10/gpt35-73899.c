//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define KB 1024
#define MB 1048576
#define GB 1073741824

long long int total_size = 0;

void analyze_directory(char *dirname){
    DIR *dir;
    struct dirent *entry;
    char pathname[1024];
    dir = opendir(dirname);
    if (!dir){
        printf("Error opening directory '%s', please ensure you have sufficient permissions.\n", dirname);
        return;
    }
    while((entry = readdir(dir)) != NULL){
        if (entry->d_type == DT_DIR){
            if (strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0) continue;
            snprintf(pathname, sizeof(pathname), "%s/%s", dirname, entry->d_name);
            analyze_directory(pathname);
        }
        else{
            char cur_file[1024];
            snprintf(cur_file, sizeof(cur_file), "%s/%s", dirname, entry->d_name);
            FILE *fp;
            fp = fopen(cur_file,"r");
            if (!fp){
                printf("Error opening file '%s', skipping...\n", cur_file);
                continue;
            }
            fseek(fp, 0L, SEEK_END);
            long long int filesize = ftell(fp);
            fclose(fp);
            printf("%s: %lld bytes\n", cur_file, filesize);
            total_size += filesize;
        }
    }
    closedir(dir);
}

int main(int argc, char **argv){
    if (argc<2){
        printf("Usage: ./disk_analyzer <directory>\n");
        exit(1);
    }
    char *dirname = argv[1];
    analyze_directory(dirname);
    printf("Total Size: ");
    if (total_size<MB) printf("%lld bytes\n", total_size);
    else if (total_size>=MB && total_size<GB) printf("%lld MB\n", total_size/MB);
    else printf("%lld GB\n", total_size/GB);
    return 0;
}