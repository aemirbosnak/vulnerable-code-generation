//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_SIZE 1024

struct sockaddr_in server_addr;
struct hostent *host;
int sockfd;

void init_socket() {
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    host = gethostbyname("google.com");
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    server_addr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *)host->h_addr_list[0]));
}

void send_packet() {
    char packet[MAX_SIZE] = "GET / HTTP/1.1\r\nHost: google.com\r\n\r\n";

    if (sendto(sockfd, packet, strlen(packet), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("sendto");
        exit(1);
    }
}

void receive_packet() {
    char buffer[MAX_SIZE];
    int len;

    len = recvfrom(sockfd, buffer, MAX_SIZE, 0, NULL, NULL);
    if (len == -1) {
        perror("recvfrom");
        exit(1);
    }

    printf("%s\n", buffer);
}

void close_socket() {
    close(sockfd);
}

int main() {
    init_socket();
    send_packet();
    receive_packet();
    close_socket();

    return 0;
}