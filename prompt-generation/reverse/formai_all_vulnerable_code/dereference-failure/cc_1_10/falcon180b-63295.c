//Falcon-180B DATASET v1.0 Category: System administration ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<signal.h>
#include<errno.h>

int count=0;
int status;
char **args;
char **envp;
char path[100];
char command[100];
char *ptr;

void sigchld_handler(int signum)
{
    while(waitpid(-1,&status,WNOHANG) > 0);
}

void execute_command(char *cmd)
{
    int pid=fork();

    if(pid==0)
    {
        if(execlp(cmd,cmd,NULL)==-1)
        {
            printf("Error: %s\n",strerror(errno));
            exit(1);
        }
    }
    else
    {
        waitpid(pid,&status,0);
    }
}

void list_directory(char *path)
{
    DIR *dir;
    struct dirent *dir_entry;

    dir=opendir(path);

    if(dir==NULL)
    {
        printf("Error: %s\n",strerror(errno));
        return;
    }

    while((dir_entry=readdir(dir))!=NULL)
    {
        printf("%s\n",dir_entry->d_name);
    }

    closedir(dir);
}

void change_directory(char *path)
{
    if(chdir(path)==-1)
    {
        printf("Error: %s\n",strerror(errno));
    }
}

void exit_program()
{
    exit(0);
}

int main(int argc,char **argv)
{
    signal(SIGCHLD,sigchld_handler);

    while(1)
    {
        printf("> ");
        fgets(command,100,stdin);
        args=NULL;
        envp=NULL;

        ptr=strtok(command," ");
        while(ptr!=NULL)
        {
            args=realloc(args,(count+1)*sizeof(char*));
            args[count]=ptr;
            count++;
            ptr=strtok(NULL," ");
        }
        args[count]=NULL;

        if(strcmp(args[0],"exit")==0)
        {
            exit_program();
        }
        else if(strcmp(args[0],"cd")==0)
        {
            change_directory(args[1]);
        }
        else if(strcmp(args[0],"ls")==0)
        {
            list_directory(args[1]);
        }
        else
        {
            execute_command(args[0]);
        }
    }

    return 0;
}