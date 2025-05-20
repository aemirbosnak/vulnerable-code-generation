//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

struct file_system
{
    char **files;
    int num_files;
    int free_space;
};

struct file_system fs;

void initialize_file_system()
{
    fs.files = (char**)malloc(MAX_FILES * sizeof(char*));
    fs.num_files = 0;
    fs.free_space = MAX_FILES;
}

void create_file(char *name)
{
    if (fs.num_files >= fs.free_space)
    {
        printf("Error: File system is full.\n");
        return;
    }

    fs.files[fs.num_files] = name;
    fs.num_files++;
    fs.free_space--;
}

void list_files()
{
    for (int i = 0; i < fs.num_files; i++)
    {
        printf("%s\n", fs.files[i]);
    }
}

int main()
{
    initialize_file_system();

    create_file("a.txt");
    create_file("b.txt");
    create_file("c.txt");

    list_files();

    return 0;
}