//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: Dennis Ritchie
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int n;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        return 1;
    }

    // Resolve server address
    if ((server = gethostbyname("127.0.0.1")) == NULL) {
        fprintf(stderr, "gethostbyname: Unknown host\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(8888);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        return 1;
    }

    char buffer[1024];
    char message[] = "Hello, World!";

    while (1) {
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("read");
            return 1;
        }
        buffer[n] = '\0';

        printf("%s\n", buffer);

        n = write(sockfd, message, strlen(message));
        if (n < 0) {
            perror("write");
            return 1;
        }
    }

    return 0;
}