//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define STOCK_COUNT 5

// Structure to hold stock data
typedef struct {
    char symbol[10];
    float price;
} Stock;

// Array to store stock prices for demonstration
Stock stockData[STOCK_COUNT] = {
    {"AAPL", 150.00},
    {"GOOGL", 2800.00},
    {"AMZN", 3400.00},
    {"TSLA", 700.00},
    {"MSFT", 290.00}
};

// Function to simulate fetching a stock price
float getStockPrice(const char *symbol) {
    for (int i = 0; i < STOCK_COUNT; i++) {
        if (strcmp(stockData[i].symbol, symbol) == 0) {
            return stockData[i].price;
        }
    }
    return -1.0; // Returns -1 if stock symbol not found
}

// Function to handle client requests
void *handleClient(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        ssize_t bytesRead = read(sock, buffer, BUFFER_SIZE);

        if (bytesRead <= 0) {
            break;
        }

        buffer[bytesRead] = '\0'; // Null terminate the received string
        printf("Received request for: %s\n", buffer);

        float price = getStockPrice(buffer);
        if (price < 0) {
            snprintf(response, BUFFER_SIZE, "Error: Stock %s not found.", buffer);
        } else {
            snprintf(response, BUFFER_SIZE, "The current price of %s is $%.2f.", buffer, price);
        }

        write(sock, response, strlen(response));
    }

    close(sock);
    free(client_socket);
    return NULL;
}

// Main function for the server
int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, 5) < 0) {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Stock market tracker server running on port %d.\n", PORT);

    while (1) {
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len);
        if (client_sock < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Client connected.\n");

        int *sock_ptr = malloc(sizeof(int));
        *sock_ptr = client_sock;

        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, handleClient, sock_ptr) != 0) {
            perror("Failed to create thread");
            free(sock_ptr);
        }

        pthread_detach(client_thread); // Detach thread to handle cleanup
    }

    close(server_sock);
    return 0;
}