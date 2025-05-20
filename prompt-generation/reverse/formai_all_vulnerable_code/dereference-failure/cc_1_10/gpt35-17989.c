//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int checkfile(char *filename){
    FILE *fp = NULL;
    char c;
    int virus = 0;
    fp = fopen(filename,"r");
    while((c = fgetc(fp)) != EOF){
        if(c == 'v'){
            c = fgetc(fp);
            if(c == 'i'){
                c = fgetc(fp);
                if(c == 'r'){
                    c = fgetc(fp);
                    if(c == 'u'){
                        c = fgetc(fp);
                        if(c == 's'){
                            virus = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    fclose(fp);
    return virus;
}

int main(){
    DIR *dir;
    struct dirent *ent;
    char foldername[50];
    printf("Enter the folder name to scan: ");
    scanf("%s",foldername);
    dir = opendir(foldername);
    if(dir == NULL){
        printf("Could not open directory.\n");
        exit(1);
    }
    while((ent = readdir(dir)) != NULL){
        if(strcmp(ent->d_name,".") != 0 && strcmp(ent->d_name,"..") != 0){
            char filepath[100];
            sprintf(filepath,"%s/%s",foldername,ent->d_name);
            if(checkfile(filepath) == 1){
                printf("'%s' contains a virus.\n",filepath);
            } else {
                printf("'%s' is clean.\n",filepath);
            }
        }
    }
    closedir(dir);
    return 0;
}