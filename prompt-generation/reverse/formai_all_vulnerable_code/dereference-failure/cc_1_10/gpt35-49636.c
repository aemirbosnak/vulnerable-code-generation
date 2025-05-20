//FormAI DATASET v1.0 Category: Image Classification system ; Style: asynchronous
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    sigset_t set;
    int fd;
    char *filename=argv[1];
    char str[60], inp[100];

    if(argc!=2)
    {
        printf("\nFormat:\n./a.out <filename>\n");
        exit(0);
    }

    if ((fd=open(filename,O_RDONLY))<0)
    {
        printf("\n Error: Cannot open source file");
        exit(0);
    }

    sprintf(str, "file %s", filename);
    FILE *fp = popen(str, "r");

    fgets(inp, sizeof(inp), fp);  // Reading the output from the file command

    pid=fork();  // Creating a child process to work asynchronously

    if(pid==-1)
    {
        printf("\n Error: Fork failed\n");
        exit(0);
    }

    else if(pid==0)
    {
        sigemptyset(&set);  // Creating an empty signal set
        sigaddset(&set, SIGUSR1);  // Adding signal SIGUSR1 to the signal set

        int i=0;
        char *tokens[5];  // Creating buffer for storing tokens

        tokens[0] = strtok(inp, ":");  // Tokenizing the output from file command with ':' as delimiter
        while(tokens[i]!=NULL)
        {
            i++;
            tokens[i]=strtok(NULL, ":");
        }

        if (strstr(tokens[1], "ELF") != NULL)  // Checking if file is an executable
        {
            printf("\n File type is executable");
            kill(getppid(), SIGUSR1);  // Sending signal to parent process
            exit(0);
        }

        else
        {
            printf("\n File type is not executable");
            exit(0);
        }
    }

    else
    {
        printf("\n Parent process running..");
        sleep(1);
        printf("\n Checking if file is executable..");
        sleep(1);
        printf("\n Child process started..");
        sleep(1);
        printf("\n Child process running..");
        sleep(1);
        printf("\n Waiting for response from child process..");
        sleep(1);
        printf("\n");

        sigemptyset(&set);
        sigaddset(&set, SIGUSR1);

        sigprocmask(SIG_BLOCK, &set, NULL);  // Blocking the signal

        while(1)
        {
            if(sigwaitinfo(&set, NULL)==SIGUSR1)  // Waiting for signal from child
            {
                printf("\n Signal received from child process..");
                sleep(1);
                printf("\n File is executable. Program will now exit.");
                exit(0);
            }
        }
    }

    close(fd);
    pclose(fp);

    return 0;  // Done
}