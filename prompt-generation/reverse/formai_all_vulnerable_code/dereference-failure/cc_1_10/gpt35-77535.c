//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define PORT 80
#define HOSTNAME "www.google.com"
#define REQUEST "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n"

int main(){
    // Initialize variables
    char buffer[BUF_SIZE];
    struct hostent *host_info;
    struct sockaddr_in server_addr;
    int sockfd, bytes_received;

    // Get host information
    host_info = gethostbyname(HOSTNAME);
    if(host_info == NULL){
        printf("Error: Could not resolve hostname.\n");
        exit(1);
    }

    // Create socket
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    // Setup server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *)host_info->h_addr);
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){
        printf("Error: Could not connect to server.\n");
        exit(1);
    }

    // Send request to server
    if(send(sockfd, REQUEST, strlen(REQUEST), 0) == -1){
        printf("Error: Could not send request to server.\n");
        exit(1);
    }

    // Receive response from server
    bytes_received = recv(sockfd, buffer, BUF_SIZE, 0);

    // Check if response was received
    if(bytes_received == -1){
        printf("Error: Could not receive response from server.\n");
        exit(1);
    }

    // Close socket
    close(sockfd);

    // Compute internet speed and print to console
    double speed = (double)bytes_received / 1000.0;
    printf("Your internet speed is %.2f KB/s\n", speed);

    return 0;
}