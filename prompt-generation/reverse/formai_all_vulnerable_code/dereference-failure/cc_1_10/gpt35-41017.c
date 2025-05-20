//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>

void happy_message() {
    printf("Yay! We're building an FTP client!\n");
    printf("Let's get started with the code!\n\n");
}

int main(int argc, char *argv[]) {
    happy_message();

    // Ensure the user provides at least one argument, which will be the IP address of the FTP server
    if (argc != 2) {
        printf("Please run the program with the IP address of the FTP server as the only argument\n");
        return 1;
    }

    char *ip_address = argv[1];
    printf("The IP address of the FTP server is: %s\n", ip_address);

    // Create a socket for the client
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Failed to create client socket\n");
        return 1;
    }
    printf("Client socket successfully created\n");

    // Convert the IP address string to a binary byte format
    struct in_addr server_address;
    if (inet_pton(AF_INET, ip_address, &server_address) <= 0) {
        perror("Failed to convert IP address to binary format\n");
        return 1;
    }

    // Set up the server address struct with the necessary information
    struct sockaddr_in server_address_struct;
    memset(&server_address_struct, 0, sizeof(server_address_struct));
    server_address_struct.sin_family = AF_INET;
    server_address_struct.sin_addr = server_address;
    server_address_struct.sin_port = htons(21);  // FTP server runs on port 21

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &server_address_struct, sizeof(server_address_struct)) == -1) {
        perror("Failed to connect to FTP server\n");
        return 1;
    }
    printf("Successfully connected to FTP server %s\n", ip_address);

    // Send the initial greeting message to the server
    char message[1024] = {0};
    int message_length = sprintf(message, "USER anonymous\r\n");
    if (send(client_socket, message, message_length, 0) == -1) {
        perror("Failed to send user name to FTP server\n");
        return 1;
    }
    printf("Sent user name to FTP server\n");

    // Receive the response from the server
    char response[1024] = {0};
    if (recv(client_socket, response, sizeof(response), 0) == -1) {
        perror("Failed to receive response from FTP server\n");
        return 1;
    }
    printf("Response: %s", response);

    // Send the password to the server
    message_length = sprintf(message, "PASS happyftpprogram\r\n");
    if (send(client_socket, message, message_length, 0) == -1) {
        perror("Failed to send password to FTP server\n");
        return 1;
    }
    printf("Sent password to FTP server\n");

    // Receive the response from the server
    memset(response, 0, sizeof(response));  // clear the response buffer before receiving a new response
    if (recv(client_socket, response, sizeof(response), 0) == -1) {
        perror("Failed to receive response from FTP server\n");
        return 1;
    }
    printf("Response: %s", response);

    // Send the passive mode command
    message_length = sprintf(message, "PASV\r\n");
    if (send(client_socket, message, message_length, 0) == -1) {
        perror("Failed to send passive mode command to FTP server\n");
        return 1;
    }
    printf("Sent passive mode command to FTP server\n");

    // Receive the response from the server
    memset(response, 0, sizeof(response));  // clear the response buffer before receiving a new response
    if (recv(client_socket, response, sizeof(response), 0) == -1) {
        perror("Failed to receive response from FTP server\n");
        return 1;
    }
    printf("Response: %s", response);

    // Extract the port number from the response and connect to the data port
    char *substring_start = strchr(response, '(') + 1;
    char *substring_end = strchr(response, ')');
    *substring_end = '\0';  // replace ')' with null terminator
    char *substring = substring_start;

    int port_1 = atoi(strsep(&substring, ","));
    int port_2 = atoi(strsep(&substring, ","));

    int data_port = port_1 * 256 + port_2;

    struct sockaddr_in data_address_struct;
    memset(&data_address_struct, 0, sizeof(data_address_struct));
    data_address_struct.sin_family = AF_INET;
    data_address_struct.sin_addr = server_address;
    data_address_struct.sin_port = htons(data_port);

    int data_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (data_socket == -1) {
        perror("Failed to create data socket\n");
        return 1;
    }
    printf("Data socket successfully created\n");

    if (connect(data_socket, (struct sockaddr *) &data_address_struct, sizeof(data_address_struct)) == -1) {
        perror("Failed to connect to data port\n");
        return 1;
    }
    printf("Successfully connected to data port %d\n", data_port);

    // Send the list command to the server
    message_length = sprintf(message, "LIST\r\n");
    if (send(client_socket, message, message_length, 0) == -1) {
        perror("Failed to send list command to FTP server\n");
        return 1;
    }
    printf("Sent list command to FTP server\n");

    // Receive the response from the server
    memset(response, 0, sizeof(response));
    if (recv(client_socket, response, sizeof(response), 0) == -1) {
        perror("Failed to receive response from FTP server\n");
        return 1;
    }
    printf("Response: %s", response);

    // Receive the list of files from the data port
    char file_buffer[1024] = {0};
    while (recv(data_socket, file_buffer, sizeof(file_buffer), 0) > 0) {
        printf("%s", file_buffer);
        memset(file_buffer, 0, sizeof(file_buffer));
    }

    // Close the data socket
    close(data_socket);

    // Send the quit command to the server
    message_length = sprintf(message, "QUIT\r\n");
    if (send(client_socket, message, message_length, 0) == -1) {
        perror("Failed to send quit command to FTP server\n");
        return 1;
    }
    printf("Sent quit command to FTP server\n");

    // Receive the response from the server
    memset(response, 0, sizeof(response));
    if (recv(client_socket, response, sizeof(response), 0) == -1) {
        perror("Failed to receive response from FTP server\n");
        return 1;
    }
    printf("Response: %s", response);

    // Close the client socket
    close(client_socket);

    printf("\n\nHooray! FTP Client program execution completed successfully!\n");

    return 0;
}