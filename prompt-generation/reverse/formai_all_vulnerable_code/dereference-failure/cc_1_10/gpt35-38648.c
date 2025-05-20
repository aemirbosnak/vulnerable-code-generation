//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_INPUT_LENGTH 256 //Max length of user input
#define MAX_DIR_NAME 1024 //Max length of directory name

//Function to print the current working directory
void print_pwd()
{
    char dir_name[MAX_DIR_NAME];
    if(getcwd(dir_name, MAX_DIR_NAME) != NULL)
    {
        printf("%s", dir_name);
    }
    else
    {
        perror("Error: ");
    }
}

//Function to handle user input and execute commands
void execute_command(char* input)
{
    char* args[16];
    char* arg;
    int i = 0;

    arg = strtok(input, " ");
    while(arg != NULL)
    {
        args[i] = arg;
        i++;
        arg = strtok(NULL, " ");
    }
    args[i] = NULL;

    if(strcmp(args[0], "cd") == 0)
    {
        if(chdir(args[1]) != 0)
        {
            perror("Error: ");
        }
    }
    else if(strcmp(args[0], "dir") == 0)
    {
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir (".")) != NULL) 
        {
            while ((ent = readdir (dir)) != NULL) 
            {
                printf ("%s\n", ent->d_name);
            }
            closedir (dir);
        } 
        else 
        {
            perror("");
        }
    }
    else
    {
        pid_t pid = fork();
        if(pid == 0)
        {
            if(execvp(args[0], args) == -1)
            {
                perror("Error: ");
            }
        }
        else if(pid < 0)
        {
            perror("Error: ");
        }
        else
        {
            waitpid(pid, NULL, 0);
        }
    }
}

int main()
{
    char input[MAX_INPUT_LENGTH];

    printf("Welcome to the ultimate Unix-like shell!\n");
    printf("Type 'exit' to exit the shell.\n");

    while(1)
    {
        print_pwd();
        printf(" $ ");
    
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;
        
        if(strcmp(input, "exit") == 0)
        {
            break;
        }

        execute_command(input);
    }

    printf("Goodbye!\n");
    return 0;
}