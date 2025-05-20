//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

#define MAX_DEVICES 256
#define MAX_DEV_NAME_LEN 64
#define MAX_IP_LEN 16
#define MAX_PORT_LEN 8

struct Device {
    char name[MAX_DEV_NAME_LEN];
    char ip[MAX_IP_LEN];
    char port[MAX_PORT_LEN];
};

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr,"Usage: %s <base IP address>\n", argv[0]);
        exit(0);
    }

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    // Open socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    // Get server name and port number
    server = gethostbyname(argv[1]);
    portno = atoi(argv[2]);
    if (portno == 0) {
        fprintf(stderr,"ERROR: Invalid port number\n");
        exit(0);
    }

    // Set server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    // Send command to server
    bzero(buffer,256);
    sprintf(buffer, "map %s", argv[1]);
    sprintf(buffer + strlen(buffer), " -p %d", portno);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");

    // Receive response from server
    bzero(buffer,256);
    n = read(sockfd, buffer, 255);
    if (n < 0) 
         error("ERROR reading from socket");

    // Parse response and build network topology map
    struct Device devices[MAX_DEVICES];
    int num_devices = 0;
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        if (strcmp(token, "connected") == 0) {
            char *device_name = strtok(NULL, " ");
            char *ip_address = strtok(NULL, " ");
            char *port_number = strtok(NULL, " ");

            struct Device device;
            strncpy(device.name, device_name, MAX_DEV_NAME_LEN);
            strncpy(device.ip, ip_address, MAX_IP_LEN);
            strncpy(device.port, port_number, MAX_PORT_LEN);
            devices[num_devices++] = device;
        }
        token = strtok(NULL, " ");
    }

    // Print network topology map
    printf("Network Topology Map:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%s (%s:%s)\n", devices[i].name, devices[i].ip, devices[i].port);
    }

    // Close socket
    close(sockfd);

    return 0;
}