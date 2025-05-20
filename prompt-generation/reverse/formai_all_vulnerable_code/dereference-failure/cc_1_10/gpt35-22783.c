//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 2048
#define MAX_FILE_LENGTH 4096

int connect_to_server(char * server_address, int port_number);
int get_command(char * command);

int main(int argc, char * argv[])
{
    if (argc != 3) {
        printf("Usage: %s SERVER_ADDRESS PORT_NUMBER\n", argv[0]);
        exit(1);
    }

    char * server_address = argv[1];
    int port_number = atoi(argv[2]);
    int sockfd = connect_to_server(server_address, port_number);

    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    char file_data[MAX_FILE_LENGTH];
    int bytes_read, bytes_written, file_size;

    while (1) {
        memset(command, 0, MAX_COMMAND_LENGTH);
        memset(response, 0, MAX_RESPONSE_LENGTH);
        bytes_read = get_command(command);

        if (bytes_read == -1) {
            printf("Error reading command\n");
            continue;
        }

        // Send command to server
        bytes_written = send(sockfd, command, bytes_read, 0);

        if (bytes_written == -1 || bytes_written != bytes_read) {
            printf("Error sending command to server\n");
            continue;
        }

        // Receive response from server
        bytes_read = recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);

        if (bytes_read == -1) {
            printf("Error receiving response from server\n");
            continue;
        }

        // Handle response
        if (strncmp(response, "error", 5) == 0) {
            printf("Server error: %s\n", response + 6);
            continue;
        }

        if (strncmp(command, "get", 3) == 0) {
            file_size = atoi(response);
            memset(file_data, 0, MAX_FILE_LENGTH);

            // Receive file data from server
            while (file_size > 0 && bytes_read > 0) {
                bytes_read = recv(sockfd, file_data, MAX_FILE_LENGTH, 0);

                if (bytes_read == -1) {
                    printf("Error receiving file data from server\n");
                    break;
                }

                // Write file data to stdout
                bytes_written = write(STDOUT_FILENO, file_data, bytes_read);

                if (bytes_written == -1 || bytes_written != bytes_read) {
                    printf("Error writing file data to stdout\n");
                    break;
                }

                file_size -= bytes_read;
            }
        }
        else {
            printf("%s", response);
        }
    }

    close(sockfd);
    return 0;
}

int connect_to_server(char * server_address, int port_number)
{
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set server address and port number
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(server_address);
    serv_addr.sin_port = htons(port_number);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    return sockfd;
}

int get_command(char * command)
{
    int bytes_read = 0;
    char * prompt = "ftp> ";

    // Print prompt and read user input
    write(STDOUT_FILENO, prompt, strlen(prompt));
    bytes_read = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);

    if (bytes_read > 0 && command[bytes_read - 1] == '\n') {
        command[bytes_read - 1] = '\0';
        bytes_read--;
    }

    return bytes_read;
}