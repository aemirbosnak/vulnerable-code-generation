//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//Constants
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

//Function Declarations
int scan_port(char *ip_addr, int port);

//Main Function
int main(int argc, char **argv) {
    //Check for valid arguments
    if (argc < 3) {
        printf("Usage: %s <ip_addr> <port1> <port2>\n", argv[0]);
        return 1;
    }

    //Get the IP address and ports from the command line
    char *ip_addr = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    //Check if the ports are valid
    if (start_port < 0 || start_port > MAX_PORTS || end_port < 0 || end_port > MAX_PORTS) {
        printf("Invalid port range\n");
        return 1;
    }

    //Scan the ports
    for (int port = start_port; port <= end_port; port++) {
        if (scan_port(ip_addr, port)) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    return 0;
}

//Function to scan a port
int scan_port(char *ip_addr, int port) {
    //Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        return 0;
    }

    //Set the socket timeout
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt() failed");
        close(sockfd);
        return 0;
    }

    //Connect to the port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip_addr);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        if (errno == ETIMEDOUT) {
            close(sockfd);
            return 0;
        } else {
            perror("connect() failed");
            close(sockfd);
            return 0;
        }
    }

    //Receive data from the port
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv() failed");
        close(sockfd);
        return 0;
    }

    //Close the socket
    close(sockfd);

    //Check if the port is open
    if (bytes_received > 0) {
        return 1;
    } else {
        return 0;
    }
}