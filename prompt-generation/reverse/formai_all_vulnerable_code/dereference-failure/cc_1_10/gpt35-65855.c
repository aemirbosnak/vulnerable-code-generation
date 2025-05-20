//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUF_SIZE 1024

// Helper function to send and receive messages from server.
int sendMessage(int sockfd, char* message) {
    char buffer[MAX_BUF_SIZE] = {0};
    int status;
    status = send(sockfd, message, strlen(message), 0);
    if (status < 0) {
        printf("\n Error: Sending message failed \n");
        return -1;
    }
    bzero(buffer, MAX_BUF_SIZE);
    status = recv(sockfd, buffer, MAX_BUF_SIZE, 0);
    if (status < 0) {
        printf("\n Error: Receiving message failed \n");
        return -1;
    }
    printf("Server: %s\n", buffer);
    return 0;
}
// Function to connect to the server.
int connectToServer(char* ipAddr, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ipAddr);
    servaddr.sin_port = htons(port); 
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        printf("\n Error: Connection with the server failed \n");
        return -1;
    }
    printf("Connected to server...\n");
    return sockfd;
}
int main(int argc, char** argv) {
    if (argc != 3) {
        printf("\n Invalid input \n Usage: ./ftpclient <server ip> <port number>\n");
        return -1;
    }
    char* ipAddr = argv[1];
    int port = atoi(argv[2]);
    int sockfd = connectToServer(ipAddr, port);
    // Message loop to handle user inputs.
    while(1) {
        char message[MAX_BUF_SIZE] = {0};
        printf("> ");
        fgets(message, MAX_BUF_SIZE, stdin);
        message[strlen(message)-1] = '\0';
        if(strcmp(message, "ls")==0 || strcmp(message, "pwd")==0 || strncmp(message, "cd ", 3)==0 || strncmp(message, "get ", 4)==0) {
            sendMessage(sockfd, message);
        }
        else if(strcmp(message, "quit")==0) {
            close(sockfd);
            printf("Disconneting from server...\n");
            break;
        }
        else{
            printf("\n Invalid input \n");
        }
    }
    return 0;
}