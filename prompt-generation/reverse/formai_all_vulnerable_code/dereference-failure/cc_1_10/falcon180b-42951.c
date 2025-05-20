//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: unmistakable
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

int main(int argc, char *argv[]) {

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    // Set up server address
    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    if ((getaddrinfo("localhost", "8080", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        exit(1);
    }

    // Connect to server
    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((connect(sock, p->ai_addr, p->ai_addrlen))!= -1) {
            break;
        }
    }
    if (p == NULL) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    // Send data to server
    char message[1000];
    sprintf(message, "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n");
    send(sock, message, strlen(message), 0);

    // Receive response from server
    char buffer[1000];
    memset(buffer, 0, sizeof(buffer));
    if ((recv(sock, buffer, sizeof(buffer), 0)) == -1) {
        perror("recv");
        exit(1);
    }

    // Print response
    printf("Response: %s\n", buffer);

    // Close socket
    close(sock);
    return 0;
}