//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <fcntl.h>

#define FTP_SERVER_PORT 21
#define BUFFER_SIZE 4096

typedef struct {
    int control_socket;
    int data_socket;
    char hostname[256];
    char username[256];
    char password[256];
} FTPClient;

// Function to create a socket to connect to the server
int create_socket(const char *hostname, int port) {
    int sock;
    struct sockaddr_in server_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(hostname, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Function to send commands to the FTP server
void send_command(FTPClient *client, const char *command) {
    send(client->control_socket, command, strlen(command), 0);
}

// Function to receive replies from the FTP server
void receive_reply(FTPClient *client) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    bytes_received = recv(client->control_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive from server");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';  // Null terminate the string
    printf("%s", buffer);
}

// Function to login to the FTP server
void ftp_login(FTPClient *client) {
    snprintf(client->username, sizeof(client->username), "USER %s\r\n", "your_username");
    snprintf(client->password, sizeof(client->password), "PASS %s\r\n", "your_password");

    send_command(client, client->username);
    receive_reply(client);
    send_command(client, client->password);
    receive_reply(client);
}

// Function to set up the data connection for file transfer
void setup_data_connection(FTPClient *client) {
    // Send PASV command to server and receive IP/port
    send_command(client, "PASV\r\n");
    receive_reply(client);

    // Extract IP address and port number from the reply (this is simplified)
    // Here you would normally need to parse the response to get the correct IP and port
    // For simplicity, using fixed values
    client->data_socket = create_socket("127.0.0.1", 1025);  // example values
}

// Function to download a file from the FTP server
void ftp_download(FTPClient *client, const char *filename) {
    setup_data_connection(client);
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    send_command(client, command);
    receive_reply(client);

    // Receive the file data
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    if (file_descriptor < 0) {
        perror("Failed to open file");
        return;
    }

    while ((bytes_received = recv(client->data_socket, buffer, sizeof(buffer), 0)) > 0) {
        write(file_descriptor, buffer, bytes_received);
    }

    close(file_descriptor);
    close(client->data_socket);
}

// Function to close the FTP client and quit
void ftp_close(FTPClient *client) {
    send_command(client, "QUIT\r\n");
    receive_reply(client);
    close(client->control_socket);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FTPClient client;
    strcpy(client.hostname, argv[1]);
    strcpy(client.username, argv[2]);
    strcpy(client.password, argv[3]);
    
    client.control_socket = create_socket(client.hostname, FTP_SERVER_PORT);
    receive_reply(&client);
    
    ftp_login(&client);
    ftp_download(&client, "example.txt");  // Replace with the actual file to download
    
    ftp_close(&client);

    return 0;
}