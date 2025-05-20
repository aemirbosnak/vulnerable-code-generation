//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

void send_packet(int sockfd, char *msg, int packet_size);
void receive_packet(int sockfd, char *buf, int packet_size);
int get_packet_size();

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    int packet_size;
    char buf[1024];

    if (argc!= 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connecting to %s...\n", argv[1]);
    printf("Enter 'quit' to exit.\n");

    while (1) {
        printf("Enter message: ");
        fgets(buf, sizeof(buf), stdin);

        if (strcmp(buf, "quit") == 0) {
            break;
        }

        packet_size = get_packet_size();
        send_packet(sockfd, buf, packet_size);

        receive_packet(sockfd, buf, packet_size);
        printf("Received: %s\n", buf);
    }

    close(sockfd);
    return 0;
}

void send_packet(int sockfd, char *msg, int packet_size) {
    ssize_t sent = send(sockfd, msg, packet_size, 0);
    if (sent < 0) {
        perror("send");
    }
}

void receive_packet(int sockfd, char *buf, int packet_size) {
    ssize_t recv_size = recv(sockfd, buf, packet_size, 0);
    if (recv_size < 0) {
        perror("recv");
    }
    else {
        buf[recv_size] = '\0';
        printf("Received: %s\n", buf);
    }
}

int get_packet_size() {
    int packet_size;
    printf("Enter packet size (in bytes): ");
    scanf("%d", &packet_size);
    return packet_size;
}