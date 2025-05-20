//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
/*
* This is a simple POP3 client implementation in C.
* The program connects to a POP3 server, authenticate the user with provided credentials
* and retrieves the latest email message from the mailbox.
* The retrieved email message is then printed to the standard output.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFF_SIZE   1024

// Helper function to print error messages and exit
void die(const char* message) {
    perror(message);
    exit(1);
}

// Helper function to receive data from a socket
int receive_data(int sock_fd, char* buff, int buff_len) {
    int bytes_received = 0;
    while (bytes_received < buff_len) {
        int n = recv(sock_fd, buff + bytes_received, buff_len - bytes_received, 0);
        if (n == -1) {
            die("recv failed.");
        } else if (n == 0) {
            // The server has closed the connection
            break;
        }
        bytes_received += n;
    }
    return bytes_received;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_addr> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char* server_addr = argv[1];
    const char* username = argv[2];
    const char* password = argv[3];

    // Create a TCP socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        die("socket creation failed.");
    }

    // Resolve the server address
    struct hostent* server = gethostbyname(server_addr);
    if (server == NULL) {
        die("failed to resolve server address.");
    }

    // Build the server address structure
    struct sockaddr_in server_addr_in;
    memset(&server_addr_in, 0, sizeof(server_addr_in));
    server_addr_in.sin_family = AF_INET;
    server_addr_in.sin_port = htons(110);
    memcpy(&server_addr_in.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sock_fd, (struct sockaddr*)&server_addr_in, sizeof(server_addr_in)) == -1) {
        die("failed to connect to server.");
    }

    // Receive the server greeting message
    char buff[MAX_BUFF_SIZE];
    int bytes_received = receive_data(sock_fd, buff, sizeof(buff) - 1);
    if (bytes_received == 0) {
        fprintf(stderr, "error: server closed the connection.\n");
        exit(1);
    }
    buff[bytes_received] = '\0';
    printf("%s\n", buff);

    // Send the user credentials to the server
    char user_cmd[MAX_BUFF_SIZE];
    sprintf(user_cmd, "USER %s\r\n", username);
    int bytes_sent = send(sock_fd, user_cmd, strlen(user_cmd), 0);
    if (bytes_sent == -1) {
        die("failed to send USER command.");
    }

    char pass_cmd[MAX_BUFF_SIZE];
    sprintf(pass_cmd, "PASS %s\r\n", password);
    bytes_sent = send(sock_fd, pass_cmd, strlen(pass_cmd), 0);
    if (bytes_sent == -1) {
        die("failed to send PASS command.");
    }

    // Receive the server response to the USER and PASS commands
    bytes_received = receive_data(sock_fd, buff, sizeof(buff) - 1);
    if (bytes_received == 0) {
        fprintf(stderr, "error: server closed the connection.\n");
        exit(1);
    }
    buff[bytes_received] = '\0';
    printf("%s\n", buff);

    // Send the RETR command to retrieve the latest email message
    const char* retr_cmd = "RETR 1\r\n";
    bytes_sent = send(sock_fd, retr_cmd, strlen(retr_cmd), 0);
    if (bytes_sent == -1) {
        die("failed to send RETR command.");
    }

    // Receive the email message from the server
    bytes_received = receive_data(sock_fd, buff, sizeof(buff) - 1);
    if (bytes_received == 0) {
        fprintf(stderr, "error: server closed the connection.\n");
        exit(1);
    }
    buff[bytes_received] = '\0';
    printf("%s\n", buff);

    // Close the socket
    close(sock_fd);

    return 0;
}