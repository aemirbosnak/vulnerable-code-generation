//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(21);
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        perror("Invalid server address");
        exit(EXIT_FAILURE);
    }

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t num_bytes_received;
    char *user_input = malloc(sizeof(char) * BUFFER_SIZE);
    char *temp_buff = malloc(sizeof(char) * BUFFER_SIZE);
    char *host_port;
    char *host_ip;
    int data_port;

    printf("Enter username: ");
    fgets(user_input, BUFFER_SIZE, stdin);
    user_input[strcspn(user_input, "\n")] = '\0'; // remove newline character
    sprintf(buffer, "USER %s\r\n", user_input);
    send(client_socket, buffer, strlen(buffer), 0);
    num_bytes_received = recv(client_socket, temp_buff, BUFFER_SIZE, 0);
    temp_buff[num_bytes_received] = '\0'; // add null terminator
    printf("%s", temp_buff);

    printf("Enter password: ");
    fgets(user_input, BUFFER_SIZE, stdin);
    user_input[strcspn(user_input, "\n")] = '\0'; // remove newline character
    sprintf(buffer, "PASS %s\r\n", user_input);
    send(client_socket, buffer, strlen(buffer), 0);
    num_bytes_received = recv(client_socket, temp_buff, BUFFER_SIZE, 0);
    temp_buff[num_bytes_received] = '\0'; // add null terminator
    printf("%s", temp_buff);

    sprintf(buffer, "PASV\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    num_bytes_received = recv(client_socket, temp_buff, BUFFER_SIZE, 0);
    temp_buff[num_bytes_received] = '\0'; // add null terminator
    printf("%s", temp_buff);

    host_port = strrchr(temp_buff, ',');
    host_port++;
    host_ip = strrchr(temp_buff, '(') + 1;
    host_ip[strcspn(host_ip, ",")] = '\0';
    data_port = atoi(host_port) * 256 + atoi(strchr(host_port, ',') + 1);

    struct sockaddr_in data_socket_address;
    data_socket_address.sin_family = AF_INET;
    data_socket_address.sin_port = htons(data_port);
    if (inet_pton(AF_INET, host_ip, &data_socket_address.sin_addr) <= 0) {
        perror("Invalid data socket address");
        exit(EXIT_FAILURE);
    }

    int data_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (data_socket < 0) {
        perror("Error creating data socket");
        exit(EXIT_FAILURE);
    }

    if (connect(data_socket, (struct sockaddr *) &data_socket_address, sizeof(data_socket_address)) < 0) {
        perror("Error connecting to data socket");
        exit(EXIT_FAILURE);
    }

    sprintf(buffer, "LIST\r\n");
    send(client_socket, buffer, strlen(buffer), 0);

    num_bytes_received = recv(client_socket, temp_buff, BUFFER_SIZE, 0);
    temp_buff[num_bytes_received] = '\0'; // add null terminator
    printf("%s", temp_buff);

    num_bytes_received = recv(data_socket, buffer, BUFFER_SIZE, 0);
    while (num_bytes_received > 0) {
        write(STDOUT_FILENO, buffer, num_bytes_received);
        num_bytes_received = recv(data_socket, buffer, BUFFER_SIZE, 0);
    }

    close(client_socket);
    close(data_socket);
    free(user_input);
    free(temp_buff);

    return EXIT_SUCCESS;
}