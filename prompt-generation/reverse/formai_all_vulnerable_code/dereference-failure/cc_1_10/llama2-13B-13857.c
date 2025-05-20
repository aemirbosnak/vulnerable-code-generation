//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define PORT 8080

struct packet {
    char *data;
    size_t len;
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        struct packet packet;
        packet.data = malloc(1024);
        packet.len = recv(sock, packet.data, 1024, 0);
        if (packet.len < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        // Check if the packet is a SYN packet
        if (packet.data[0] == 0x12 && packet.data[1] == 0x34) {
            // If it is, send back an ACK packet
            char *ack_data = malloc(1024);
            memcpy(ack_data, "ACK!", 4);
            ack_data[4] = packet.data[2];
            ack_data[5] = packet.data[3];
            send(sock, ack_data, 4, 0);
            free(ack_data);
        } else {
            // If it's not a SYN packet, drop it
            free(packet.data);
        }

        // Sleep for a bit before checking again
        sleep(1);
    }

    return 0;
}