//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to perform the mathematical operation
double calculate(double num1, double num2, char operator) {
    switch (operator) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/':
            if (num2 != 0) return num1 / num2;
            else {
                printf("Error: Division by zero\n");
                return 0;
            }
        default: 
            printf("Error: Invalid operator\n");
            return 0;
    }
}

// Server code
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    double num1, num2, result;
    char operator;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to PORT
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("🛠️ Server is listening on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        printf("🔐 Connection accepted!\n");

        read(new_socket, buffer, BUFFER_SIZE);
        sscanf(buffer, "%lf %c %lf", &num1, &operator, &num2);
        
        result = calculate(num1, num2, operator);
        
        snprintf(buffer, BUFFER_SIZE, "Result: %.2lf\n", result);
        write(new_socket, buffer, strlen(buffer));
        printf("📤 Sent result: %.2lf\n", result);
        
        close(new_socket);
    }
}

// Client code
void start_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "0 + 0"; // Placeholder message
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    // User input for calculation
    double num1, num2;
    char operator;

    printf("Enter calculation (example: 3.5 * 2.1): ");
    scanf("%lf %c %lf", &num1, &operator, &num2);
    
    snprintf(buffer, BUFFER_SIZE, "%.2lf %c %.2lf", num1, operator, num2);
    send(sock, buffer, strlen(buffer), 0);
    printf("📤 Sent: %s\n", buffer);

    read(sock, buffer, BUFFER_SIZE);
    printf("📥 Received: %s\n", buffer);

    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc > 1 && strcmp(argv[1], "client") == 0) {
        start_client();
    } else {
        start_server();
    }
    return 0;
}