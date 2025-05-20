//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<fcntl.h>

#define MAX_LENGTH 512
#define MAX_ARGUMENTS 10

int main(){

    char input[MAX_LENGTH];
    char* arguments[MAX_ARGUMENTS];
    char* token;

    while(1){
        printf("Enter a command: ");
        fgets(input, MAX_LENGTH, stdin);
        
        token = strtok(input, " \n");
        
        int i = 0;
        while(token != NULL){
            arguments[i] = token;
            token = strtok(NULL, " \n");
            i++;
        }
        arguments[i] = NULL;
        
        if(strcmp(arguments[0], "exit") == 0){
            printf("Goodbye!\n");
            break;
        }
        
        pid_t pid = fork();
        if(pid == 0){
            if(strcmp(arguments[0], "phoenix") == 0){
                printf("\nThe sky is bleeding and the flames are alive...\n");
                printf("The phoenix rises from the ashes.\n");
            }
            else if(strcmp(arguments[0], "ocean") == 0){
                printf("\nThe sea sings a song of storm and sorrow...\n");
                printf("The ocean whispers secrets of the deep.\n");
            }
            else if(strcmp(arguments[0], "sunflower") == 0){
                printf("\nThe earth is a canvas of vibrant color...\n");
                printf("The sunflower is the masterpiece of the sun.\n");
            }
            else{
                printf("Command not recognized.\n");
                exit(0);
            }
        }
        else if(pid > 0){
            wait(NULL);
        }
        else{
            printf("Fork failed.\n");
        }
    }
    
    return 0;
}