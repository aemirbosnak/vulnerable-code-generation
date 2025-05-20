//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>

typedef struct {
    struct sockaddr_storage address;
    int socket_fd;
    int current_speed;
} client_info;

// Min speed of 1 MBps
const int MINIMUM_SPEED = 1000000;

void *connection_handler(void *);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./qos_monitor <port_number>\n");
        exit(1);
    }

    int port = atoi(argv[1]);

    int server_socket_fd;
    struct sockaddr_in server_address;

    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket_fd == -1) {
        printf("Failed to create socket\n");
        exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(server_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("Failed to bind to port\n");
        exit(1);
    }

    listen(server_socket_fd, 5);

    printf("Server started on port %d\n", port);

    while (1) {
        struct sockaddr_storage client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket_fd = accept(server_socket_fd, (struct sockaddr *) &client_address, &client_address_len);

        if (client_socket_fd == -1) {
            printf("Failed to accept connection\n");
            exit(1);
        }

        client_info *info = (client_info *) malloc(sizeof(client_info));
        info->address = client_address;
        info->socket_fd = client_socket_fd;
        info->current_speed = 0;

        pthread_t client_thread;
        pthread_create(&client_thread, NULL, connection_handler, (void *) info);
        pthread_detach(client_thread);
    }

    return 0;
}

void *connection_handler(void* arg) {
    client_info *info = (client_info *) arg;

    char client_ip[INET6_ADDRSTRLEN];
    const int client_port = ntohs(((struct sockaddr_in *) &info->address)->sin_port);

    inet_ntop(info->address.ss_family, &(((struct sockaddr_in *) &info->address)->sin_addr), client_ip, sizeof(client_ip));

    printf("New connection from %s:%d\n", client_ip, client_port);

    struct timeval start, end;
    char buffer[1024];

    gettimeofday(&start, NULL);

    while (1) {
        ssize_t bytes_received = recv(info->socket_fd, buffer, sizeof(buffer), 0);

        if (bytes_received == -1) {
            printf("Error receiving data\n");
            break;
        } else if (bytes_received == 0) {
            printf("Connection closed by %s:%d\n", client_ip, client_port);
            break;
        }

        info->current_speed += bytes_received;

        gettimeofday(&end, NULL);
        double time_diff = (double) (end.tv_sec - start.tv_sec) + (double) (end.tv_usec - start.tv_usec) / 1000000;

        if (time_diff >= 1) {
            double speed_in_bps = (double) info->current_speed / time_diff;

            printf("[%s:%d] Current speed: %.2f MBps\n", client_ip, client_port, speed_in_bps / 1000000);

            if (speed_in_bps < MINIMUM_SPEED) {
                printf("[%s:%d] Connection speed is below minimum threshold, closing connection\n", client_ip, client_port);
                break;
            }

            info->current_speed = 0;
            gettimeofday(&start, NULL);
        }
    }

    close(info->socket_fd);
    free(info);

    return NULL;
}