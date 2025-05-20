//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1024
#define THRESHOLD 200

//The Intrusion Detection System function, which checks for intrusion
void intrusion_detection_system(char* log_file)
{
    FILE *file;
    char line[MAX_SIZE];
    int count=0;

    file = fopen(log_file,"r");

    if(file == NULL)
    {
        printf("Cannot open the log file %s",log_file);
        exit(1);
    }

    printf("Starting Intrusion detection system...\n");

    while(fgets(line,sizeof(line),file) != NULL)
    {
        char *p;
        p = strtok(line," "); //splitting the line using space delimiter

        if(strcmp(p,"I") == 0) //if first token is "I", then it is an intrusion attempt
        {
            count++;
        }

        if(count >= THRESHOLD) //over a certain threshold we consider it an attack
        {
            printf("ALERT! Possible intrusion detected. Total intrustion attempts: %d\n",count);
            break;
        }
    }

    if(count < THRESHOLD)
    {
        printf("No intrusion detected. Total intrustion attempts: %d\n",count);
    }

    fclose(file);
}

//Driver function
int main()
{
    char log_file[MAX_SIZE];

    printf("Please enter the complete path of the log file: ");
    scanf("%s",log_file);

    intrusion_detection_system(log_file);

    return 0;
}