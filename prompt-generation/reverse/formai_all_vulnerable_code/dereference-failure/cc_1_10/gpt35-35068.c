//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char command[50] = "free -m | grep Mem: | awk '{print $2}'";  // command to get total RAM
    char* output = malloc(sizeof(char) * 10);                     // allocate memory to store command output
    FILE* fp = popen(command, "r");                                // run command using popen() and get output

    if (fp == NULL)                                                // check if command execution is successful
    {
        printf("Error: Failed to run command\n");
        return 0;
    }

    fgets(output, 10, fp);     // read output of command into 'output' variable
    pclose(fp);                // close the pipe

    int total_ram = atoi(output);  // convert output string to integer

    while (1)    // loop to continuously monitor RAM usage
    {
        system("clear");   // clear terminal screen

        char command1[50] = "free -m | grep Mem: | awk '{print $3}'";  // command to get used RAM
        char* output1 = malloc(sizeof(char) * 10);                    // allocate memory to store command output
        FILE* fp1 = popen(command1, "r");                              // run command using popen() and get output

        if (fp1 == NULL)     // check if command execution is successful
        {
            printf("Error: Failed to run command\n");
            return 0;
        }

        fgets(output1, 10, fp1);    // read output of command into 'output1' variable
        pclose(fp1);               // close the pipe

        int used_ram = atoi(output1);  // convert output string to integer

        printf("RAM Usage: %d/%d MB\n", used_ram, total_ram);  // display RAM usage on terminal

        free(output1);    // free memory allocated to output1 variable

        sleep(1);    // pause execution of program for 1 second
    }

    free(output);    // free memory allocated to output variable

    return 0;
}