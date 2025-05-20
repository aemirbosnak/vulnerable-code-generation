//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: shocked
// Prepare to be shocked!

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>

// Bolt from the blue!
int create_client(char *ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed!");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    int conn = connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (conn == -1) {
        perror("Connection failed!");
        exit(1);
    }

    return sock;
}

// The server strikes back!
int create_server(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed!");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    int bind_res = bind(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (bind_res == -1) {
        perror("Bind failed!");
        exit(1);
    }

    int listen_res = listen(sock, 5);
    if (listen_res == -1) {
        perror("Listen failed!");
        exit(1);
    }

    return sock;
}

// Sparks fly!
void handle_client(int sock) {
    while (1) {
        char buffer[1024];
        int recv_res = recv(sock, buffer, sizeof(buffer), 0);
        if (recv_res <= 0) {
            printf("Client disconnected!\n");
            break;
        }

        printf("Client: %s\n", buffer);
        send(sock, buffer, strlen(buffer), 0);
    }
}

// Lightning bolts!
int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "-s") == 0) {
        int server_sock = create_server(atoi(argv[2]));
        while (1) {
            int client_sock = accept(server_sock, NULL, NULL);
            handle_client(client_sock);
        }
    } else if (strcmp(argv[1], "-c") == 0) {
        int client_sock = create_client(argv[2], atoi(argv[3]));
        while (1) {
            char buffer[1024];
            printf("Enter a message: ");
            fgets(buffer, sizeof(buffer), stdin);
            send(client_sock, buffer, strlen(buffer), 0);
            int recv_res = recv(client_sock, buffer, sizeof(buffer), 0);
            if (recv_res <= 0) {
                printf("Server disconnected!\n");
                break;
            }
            printf("Server: %s\n", buffer);
        }
    } else {
        printf("Invalid argument!\n");
        exit(1);
    }

    return 0;
}