//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>

#define PORT 8080
#define MAXLINE 1024

int main(int argc, char const *argv[]) {

    int sockfd;
    char message[MAXLINE], buffer[MAXLINE];
    struct sockaddr_in servaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation failed: %s\n", strerror(errno));
        return -1;
    }

    // Filling server information
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        printf("Invalid address / Address not supported: %s\n", strerror(errno));
        return -1;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Connection Failed: %s\n", strerror(errno));
        return -1;
    }

    // Sending message to server
    printf("Enter a number: ");
    fgets(message, MAXLINE, stdin);
    write(sockfd, message, strlen(message));

    // Receiving result from server
    read(sockfd, buffer, MAXLINE);
    printf("Result: %s", buffer);

    // Closing the socket
    close(sockfd);

    return 0;
}

/*
Example usage:
Enter a number: 34
Result: The square of 34 is 1156
*/