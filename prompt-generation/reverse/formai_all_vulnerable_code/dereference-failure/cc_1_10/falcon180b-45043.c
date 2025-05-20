//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define SERVER_PORT 8080

struct sockaddr_in server_addr;
int sock;
char data[MAX_DATA_SIZE];

int main() {
    int ret;
    char *ip;
    struct hostent *host;

    // Get the IP address of the server
    ip = "127.0.0.1";
    host = gethostbyname(ip);
    if (host == NULL) {
        printf("Failed to resolve hostname: %s\n", hstrerror(h_errno));
        return 1;
    }

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket: %s\n", strerror(errno));
        return 1;
    }

    // Connect to the server
    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Failed to connect to server: %s\n", strerror(errno));
        return 1;
    }

    printf("Connected to server\n");

    // Send data to the server
    strcpy(data, "Hello, World!");
    ret = send(sock, data, strlen(data), 0);
    if (ret == -1) {
        printf("Failed to send data: %s\n", strerror(errno));
        return 1;
    }

    printf("Data sent to server\n");

    // Receive data from the server
    memset(data, 0, MAX_DATA_SIZE);
    ret = recv(sock, data, MAX_DATA_SIZE, 0);
    if (ret == -1) {
        printf("Failed to receive data: %s\n", strerror(errno));
        return 1;
    }

    printf("Data received from server: %s\n", data);

    // Close the socket
    ret = close(sock);
    if (ret == -1) {
        printf("Failed to close socket: %s\n", strerror(errno));
        return 1;
    }

    printf("Socket closed\n");

    return 0;
}