//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int opt = 1;
    char buffer[MAX_DATA_SIZE];
    int len = MAX_DATA_SIZE;

    if (argc < 2) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    if ((server = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "ERROR: no such host\n");
        return 1;
    }

    portno = atoi(argv[2]);
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(int)) < 0) {
        perror("ERROR setting socket options");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    while (1) {
        if (read(sockfd, buffer, len) < 0) {
            perror("ERROR reading from socket");
            return 1;
        }

        printf("Received data: %s\n", buffer);

        if (write(sockfd, "Hello, world!", 13) < 0) {
            perror("ERROR writing to socket");
            return 1;
        }
    }

    return 0;
}