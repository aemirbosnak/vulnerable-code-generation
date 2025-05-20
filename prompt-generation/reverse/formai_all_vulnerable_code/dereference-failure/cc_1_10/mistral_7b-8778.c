//MISTRAL-7B DATASET v1.0 Category: TCP/IP Programming ; Style: scientific
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024
#define SENSOR_DATA_FILE "sensor_data.txt"

bool read_sensor_data(char *buffer, size_t size);
void send_response(int client_socket, const char *response);

int main() {
    int server_socket, new_socket;
    int addrlen;
    struct sockaddr_in server_addr, client_addr;

    // Initialize socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set up the address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind error");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(server_socket, MAX_CLIENTS);

    fd_set master_fds, read_fds;
    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);
    FD_SET(server_socket, &master_fds);

    while (true) {
        read_fds = master_fds;
        if (select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select error");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < FD_SETSIZE; ++i) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == server_socket) {
                    addrlen = sizeof(client_addr);
                    new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);
                    if (new_socket < 0) {
                        perror("accept error");
                        exit(EXIT_FAILURE);
                    }
                    printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                    FD_SET(new_socket, &master_fds);
                } else {
                    int client_socket = i;
                    char buffer[BUFFER_SIZE];
                    if (read(client_socket, buffer, BUFFER_SIZE) > 0) {
                        printf("Data received from client: %s\n", buffer);
                        if (read_sensor_data(buffer, sizeof(buffer))) {
                            send_response(client_socket, "Processed data:\n");
                            write(client_socket, buffer, strlen(buffer));
                        }
                    }
                    close(client_socket);
                    FD_CLR(client_socket, &master_fds);
                    printf("Client disconnected\n");
                }
            }
        }
    }

    close(server_socket);
    return EXIT_SUCCESS;
}

bool read_sensor_data(char *buffer, size_t size) {
    FILE *sensor_file = fopen(SENSOR_DATA_FILE, "r");
    if (!sensor_file) {
        perror("Error opening sensor data file");
        return false;
    }

    size_t read_bytes = fread(buffer, 1, size, sensor_file);
    if (read_bytes > 0) {
        fclose(sensor_file);
        return true;
    }

    perror("Error reading sensor data file");
    fclose(sensor_file);
    return false;
}

void send_response(int client_socket, const char *response) {
    size_t response_len = strlen(response);
    write(client_socket, response, response_len);
}