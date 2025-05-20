//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void scan_file(char *filename){
    FILE *fp;
    char buf[1024];

    fp = fopen(filename, "r");

    while(fgets(buf, sizeof(buf), fp)){
        if(strstr(buf, "virus")){
            printf("Virus found in file: %s\n", filename);
            break;
        }
    }

    fclose(fp);
}

void scan_directory(char *path){
    DIR *dir;
    struct dirent *dp;

    dir = opendir(path);

    while((dp = readdir(dir)) != NULL){
        if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0){
            continue;
        }

        char file_path[1024];
        sprintf(file_path, "%s/%s", path, dp->d_name);

        if(dp->d_type == DT_DIR){
            scan_directory(file_path);
        }
        else{
            scan_file(file_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: ./scanner /path/to/scan\n");
        exit(1);
    }

    char *path = argv[1];
    scan_directory(path);

    return 0;
}