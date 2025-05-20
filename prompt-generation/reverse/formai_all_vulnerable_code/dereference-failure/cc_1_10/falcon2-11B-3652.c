//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

#define POP3_PORT 110

int main(int argc, char **argv)
{
    int sockfd;
    int numbytes;
    struct hostent *server;
    struct sockaddr_in serv_addr;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: Unknown host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to %s on port %d\n", inet_ntoa(serv_addr.sin_addr), POP3_PORT);

    char buf[256];
    char command[256];
    int i = 0;

    while (1) {
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);
        strtok(command, "\n");

        if (strcmp(command, "quit") == 0) {
            break;
        }

        memset(buf, 0, sizeof(buf));
        numbytes = send(sockfd, command, strlen(command), 0);
        if (numbytes < 0) {
            perror("ERROR sending command");
            exit(1);
        }

        memset(buf, 0, sizeof(buf));
        numbytes = recv(sockfd, buf, sizeof(buf) - 1, 0);
        if (numbytes < 0) {
            perror("ERROR receiving response");
            exit(1);
        }

        buf[numbytes] = '\0';
        printf("Server: %s\n", buf);
    }

    close(sockfd);
    return 0;
}