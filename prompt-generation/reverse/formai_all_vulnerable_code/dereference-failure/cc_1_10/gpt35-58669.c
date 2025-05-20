//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

#define SIZE 1000000000 //maximum size in bytes
#define GB_SIZE 1000000000.0 //1 GB in bytes

struct dir {
    char name[256];
    long int size;
    struct dir *next;
};

struct dir *head=NULL;

void insert(char name[256], long int size) {
    struct dir *temp;
    temp=(struct dir *)malloc(sizeof(struct dir));
    strcpy(temp->name, name);
    temp->size=size;
    temp->next=NULL;
    if(head==NULL) {
        head=temp;
    }
    else {
        struct dir *p;
        p=head;
        while(p->next!=NULL) {
            p=p->next;
        }
        p->next=temp;
    }
}

void scan_directory(char *dir_path) {
    struct dirent *dp;
    DIR *dir;
    struct stat buf;
    long int size=0;
    char temp_path[256];
    dir=opendir(dir_path);
    while((dp=readdir(dir))!=NULL) {
        if(strcmp(dp->d_name, ".")!=0 && strcmp(dp->d_name, "..")!=0) {
            strcpy(temp_path, dir_path);
            strcat(temp_path, "/");
            strcat(temp_path, dp->d_name);
            if(stat(temp_path, &buf)==-1) {
                printf("%s can't be accessed.\n", temp_path);
            }
            else {
                if(S_ISDIR(buf.st_mode)) {
                    scan_directory(temp_path);
                }
                else {
                    size=size+buf.st_size;
                }
            }
        }
    }
    closedir(dir);
    insert(dir_path, size);
}

void print_directory_structure() {
    struct dir *p;
    p=head;
    printf("Directory Structure:\n");
    printf("--------------------\n");
    while(p!=NULL) {
        printf("%s - ", p->name);
        if(p->size>=GB_SIZE) {
            printf("%.2f GB\n", (float)p->size/GB_SIZE);
        }
        else {
            printf("%.2f MB\n", (float)p->size/1000000);
        }
        p=p->next;
    }
}

int main() {
    char dir_path[256];
    printf("Enter the directory path: ");
    scanf("%s", dir_path);
    scan_directory(dir_path);
    print_directory_structure();
    return 0;
}