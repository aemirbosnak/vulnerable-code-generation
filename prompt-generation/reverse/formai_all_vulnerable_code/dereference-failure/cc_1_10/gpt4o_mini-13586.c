//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: Romeo and Juliet
// romeo_juliet.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void run_server();
void run_client(char *message);

int main(int argc, char *argv[]) {
    if (argc == 2) {
        run_client(argv[1]);
    } else {
        run_server();
    }
    return 0;
}

// The Capulet Family's server
void run_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Creating file descriptor and binding
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Capulet: Socket creation failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Capulet: Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Capulet: Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Capulet: The stage is set... Awaiting the Montagues.\n");

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Capulet: Accept failed");
        exit(EXIT_FAILURE);
    }

    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Capulet: Received - %s", buffer);

        if (strcmp(buffer, "exit\n") == 0) {
            printf("Capulet: Farewell, dear Montague!\n");
            break;
        }

        // Reply with a jest
        char *response = "Capulet: 'A plague o' both your houses!'\n";
        send(new_socket, response, strlen(response), 0);
    }

    close(new_socket);
    close(server_fd);
}

// The Montague Family's client
void run_client(char *message) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Montague: Socket creation error\n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Montague: Invalid address\n");
        return;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Montague: Connection Failed\n");
        return;
    }

    char *msg = message;
    while (1) {
        printf("Montague: Send a message to Capulet: ");
        fgets(msg, BUFFER_SIZE, stdin);
        send(sock, msg, strlen(msg), 0);

        if (strcmp(msg, "exit\n") == 0) {
            printf("Montague: Until we meet again...\n");
            break;
        }

        // Now listen for Capulet's retort
        memset(buffer, 0, BUFFER_SIZE);
        read(sock, buffer, BUFFER_SIZE);
        printf("%s", buffer);
    }

    close(sock);
}