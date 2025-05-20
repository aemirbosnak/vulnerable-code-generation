//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void send_data(int sockfd, char *message) {
    int sent = send(sockfd, message, strlen(message), 0);
    if (sent < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *message = "Intrusion detected! ";

    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    portno = htons(80);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    send_data(sockfd, message);

    close(sockfd);

    return 0;
}