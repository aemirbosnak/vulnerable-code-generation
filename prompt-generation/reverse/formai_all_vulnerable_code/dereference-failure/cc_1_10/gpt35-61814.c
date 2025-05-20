//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFFER_LENGTH 1024 // Maximum FTP buffer length
#define MAX_FILENAME_LENGTH 256 // Maximum length of filename
#define MAX_COMMAND_LENGTH 256 // Maximum length of FTP command
#define MAX_REPLY_LENGTH 1024 // Maximum length of FTP reply message

int setup_data_socket(int socket_control) {
    char buffer[BUFFER_LENGTH];
    int data_socket;
    struct sockaddr_in server_address;

    memset(&server_address, 0, sizeof(server_address));

    // Send PASV command to server
    send(socket_control, "PASV\r\n", strlen("PASV\r\n"), 0);

    // Get PASV response from the server
    if (recv(socket_control, buffer, BUFFER_LENGTH, 0) < 0) {
        perror("Error receiving data from server\n");
        return -1;
    }

    // Parse PASV response to get server IP and port
    int ip_1, ip_2, ip_3, ip_4, port_1, port_2;
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)\n", &ip_1, &ip_2, &ip_3, &ip_4, &port_1, &port_2);

    // Set up server address for data connection
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl((ip_1 << 24) | (ip_2 << 16) | (ip_3 << 8) | ip_4);
    server_address.sin_port = htons((port_1 << 8) | port_2);

    // Create data socket
    if ((data_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket for data connection\n");
        return -1;
    }

    // Connect to server using the data socket
    if (connect(data_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server via data socket\n");
        return -1;
    }

    return data_socket;
}

int main(int argc, char **argv) {
    char buffer[BUFFER_LENGTH], command[MAX_COMMAND_LENGTH], filename[MAX_FILENAME_LENGTH], reply[MAX_REPLY_LENGTH];
    int data_socket, bytes_received;
    long long file_size = 0;

    // Check number of arguments
    if (argc != 4) {
        printf("Usage: ftp_client <server_address> <server_port> <filename>\n");
        return -1;
    }

    // Set up control socket
    int socket_control = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_control < 0) {
        perror("Error creating socket for control connection\n");
        return -1;
    }

    // Set up server address for control connection
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        perror("Error converting server address to binary form\n");
        return -1;
    }

    // Connect to server using the control socket
    if (connect(socket_control, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server via control socket\n");
        return -1;
    }

    // Get initial greeting message from server
    if (recv(socket_control, buffer, BUFFER_LENGTH, 0) < 0) {
        perror("Error receiving greeting message from server\n");
        return -1;
    }

    // Send user and password
    send(socket_control, "USER anonymous\r\n", strlen("USER anonymous\r\n"), 0);
    recv(socket_control, buffer, BUFFER_LENGTH, 0);
    send(socket_control, "PASS anonymous\r\n", strlen("PASS anonymous\r\n"), 0);
    recv(socket_control, buffer, BUFFER_LENGTH, 0);

    // Request file size for given filename
    sprintf(command, "SIZE %s\r\n", argv[3]);
    send(socket_control, command, strlen(command), 0);
    if (recv(socket_control, reply, MAX_REPLY_LENGTH, 0) < 0) {
        perror("Error receiving file size from server\n");
        return -1;
    }
    sscanf(reply, "213 %lld", &file_size);

    // Request file transfer from server
    sprintf(command, "RETR %s\r\n", argv[3]);
    send(socket_control, command, strlen(command), 0);
    if (recv(socket_control, reply, MAX_REPLY_LENGTH, 0) < 0) {
        perror("Error receiving remote file from server\n");
        return -1;
    }

    // Set up data connection
    if ((data_socket = setup_data_socket(socket_control)) < 0) {
        perror("Error setting up data socket\n");
        return -1;
    }

    // Open local file for writing
    int local_file = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (local_file < 0) {
        perror("Error opening local file for writing\n");
        return -1;
    }

    // Receive data from server and write to local file
    while ((bytes_received = read(data_socket, buffer, BUFFER_LENGTH)) > 0) {
        write(local_file, buffer, bytes_received);
    }

    // Close local file and data socket
    close(local_file);
    close(data_socket);

    printf("File transfer complete. %lld bytes received.\n", file_size);

    return 0;
}