//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

void error_handler(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: qmon IP PORT\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error_handler("Error: Socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        error_handler("Error: Invalid IP address");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handler("Error: Connection failed");
    }

    char buff[BUFF_SIZE];
    while (1) {
        int n = read(sock, buff, sizeof(buff));
        if (n <= 0) break;

        printf("Received: %s", buff);
        float values[3];
        sscanf(buff, "%f %f %f", &values[0], &values[1], &values[2]);
        float avg = (values[0] + values[1] + values[2]) / 3.0;

        if (avg > 60.0) {
            printf("Alert! Network Quality of Service (QoS) is degraded!\n");
            // send alert message to a remote monitoring server
        }
    }

    close(sock);
    return 0;
}