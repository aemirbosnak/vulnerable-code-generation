//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 110

int main(int argc, char *argv[]) {
    int server_fd, conn_fd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    if (argc!= 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Unknown host: %s\n", argv[1]);
        exit(1);
    }

    portno = htons(PORT);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        if (read(server_fd, buffer, 1024) == 0) {
            break;
        }

        if (buffer[0] == '+') {
            printf("OK\n");
        } else if (buffer[0] == '-') {
            printf("ERR %s\n", buffer);
        } else if (buffer[0] == 'N') {
            printf("CAPA OK\n");
        } else if (buffer[0] == 'L') {
            printf("L NAMES\n");
        } else if (buffer[0] == 'R') {
            printf("R NAMES\n");
        } else if (buffer[0] == 'S') {
            printf("S NAMES\n");
        } else if (buffer[0] == 'C') {
            printf("C NAMES\n");
        } else if (buffer[0] == 'U') {
            printf("U NAMES\n");
        } else if (buffer[0] == 'D') {
            printf("D NAMES\n");
        } else if (buffer[0] == 'A') {
            printf("A NAMES\n");
        } else if (buffer[0] == 'F') {
            printf("F NAMES\n");
        } else if (buffer[0] == 'Q') {
            printf("Q NAMES\n");
        } else if (buffer[0] == 'P') {
            printf("P NAMES\n");
        } else if (buffer[0] == 'R') {
            printf("R NAMES\n");
        } else if (buffer[0] == 'S') {
            printf("S NAMES\n");
        } else if (buffer[0] == 'C') {
            printf("C NAMES\n");
        } else if (buffer[0] == 'U') {
            printf("U NAMES\n");
        } else if (buffer[0] == 'D') {
            printf("D NAMES\n");
        } else if (buffer[0] == 'A') {
            printf("A NAMES\n");
        } else if (buffer[0] == 'F') {
            printf("F NAMES\n");
        } else if (buffer[0] == 'Q') {
            printf("Q NAMES\n");
        } else if (buffer[0] == 'P') {
            printf("P NAMES\n");
        } else {
            printf("Unknown command: %s\n", buffer);
        }
    }

    return 0;
}