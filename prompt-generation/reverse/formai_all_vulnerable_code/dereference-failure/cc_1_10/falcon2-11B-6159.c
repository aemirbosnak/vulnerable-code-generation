//Falcon2-11B DATASET v1.0 Category: File handling ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <filename> <mode>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int mode = atoi(argv[2]);

    int fd = open(filename, mode);

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), stdin))
    {
        if (fwrite(buffer, sizeof(char), strlen(buffer), stdout)!= strlen(buffer))
        {
            perror("Error writing to file");
            return 1;
        }
    }

    if (mode == O_WRONLY)
    {
        if (fclose(stdout)!= 0)
        {
            perror("Error closing file");
            return 1;
        }
    }
    else
    {
        if (fclose(stdin)!= 0)
        {
            perror("Error closing file");
            return 1;
        }
    }

    if (close(fd)!= 0)
    {
        perror("Error closing file");
        return 1;
    }

    return 0;
}