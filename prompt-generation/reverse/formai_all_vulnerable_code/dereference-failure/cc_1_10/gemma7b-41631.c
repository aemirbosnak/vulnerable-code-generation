//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    char *filename = "/tmp/foo.txt";
    FILE *fp;
    pid_t pid;
    int status;

    if ((fp = fopen(filename, "w")) == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    pid = fork();

    if (pid == 0)
    {
        fprintf(fp, "Hello, world!");
        fclose(fp);
        exit(0);
    }
    else if (pid > 0)
    {
        wait(&status);
        printf("Child process exited with status %d\n", status);

        if (stat(filename, NULL) == 0)
        {
            printf("File contents:\n");
            fp = fopen(filename, "r");
            char buf[1024];
            size_t bytes_read;

            while ((bytes_read = fread(buf, 1, 1024, fp)) > 0)
            {
                printf("%s", buf);
            }

            fclose(fp);
        }
    }
    else
    {
        perror("Error fork");
        exit(1);
    }

    return 0;
}