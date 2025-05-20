//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LEN 1024
#define MAX_PACKET_LEN 512

struct pack {
    char command[MAX_CLIENT_LEN];
    char data[MAX_PACKET_LEN];
};

int main(void) {
    int sock;
    struct sockaddr_in server, client;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(1234);

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind() failed");
        exit(1);
    }

    if (listen(sock, 5) < 0) {
        perror("listen() failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", server.sin_port);

    while (1) {
        struct pack *pack;
        int client_sock;

        pack = malloc(sizeof(*pack));
        if (pack == NULL) {
            perror("malloc() failed");
            exit(1);
        }

        client_sock = accept(sock, (struct sockaddr *)&client, NULL);
        if (client_sock < 0) {
            perror("accept() failed");
            exit(1);
        }

        printf("Client connected from IP %s, port %d...\n",
               inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Process client packet
        read(client_sock, pack->data, MAX_PACKET_LEN);
        pack->command[0] = '\0';
        if (strncmp(pack->data, "HELLO", 5) == 0) {
            printf("Client says: Hello, brave knight! What is thy bidding?\n");
            pack->command[0] = 'A';
            pack->command[1] = 'C';
            pack->command[2] = 'K';
            pack->command[3] = 'E';
            pack->command[4] = 'L';
            pack->command[5] = 'L';
            pack->command[6] = 'O';
            pack->command[7] = '\0';
        } else if (strncmp(pack->data, "ATTACK", 6) == 0) {
            printf("Client says: Prepare to defend thyself, varlet! I shall attack thee with my sword of might!\n");
            pack->command[0] = 'A';
            pack->command[1] = 'T';
            pack->command[2] = 'T';
            pack->command[3] = 'A';
            pack->command[4] = 'C';
            pack->command[5] = 'K';
            pack->command[6] = '\0';
        } else {
            printf("Client says: ??? (Unrecognized command)\n");
        }

        write(client_sock, pack->command, strlen(pack->command));
        free(pack);
    }

    close(sock);
    return 0;
}