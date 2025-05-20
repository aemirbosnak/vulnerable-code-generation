//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: active
// Building an Active FTP Client in C

// Required Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

// Constants
#define FTP_PORT 21
#define BUF_SIZE 1024

// Function Declarations
int connect_to_server(char *host, char *port);
void send_command(int sock, char *cmd);
char *receive_response(int sock);
void download_file(int sock, char *filename);

// Main Function
int main(int argc, char *argv[]) {
    // Check Arguments
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Connect to the FTP Server
    int sock = connect_to_server(argv[1], argv[2]);

    // Send a USER command
    send_command(sock, "USER anonymous");

    // Receive the response
    char *response = receive_response(sock);
    printf("%s\n", response);

    // Send a PASS command
    send_command(sock, "PASS guest");

    // Receive the response
    response = receive_response(sock);
    printf("%s\n", response);

    // Send a TYPE command
    send_command(sock, "TYPE I");

    // Receive the response
    response = receive_response(sock);
    printf("%s\n", response);

    // Download a File
    download_file(sock, "README.txt");

    // Close the Connection
    close(sock);

    return 0;
}

// Connects to the FTP Server
int connect_to_server(char *host, char *port) {
    // Create a Socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Resolve the Hostname
    struct hostent *host_entry = gethostbyname(host);
    if (host_entry == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Set the Server Address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    memcpy(&server_addr.sin_addr, host_entry->h_addr_list[0], host_entry->h_length);

    // Connect to the Server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Sends a Command to the Server
void send_command(int sock, char *cmd) {
    // Send the Command
    if (send(sock, cmd, strlen(cmd), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Send a CRLF
    if (send(sock, "\r\n", 2, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

// Receives a Response from the Server
char *receive_response(int sock) {
    // Create a Buffer for the Response
    char buf[BUF_SIZE];

    // Receive the Response
    if (recv(sock, buf, BUF_SIZE - 1, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Terminate the Response
    buf[strlen(buf)] = '\0';

    // Return the Response
    return buf;
}

// Downloads a File from the Server
void download_file(int sock, char *filename) {
    // Send a RETR command
    send_command(sock, "RETR README.txt");

    // Receive the File
    FILE *fp = fopen("README.txt", "wb");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char buf[BUF_SIZE];
    while (1) {
        int bytes_received = recv(sock, buf, BUF_SIZE, 0);
        if (bytes_received == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        if (bytes_received == 0) {
            break;
        }
        fwrite(buf, 1, bytes_received, fp);
    }

    // Close the File
    fclose(fp);
}