//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

int total_bytes_received = 0;
double speed = 0;

typedef struct QoS {
    int socket_fd;
    struct sockaddr_in address;
    int duration;
} QoS;

void* calculate_speed(void* q) {
    QoS* qos = (QoS*) q;
    char buffer[BUFFER_SIZE];
    int bytes_received = 0, seconds = 0;
    time_t start_time, current_time;

    start_time = time(NULL);

    while (1) {
        time(&current_time);
        if (current_time - start_time > qos->duration) {
            break;
        }
        bytes_received = recv(qos->socket_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Error in receiving data");
            break;
        }
        total_bytes_received += bytes_received;
    }
    speed = (double) total_bytes_received / ((double) qos->duration * 1000000);
    close(qos->socket_fd);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <IP> <port> <seconds>\n", argv[0]);
        return 1;
    }

    QoS qos;
    pthread_t thread_id;

    qos.socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (qos.socket_fd < 0) {
        perror("Error in creating socket");
        return 1;
    }

    memset(&qos.address, 0, sizeof(qos.address));
    qos.address.sin_family = AF_INET;
    qos.address.sin_addr.s_addr = inet_addr(argv[1]);
    qos.address.sin_port = htons(atoi(argv[2]));

    if (connect(qos.socket_fd, (struct sockaddr *) &qos.address, sizeof(qos.address)) < 0) {
        perror("Error in connecting");
        return 1;
    }

    qos.duration = atoi(argv[3]);
    pthread_create(&thread_id, NULL, calculate_speed, &qos);

    pthread_join(thread_id, NULL);

    printf("\n\n--- Network Quality of Service (QoS) Monitor ---\n");
    printf("Total bytes received: %d bytes\n", total_bytes_received);
    printf("Duration: %d seconds\n", qos.duration);
    printf("Download speed: %.2f Mbps\n", speed);

    return 0;
}