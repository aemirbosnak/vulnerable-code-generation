//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOSTNAME_SIZE 256
#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, retval;
    struct sockaddr_in target_addr;
    char hostname[MAX_HOSTNAME_SIZE];
    char data[MAX_DATA_SIZE];
    int datalen, sent_bytes;
    struct timeval timeout;

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    strncpy(hostname, argv[1], MAX_HOSTNAME_SIZE);

    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(7);
    inet_pton(AF_INET, hostname, &target_addr.sin_addr);

    retval = connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));
    if (retval!= 0) {
        printf("Error connecting to %s\n", hostname);
        exit(1);
    }

    memset(data, 'A', MAX_DATA_SIZE);
    datalen = strlen(data);

    retval = setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    if (retval!= 0) {
        printf("Error setting timeout\n");
        exit(1);
    }

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    retval = setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
    if (retval!= 0) {
        printf("Error setting timeout\n");
        exit(1);
    }

    sent_bytes = send(sockfd, data, datalen, 0);
    if (sent_bytes!= datalen) {
        printf("Error sending data\n");
        exit(1);
    }

    retval = recv(sockfd, data, MAX_DATA_SIZE, 0);
    if (retval <= 0) {
        printf("Error receiving data\n");
        exit(1);
    }

    printf("Received %d bytes of data:\n", retval);
    printf("%s\n", data);

    close(sockfd);
    return 0;
}