//FormAI DATASET v1.0 Category: File Synchronizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

void sync_folders(char *source, char *destination){
    struct dirent *dp;
    DIR *dir = opendir(source);

    while((dp=readdir(dir))!=NULL){
        if(strcmp(dp->d_name,".")==0 || strcmp(dp->d_name,"..")==0)
            continue;
        
        char source_path[1000], dest_path[1000];       
        sprintf(source_path,"%s/%s",source,dp->d_name);
        sprintf(dest_path,"%s/%s",destination,dp->d_name);
        struct stat statbuf;
    
        if(stat(source_path, &statbuf)==-1){
            printf("Error syncing %s\n",source_path);
            continue;
        }
    
        if(S_ISDIR(statbuf.st_mode)){
            mkdir(dest_path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
            sync_folders(source_path, dest_path);
        }else{
            FILE *source_file = fopen(source_path, "rb");
            FILE *dest_file = fopen(dest_path, "wb");
        
            if (!source_file || !dest_file){
                printf("Error syncing: %s or %s\n",source_path, dest_path);
                continue;
            }
        
            char buff[1024];
            size_t size;
            while ((size = fread(buff, 1, 1024, source_file)) > 0) {
                fwrite(buff, size, 1, dest_file);
            }
            fclose(source_file);
            fclose(dest_file);
        }
    }
}

int main(int argc, char** argv){  
    if(argc<3){
        printf("Invalid arguments. Usage: %s <source_folder> <destination_folder>\n",argv[0]);
        return 1;
    }
    while(1){
        sync_folders(argv[1], argv[2]);
        sleep(30); // wait for 30 seconds before syncing again
    }
    return 0;
}