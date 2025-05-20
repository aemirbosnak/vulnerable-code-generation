//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define BUFFER_SIZE 1024
#define COMMAND_SIZE 100
#define FILE_NAME_SIZE 100

void error(char* message) {
    perror(message);
    exit(1);
}

void send_file(int socket, char* file_name) {
    char buffer[BUFFER_SIZE];
    ssize_t num_read;
    int file;
    size_t sent_size = 0;
    struct stat file_stat;

    file = open(file_name, O_RDONLY);
    if (file == -1) {
        error("Error opening file");
    }

    if (fstat(file, &file_stat) < 0) {
        error("Error fstat");
    }

    sprintf(buffer, "%ld", file_stat.st_size);
    if (send(socket, buffer, BUFFER_SIZE, 0) == -1) {
        error("Error sending file size");
    }

    while ((num_read = read(file, buffer, BUFFER_SIZE)) > 0) {
        if (send(socket, buffer, num_read, 0) == -1) {
            error("Error sending file");
        }
        sent_size += num_read;
    }

    printf("File sent successfully\n");

    close(file);
}

void receive_file(int socket, char* file_name) {
    char buffer[BUFFER_SIZE];
    ssize_t num_read;
    int file;
    size_t received_size = 0;
    size_t file_size;

    if ((num_read = recv(socket, buffer, BUFFER_SIZE, 0)) <= 0) {
        error("Error receiving file size");
    }

    file_size = atoi(buffer);
    file = open(file_name, O_CREAT | O_WRONLY, 0666);
    if (file == -1) {
        error("Error creating file");
    }

    while (received_size < file_size) {
        if ((num_read = recv(socket, buffer, BUFFER_SIZE, 0)) <= 0) {
            error("Error receiving file");
        }

        if (write(file, buffer, num_read) == -1) {
            error("Error writing to file");
        }

        received_size += num_read;
    }

    printf("File received successfully\n");

    close(file);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("usage: %s server_address server_port\n", argv[0]);
        exit(1);
    }

    int socket_fd;
    struct sockaddr_in server_addr;
    char command[COMMAND_SIZE];
    char file_name[FILE_NAME_SIZE];
    int command_code;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        error("Error creating socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(socket_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        error("Error connecting to server");
    }

    while (1) {
        printf("Enter command: ");
        fgets(command, COMMAND_SIZE, stdin);
        strtok(command, "\n");

        if (strcmp(command, "exit") == 0) {
            break;
        }

        command_code = 0;
        if (strncmp(command, "put", 3) == 0) {
            command_code = 1;
            sscanf(command + 4, "%s", file_name);
        } else if (strncmp(command, "get", 3) == 0) {
            command_code = 2;
            sscanf(command + 4, "%s", file_name);
        } else {
            printf("Invalid command\n");
            continue;
        }

        if (send(socket_fd, &command_code, sizeof(int), 0) == -1) {
            error("Error sending command code");
        }

        if (command_code == 1) {
            send_file(socket_fd, file_name);
        } else if (command_code == 2) {
            receive_file(socket_fd, file_name);
        }
    }

    close(socket_fd);

    return 0;
}