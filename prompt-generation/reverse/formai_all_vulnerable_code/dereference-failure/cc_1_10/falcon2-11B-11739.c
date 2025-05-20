//Falcon2-11B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>

int main() {
    int sockfd, n, len, i, j;
    struct ifreq ifr;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    printf("Enter the MAC Address of the Wi-Fi Access Point: ");
    scanf("%s", &ifr.ifr_name);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("192.168.0.1");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(0);

    for (i = 0; i < 10; i++) {
        memset(buffer, 0, sizeof(buffer));
        strcpy(buffer, "GET / HTTP/1.1\r\nHost: 192.168.0.1\r\n\r\n");

        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        memset(buffer, 0, sizeof(buffer));
        memset(buffer, 0, sizeof(buffer));
        for (j = 0; j < 100; j++) {
            if (read(sockfd, &buffer, 1) < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
        }

        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}