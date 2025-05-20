//FormAI DATASET v1.0 Category: Smart home light control ; Style: immersive
#include<stdio.h>
#include<string.h>

int main(){
    char input[50];
    int action;
    int light1 = 0;
    int light2 = 0;
    int light3 = 0;
    int brightness1 = 0;
    int brightness2 = 0;
    int brightness3 = 0;

    printf("Welcome to Smart Home Light Control!\n");
    printf("To turn on/off a light, type 'light [number] on/off'.\n");
    printf("To adjust brightness, type 'brightness [number] [0-100]'.\n");
    printf("To exit, type 'exit'.\n\n");

    while(1){
        printf("Enter command: ");
        fgets(input, 50, stdin);

        //parse input
        char *token = strtok(input, " ");
        char *command[3];
        int i = 0;
        while(token != NULL){
            command[i++] = token;
            token = strtok(NULL, " ");
        }
        action = i;

        //execute command
        if(strcmp(command[0], "exit\n") == 0){
            printf("Goodbye!\n");
            break;
        }
        else if(action == 3 && strcmp(command[0], "light") == 0){
            int lightNum = atoi(command[1]);
            if(strcmp(command[2], "on\n") == 0){
                if(lightNum == 1) light1 = 1;
                if(lightNum == 2) light2 = 1;
                if(lightNum == 3) light3 = 1;
                printf("Light %d turned on.\n", lightNum);
            }
            else if(strcmp(command[2], "off\n") == 0){
                if(lightNum == 1) light1 = 0;
                if(lightNum == 2) light2 = 0;
                if(lightNum == 3) light3 = 0;
                printf("Light %d turned off.\n", lightNum);
            }
            else{
                printf("Invalid command.\n");
            }
        }
        else if(action == 3 && strcmp(command[0], "brightness") == 0){
            int lightNum = atoi(command[1]);
            int brightness = atoi(command[2]);
            if(brightness < 0 || brightness > 100){
                printf("Brightness must be between 0-100.\n");
            }
            else{
                if(lightNum == 1) brightness1 = brightness;
                if(lightNum == 2) brightness2 = brightness;
                if(lightNum == 3) brightness3 = brightness;
                printf("Brightness of light %d set to %d.\n", lightNum, brightness);
            }
        }
        else{
            printf("Invalid command.\n");
        }
    }

    return 0;
}