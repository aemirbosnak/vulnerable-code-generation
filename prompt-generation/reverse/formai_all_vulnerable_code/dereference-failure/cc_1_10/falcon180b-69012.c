//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_LEN 1024
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo hints, *ai;
    char host[MAX_HOST_LEN];
    char data[MAX_DATA_LEN];
    int rv, opt;
    socklen_t optlen;
    int qos;

    /* Set up socket */
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;

    if ((rv = getaddrinfo(argv[1], NULL, &hints, &ai))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    sock = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    /* Set QoS */
    opt = IP_TOS;
    optlen = sizeof(qos);
    qos = 0xB8; /* high priority */
    if (setsockopt(sock, IPPROTO_IP, opt, &qos, optlen) == -1) {
        perror("setsockopt");
        exit(1);
    }

    /* Send data */
    strcpy(data, "Hello, world!");
    if (sendto(sock, data, strlen(data), 0, ai->ai_addr, ai->ai_addrlen) == -1) {
        perror("sendto");
        exit(1);
    }

    /* Receive data */
    memset(data, 0, MAX_DATA_LEN);
    optlen = sizeof(qos);
    if (getsockopt(sock, IPPROTO_IP, opt, &qos, &optlen) == -1) {
        perror("getsockopt");
        exit(1);
    }
    printf("Received QoS: %d\n", qos);

    close(sock);
    freeaddrinfo(ai);

    return 0;
}