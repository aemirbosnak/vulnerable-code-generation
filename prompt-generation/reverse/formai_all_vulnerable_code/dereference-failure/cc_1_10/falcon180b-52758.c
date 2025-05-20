//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: creative
// C Network Ping Test

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_SIZE];
    int data_len;

    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        printf("Usage:./ping <IP address> <port number>\n");
        return 1;
    }

    // Convert the IP address from string to binary format
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) == 0) {
        printf("Invalid IP address\n");
        return 1;
    }

    // Set up the socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    // Send a message to the server
    strcpy(data, "PING");
    data_len = strlen(data);
    if (send(sock, data, data_len, 0) == -1) {
        printf("Error sending message\n");
        close(sock);
        return 1;
    }

    // Receive a response from the server
    memset(data, 0, MAX_DATA_SIZE);
    data_len = recv(sock, data, MAX_DATA_SIZE, 0);
    if (data_len == -1) {
        printf("Error receiving response\n");
        close(sock);
        return 1;
    }

    // Print the response
    printf("Response: %s\n", data);

    // Close the socket
    close(sock);

    return 0;
}