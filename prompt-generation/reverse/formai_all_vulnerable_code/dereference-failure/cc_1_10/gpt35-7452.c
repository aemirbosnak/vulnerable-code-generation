//FormAI DATASET v1.0 Category: Firewall ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    //initialize variables
    char ip[15];
    int port;
    char protocol[10];
    int blocked = 0;

    //open the configuration file
    FILE *config = fopen("firewall.conf","r");
    if(config == NULL){
        printf("Could not open configuration file");
        return 1;
    }

    //take user input
    printf("Enter the IP address: ");
    scanf("%s", ip);
    printf("Enter the port number: ");
    scanf("%d", &port);
    printf("Enter the protocol (TCP/UDP): ");
    scanf("%s", protocol);

    //read the configuration file
    char line[50];
    while(fgets(line, sizeof(line), config)){
        //split the line into IP address, port number and protocol
        char *token = strtok(line, ",");
        char *config_ip = token;
        token = strtok(NULL, ",");
        int config_port = atoi(token);
        token = strtok(NULL, ",");
        char *config_protocol = token;

        //check if the user input matches the configuration
        if(strcmp(ip, config_ip) == 0 && port == config_port && strcmp(protocol, config_protocol) == 0){
            blocked = 1;
            break;
        }
    }

    //close the configuration file
    fclose(config);

    //display the result to the user
    if(blocked){
        printf("Access Denied!");
    }
    else{
        printf("Access Granted!");
    }

    return 0;
}