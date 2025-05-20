//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUFFER_SIZE 1024

int SocketRead(int socketfd, char* buffer, int bufsize) {
    int totalBytesRead = 0;
    int bytesReceived;
    while(totalBytesRead < bufsize) {
        bytesReceived = recv(socketfd, buffer+totalBytesRead, bufsize-totalBytesRead, 0);
        if(bytesReceived < 1) {
            return bytesReceived;
        }
        totalBytesRead += bytesReceived;
    }
    return totalBytesRead;
}

int main(int argc, char** argv) {
    char* serverAddress = "pop.gmail.com";
    int serverPort = 995;

    printf("POP3 Client\n");

    // Resolve server hostname to IP address
    struct hostent* he = gethostbyname(serverAddress);
    if(!he) {
        printf("ERROR: Cannot resolve server address '%s'\n", serverAddress);
        return -1;
    }
    printf("Resolved server '%s' to IP address %s\n", serverAddress, inet_ntoa(*((struct in_addr*)he->h_addr_list[0])));
    
    // Connect to server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("ERROR: Cannot create socket\n");
        return -1;
    }
    printf("Created socket\n");
    
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(inet_ntoa(*((struct in_addr*)he->h_addr_list[0])));
    serverAddr.sin_port = htons(serverPort);

    if(connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr_in)) < 0) {
        printf("ERROR: Cannot connect to server %s:%d\n", serverAddress, serverPort);
        return -1;
    }
    printf("Connected to server %s:%d\n", serverAddress, serverPort);

    // Receive server greeting
    char buffer[MAX_BUFFER_SIZE];
    if(SocketRead(sockfd, buffer, MAX_BUFFER_SIZE) < 1) {
        printf("ERROR: Did not receive server greeting\n");
        return -1;
    }
    printf("Server greeting: %s\n", buffer);

    // Send user login
    char user[MAX_BUFFER_SIZE];
    printf("Username: ");
    scanf("%s", user);
    sprintf(buffer, "USER %s\r\n", user);
    if(send(sockfd, buffer, strlen(buffer), 0) < strlen(buffer)) {
        printf("ERROR: Cannot send user login\n");
        return -1;
    }

    // Receive server response to user login
    if(SocketRead(sockfd, buffer, MAX_BUFFER_SIZE) < 1) {
        printf("ERROR: Did not receive response to user login\n");
        return -1;
    }
    printf("%s", buffer);

    // Send password
    char pass[MAX_BUFFER_SIZE];
    printf("Password: ");
    scanf("%s", pass);
    sprintf(buffer, "PASS %s\r\n", pass);
    if(send(sockfd, buffer, strlen(buffer), 0) < strlen(buffer)) {
        printf("ERROR: Cannot send password\n");
        return -1;
    }

    // Receive server response to password
    if(SocketRead(sockfd, buffer, MAX_BUFFER_SIZE) < 1) {
        printf("ERROR: Did not receive response to password\n");
        return -1;
    }
    printf("%s", buffer);

    // List messages
    sprintf(buffer, "LIST\r\n");
    if(send(sockfd, buffer, strlen(buffer), 0) < strlen(buffer)) {
        printf("ERROR: Cannot send list command\n");
        return -1;
    }
    
    // Receive server response
    if(SocketRead(sockfd, buffer, MAX_BUFFER_SIZE) < 1) {
        printf("ERROR: Did not receive response to list command\n");
        return -1;
    }
    printf("%s", buffer);

    // Quit
    sprintf(buffer, "QUIT\r\n");
    if(send(sockfd, buffer, strlen(buffer), 0) < strlen(buffer)) {
        printf("ERROR: Cannot send quit command\n");
        return -1;
    }
    close(sockfd);
    return 0;
}