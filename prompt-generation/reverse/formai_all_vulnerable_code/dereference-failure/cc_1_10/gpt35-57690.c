//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

void get_file(int sock_fd, char* file_name) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    FILE* file_ptr = fopen(file_name, "w");
    if(file_ptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    memset(buffer, 0, BUFFER_SIZE);
    while((bytes_read = recv(sock_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, file_ptr);
        memset(buffer, 0, BUFFER_SIZE);
    }

    fclose(file_ptr);
}

int main(int argc, char const *argv[]) {
    char* ip_address = argv[1];
    int port_number = atoi(argv[2]);
    char* file_name = argv[3];
    bool successful = false;

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0) {
        printf("Error creating socket.\n");
        return 1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    if(connect(sock_fd, (struct sockaddr*) &server_address, sizeof(server_address)) != 0) {
        printf("Error connecting to server.\n");
        return 1;
    }

    char message_buffer[BUFFER_SIZE];
    memset(message_buffer, 0, BUFFER_SIZE);
    sprintf(message_buffer, "get %s", file_name);

    if(send(sock_fd, message_buffer, sizeof(message_buffer), 0) < 0) {
        printf("Error sending request.\n");
        return 1;
    }

    memset(message_buffer, 0, sizeof(message_buffer));
    if(recv(sock_fd, message_buffer, sizeof(message_buffer), 0) < 0) {
        printf("Error receiving response.\n");
        return 1;
    }

    if(strncmp(message_buffer, "File", 4) == 0) {
        get_file(sock_fd, file_name);
        printf("File successfully transferred.\n");
        successful = true;
    } else {
        printf("File not found or some other error occured.\n");
    }

    close(sock_fd);

    if(successful == true) {
        return 0;
    } else {
        return 1;
    }
}