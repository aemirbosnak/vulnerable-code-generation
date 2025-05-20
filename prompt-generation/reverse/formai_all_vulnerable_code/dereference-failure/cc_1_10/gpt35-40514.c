//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define USERNAME "username"
#define PASSWORD "password"

int main(int argc, char *argv[]) {
    int sockfd, port;
    struct sockaddr_in servaddr;
    char buffer[1024];

    if(argc < 3) {
        printf("Usage: %s <ip_address> <port>\n", argv[0]);
        exit(0);
    }

    port = atoi(argv[2]);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error creating socket!\n");
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(port);

    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error connecting to server!\n");
        exit(0);
    }

    printf("Connected to server! Sending username and password...\n");
    sprintf(buffer, "%s", USERNAME);
    write(sockfd, buffer, strlen(buffer));
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "%s", PASSWORD);
    write(sockfd, buffer, strlen(buffer));
    printf("Username and Password sent successfully!\n");

    while(1) {
        printf("Enter command: ");
        fgets(buffer, 1024, stdin);
        write(sockfd, buffer, strlen(buffer));
        memset(buffer, 0, sizeof(buffer));
        read(sockfd, buffer, sizeof(buffer));
        printf("%s", buffer);
    }

    return 0;
}