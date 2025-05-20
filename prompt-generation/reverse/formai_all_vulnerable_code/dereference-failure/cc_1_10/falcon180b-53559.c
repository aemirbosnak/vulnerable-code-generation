//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

int main() {
    int sock = 0;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    int server_len = sizeof(server_addr);
    char *response = NULL;
    long int total_bytes = 0;
    double speed = 0;
    time_t start_time, end_time;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, server_len) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    start_time = time(NULL);
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sock, buffer, strlen(buffer), 0);

        response = malloc(BUFFER_SIZE);
        memset(response, 0, BUFFER_SIZE);
        recv(sock, response, BUFFER_SIZE, 0);

        total_bytes += strlen(response);

        if (strstr(response, "Test Complete")!= NULL) {
            end_time = time(NULL);
            speed = (double)total_bytes / (end_time - start_time);
            printf("Internet Speed: %.2lf bytes/second\n", speed);
            break;
        }
    }

    close(sock);
    free(response);
    return 0;
}