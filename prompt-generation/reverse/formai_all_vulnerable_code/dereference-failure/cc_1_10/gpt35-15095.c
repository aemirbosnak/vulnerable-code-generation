//FormAI DATASET v1.0 Category: Data mining ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_NODES 10
#define MAX_DATA_SIZE 100

typedef struct {
    char data[MAX_DATA_SIZE];
} Data;

typedef struct {
    int node_id;
    int num_nodes;
    Data data[MAX_NODES];
} GameState;

GameState game_state;

void* listen_for_data(void* arg) {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket() failed");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(0);

    if (bind(server_sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind() failed");
        exit(1);
    }

    socklen_t addrlen = sizeof(server_addr);
    if (getsockname(server_sock, (struct sockaddr*) &server_addr, &addrlen) < 0) {
        perror("getsockname() failed");
        exit(1);
    }

    printf("Node %d listening on port %d\n", game_state.node_id, ntohs(server_addr.sin_port));

    if (listen(server_sock, game_state.num_nodes - 1) < 0) {
        perror("listen() failed");
        exit(1);
    }

    int connect_cnt = 0;
    while (connect_cnt < game_state.num_nodes - 1) {
        struct sockaddr_in client_addr;
        socklen_t client_addrlen = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr*) &client_addr, &client_addrlen);
        if (client_sock < 0) {
            perror("accept() failed");
            exit(1);
        }

        printf("Node %d connected to node %d\n", game_state.node_id, connect_cnt);

        int data_size = sizeof(Data);
        int remaining_data = data_size;
        char* buffer = (char*) &game_state.data[connect_cnt];
        while (remaining_data > 0) {
            int num_bytes = read(client_sock, buffer, remaining_data);
            if (num_bytes < 0) {
                perror("read() failed");
                exit(1);
            }
            else if (num_bytes == 0) {
                break;
            }
            remaining_data -= num_bytes;
            buffer += num_bytes;
        }

        close(client_sock);
        printf("Node %d disconnected from node %d\n", game_state.node_id, connect_cnt);

        connect_cnt++;
    }

    close(server_sock);
    printf("Node %d exiting\n", game_state.node_id);

    return NULL;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <node_id> <num_nodes>\n", argv[0]);
        return 1;
    }

    game_state.node_id = atoi(argv[1]);
    game_state.num_nodes = atoi(argv[2]);

    srand(time(NULL));

    for (int i = 0; i < game_state.num_nodes; i++) {
        sprintf(game_state.data[i].data, "data_%d_%d", game_state.node_id, i);
    }

    pthread_t thread;
    pthread_create(&thread, NULL, listen_for_data, NULL);

    sleep(1);

    printf("Node %d broadcasting data:\n", game_state.node_id);
    for (int i = 0; i < game_state.num_nodes; i++) {
        printf("%s\n", game_state.data[i].data);
    }

    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    for (int i = 0; i < game_state.num_nodes; i++) {
        if (i != game_state.node_id) {
            dest_addr.sin_port = htons(i + 10000);

            int client_sock = socket(AF_INET, SOCK_STREAM, 0);
            if (client_sock < 0) {
                perror("socket() failed");
                exit(1);
            }

            if (connect(client_sock, (struct sockaddr*) &dest_addr, sizeof(dest_addr)) < 0) {
                perror("connect() failed");
                exit(1);
            }

            int data_size = sizeof(Data);
            int remaining_data = data_size;
            char* buffer = (char*) &game_state.data[i];
            while (remaining_data > 0) {
                int num_bytes = write(client_sock, buffer, remaining_data);
                if (num_bytes < 0) {
                    perror("write() failed");
                    exit(1);
                }
                remaining_data -= num_bytes;
                buffer += num_bytes;
            }

            close(client_sock);
        }
    }

    pthread_join(thread, NULL);

    return 0;
}