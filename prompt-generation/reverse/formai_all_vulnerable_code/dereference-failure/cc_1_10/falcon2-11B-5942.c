//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21

int main() {
    // Create a socket
    int sockfd;
    struct sockaddr_in serv_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set up server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send command
    char command[100];
    sprintf(command, "USER anonymous\r\n");
    write(sockfd, command, strlen(command));
    sprintf(command, "PASS anonymous\r\n");
    write(sockfd, command, strlen(command));
    sprintf(command, "MKD new_directory\r\n");
    write(sockfd, command, strlen(command));
    sprintf(command, "CWD new_directory\r\n");
    write(sockfd, command, strlen(command));

    // Receive and print response
    char response[100];
    read(sockfd, response, 100);
    printf("%s\n", response);

    // Close socket
    close(sockfd);

    return 0;
}