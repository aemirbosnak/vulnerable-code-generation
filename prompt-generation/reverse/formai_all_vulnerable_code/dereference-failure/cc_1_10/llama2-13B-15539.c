//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 100
#define BENCHMARK_LEN 1024

struct client_data {
    int sock;
    char buffer[BENCHMARK_LEN];
};

void *client_thread(void *data) {
    struct client_data *cd = data;
    int bytes_sent = 0;

    while (1) {
        bytes_sent = send(cd->sock, "Hello, client!", 13, 0);
        if (bytes_sent < 0) {
            perror("send failed");
            break;
        }

        usleep(100000); // 100ms sleep
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(server_sock, MAX_CLIENTS);

    while (1) {
        int client_sock = accept(server_sock, NULL, NULL);
        struct client_data *cd = malloc(sizeof(struct client_data));
        cd->sock = client_sock;

        pthread_t thread;
        pthread_create(&thread, NULL, client_thread, cd);

        usleep(100000); // 100ms sleep
    }

    return 0;
}