//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int n;
    struct hostent *server;
    socklen_t addr_size;
    char *ip_address = "127.0.0.1";
    char *port_num = "8080";

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error in socket creation\n");
        exit(1);
    }

    // Set the server address
    server = gethostbyname(ip_address);
    if (server == NULL) {
        printf("Error in gethostbyname\n");
        exit(1);
    }
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port_num));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error in connecting to the server\n");
        exit(1);
    }

    // Receive data from the server
    while (1) {
        bzero(buffer, 1024);
        n = read(sockfd, buffer, 1024);
        if (n < 0) {
            printf("Error in reading from the server\n");
            exit(1);
        }
        printf("Received data from the server: %s\n", buffer);
    }

    // Close socket
    close(sockfd);
    return 0;
}