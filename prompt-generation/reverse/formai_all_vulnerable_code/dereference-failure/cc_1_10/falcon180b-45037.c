//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define MAX_HOST_NAME 256
#define MAX_PORT_NUMBER 6
#define MAX_PAYLOAD 1024

int main(int argc, char *argv[]) {
    int sockfd, opt = 1;
    struct sockaddr_in servaddr;
    char hostname[MAX_HOST_NAME];
    char port[MAX_PORT_NUMBER];
    char payload[MAX_PAYLOAD];
    int retval = 0;

    if (argc!= 4) {
        printf("Usage:./qos_monitor <hostname> <port> <payload>\n");
        return -1;
    }

    strcpy(hostname, argv[1]);
    strcpy(port, argv[2]);
    strcpy(payload, argv[3]);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(hostname);
    servaddr.sin_port = htons(atoi(port));

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    while (1) {
        retval = sendto(sockfd, payload, strlen(payload), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
        if (retval == -1) {
            printf("Error sending payload\n");
            break;
        }
        usleep(500000); // Sleep for 500ms
    }

    close(sockfd);
    return 0;
}