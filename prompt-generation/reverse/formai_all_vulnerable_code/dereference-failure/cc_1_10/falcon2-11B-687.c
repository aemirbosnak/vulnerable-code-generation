//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_EMAIL_LENGTH 512
#define MAX_EMAIL_ADDR_LENGTH 128

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <recipient> <message>\n", argv[0]);
        return 1;
    }
    
    char recipient[MAX_EMAIL_ADDR_LENGTH + 1];
    strcpy(recipient, argv[1]);
    
    char message[MAX_EMAIL_LENGTH + 1];
    strcpy(message, argv[2]);
    
    int sockfd;
    struct sockaddr_in server;
    int port = 25;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }
    
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    int bind_result = bind(sockfd, (struct sockaddr *) &server, sizeof(server));
    if (bind_result < 0) {
        perror("Error binding socket");
        return 1;
    }
    
    connect(sockfd, (struct sockaddr *) &server, sizeof(server));
    
    int n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("Error sending message");
        return 1;
    }
    
    close(sockfd);
    return 0;
}