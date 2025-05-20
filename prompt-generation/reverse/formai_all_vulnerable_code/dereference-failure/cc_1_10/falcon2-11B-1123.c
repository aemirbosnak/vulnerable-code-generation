//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <string.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 65535

void* get_packet(int sockfd, unsigned char* packet, int max_packet_size) {
    if (recv(sockfd, packet, max_packet_size, 0) < 0) {
        perror("Error receiving packet");
        exit(1);
    }
    return packet;
}

void* check_packet(void* packet, unsigned char* packet_header) {
    if (memcmp(packet, packet_header, sizeof(packet_header)) == 0) {
        return packet + sizeof(packet_header);
    }
    return NULL;
}

int main(int argc, char** argv) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    unsigned char packet_header[12] = {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05};
    unsigned char packet[MAX_PACKET_SIZE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    if (listen(sockfd, 1) < 0) {
        perror("Error listening on socket");
        exit(1);
    }

    for (;;) {
        sockfd = accept(sockfd, NULL, NULL);
        if (sockfd < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        unsigned char* packet_data = get_packet(sockfd, packet, MAX_PACKET_SIZE);
        if (packet_data == NULL) {
            continue;
        }

        unsigned char* packet_header = check_packet(packet_data, packet_header);
        if (packet_header == NULL) {
            continue;
        }

        printf("Packet received: ");
        for (int i = 0; i < 12; i++) {
            printf("%02x", packet_header[i]);
        }
        printf("\n");
    }

    return 0;
}