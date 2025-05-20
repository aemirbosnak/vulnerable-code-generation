//Falcon-180B DATASET v1.0 Category: Networking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in servername;
    struct sockaddr_in clientname;
    socklen_t clientlen;
    char buffer[1024];
    int n;
    int maxi;

    if(argc < 3) {
        fprintf(stderr, "Usage: %s <port> <message>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        error("socket failed");
    }

    servername.sin_family = AF_INET;
    servername.sin_addr.s_addr = htonl(INADDR_ANY);
    servername.sin_port = htons(portno);

    if(bind(sockfd, (struct sockaddr *)&servername, sizeof(servername)) < 0) {
        error("bind failed");
    }

    if(listen(sockfd, 1) < 0) {
        error("listen");
    }

    while(1) {
        clientlen = sizeof(clientname);
        newsockfd = accept(sockfd, (struct sockaddr *)&clientname, &clientlen);

        if(newsockfd < 0) {
            error("accept");
        }

        printf("Connection with client established.\n");

        send(newsockfd, argv[2], strlen(argv[2]), 0);

        while((n = recv(newsockfd, buffer, 1024, 0)) > 0) {
            buffer[n] = '\0';
            printf("Client message: %s\n", buffer);
        }

        close(newsockfd);
    }

    return 0;
}