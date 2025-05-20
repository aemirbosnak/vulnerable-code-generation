//MISTRAL-7B DATASET v1.0 Category: Networking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// A dance of bits and bytes, where love is sent and received
// Over the ethereal plane of the internet, through the wires and beams

typedef struct {
    int socket;
    struct sockaddr_in server_addr;
} network_ballerina;

void dance_of_love(network_ballerina *ballerina, char *message) {
    int send_len = strlen(message);

    if (send(ballerina->socket, message, send_len, 0) <= 0) {
        perror("Failed to send love message");
        exit(EXIT_FAILURE);
    }

    char receive_buffer[256];
    int receive_len = recv(ballerina->socket, receive_buffer, sizeof(receive_buffer), 0);

    if (receive_len <= 0) {
        perror("Failed to receive love message");
        exit(EXIT_FAILURE);
    }

    printf("Received love message: %s\n", receive_buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct in_addr ipv4_addr;
    inet_aton(argv[1], &ipv4_addr);

    network_ballerina ballerina = {
        .socket = socket(AF_INET, SOCK_STREAM, 0),
        .server_addr = {
            .sin_family = AF_INET,
            .sin_port = htons(atoi(argv[2])),
            .sin_addr = ipv4_addr
        }
    };

    if (connect(ballerina.socket, (struct sockaddr *)&ballerina.server_addr, sizeof(ballerina.server_addr)) <= 0) {
        perror("Failed to connect to server");
        close(ballerina.socket);
        return EXIT_FAILURE;
    }

    char message[256] = "I love you, my dear server.";
    dance_of_love(&ballerina, message);

    close(ballerina.socket);
    return EXIT_SUCCESS;
}