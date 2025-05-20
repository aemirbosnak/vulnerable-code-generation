//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s interface\n", argv[0]);
        exit(1);
    }

    char interface[128];
    strncpy(interface, argv[1], sizeof(interface) - 1);

    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(2000);

    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        exit(1);
    }

    sendto(socket_fd, "sniff", 6, 0, (struct sockaddr *)&address, sizeof(address));

    char buffer[4096];
    int bytes_read = recvfrom(socket_fd, buffer, sizeof(buffer), 0, NULL, NULL);
    if (bytes_read <= 0) {
        perror("recvfrom");
        exit(1);
    }

    char *sniff_line = strstr(buffer, "\n");
    if (sniff_line == NULL) {
        fprintf(stderr, "sniff line not found\n");
        exit(1);
    }

    *sniff_line = '\0';
    char *qos_value = strstr(sniff_line, "QoS:");
    if (qos_value == NULL) {
        fprintf(stderr, "QoS value not found\n");
        exit(1);
    }

    qos_value += 5;
    char *end_of_value = strstr(qos_value, "\n");
    if (end_of_value == NULL) {
        fprintf(stderr, "end of value not found\n");
        exit(1);
    }

    *end_of_value = '\0';
    int qos_value_int = atoi(qos_value);

    printf("QoS value: %d\n", qos_value_int);

    close(socket_fd);
    return 0;
}