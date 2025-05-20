//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

struct thread_data {
    int sock;
    struct sockaddr_in server;
};

void *port_scanner(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    if (connect(data->sock, (struct sockaddr *) &data->server, sizeof(data->server)) == 0) {
        printf("Port %d is open\n", ntohs(data->server.sin_port));
        close(data->sock);
        return NULL;
    } else {
        printf("Port %d is closed\n", ntohs(data->server.sin_port));
        close(data->sock);
        return NULL;
    }
}

int main(int argc, char *argv[]) {
    int sock, port, max_threads, thread_count = 0;
    struct sockaddr_in server;
    pthread_t threads[MAX_THREADS];

    if (argc!= 3) {
        printf("Usage:./port_scanner <IP Address> <Port Range>\n");
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));

    while (thread_count < MAX_THREADS && port <= atoi(argv[2])) {
        if (pthread_create(&threads[thread_count], NULL, port_scanner, (void *) &server)!= 0) {
            printf("Error creating thread\n");
            return 1;
        }
        port++;
        thread_count++;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sock);
    return 0;
}