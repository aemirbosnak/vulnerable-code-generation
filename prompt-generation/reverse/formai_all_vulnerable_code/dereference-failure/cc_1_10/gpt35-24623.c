//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>

#define MAX_DEVICES 100
#define PORT 8888

struct device{
    char name[50];
    char ip_address[20];
    char mac_address[20];
};

int main(){
    struct device devices[MAX_DEVICES]; //declare array of devices
    int num_devices = 0; //initialize number of devices to 0

    int sockfd = socket(AF_INET, SOCK_STREAM, 0); //create socket
    if(sockfd < 0){
        perror("Socket creation error");
        return -1;
    }

    struct sockaddr_in server; //server address struct
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if(bind(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0){ //bind socket to address
        perror("Bind error");
        return -1;
    }

    if(listen(sockfd, 5) < 0){ //listen for incoming connections
        perror("Listen error");
        return -1;
    }
    
    printf("Started network topology mapper...\n");

    while(1){
        int new_socket = accept(sockfd, NULL, NULL); //accept incoming connection
        if(new_socket < 0){
            perror("Accept error");
            continue;
        }

        char* device_info = (char*)malloc(sizeof(char)*1024); //allocate memory for device info string
        recv(new_socket, device_info, 1024, 0); //receive device info from client

        if(strlen(device_info) > 0){ //if client sends device info
            char* name = strtok(device_info, ",");
            char* ip_address = strtok(NULL, ",");
            char* mac_address = strtok(NULL, ",");

            strcpy(devices[num_devices].name, name); //copy device info to device struct
            strcpy(devices[num_devices].ip_address, ip_address);
            strcpy(devices[num_devices].mac_address, mac_address);

            printf("Added device: %s, %s, %s\n", name, ip_address, mac_address);
            num_devices++; //update number of devices
        }

        char* topology_info = (char*)malloc(sizeof(char)*1024); //allocate memory for topology info string

        for(int i=0;i<num_devices;i++){ //iterate through devices and send topology info
            strcpy(topology_info, devices[i].name);
            strcat(topology_info, ",");
            strcat(topology_info, devices[i].ip_address);
            strcat(topology_info, ",");
            strcat(topology_info, devices[i].mac_address);
            for(int j=0;j<num_devices;j++){
                if(i != j){ //if devices are different
                    strcat(topology_info, ",");
                    strcat(topology_info, devices[j].name);
                    strcat(topology_info, ",");
                    strcat(topology_info, devices[j].ip_address);
                }
            }

            send(new_socket, topology_info, strlen(topology_info), 0); //send topology info to client
            printf("Sent topology info: %s\n", topology_info);
        }

        free(device_info);
        free(topology_info);
        close(new_socket); //close connection
    }

    return 0;
}