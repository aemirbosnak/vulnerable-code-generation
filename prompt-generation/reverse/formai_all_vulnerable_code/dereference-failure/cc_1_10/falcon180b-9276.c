//Falcon-180B DATASET v1.0 Category: Networking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    if(argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    server_addr.sin_port = htons(port_number);

    // Connect to remote server
    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char send_buffer[BUF_SIZE];
    char receive_buffer[BUF_SIZE];

    while(TRUE) {
        memset(send_buffer, 0, BUF_SIZE);
        memset(receive_buffer, 0, BUF_SIZE);

        // Read input from user
        printf("Enter message: ");
        fgets(send_buffer, BUF_SIZE, stdin);

        // Send message to server
        if(send(sockfd, send_buffer, strlen(send_buffer), 0) == -1) {
            printf("Error sending message\n");
            exit(1);
        }

        // Receive message from server
        int bytes_received = recv(sockfd, receive_buffer, BUF_SIZE, 0);
        if(bytes_received == -1) {
            printf("Error receiving message\n");
            exit(1);
        } else if(bytes_received == 0) {
            printf("Connection closed by server\n");
            exit(0);
        }

        // Print received message
        printf("Received message: %s\n", receive_buffer);
    }

    close(sockfd);
    return 0;
}