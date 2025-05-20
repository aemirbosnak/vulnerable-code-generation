//MISTRAL-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#define _CRYPTIC_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>

#define IP "192.168.1.1"
#define PORT 80
#define USLEEP 1000000

typedef unsigned char byte;
byte secret[16] = {0x67, 0x2B, 0x2F, 0x34, 0x55, 0x32, 0x53, 0x53, 0x62, 0x69, 0x61, 0x72, 0x79, 0x70, 0x74, 0x6F};

int main(void) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    byte response[1024];
    int bytes_received;
    int i, status;
    int *status_ptr;

    signal(SIGPIPE, SIG_IGN);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(IP);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr,
         (char *) &serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    send(sockfd, secret, sizeof(secret), 0);

    bytes_received = recv(sockfd, response, sizeof(response), 0);
    if (bytes_received < 0) {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }

    status_ptr = (int *) response;
    status = *status_ptr;

    if (status != 200) {
        printf("Error: HTTP status code %d\n", status);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < sizeof(secret); i++) {
        if (response[i] != secret[i]) {
            printf("Error: Response data does not match secret\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("Website is up\n");

    close(sockfd);
    usleep(USLEEP);
    main();
    return EXIT_SUCCESS;
}