//LLAMA2-13B DATASET v1.0 Category: Bitwise operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sock, conn_sock;
    struct sockaddr_in server, client;
    char buffer[1024];
    int num1, num2, xor_result;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(PORT);

    // Connect to the server
    conn_sock = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (conn_sock < 0) {
        perror("connect failed");
        exit(1);
    }

    // Send the first integer to the server
    num1 = atoi(argv[1]);
    send(sock, &num1, sizeof(int), 0);

    // Receive the second integer from the server
    recv(sock, &num2, sizeof(int), 0);

    // Calculate the XOR of the two integers
    xor_result = num1 ^ num2;

    // Send the XOR result back to the server
    send(sock, &xor_result, sizeof(int), 0);

    // Close the socket
    close(sock);

    return 0;
}