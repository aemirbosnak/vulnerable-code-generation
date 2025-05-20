//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char hostname[256];
    gethostname(hostname, sizeof(hostname));

    printf("Hostname: %s\n", hostname);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    portno = htons(5000);

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    server = gethostbyname(hostname);

    if (server == NULL) {
        fprintf(stderr, "Hostname not found\n");
        exit(EXIT_FAILURE);
    }

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    printf("Socket created\n");
    printf("Port number: %d\n", portno);

    while (1) {
        n = sendto(sockfd, "Hello from host %s", sizeof("Hello from host %s"), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

        if (n < 0) {
            perror("sendto");
        } else {
            printf("Message sent successfully\n");
        }

        printf("Enter hostname to check: ");
        fgets(hostname, sizeof(hostname), stdin);

        server = gethostbyname(hostname);

        if (server == NULL) {
            printf("Hostname not found\n");
        } else {
            bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

            printf("Socket created\n");
            printf("Port number: %d\n", portno);

            n = sendto(sockfd, "Hello from host %s", sizeof("Hello from host %s"), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

            if (n < 0) {
                perror("sendto");
            } else {
                printf("Message sent successfully\n");
            }
        }
    }

    close(sockfd);
    return 0;
}