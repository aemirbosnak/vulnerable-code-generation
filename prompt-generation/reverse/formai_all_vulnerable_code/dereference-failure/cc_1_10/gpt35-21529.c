//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define PORT 1337
#define BUFFER_SIZE 1024

void display_help(){
    printf("Usage: ./wireless_scanner [interface] [optional:IP address] \n");
    printf("Note: If no additional arguments are provided, the IP address will be defaulted to 192.168.1.1\n");
}

int main(int argc, char* argv[]){
    // Check if enough arguments are provided
    if(argc < 2){
        printf("Not enough arguments provided.\n");
        display_help();
        return 1;
    }

    // Create a buffer to hold received data
    char buffer[BUFFER_SIZE];

    // Get the interface to be used for scanning
    char *interface = argv[1];

    // Set the IP address to be scanned (defaults to 192.168.1.1)
    char ip_address[16] = "192.168.1.1";
    if(argc > 2){
        strcpy(ip_address, argv[2]);
    }

    // Create a socket to be used for communication
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("Unable to create socket.\n");
        return 1;
    }

    // Set up the server address to be used for connecting
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    // Connect to the server at the provided IP address
    if(connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0){
        perror("Connection failed.\n");
        return 1;
    }

    // Get the MAC address of the interface
    char mac_address[18] = {0};
    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strcpy(ifr.ifr_name, interface);
    if(ioctl(sockfd, SIOCGIFHWADDR, &ifr) == 0){
        sprintf(mac_address, "%.2X:%.2X:%.2X:%.2X:%.2X:%.2X",
            (unsigned char) ifr.ifr_hwaddr.sa_data[0],
            (unsigned char) ifr.ifr_hwaddr.sa_data[1],
            (unsigned char) ifr.ifr_hwaddr.sa_data[2],
            (unsigned char) ifr.ifr_hwaddr.sa_data[3],
            (unsigned char) ifr.ifr_hwaddr.sa_data[4],
            (unsigned char) ifr.ifr_hwaddr.sa_data[5]);
    }

    // Send a message to the server containing the MAC address of the interface
    char send_buffer[BUFFER_SIZE];
    sprintf(send_buffer, "REQUEST|%s", mac_address);
    if(send(sockfd, send_buffer, BUFFER_SIZE, 0) < 0){
        perror("Send failed.\n");
        return 1;
    }

    // Receive data from the server
    if(recv(sockfd, buffer, BUFFER_SIZE, 0) < 0){
        perror("Data reception failed.\n");
        return 1;
    }

    // Parse the received data to get a list of connected devices
    char *token = strtok(buffer, "|");
    while(token != NULL){
        if(strcmp(token, "RESPONSE") == 0){
            token = strtok(NULL, "|");
            printf("List of devices connected on network:\n");
            printf("--------------------------------------\n");
            while(token != NULL){
                printf("%s\n", token);
                token = strtok(NULL, "|");
            }
        } else {
            printf("Unknown response received: %s\n", token);
            return 1;
        }
    }

    // Close the socket and return success
    close(sockfd);
    return 0;
}