//MISTRAL-7B DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT_START 1
#define PORT_END 65535
#define BUFFER_SIZE 1024
#define BANNER " scanbot v3.001 - The Galactic Port Scanner \n"

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd, port, i;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char ipstr[INET_ADDRSTRLEN];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP-ADDRESS>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("ERROR opening socket");
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT_START);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *) server->h_addr),
             &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        die("Connection failed");
    }

    printf(BANNER);
    printf("Scanning ports on %s:\n", inet_ntoa(*(struct in_addr *) server->h_addr));

    for (port = PORT_START; port <= PORT_END; port++) {
        serv_addr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            continue;
        }

        getnameinfo((struct sockaddr *) &serv_addr, sizeof(serv_addr), ipstr, sizeof(ipstr), NULL, 0, NI_NUMERICHOST);
        printf("Port %d: OPEN - %s\n", port, ipstr);

        memset(buffer, 0, BUFFER_SIZE);
        send(sockfd, "SYN\r\n", strlen("SYN\r\n"), 0);
        recv(sockfd, buffer, BUFFER_SIZE, 0);

        close(sockfd);
        if (strstr(buffer, "HTTP") != NULL) {
            printf("Possible web server on port %d\n", port);
        }
    }

    close(sockfd);
    return 0;
}