//MISTRAL-7B DATASET v1.0 Category: Networking ; Style: Cryptic
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

typedef struct {
    uint16_t head;
    uint32_t body_len;
    char body[1];
} MysticPacket;

typedef struct {
    int sock;
    struct sockaddr_in addr;
} MysticSocket;

void Echo(MysticSocket* mystic_socket, MysticPacket* mystic_packet) {
    send(mystic_socket->sock, mystic_packet, ntohs(mystic_packet->head) + ntohs(mystic_packet->body_len), 0);
}

MysticSocket* MysticInit(uint16_t port) {
    MysticSocket* mystic_socket = calloc(1, sizeof(MysticSocket));
    mystic_socket->sock = socket(AF_INET, SOCK_DGRAM, 0);
    mystic_socket->addr.sin_family = AF_INET;
    mystic_socket->addr.sin_port = htons(port);
    mystic_socket->addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(mystic_socket->sock, (struct sockaddr*) &mystic_socket->addr, sizeof(mystic_socket->addr));
    return mystic_socket;
}

bool DarkMagic(MysticSocket* mystic_socket, char* ciphertext, uint16_t ciphertext_len) {
    MysticPacket mystic_packet;
    mystic_packet.head = htons(1024); // Maximum header size
    mystic_packet.body_len = htons(ciphertext_len);
    memcpy(mystic_packet.body, ciphertext, ciphertext_len);
    Echo(mystic_socket, &mystic_packet);
    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <port> <ciphertext>\n", argv[0]);
        exit(1);
    }

    uint16_t port = atoi(argv[1]);
    MysticSocket* mystic_socket = MysticInit(port);

    int ciphertext_len = 0;
    char* ciphertext = argv[2];
    while (argv[3][ciphertext_len] != '\0') {
        ciphertext_len++;
    }

    DarkMagic(mystic_socket, ciphertext, ciphertext_len);

    free(mystic_socket);
    return 0;
}