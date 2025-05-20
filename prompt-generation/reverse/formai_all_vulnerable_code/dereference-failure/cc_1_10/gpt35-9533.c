//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 1024

void qos_monitor(char* server_ip, int port_num) {
    int sockfd, res, i;
    char buffer[BUF_SIZE];
    struct sockaddr_in server_addr;
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }
    
    // Resolve server IP address
    struct hostent* server = gethostbyname(server_ip);
    if (!server) {
        printf("Error resolving server IP address\n");
        exit(1);
    }
    
    // Set server address and port number
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(port_num);
    
    // Connect to server
    res = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (res < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }
    
    // Monitor QoS every second for 10 seconds
    for (i = 0; i < 10; i++) {
        sleep(1);
        // Send QoS request to server
        sprintf(buffer, "QoS request %d", i);
        res = send(sockfd, buffer, strlen(buffer), 0);
        if (res < 0) {
            printf("Error sending QoS request\n");
            exit(1);
        }
        // Receive QoS response from server
        res = recv(sockfd, buffer, BUF_SIZE, 0);
        if (res < 0) {
            printf("Error receiving QoS response\n");
            exit(1);
        }
        // Display QoS response from server
        printf("QoS response %d received: %s\n", i, buffer);
    }
    
    // Close socket
    close(sockfd);
}

int main(int argc, char* argv[]) {
    // Check for command line arguments
    if (argc != 3) {
        printf("Usage: qos_monitor <server IP address> <port number>\n");
        exit(1);
    }
    // Call QoS monitor function
    qos_monitor(argv[1], atoi(argv[2]));
    return 0;
}