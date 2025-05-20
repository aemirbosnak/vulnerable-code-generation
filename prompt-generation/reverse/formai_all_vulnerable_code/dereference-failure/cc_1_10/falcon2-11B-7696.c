//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: automated
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>

#define MAX_CONN 100

int main() {
    int socket_fd, port_num;
    struct sockaddr_in server_address;
    struct hostent *server;
    char buffer[1024];

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Error opening socket\n");
        return 1;
    }

    server = gethostbyname("www.google.com");
    if (server == NULL) {
        printf("Error, no such host\n");
        return 1;
    }

    port_num = htons(80);
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = port_num;

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error connecting\n");
        return 1;
    }

    while (1) {
        printf("Enter a URL to be sent (e.g., www.google.com): ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }

        if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
            printf("Error sending data\n");
            return 1;
        }

        if (recv(socket_fd, buffer, sizeof(buffer), 0) < 0) {
            printf("Error receiving data\n");
            return 1;
        }

        printf("%s\n", buffer);
    }

    close(socket_fd);
    return 0;
}