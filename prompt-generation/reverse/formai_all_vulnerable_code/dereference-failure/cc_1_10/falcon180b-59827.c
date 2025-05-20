//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: calm
#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define BUF_SIZE 1024

typedef struct node
{
    char name[256];
    unsigned long long size;
}node;

void get_file_size(char* path, unsigned long long* size)
{
    struct stat st;
    stat(path,&st);
    *size = st.st_size;
}

int compare(const void* a, const void* b)
{
    node* n1 = (node*)a;
    node* n2 = (node*)b;

    if(n1->size > n2->size)
        return -1;
    else if(n1->size < n2->size)
        return 1;
    else
        return 0;
}

void print_files(node* files, int num_files)
{
    printf("File Name\tSize\n");
    for(int i=0; i<num_files; i++)
    {
        printf("%s\t%llu\n", files[i].name, files[i].size);
    }
}

int main()
{
    char dir[256];
    printf("Enter directory path: ");
    scanf("%s", dir);

    DIR* d;
    struct dirent* dirp;
    d = opendir(dir);

    if(d)
    {
        node* files = (node*)malloc(sizeof(node)*BUF_SIZE);
        int num_files = 0;

        while((dirp = readdir(d))!= NULL)
        {
            if(dirp->d_type == DT_REG)
            {
                if(num_files == BUF_SIZE)
                {
                    printf("Buffer full. Exiting...\n");
                    exit(0);
                }

                strcpy(files[num_files].name, dirp->d_name);
                get_file_size(dir, &(files[num_files].size));
                num_files++;
            }
        }

        closedir(d);

        qsort(files, num_files, sizeof(node), compare);

        printf("Sorted by size:\n");
        print_files(files, num_files);

        free(files);
    }
    else
    {
        printf("Error opening directory\n");
    }

    return 0;
}