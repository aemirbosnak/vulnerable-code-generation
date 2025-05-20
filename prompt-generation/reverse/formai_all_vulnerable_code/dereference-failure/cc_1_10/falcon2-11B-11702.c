//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

struct _packet {
    char* data;
    int length;
    int timestamp;
};

int create_socket(char* hostname, int port) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, port, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return -1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }

        break;
    }

    freeaddrinfo(servinfo);
    return sockfd;
}

void* packet_monitor(void* arg) {
    struct _packet packet;
    char buffer[1024];
    int sockfd;
    int n;
    int i;

    sockfd = (int) arg;

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            printf("Error receiving packet\n");
            break;
        }

        packet.data = buffer;
        packet.length = n;
        packet.timestamp = time(NULL);

        for (i = 0; i < n; i++) {
            if (buffer[i] == '\n') {
                break;
            }
        }

        printf("Received packet: %s\n", buffer);
        printf("Timestamp: %d\n", packet.timestamp);
        printf("Length: %d\n", packet.length);
    }

    return NULL;
}

int main() {
    char hostname[] = "localhost";
    int port = 1234;
    int sockfd;
    pthread_t thread;

    sockfd = create_socket(hostname, port);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return -1;
    }

    packet_monitor(sockfd);

    return 0;
}