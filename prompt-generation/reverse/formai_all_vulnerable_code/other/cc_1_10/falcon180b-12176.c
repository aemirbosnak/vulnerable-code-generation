//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int scan_port(int sock, int port) {
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (result == 0) {
        printf("Port %d is open\n", port);
    } else {
        printf("Port %d is closed\n", port);
    }
    close(sock);
    return result;
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (result == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    printf("Connected to server\n");

    int max_threads = 10;
    pthread_t threads[max_threads];

    for (int i = 0; i < max_threads; i++) {
        int port = i * MAX_PORTS / max_threads + 1;
        pthread_create(&threads[i], NULL, (void *)scan_port, (void *)port);
    }

    for (int i = 0; i < max_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sock);
    return 0;
}