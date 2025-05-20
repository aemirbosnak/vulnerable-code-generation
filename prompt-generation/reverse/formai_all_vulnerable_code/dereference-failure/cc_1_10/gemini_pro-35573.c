//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 21
#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        printf("Usage: %s <server_address> <filename>\n", argv[0]);
        return -1;
    }

    // Get the server address and filename from the command line
    char *server_address = argv[1];
    char *filename = argv[2];

    // Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("socket() failed");
        return -1;
    }

    // Resolve the server address
    struct hostent *host = gethostbyname(server_address);
    if (host == NULL) {
        perror("gethostbyname() failed");
        return -1;
    }

    // Create a server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(DEFAULT_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect() failed");
        return -1;
    }

    // Send the RETR command to the server
    char retr_command[BUFFER_SIZE];
    snprintf(retr_command, BUFFER_SIZE, "RETR %s\r\n", filename);
    if (send(client_socket, retr_command, strlen(retr_command), 0) == -1) {
        perror("send() failed");
        return -1;
    }

    // Receive the response from the server
    char response[BUFFER_SIZE];
    if (recv(client_socket, response, BUFFER_SIZE, 0) == -1) {
        perror("recv() failed");
        return -1;
    }

    // Check if the server sent an error message
    if (strncmp(response, "550", 3) == 0) {
        printf("Error: %s\n", response);
        return -1;
    }

    // Open a file to save the downloaded data
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("fopen() failed");
        return -1;
    }

    // Receive the data from the server and write it to the file
    int bytes_received;
    while ((bytes_received = recv(client_socket, response, BUFFER_SIZE, 0)) > 0) {
        fwrite(response, 1, bytes_received, file);
    }

    // Close the file
    fclose(file);

    // Close the socket
    close(client_socket);

    return 0;
}