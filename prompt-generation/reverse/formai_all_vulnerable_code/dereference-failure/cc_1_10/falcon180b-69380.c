//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <math.h>

#define MAX_DATA_SIZE 2048
#define QOS_INTERVAL 10 // seconds

struct sockaddr_in server_addr;
int sock;
double qos_data[QOS_INTERVAL];
int qos_index = 0;

void init_socket() {
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
}

void set_server_addr(char* ip, int port) {
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);
}

void send_qos_data(double data) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    double current_time = tv.tv_sec + (tv.tv_usec / 1000000.0);
    if (qos_index == QOS_INTERVAL) {
        qos_index = 0;
    }
    qos_data[qos_index] = data;
    qos_index++;
    printf("QoS data sent: %lf\n", data);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <IP> <Port> <QoS Data>\n", argv[0]);
        return 1;
    }

    char* ip = argv[1];
    int port = atoi(argv[2]);
    double qos_data = atof(argv[3]);

    init_socket();
    set_server_addr(ip, port);

    while (1) {
        send_qos_data(qos_data);
        sleep(QOS_INTERVAL);
    }

    return 0;
}