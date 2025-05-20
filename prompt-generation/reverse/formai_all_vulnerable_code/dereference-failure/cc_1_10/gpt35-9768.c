//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

void *measure_qos(void *host_name);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host_name = argv[1];

    pthread_t qos_thread;
    if (pthread_create(&qos_thread, NULL, &measure_qos, (void *) host_name) != 0) {
        fprintf(stderr, "Error creating QoS monitoring thread.\n");
        exit(EXIT_FAILURE);
    }

    pthread_join(qos_thread, NULL);
    exit(EXIT_SUCCESS);
}

void *measure_qos(void *host_name) {
    char *host = (char *) host_name;
    struct hostent *host_info = gethostbyname(host);
    if (host_info == NULL) {
        fprintf(stderr, "Error: Could not find host %s.", host);
        exit(EXIT_FAILURE);
    }

    int sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_fd < 0) {
        fprintf(stderr, "Error: Could not create socket.\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(80);
    sin.sin_addr = *(struct in_addr *) host_info->h_addr_list[0];

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int sent_bytes = sendto(sock_fd, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &sin, sizeof(struct sockaddr));
    if (sent_bytes < 0) {
        fprintf(stderr, "Error: Could not send test packet.\n");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    struct timeval tv;
    tv.tv_sec = 2;
    tv.tv_usec = 0;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        fprintf(stderr, "Error: Could not set socket timeout.\n");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);
    int received_bytes = recv(sock_fd, response, BUFFER_SIZE, 0);
    if (received_bytes < 0) {
        fprintf(stderr, "Error: Could not receive test packet.\n");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    struct iphdr *ip = (struct iphdr *) response;
    struct tcphdr *tcp = (struct tcphdr *) (response + sizeof(struct iphdr));
    printf("Response from %s: IP TTL=%d, TCP MSS=%d.\n", host, ip->ttl, ntohs(tcp->window));

    close(sock_fd);
    pthread_exit(NULL);
}