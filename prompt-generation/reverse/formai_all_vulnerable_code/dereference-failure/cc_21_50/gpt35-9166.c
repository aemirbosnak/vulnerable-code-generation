//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <fcntl.h>
#include <time.h>

#define MAX_QUEUE_SIZE 1000
#define TIME_INTERVAL 5

typedef struct {
    int queue_size;
    time_t timestamp;
} QoS;

QoS monitor[MAX_QUEUE_SIZE];

int main(int argc, char *argv[]) {
    int sock_fd;
    struct ifreq ifr;
    struct sockaddr_in server_address;
    char buffer[1024];
    int n, size, total;
    time_t start_time, end_time;
    long elapsed_time;
    int i, j, k;
    int min_index, max_index, avg_index;
    double min_value, max_value, avg_value;

    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(1);
    }

    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock_fd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, argv[1], IFNAMSIZ-1);

    if (ioctl(sock_fd, SIOCGIFFLAGS, &ifr) == -1) {
        perror("ioctl");
        exit(1);
    }

    ifr.ifr_flags |= IFF_PROMISC;

    if (ioctl(sock_fd, SIOCSIFFLAGS, &ifr) == -1) {
        perror("ioctl");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);

    if (bind(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        exit(1);
    }

    printf("QoS Monitor started on interface %s.\n", argv[1]);

    memset(monitor, 0, sizeof(monitor));
    total = 0;

    while (1) {
        start_time = time(NULL);

        while (1) {
            n = recvfrom(sock_fd, buffer, sizeof(buffer), 0, NULL, NULL);

            if (n < 0) {
                perror("recvfrom");
                exit(1);
            }

            if (n == 0) {
                break;
            }

            size += n;
        }

        end_time = time(NULL);

        elapsed_time = end_time - start_time;

        if (elapsed_time == 0) {
            elapsed_time = 1;
        }

        monitor[total].queue_size = size / elapsed_time;
        monitor[total].timestamp = end_time;

        total = (total + 1) % MAX_QUEUE_SIZE;

        if (total == 0) {
            printf("QoS Monitor Queue Full\n\n");
            break;
        }

        size = 0;

        for (i = 0; i < MAX_QUEUE_SIZE; i++) {
            if (monitor[i].queue_size == 0) {
                break;
            }
        }

        if (i == MAX_QUEUE_SIZE) {
            printf("QoS Monitor Queue Full\n\n");
            break;
        }

        for (j = 0; j < (i - 1); j++) {
            min_index = j;

            for (k = (j + 1); k < i; k++) {
                if (monitor[k].queue_size < monitor[min_index].queue_size) {
                    min_index = k;
                }
            }

            if (min_index != j) {
                QoS temp = monitor[j];
                monitor[j] = monitor[min_index];
                monitor[min_index] = temp;
            }
        }

        min_value = monitor[0].queue_size;

        for (j = 0; j < i; j++) {
            max_index = j;

            for (k = (j + 1); k < i; k++) {
                if (monitor[k].queue_size > monitor[max_index].queue_size) {
                    max_index = k;
                }
            }

            if (max_index != j) {
                QoS temp = monitor[j];
                monitor[j] = monitor[max_index];
                monitor[max_index] = temp;
            }
        }

        max_value = monitor[0].queue_size;

        avg_value = 0;

        for (j = 0; j < i; j++) {
            avg_value += monitor[j].queue_size;
        }

        avg_value /= i;

        printf("QoS Monitor Results - Time Interval: %d seconds, Queue Size: %d\n", TIME_INTERVAL, i);

        printf("Minimum Average Queue Size: %.2f packets/second\n", min_value);

        printf("Maximum Average Queue Size: %.2f packets/second\n", max_value);

        printf("Average Queue Size: %.2f packets/second\n\n", avg_value);
        
        sleep(TIME_INTERVAL);
    }

    close(sock_fd);

    return 0;
}