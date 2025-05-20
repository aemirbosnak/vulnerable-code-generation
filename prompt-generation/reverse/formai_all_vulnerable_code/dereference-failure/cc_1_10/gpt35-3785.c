//FormAI DATASET v1.0 Category: Client Server Application ; Style: expert-level
/*
 * This is a client-server application that demonstrates a simple file transfer system.
 *
 * The client connects to the server and requests a file to be transferred. The server checks if the requested
 * file exists, and if it does it sends the file over to the client. If the file does not exist, the server sends
 * an error message to the client.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MAX_FILENAME_LEN 256
#define MAX_FILESIZE 1000000 //1 MB

void die(char *message){
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
        exit(1);
    }

    int server_socket, client_socket, file_size;
    char filename[MAX_FILENAME_LEN], file_buffer[MAX_FILESIZE];
    socklen_t client_length;
    struct sockaddr_in server_address, client_address;

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(atoi(argv[1]));

    // create server socket
    if ((server_socket = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        die("Error: Failed to create server socket.\n");
    }

    // bind server socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        die("Error: Failed to bind server socket to address.\n");
    }

    // listen for incoming connections
    if (listen(server_socket, 1) < 0) {
        die("Error: Failed to listen for incoming connections.\n");
    }

    client_length = sizeof(client_address);

    while (1) {
        // accept incoming connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_length)) < 0) {
            die("Error: Failed to accept incoming connection.\n");
        }

        // receive filename from client
        memset(filename, 0, MAX_FILENAME_LEN);
        if (recv(client_socket, filename, MAX_FILENAME_LEN, 0) < 0) {
            die("Error: Failed to receive filename from client.\n");
        }

        // check if file exists
        int file = open(filename, O_RDONLY);
        if (file < 0) {
            char error_message[] = "Error: File not found.\n";
            if (send(client_socket, error_message, strlen(error_message), 0) < 0) {
                die("Error: Failed to send error message to client.\n");
            }
            close(client_socket);
            continue;
        }

        // get file size
        file_size = lseek(file, 0, SEEK_END);
        lseek(file, 0, SEEK_SET);

        // read file into buffer
        if (read(file, file_buffer, file_size) < 0) {
            die("Error: Failed to read file into buffer.\n");
        }

        // send file to client
        if (send(client_socket, file_buffer, file_size, 0) < 0) {
            die("Error: Failed to send file to client.\n");
        }

        close(file);
        close(client_socket);
    }

    return 0;
}