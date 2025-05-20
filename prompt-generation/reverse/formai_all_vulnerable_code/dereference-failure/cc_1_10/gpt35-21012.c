//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXBUFFER 1024

int main(int argc, char *argv[]) {
    int sockfd, connect_result;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char address[MAXBUFFER], message[MAXBUFFER];
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    host = gethostbyname(argv[1]);
    
    if (host == NULL) {
        fprintf(stderr, "Error: Could not find server address %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if (sockfd < 0) {
        perror("Error: Could not create socket");
        exit(EXIT_FAILURE);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *) (host->h_addr_list[0])));
    server_addr.sin_port = htons(25);
    
    connect_result = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    
    if (connect_result < 0) {
        perror("Error: Could not connect to server");
        exit(EXIT_FAILURE);
    }
    
    printf("Enter message: ");
    fgets(message, MAXBUFFER, stdin);
    
    strcat(message, "\r\n");
    
    send(sockfd, message, strlen(message), 0);
    
    close(sockfd);
    
    return 0;
}