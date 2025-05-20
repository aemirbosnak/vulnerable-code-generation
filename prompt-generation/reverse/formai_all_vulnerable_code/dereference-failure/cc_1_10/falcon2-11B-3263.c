//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

// Function to establish a TCP connection to the FTP server
int establish_connection(const char* host, const char* port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return -1;
    }

    // Convert host and port to network format
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(port));
    server.sin_addr.s_addr = inet_addr(host);

    // Connect to the FTP server
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) == -1) {
        perror("Connection failed");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

// Function to send a command to the FTP server
int send_command(int sockfd, const char* command) {
    int bytes_sent = write(sockfd, command, strlen(command));
    if (bytes_sent == -1) {
        perror("Write failed");
        return -1;
    }

    return 0;
}

// Function to receive data from the FTP server
int receive_data(int sockfd, char* buffer, int size) {
    int bytes_read = read(sockfd, buffer, size);
    if (bytes_read == -1) {
        perror("Read failed");
        return -1;
    }

    return bytes_read;
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <host> <port> <file>\n", argv[0]);
        return 1;
    }

    int sockfd = establish_connection(argv[1], argv[2]);
    if (sockfd == -1) {
        return 1;
    }

    char command[256];
    sprintf(command, "USER anonymous\r\n");
    send_command(sockfd, command);

    sprintf(command, "PASS %s\r\n", argv[3]);
    send_command(sockfd, command);

    sprintf(command, "TYPE I\r\n");
    send_command(sockfd, command);

    sprintf(command, "CWD /public/images\r\n");
    send_command(sockfd, command);

    int file_size = receive_data(sockfd, &file_size, 4);
    if (file_size == -1) {
        return 1;
    }

    char filename[256];
    sprintf(filename, "%s", argv[3]);
    char* file_ptr = filename;

    char buffer[256];
    while (1) {
        int bytes_read = receive_data(sockfd, buffer, 256);
        if (bytes_read == -1) {
            return 1;
        }

        int bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
        if (bytes_written == -1) {
            perror("Write to stdout failed");
            return 1;
        }

        int next_char = *file_ptr;
        if (next_char == '\0') {
            break;
        }
        file_ptr++;
    }

    close(sockfd);
    return 0;
}