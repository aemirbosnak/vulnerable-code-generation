//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LOGS 1000

struct log {
    char source_ip[16];
    char message[100];
};

int main() {
    struct log logs[MAX_LOGS]; // array to store intrusion logs
    int num_logs = 0; // count of the number of logs
    int i, j, flag;
    char check_ip[16];
    
    // read log file and create logs
    FILE *fp = fopen("intrusion_log.txt", "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    char line[100];
    while(fgets(line, 100, fp) != NULL) {
        char *ip = strtok(line, " ");
        char *message = strtok(NULL, "\n");
        strcpy(logs[num_logs].source_ip, ip);
        strcpy(logs[num_logs].message, message);
        num_logs++;
    }
    fclose(fp);
    
    // check for duplicate IP addresses in logs
    printf("Duplicate IP addresses:\n");
    for(i=0; i<num_logs; i++) {
        flag = 0;
        for(j=0; j<i; j++) {
            if(strcmp(logs[i].source_ip, logs[j].source_ip) == 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) {
            printf("%s\n", logs[i].source_ip);
        }
    }
    
    // check for specific IP address in logs
    printf("Enter an IP address to search for: ");
    scanf("%s", check_ip);
    flag = 0;
    for(i=0; i<num_logs; i++) {
        if(strcmp(check_ip, logs[i].source_ip) == 0) {
            printf("%s: %s\n", logs[i].source_ip, logs[i].message);
            flag = 1;
        }
    }
    if(flag == 0) {
        printf("No logs found for IP address %s\n", check_ip);
    }
    
    return 0;
}