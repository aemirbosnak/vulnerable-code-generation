//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>

//Function to get size of a file
long int getfilesize(char filename[])
{
    struct stat st;
    if(stat(filename, &st)==0)
        return st.st_size;
    else 
        return -1;
}

//Function to get size of a directory
long int getdirsize(char dirname[])
{
    long int size=0;
    DIR *d;
    struct dirent *dir;
    struct stat st;
    char filename[256];
    d=opendir(dirname);
    if(d){
        while((dir=readdir(d))!=NULL){
            if(strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0){
                sprintf(filename,"%s/%s",dirname,dir->d_name);
                if(stat(filename, &st)==0)
                {
                    if(S_ISREG(st.st_mode))
                        size+=st.st_size;
                    if(S_ISDIR(st.st_mode))
                        size+=getdirsize(filename);
                }
            }
        }
        closedir(d);
    }
    return size;
}

int main()
{
    char path[256];
    printf("Enter directory path: ");
    scanf("%s",path);
    printf("\n");

    long int dirsize=getdirsize(path);

    if(dirsize==-1)
        printf("Error: %s does not exist or is inaccessible\n",path);
    else if(dirsize==0)
        printf("%s is empty\n",path);
    else
        printf("%s size is %ld bytes\n",path,dirsize);
    
    return 0;
}