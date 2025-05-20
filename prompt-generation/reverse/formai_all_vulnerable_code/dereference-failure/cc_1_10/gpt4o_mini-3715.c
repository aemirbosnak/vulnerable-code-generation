//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define BUFFER_SIZE 4096
#define MAX_LINE_LENGTH 512

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        handle_error("send failed");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        if (buffer[bytes_received - 1] == '\n')  // Check for end of response
            break;
    }
    
    if (bytes_received < 0) {
        handle_error("recv failed");
    }
}

void login(int control_sock, const char *username, const char *password) {
    char command[MAX_LINE_LENGTH];
    
    // Send USER command
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(control_sock, command);
    receive_response(control_sock);

    // Send PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(control_sock, command);
    receive_response(control_sock);
}

void list_files(int control_sock) {
    send_command(control_sock, "PASV\r\n");
    
    char response[BUFFER_SIZE];
    receive_response(control_sock);
    
    // Here you should parse the response to get the port for data connection
    // Example response: 227 Entering Passive Mode (192,168,1,5,194,47)
    unsigned int p1, p2;
    if (sscanf(response, "227 Entering Passive Mode (%*d,%*d,%*d,%*d,%u,%u)", &p1, &p2) != 2) {
        fprintf(stderr, "Passive mode response not recognized\n");
        return;
    }

    int data_port = p1 * 256 + p2;
    
    // Create a data connection
    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sock < 0) {
        handle_error("socket failed");
    }

    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    // For this example, we assume the server is local; this could also be an IP address extracted from the PASV response

    if (connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        handle_error("connect failed");
    }

    // Ask for a file listing
    send_command(control_sock, "LIST\r\n");
    receive_response(control_sock);
    
    // Receiving the file listing
    receive_response(data_sock);
    
    close(data_sock);
    receive_response(control_sock);
}

void download_file(int control_sock, const char *filename) {
    send_command(control_sock, "PASV\r\n");
    
    char response[BUFFER_SIZE];
    receive_response(control_sock);
    
    unsigned int p1, p2;
    if (sscanf(response, "227 Entering Passive Mode (%*d,%*d,%*d,%*d,%u,%u)", &p1, &p2) != 2) {
        fprintf(stderr, "Passive mode response not recognized\n");
        return;
    }

    int data_port = p1 * 256 + p2;

    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sock < 0) {
        handle_error("socket failed");
    }

    // Using localhost for data connection, adjust accordingly
    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);

    if (connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        handle_error("connect failed");
    }

    // Request file download
    char command[MAX_LINE_LENGTH];
    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    send_command(control_sock, command);
    receive_response(control_sock);

    // Receiving the file
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        handle_error("File opening failed");
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;
    
    while ((bytes_received = recv(data_sock, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytes_received, fp);
    }

    if (bytes_received < 0) {
        handle_error("recv failed");
    }

    fclose(fp);
    close(data_sock);
    receive_response(control_sock);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password> <command>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    const char *command = argv[4];

    int control_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (control_sock < 0) {
        handle_error("socket failed");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21); // FTP port
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(control_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("connect failed");
    }

    // Initial connection response
    receive_response(control_sock);
    
    // Login
    login(control_sock, username, password);

    // Execute command
    if (strcmp(command, "list") == 0) {
        list_files(control_sock);
    } else if (strcmp(command, "download") == 0 && argc == 6) {
        download_file(control_sock, argv[5]);
    } else {
        fprintf(stderr, "Unknown command or incorrect usage.\n");
    }

    // Close control connection
    close(control_sock);
    return EXIT_SUCCESS;
}