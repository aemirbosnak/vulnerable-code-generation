//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888

struct complex {
    double real;
    double imag;
};

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(struct sockaddr_in);
    char buffer[1024];
    struct complex num1, num2, sum;

    // Create server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind server socket
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept incoming connection
    client_len = sizeof(struct sockaddr_in);
    client = (struct sockaddr_in) {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(0)
    };
    sock = accept(sock, (struct sockaddr *)&client, &client_len);
    if (sock < 0) {
        perror("accept failed");
        exit(1);
    }

    printf("Connection accepted from client...\n");

    // Read complex number from client
    read(sock, buffer, 1024);
    num1.real = atof(buffer);
    num1.imag = atof(buffer + strlen(buffer));
    printf("Received complex number: %f + %fi\n", num1.real, num1.imag);

    // Calculate sum of two complex numbers
    sum.real = num1.real + num2.real;
    sum.imag = num1.imag + num2.imag;
    printf("Sum of two complex numbers: %f + %fi\n", sum.real, sum.imag);

    // Write result to client
    write(sock, buffer, 1024);

    // Close sockets
    close(sock);

    return 0;
}