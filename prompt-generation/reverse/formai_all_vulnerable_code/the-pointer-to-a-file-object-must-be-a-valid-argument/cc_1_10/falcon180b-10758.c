//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

#define MAX_PROCESSES 1024
#define MAX_LINE 1024

typedef struct process_info
{
    int pid;
    char name[MAX_LINE];
    int status;
} PROCESS_INFO;

PROCESS_INFO process_list[MAX_PROCESSES];
int num_processes = 0;

void add_process(PROCESS_INFO *process)
{
    if (num_processes >= MAX_PROCESSES)
    {
        printf("Error: Process list is full.\n");
        return;
    }

    process_list[num_processes] = *process;
    num_processes++;
}

void print_processes()
{
    printf("Process ID\tProcess Name\tStatus\n");

    for (int i = 0; i < num_processes; i++)
    {
        printf("%d\t%s\t%d\n", process_list[i].pid, process_list[i].name, process_list[i].status);
    }
}

void signal_handler(int signal)
{
    if (signal == SIGCHLD)
    {
        int status;
        waitpid(-1, &status, WNOHANG);
    }
}

int main()
{
    signal(SIGCHLD, signal_handler);

    while (1)
    {
        system("ps aux > ps.txt");

        FILE *fp = fopen("ps.txt", "r");
        char line[MAX_LINE];
        PROCESS_INFO process;

        while (fgets(line, MAX_LINE, fp)!= NULL)
        {
            char *token = strtok(line, " ");
            process.pid = atoi(token);

            token = strtok(NULL, " ");
            strcpy(process.name, token);

            add_process(&process);
        }

        fclose(fp);
        remove("ps.txt");

        print_processes();
        sleep(5);
    }

    return 0;
}