//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// function to display network QoS
void display_qos(int socket_fd) {
    // variables to store QoS statistics
    float latency = 0.0, jitter = 0.0, packet_loss_rate = 0.0;
    // sending request to server for QoS statistics
    char buffer[256] = "get_qos";
    int n = write(socket_fd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error writing to socket\n");
        exit(1);
    }
    // reading QoS statistics from server
    n = read(socket_fd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error reading from socket\n");
        exit(1);
    }
    // parsing QoS statistics
    char* ptr = strtok(buffer, ",");
    latency = atof(ptr);
    ptr = strtok(NULL, ",");
    jitter = atof(ptr);
    ptr = strtok(NULL, ",");
    packet_loss_rate = atof(ptr);
    // displaying QoS statistics
    printf("Latency: %.2f ms\n", latency);
    printf("Jitter: %.2f ms\n", jitter);
    printf("Packet loss rate: %.2f %%\n", packet_loss_rate);
}

int main() {
    // connecting to server
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }
    struct hostent *server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error finding host\n");
        exit(1);
    }
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(8080);
    if (connect(socket_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }
    // displaying QoS every 5 seconds
    while(1) {
        display_qos(socket_fd);
        sleep(5);
    }
    close(socket_fd);
    return 0;
}