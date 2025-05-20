//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    int portno;
    char buffer[256];
    int n;

    if (argc < 3) {
        printf("Usage: ping -n <count> <host>\n");
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    if (inet_pton(AF_INET, argv[2], &serv_addr.sin_addr) <= 0) {
        perror("ERROR, cannot resolve host");
        exit(0);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(0);
    }

    printf("Pinging %s with %d bytes of data: \n", argv[2], (int) sizeof(buffer));

    for (int i = 0; i < atoi(argv[1]); i++) {
        send(sockfd, buffer, sizeof(buffer), 0);
        bzero(buffer, sizeof(buffer));

        n = recv(sockfd, buffer, sizeof(buffer), 0);

        if (n < 0) {
            perror("ERROR receiving");
            exit(0);
        }

        printf("Received %d bytes from %s: ", n, argv[2]);
        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}