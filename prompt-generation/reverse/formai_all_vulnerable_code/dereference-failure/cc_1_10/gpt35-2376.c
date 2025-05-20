//FormAI DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

void synchronize(char[], char[]);

int main()
{
    char source_path[100], destination_path[100];

    printf("Enter the path of the source directory: ");
    scanf("%s", source_path);

    printf("Enter the path of the destination directory: ");
    scanf("%s", destination_path);

    synchronize(source_path, destination_path);

    return 0;
}

void synchronize(char source_path[], char destination_path[])
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char source_file[200], destination_file[200], ch;
    int fd1, fd2, f1_size, f2_size;

    dir = opendir(source_path);

    if(dir == NULL)
    {
        printf("Error: Unable to open source directory.\n");
        exit(1);
    }

    while((entry = readdir(dir)) != NULL)
    {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        sprintf(source_file, "%s/%s", source_path, entry->d_name);
        sprintf(destination_file, "%s/%s", destination_path, entry->d_name);

        lstat(source_file, &file_stat);

        if(S_ISREG(file_stat.st_mode))
        {
            // Synchronize files only if they are modified
            fd1 = open(source_file, O_RDONLY);
            fd2 = open(destination_file, O_RDONLY);

            if(fd2 < 0)
            {
                printf("Destination file %s does not exist. Copying file.\n", entry->d_name);
                fd2 = creat(destination_file, file_stat.st_mode);
                close(fd2);
                fd2 = open(destination_file, O_RDWR);
            }

            f1_size = lseek(fd1, 0, SEEK_END);
            f2_size = lseek(fd2, 0, SEEK_END);

            if(f1_size != f2_size)
            {
                printf("Copying file %s as file sizes are different.\n", entry->d_name);
                close(fd1);
                close(fd2);
                fd1 = open(source_file, O_RDONLY);
                fd2 = creat(destination_file, file_stat.st_mode);
                close(fd2);
                fd2 = open(destination_file, O_RDWR);
                ch = '\0';
                while(read(fd1, &ch, 1) > 0)
                    write(fd2, &ch, 1);
                printf("File %s copied successfully.\n", entry->d_name);
            }

            else
            {
                close(fd1);
                close(fd2);
                fd1 = open(source_file, O_RDONLY);
                fd2 = open(destination_file, O_RDWR);
                ch = '\0';
                while(read(fd1, &ch, 1) > 0)
                    write(fd2, &ch, 1);
                printf("File %s synchronized successfully.\n", entry->d_name);
            }

            close(fd1);
            close(fd2);

        }

        if(S_ISDIR(file_stat.st_mode))
        {
            synchronize(source_file, destination_file);
        }

    }

    printf("\nSynchronization complete.\n");

}