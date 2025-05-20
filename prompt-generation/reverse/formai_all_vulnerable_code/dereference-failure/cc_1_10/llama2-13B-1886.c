//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/wait.h>

#define PORT 8080

int main() {
    int sock, client_sock, i, j, k, temp;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buffer[256];

    // Create the server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the server socket to the address and port
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept an incoming connection
    client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
    if (client_sock < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Read the list of integers from the client
    printf("Please enter the list of integers, separated by spaces:\n");
    fgets(buffer, 256, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove the newline character
    char *token = strtok(buffer, " ");
    int *list = malloc(sizeof(int) * strlen(buffer));
    int count = 0;
    while (token != NULL) {
        list[count] = atoi(token);
        count++;
        token = strtok(NULL, " ");
    }

    // Distributed sorting
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if (list[i] > list[j]) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    // Send the sorted list back to the client
    send(client_sock, list, sizeof(int) * count, 0);

    // Close the client socket
    close(client_sock);

    return 0;
}