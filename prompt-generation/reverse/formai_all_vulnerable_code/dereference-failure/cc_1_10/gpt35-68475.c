//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    FILE* filePointer;
    char buffer[100];
    char cpu[10];
    char* token;
    float idletime, usertime, systemtime, iowaittime;

    while (1)
    {
        filePointer = fopen("/proc/stat", "r");
        if (filePointer == NULL)
        {
            printf("Unable to open file /proc/stat");
            exit(1);
        }

        fgets(buffer, 100, filePointer);

        token = strtok(buffer, " ");
        strcpy(cpu, token);

        usertime = strtof(strtok(NULL, " "), NULL);
        usertime += strtof(strtok(NULL, " "), NULL);
        systemtime = strtof(strtok(NULL, " "), NULL);
        iowaittime = strtof(strtok(NULL, " "), NULL);
        idletime = strtof(strtok(NULL, " "), NULL);

        printf("\nCPU Usage Stats:");
        printf("\n--------------------");

        printf("\nCPU: %s", cpu);

        printf("\nUser Time: %f seconds", usertime/100.0);
        printf("\nSystem Time: %f seconds", systemtime/100.0);
        printf("\nIO Wait Time: %f seconds", iowaittime/100.0);
        printf("\nIdle Time: %f seconds", idletime/100.0);

        fclose(filePointer);
        sleep(1);
        system("clear");
    }

    return 0;
}