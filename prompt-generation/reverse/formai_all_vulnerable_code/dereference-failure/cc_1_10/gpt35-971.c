//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct log_entry{
    char ip_address[20];
    char timestamp[100];
    char message[200];
};

int main(){
    struct log_entry logs[100];
    int count = 0;

    //read the log file
    FILE *logfile;
    char *filename = "logfile.txt";
    char line[200];
    logfile = fopen(filename, "r");

    if(logfile == NULL){
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    //parse each log entry and store in logs array
    while(fgets(line, 200, logfile)){
        char *token = strtok(line, ",");
        strcpy(logs[count].ip_address, token);
        token = strtok(NULL, ",");
        strcpy(logs[count].timestamp, token);
        token = strtok(NULL, ",");
        strcpy(logs[count].message, token);
        count++;
    }

    //check for intrusions
    int intrusion_count = 0;
    for(int i = 0; i < count-1; i++){
        int time_interval = atoi(logs[i+1].timestamp) - atoi(logs[i].timestamp);
        if(time_interval < 5 && strcmp(logs[i].ip_address, logs[i+1].ip_address) != 0){
            //potential intrusion detected
            printf("Intrusion detected: %s tried to access from %s\n", logs[i+1].ip_address, logs[i].ip_address);
            intrusion_count++;
        }
    }

    if(intrusion_count != 0){
        printf("%d potential intrusion(s) detected!\n", intrusion_count);
    }
    else{
        printf("No potential intrusions detected.\n");
    }

    fclose(logfile);
    return 0;
}