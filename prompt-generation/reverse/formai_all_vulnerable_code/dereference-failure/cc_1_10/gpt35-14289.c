//FormAI DATASET v1.0 Category: Networking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main() {
    int sock_fd, conn_fd, n;
    struct sockaddr_in server_address;
    struct hostent *server;

    char buffer[256];

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr,"Error, no such host\n");
        exit(0);
    }

    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(PORT);

    if (connect(sock_fd,(struct sockaddr *) &server_address,sizeof(server_address)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    printf("Type a message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);

    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer,256);
    n = read(sock_fd, buffer, 255);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("%s\n",buffer);
    close(sock_fd);
    return 0;
}