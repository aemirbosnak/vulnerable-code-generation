//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 1024
#define QOS_THRESHOLD 1000 //1 second

typedef struct {
    int socket_fd;
    struct sockaddr_in server_address;
    int is_running;
} QoS_Monitor;

void init_monitor(QoS_Monitor *monitor, char *address, int port);
void *start_monitor(void *monitor_ptr);
void stop_monitor(QoS_Monitor *monitor);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return 0;
    }

    QoS_Monitor monitor;
    init_monitor(&monitor, argv[1], atoi(argv[2]));

    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, start_monitor, &monitor);

    while (1) {
        char input[MAX_BUFFER_SIZE];
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }
    }

    stop_monitor(&monitor);

    return 0;
}

void init_monitor(QoS_Monitor *monitor, char *address, int port) {
    monitor->socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&monitor->server_address, 0, sizeof(monitor->server_address));
    monitor->server_address.sin_family = AF_INET;
    monitor->server_address.sin_addr.s_addr = inet_addr(address);
    monitor->server_address.sin_port = htons(port);

    monitor->is_running = 1;
}

void *start_monitor(void *monitor_ptr) {
    QoS_Monitor *monitor = monitor_ptr;

    while (monitor->is_running) {
        if (connect(monitor->socket_fd, (struct sockaddr *)&monitor->server_address, sizeof(monitor->server_address)) == -1) {
            printf("Connection to server at %s:%d failed\n", inet_ntoa(monitor->server_address.sin_addr), ntohs(monitor->server_address.sin_port));
        }
        else {
            printf("Successfully connected to server at %s:%d\n", inet_ntoa(monitor->server_address.sin_addr), ntohs(monitor->server_address.sin_port));

            struct timeval start_time, end_time;
            char buffer[MAX_BUFFER_SIZE];

            gettimeofday(&start_time, NULL);

            if (recv(monitor->socket_fd, buffer, MAX_BUFFER_SIZE, 0) > 0) {
                gettimeofday(&end_time, NULL);

                double elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0;

                if (elapsed_time > QOS_THRESHOLD) {
                    printf("Network quality is poor: %f ms\n", elapsed_time);
                }
                else {
                    printf("Network quality is good: %f ms\n", elapsed_time);
                }
            }
            else {
                printf("Error receiving data from server at %s:%d\n", inet_ntoa(monitor->server_address.sin_addr), ntohs(monitor->server_address.sin_port));
            }

            close(monitor->socket_fd);
        }

        sleep(5); //check every 5 seconds
    }

    pthread_exit(NULL);
}

void stop_monitor(QoS_Monitor *monitor) {
    monitor->is_running = 0;
}