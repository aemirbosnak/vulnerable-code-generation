//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <sys/time.h>

// Global variables
int sockfd, portno, msg_sent;
struct sockaddr_in server;
char buffer[1024], msg[1024], *msg_ptr;

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[2]);
    if (portno <= 0 || portno > 65535) {
        printf("Invalid port number: %s\n", argv[2]);
        return 1;
    }

    strncpy(server.sin_addr.s_addr, argv[1], sizeof(server.sin_addr.s_addr));
    server.sin_family = AF_INET;
    server.sin_port = htons(portno);

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the message
    msg_ptr = msg;
    msg_sent = 0;
    while (*msg_ptr!= '\0') {
        if (send(sockfd, msg_ptr, strlen(msg_ptr), 0) < 0) {
            perror("send");
            return 1;
        }
        msg_ptr += strlen(msg_ptr);
        msg_sent++;
    }

    if (msg_sent == 0) {
        printf("No message to send.\n");
        return 1;
    }

    // Receive the response
    bzero(buffer, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return 1;
    }
    printf("Response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}