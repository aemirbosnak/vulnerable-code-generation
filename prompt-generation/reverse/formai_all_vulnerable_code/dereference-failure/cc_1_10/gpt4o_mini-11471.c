//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define BACKLOG 5

void log_error(const char *msg) {
    fprintf(stderr, "[ERROR] %s: %s\n", msg, strerror(errno));
    exit(EXIT_FAILURE);
}

void paranoid_log(const char *msg) {
    printf("[LOG] %s\n", msg);
}

void check_and_exit(int condition, const char *msg) {
    if (condition) {
        log_error(msg);
    }
}

void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    check_and_exit((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1, "Socket creation failed");

    paranoid_log("Socket created successfully!");

    check_and_exit((setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) < 0, "Setsockopt failed");

    paranoid_log("Socket options set successfully!");

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // bind to any available interface
    address.sin_port = htons(PORT);

    check_and_exit(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0, "Bind failed");

    paranoid_log("Socket bound to port!");

    check_and_exit(listen(server_fd, BACKLOG) < 0, "Listen failed");

    paranoid_log("Waiting for connections...");
    
    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        check_and_exit(new_socket < 0, "Accept failed");

        paranoid_log("Connection accepted!");

        int bytes_received = read(new_socket, buffer, BUFFER_SIZE);
        check_and_exit(bytes_received < 0, "Read failed");

        buffer[bytes_received] = '\0';
        paranoid_log("Message received.");

        printf("Client: %s\n", buffer);
        char *response = "Message received and logged.";
        send(new_socket, response, strlen(response), 0);

        close(new_socket);
        paranoid_log("Connection closed.");
    }

    close(server_fd);
}

void start_client(const char *ip_address) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello from Client!";
    char buffer[BUFFER_SIZE] = {0};

    while (1) {
        check_and_exit((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0, "Socket creation failed");

        paranoid_log("Client socket created!");

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);

        check_and_exit(inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0, "Invalid address or address not supported");

        paranoid_log("Connecting to the server...");
        check_and_exit(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0, "Connection Failed");

        paranoid_log("Connected to server, sending message...");

        send(sock, message, strlen(message), 0);
        paranoid_log("Message sent!");

        int bytes_received = read(sock, buffer, BUFFER_SIZE);
        check_and_exit(bytes_received < 0, "Read failed");

        buffer[bytes_received] = '\0';
        paranoid_log("Response received.");
        printf("Server: %s\n", buffer);

        close(sock);
        paranoid_log("Client socket closed.");

        sleep(2); // Wait before next attempt to avoid flooding
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (fork() == 0) {
        // This will run in the child process
        start_server();
    } else {
        // Parent process runs client
        sleep(1); // Give server time to start
        start_client(argv[1]);
    }

    return 0;
}