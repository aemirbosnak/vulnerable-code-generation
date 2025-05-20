//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, nbytes, valread;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: Unknown host: %s\n", argv[1]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    sprintf(buffer, "Ping: %s (%s) %d bytes of data.\n", argv[1], inet_ntoa(serv_addr.sin_addr), htons(2000));
    send(sockfd, buffer, strlen(buffer), 0);

    nbytes = read(sockfd, buffer, 256);
    if (nbytes < 0) {
        perror("ERROR reading data");
        exit(1);
    }
    buffer[nbytes] = '\0';
    printf("Received: %s\n", buffer);

    close(sockfd);
    return 0;
}