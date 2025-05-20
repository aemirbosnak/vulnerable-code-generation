//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: secure
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PACKET_SIZE 512

int main(int argc, char* argv[]) {
    struct sockaddr_in dest_addr;
    struct hostent *server;
    char buffer[MAX_PACKET_SIZE];
    char *s;
    int sockfd, n, portno;
    struct sockaddr_in source_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("255.255.255.255");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    portno = htons(10000);
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(portno);
    bcopy((char*)server->h_addr, (char*)&dest_addr.sin_addr.s_addr, server->h_length);

    while (1) {
        s = inet_ntoa(dest_addr.sin_addr);
        printf("Broadcast to %s\n", s);
        n = sendto(sockfd, "Hello, world!", sizeof("Hello, world!"), 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr));
        if (n < 0) {
            perror("ERROR sending data");
            exit(1);
        }

        char response[MAX_PACKET_SIZE];
        n = recvfrom(sockfd, response, MAX_PACKET_SIZE, 0, NULL, NULL);
        if (n < 0) {
            perror("ERROR receiving data");
            exit(1);
        }

        printf("Received: %s\n", response);
    }

    close(sockfd);
    return 0;
}