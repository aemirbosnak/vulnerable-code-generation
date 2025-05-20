//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 4096
#define POP3_PORT 110

// Function to connect to the POP3 server
int connect_to_pop3_server(const char *host) {
    int sock_fd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Create a new socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error opening socket");
        return -1;
    }

    // Get the host details
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host %s\n", host);
        return -1;
    }

    // Configure the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = *((unsigned long *) server->h_addr);
    server_addr.sin_port = htons(POP3_PORT);

    // Connect to the server
    if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to POP3 server");
        return -1;
    }

    // Read the server response
    char buf[BUF_SIZE];
    recv(sock_fd, buf, sizeof(buf), 0);
    printf("[SERVER] %s", buf);

    return sock_fd;
}

// Function to send a command to the POP3 server
void send_pop3_command(int sock_fd, const char *command) {
    char buf[BUF_SIZE];
    snprintf(buf, sizeof(buf), "%s\r\n", command);
    send(sock_fd, buf, strlen(buf), 0);
}

// Function to parse the response from the POP3 server
int parse_pop3_response(char *response) {
    char *p = strtok(response, " \r\n");
    if (p == NULL) {
        return -1;
    }
    int response_code = atoi(p);
    return response_code;
}

// Function to print the message headers and body
void print_message(char *headers, char *body) {
    printf("%s\n\n%s\n", headers, body);
}

int main() {
    // Connect to the POP3 server
    int sock_fd = connect_to_pop3_server("pop.example.com");
    if (sock_fd < 0) {
        fprintf(stderr, "Error connecting to POP3 server");
        exit(1);
    }

    // Send the username
    send_pop3_command(sock_fd, "USER username");

    // Read the response
    char buf[BUF_SIZE];
    recv(sock_fd, buf, sizeof(buf), 0);
    printf("[SERVER] %s", buf);

    // Send the password
    send_pop3_command(sock_fd, "PASS password");

    // Read the response
    recv(sock_fd, buf, sizeof(buf), 0);
    printf("[SERVER] %s", buf);

    // Send the list command to get the message list
    send_pop3_command(sock_fd, "LIST");

    // Read the response
    recv(sock_fd, buf, sizeof(buf), 0);
    printf("[SERVER] %s", buf);

    // Parse the response and get the number of messages
    int num_messages = 0;
    int response_code = parse_pop3_response(buf);
    if (response_code == 110) {
        char *p = strtok(buf, " \r\n");
        while ((p = strtok(NULL, " \r\n")) != NULL) {
            num_messages++;
        }
    }

    // Print the number of messages
    printf("Total messages: %d\n", num_messages);

    // Loop through each message and print the headers and body
    for (int i = 1; i <= num_messages; i++) {
        // Send the retr command to get the message contents
        char command[BUF_SIZE];
        snprintf(command, sizeof(command), "RETR %d", i);
        send_pop3_command(sock_fd, command);

        // Read the response
        recv(sock_fd, buf, sizeof(buf), 0);
        printf("[SERVER] %s", buf);

        // Parse the response and get the message size
        int message_size = 0;
        response_code = parse_pop3_response(buf);
        if (response_code == 110) {
            char *p = strtok(buf, " \r\n");
            p = strtok(NULL, " \r\n");
            message_size = atoi(p);
        }

        // Allocate memory for the message contents
        char *message = (char *) malloc(message_size * sizeof(char));

        // Read the message contents
        int bytes_read = 0;
        int total_bytes_read = 0;
        while ((bytes_read = recv(sock_fd, message + total_bytes_read, message_size - total_bytes_read, 0)) > 0) {
            total_bytes_read += bytes_read;
            if (total_bytes_read >= message_size) {
                break;
            }
        }

        // Find the end of the headers
        char *headers_end = strstr(message, "\r\n\r\n");
        if (headers_end == NULL) {
            fprintf(stderr, "Error parsing message headers");
            continue;
        }

        // Null-terminate the headers and copy to a new buffer
        *headers_end = '\0';
        char *headers = (char *) malloc(strlen(message) + 1);
        strncpy(headers, message, strlen(message) + 1);

        // Find the start of the body
        char *body_start = headers_end + 4;

        // Print the message headers and body
        print_message(headers, body_start);

        // Free memory
        free(headers);
        free(message);
    }

    // Send the quit command to close the connection
    send_pop3_command(sock_fd, "QUIT");

    // Read the response
    recv(sock_fd, buf, sizeof(buf), 0);
    printf("[SERVER] %s", buf);

    // Close the socket
    close(sock_fd);

    return 0;
}