//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_THREADS 1024
#define BUFFER_SIZE 1024

typedef struct {
    int sock;
    struct sockaddr_in addr;
} thread_data_t;

void *scan_thread(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        bytes_received = recv(data->sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        printf("Received data from %s:%d: %s\n", inet_ntoa(data->addr.sin_addr), ntohs(data->addr.sin_port), buffer);
    }

    close(data->sock);
    free(data);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    char *port = argv[2];
    int num_threads = 0;

    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);
        if (strcmp(buffer, "scan") == 0) {
            int port_num = atoi(port);
            for (int i = 1; i <= MAX_THREADS; i++) {
                pthread_t thread_id;
                thread_data_t *data = (thread_data_t *) malloc(sizeof(thread_data_t));
                data->sock = socket(AF_INET, SOCK_STREAM, 0);
                data->addr.sin_family = AF_INET;
                data->addr.sin_port = htons(port_num + i - 1);
                data->addr.sin_addr.s_addr = inet_addr(host);

                if (connect(data->sock, (struct sockaddr *)&data->addr, sizeof(data->addr)) == 0) {
                    printf("Connected to %s:%d\n", inet_ntoa(data->addr.sin_addr), ntohs(data->addr.sin_port));
                    pthread_create(&thread_id, NULL, scan_thread, data);
                    num_threads++;
                } else {
                    close(data->sock);
                    free(data);
                }
            }
        } else if (strcmp(buffer, "quit") == 0) {
            break;
        }
    }

    close(sock);
    return 0;
}