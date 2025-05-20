//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 5

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Client Handler Function
void *client_handler(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char client_message[BUFFER_SIZE];

    // Receiving messages from the client
    while (1) {
        bzero(client_message, BUFFER_SIZE);
        int read_size = recv(sock, client_message, BUFFER_SIZE, 0);
        if (read_size <= 0) {
            break;
        }
        
        printf("Client: %s", client_message);
        
        // Example: Echoing back the message
        send(sock, client_message, strlen(client_message), 0);
    }
    
    printf("Client disconnected.\n");
    close(sock);
    return 0;
}

// Server Function
void run_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error_exit("Socket failed");
    }
    
    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        error_exit("Setsockopt failed");
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error_exit("Bind failed");
    }
    
    // Listening
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        error_exit("Listen failed");
    }

    printf("🌍 Server listening on port %d...\n", PORT);

    // Accepting clients
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))) {
        printf("👤 New connection accepted.\n");
        
        // Creating a thread for the client handler
        pthread_t client_thread;
        int *new_sock = malloc(1);
        *new_sock = new_socket;
        pthread_create(&client_thread, NULL, client_handler, (void *)new_sock);
    }

    // Closing socket (though this should never be reached in the loop)
    close(server_fd);
}

// Client Function
void run_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client!\n";
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_exit("Socket creation error");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        error_exit("Invalid address/ Address not supported");
    }
    
    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_exit("Connection failed");
    }

    // Sending and receiving messages
    while(1) {
        printf("📝 Client: ");
        bzero(buffer, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);
        
        send(sock, buffer, strlen(buffer), 0);
        if (strncmp(buffer, "exit", 4) == 0) {
            printf("👋 Exiting client...\n");
            break;
        }
        
        bzero(buffer, BUFFER_SIZE);
        recv(sock, buffer, BUFFER_SIZE, 0);
        printf("🌐 Server response: %s", buffer);
    }
    
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc > 1 && strcmp(argv[1], "client") == 0) {
        run_client();
    } else {
        run_server();
    }

    return 0;
}