//FormAI DATASET v1.0 Category: Error handling ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

void handle_error(int errnum)
{
    if(errnum == EACCES)
    {
        printf("Permission denied!\n");
        exit(EXIT_FAILURE);
    }
    else if(errnum == ENOENT)
    {
        printf("File not found!\n");
        exit(EXIT_FAILURE);
    }
    else if(errnum == EINVAL)
    {
        printf("Invalid argument passed!\n");
        exit(EXIT_FAILURE);
    }
    else if(errnum == ENOMEM)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    else if(errnum == EIO)
    {
        printf("Input/Output error occurred!\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Invalid number of arguments passed!\n");
        return EXIT_FAILURE;
    }
    
    FILE* fp = fopen(argv[1], "r");
    
    if(fp == NULL)
    {
        handle_error(errno);
    }
    
    printf("File opened successfully!\n");
    
    char ch;
    
    while((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }
    
    fclose(fp);
    return EXIT_SUCCESS;
}