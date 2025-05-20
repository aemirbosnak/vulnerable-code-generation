//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define MAX_SIZE 1024
#define MAX_PACKET_SIZE 64

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <target_ip>\n", argv[0]);
        return 1;
    }

    char target_ip[MAX_SIZE] = "";
    strcpy(target_ip, argv[1]);

    int sockfd, send_fd, recv_fd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    struct sockaddr_in sin;

    host = gethostbyname(target_ip);
    if (host == NULL) {
        fprintf(stderr, "Error: host not found\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: failed to create socket\n");
        exit(1);
    }

    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    bcopy((char *) host->h_addr, (char *) &server_addr.sin_addr.s_addr, host->h_length);

    connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));

    send_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (send_fd < 0) {
        fprintf(stderr, "Error: failed to create send socket\n");
        exit(1);
    }

    char packet[MAX_PACKET_SIZE] = "";
    memset(packet, 0, sizeof(packet));

    for (int i = 0; i < 1000; i++) {
        sprintf(packet, "Ping %d", i);
        sendto(send_fd, packet, strlen(packet), 0, (struct sockaddr *) &sin, sizeof(sin));

        recv_fd = accept(sockfd, NULL, NULL);
        if (recv_fd < 0) {
            fprintf(stderr, "Error: failed to accept connection\n");
            exit(1);
        }

        char response[MAX_SIZE] = "";
        memset(response, 0, sizeof(response));
        recv(recv_fd, response, MAX_SIZE, 0);
        printf("%s\n", response);

        close(recv_fd);
    }

    close(send_fd);
    close(sockfd);

    return 0;
}