//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define PORT 8080
#define MAX_PENDING_CONN 10
#define BUFFER_SIZE 1024

int main() {

    // Variables for creating sockets and accepting incoming client connections
    int sockfd, client_sockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_addr_len = sizeof(cli_addr);

    // Create a TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set socket options to allow reuse of listening port
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        perror("Socket option error");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific port and address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("Socket bind error");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming client connections
    if (listen(sockfd, MAX_PENDING_CONN) == -1) {
        perror("Socket listen error");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    // Loop to accept incoming client connections and handle them
    while (1) {

        // Accept an incoming client connection
        if ((client_sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_addr_len)) < 0) {
            perror("Socket accept error");
            exit(EXIT_FAILURE);
        }

        // Receive data from the client and calculate average RTT
        char buffer[BUFFER_SIZE];
        int total_rtts = 0;
        int num_rtts = 0;
        int recv_size;

        while ((recv_size = recv(client_sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
            int rtt = atoi(buffer);
            total_rtts += rtt;
            num_rtts++;
        }

        if (recv_size == -1) {
            perror("Socket receive error");
            exit(EXIT_FAILURE);
        }

        // Calculate average RTT and print it to the console
        int avg_rtt = total_rtts / num_rtts;
        printf("Client %s:%d - Average RTT: %d ms\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port), avg_rtt);

        // Send the average RTT back to the client
        char response[20];
        snprintf(response, sizeof(response), "%d", avg_rtt);
        if (send(client_sockfd, response, sizeof(response), 0) == -1) {
            perror("Socket send error");
            exit(EXIT_FAILURE);
        }

        // Close the client socket
        close(client_sockfd);
    }

    // Close the server socket
    close(sockfd);

    return 0;
}