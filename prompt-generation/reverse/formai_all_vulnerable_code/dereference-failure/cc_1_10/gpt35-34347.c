//FormAI DATASET v1.0 Category: File system simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCK_SIZE 4096
#define MAX_FILE_NAME 16
#define MAX_FILES 64

typedef struct block
{
    int block_num;
    char data[MAX_BLOCK_SIZE];
    struct block *next;
} Block;

typedef struct file
{
    char name[MAX_FILE_NAME];
    int size;
    Block *head;
} File;

typedef struct directory
{
    int num_files;
    File files[MAX_FILES];
} Directory;

Directory *create_directory()
{
    Directory *dir = malloc(sizeof(Directory));
    dir -> num_files = 0;
    return dir;
}

Block *create_block(int num)
{
    Block *block = malloc(sizeof(Block));
    block -> block_num = num;
    block -> next = NULL;
    return block;
}

File *create_file(char *name)
{
    File *file = malloc(sizeof(File));
    strcpy(file -> name, name);
    file -> size = 0;
    file -> head = NULL;
    return file;
}

int add_file(Directory *dir, char *name)
{
    if(dir -> num_files == MAX_FILES)
    {
        printf("Maximum number of files reached\n");
        return -1;
    }

    for(int i=0; i<dir -> num_files; i++)
    {
        if(strcmp(dir -> files[i].name, name) == 0)
        {
            printf("File with name '%s' already exists\n", name);
            return -1;
        }
    }

    File *file = create_file(name);
    dir -> files[dir -> num_files] = *file;
    dir -> num_files++;
    printf("File '%s' created\n", name);
    return 0;
}

int delete_file(Directory *dir, char *name)
{
    for(int i=0; i<dir -> num_files; i++)
    {
        if(strcmp(dir -> files[i].name, name) == 0)
        {
            File file = dir -> files[i];
            while(file.head != NULL)
            {
                Block *temp = file.head;
                file.head = file.head -> next;
                free(temp);
            }
            dir -> num_files--;
            for(int j=i; j<dir -> num_files; j++)
            {
                dir -> files[j] = dir -> files[j+1];
            }
            printf("File '%s' deleted\n", name);
            return 0;
        }
    }
    printf("File with name '%s' does not exist\n", name);
    return -1;
}

int add_data(Directory *dir, char *name, char *data)
{
    for(int i=0; i<dir -> num_files; i++)
    {
        if(strcmp(dir -> files[i].name, name) == 0)
        {
            File *file = &dir -> files[i];
            int data_size = strlen(data);
            int num_blocks = data_size % MAX_BLOCK_SIZE == 0 ? data_size / MAX_BLOCK_SIZE : data_size / MAX_BLOCK_SIZE + 1;
            for(int i=0; i<num_blocks; i++)
            {
                Block *block = create_block(file -> size + i);
                int j = 0;
                while(j < MAX_BLOCK_SIZE && (i*MAX_BLOCK_SIZE+j) < data_size)
                {
                    block -> data[j] = data[i*MAX_BLOCK_SIZE+j];
                    j++;
                }
                block -> data[j] = '\0';
                if(file -> head == NULL)
                {
                    file -> head = block;
                }
                else
                {
                    Block *temp = file -> head;
                    while(temp -> next != NULL)
                    {
                        temp = temp -> next;
                    }
                    temp -> next = block;
                }
            }
            file -> size = data_size;
            printf("Data added to file '%s'\n", name);
            return 0;
        }
    }
    printf("File with name '%s' does not exist\n", name);
    return -1;
}

int delete_data(Directory *dir, char *name)
{
    for(int i=0; i<dir -> num_files; i++)
    {
        if(strcmp(dir -> files[i].name, name) == 0)
        {
            File *file = &dir -> files[i];
            file -> size = 0;
            while(file -> head != NULL)
            {
                Block *temp = file -> head;
                file -> head = file -> head -> next;
                free(temp);
            }
            printf("Data deleted from file '%s'\n", name);
            return 0;
        }
    }
    printf("File with name '%s' does not exist\n", name);
    return -1;
}

void print_directory(Directory *dir)
{
    printf("Directory Contents:\n");
    printf("===================\n");
    if(dir -> num_files == 0)
    {
        printf("Directory is empty\n");
        return;
    }

    for(int i=0; i<dir -> num_files; i++)
    {
        File file = dir -> files[i];
        printf("File Name: %s\n", file.name);
        printf("File Size: %d bytes\n", file.size);
        if(file.head != NULL)
        {
            printf("File Data: \n");
            Block *temp = file.head;
            while(temp != NULL)
            {
                printf("%s", temp -> data);
                temp = temp -> next;
            }
            printf("\n");
        }
        else
        {
            printf("File is Empty\n");
        }
    }
}

int main()
{
    Directory *dir = create_directory();
    add_file(dir, "file1");
    add_file(dir, "file2");
    print_directory(dir);
    add_data(dir, "file1", "Hello World!");
    print_directory(dir);
    add_data(dir, "file2", "This is a sample file.");
    print_directory(dir);
    delete_data(dir, "file1");
    delete_file(dir, "file2");
    print_directory(dir);
    return 0;
}