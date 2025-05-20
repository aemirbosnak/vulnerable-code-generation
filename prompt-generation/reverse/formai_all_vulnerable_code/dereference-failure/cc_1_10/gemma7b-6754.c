//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#define MAX_PROC_NUM 10

int main()
{
    int i, pid, status, proc_num = 0;
    char **processes = NULL;
    struct stat sb;

    processes = (char**)malloc(MAX_PROC_NUM * sizeof(char*));

    for (i = 0; i < MAX_PROC_NUM; i++)
    {
        processes[i] = (char*)malloc(256);
    }

    while (proc_num < MAX_PROC_NUM)
    {
        printf("Enter process name: ");
        scanf("%s", processes[proc_num]);

        pid = fork();

        if (pid == 0)
        {
            execlp("/bin/ls", "ls", processes[proc_num], NULL);
            exit(0);
        }

        else if (pid > 0)
        {
            wait(&status);
            proc_num++;
        }
    }

    for (i = 0; i < MAX_PROC_NUM; i++)
    {
        free(processes[i]);
    }

    free(processes);

    return 0;
}