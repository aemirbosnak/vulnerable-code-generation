//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 21
#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void execute_command(int sockfd, const char *command, char *response, size_t response_size) {
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, response, response_size, 0);
    printf("%s", response);
}

void list_files(int sockfd) {
    char response[BUFFER_SIZE];
    execute_command(sockfd, "LIST\r\n", response, sizeof(response));
}

void upload_file(int sockfd, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Could not open file %s for reading.\n", filename);
        return;
    }

    // Prepare to send file
    char response[BUFFER_SIZE];
    execute_command(sockfd, "PASV\r\n", response, sizeof(response));

    // Extract the data connection details from response
    int p1, p2;
    sscanf(response, "%*s %*s %*s %*s %*s %d,%d", &p1, &p2); 
    int data_port = p1 * 256 + p2;

    // Create data socket
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    data_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Error connecting to data socket");
    }

    // Send STOR Command
    char stor_command[BUFFER_SIZE];
    snprintf(stor_command, sizeof(stor_command), "STOR %s\r\n", filename);
    execute_command(sockfd, stor_command, response, sizeof(response));

    // Send file content
    char buffer[BUFFER_SIZE];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        send(data_sockfd, buffer, n, 0);
    }

    fclose(file);
    close(data_sockfd);
    execute_command(sockfd, "QUIT\r\n", response, sizeof(response));
}

void download_file(int sockfd, const char *filename) {
    // Getting data connection details
    char response[BUFFER_SIZE];
    execute_command(sockfd, "PASV\r\n", response, sizeof(response));

    // Extract the data connection details from the response
    int p1, p2;
    sscanf(response, "%*s %*s %*s %*s %*s %d,%d", &p1, &p2);
    int data_port = p1 * 256 + p2;

    // Create data socket
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    data_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Error connecting to data socket");
    }

    // Send RETR Command
    char retr_command[BUFFER_SIZE];
    snprintf(retr_command, sizeof(retr_command), "RETR %s\r\n", filename);
    execute_command(sockfd, retr_command, response, sizeof(response));

    // Write the received data to a file
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Could not open file %s for writing.\n", filename);
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes;
    while ((bytes = recv(data_sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytes, file);
    }

    fclose(file);
    close(data_sockfd);
    execute_command(sockfd, "QUIT\r\n", response, sizeof(response));
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <command> [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *command = argv[2];

    // Creating socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Error opening socket");

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer), 0); // Read welcome message
    printf("%s", buffer);

    // Execute specific command
    if (strcmp(command, "LIST") == 0) {
        list_files(sockfd);
    } else if (strcmp(command, "UPLOAD") == 0 && argc == 4) {
        upload_file(sockfd, argv[3]);
    } else if (strcmp(command, "DOWNLOAD") == 0 && argc == 4) {
        download_file(sockfd, argv[3]);
    } else {
        printf("Invalid command or missing filename\n");
    }

    close(sockfd);
    return 0;
}