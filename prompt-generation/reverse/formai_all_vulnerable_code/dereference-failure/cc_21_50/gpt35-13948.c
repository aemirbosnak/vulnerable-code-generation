//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: relaxed
// In this program, we will build a simple FTP client that can connect to an FTP server, login, and download a file from the server.

// Include necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define constants
#define FTP_PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Define variables
    char buffer[BUFFER_SIZE];
    int control_socket, data_socket, bytes_recv, bytes_sent, conn_status;
    struct sockaddr_in server_addr;
    struct hostent *server_info;

    // Check for required arguments
    if(argc < 3) {
        printf("Usage: %s <host-name> <file-path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get server information
    server_info = gethostbyname(argv[1]);
    if(server_info == NULL) {
        fprintf(stderr, "Error: Could not resolve host %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    bcopy((char *)server_info->h_addr, (char *)&server_addr.sin_addr.s_addr, server_info->h_length);

    // Create control socket
    control_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(control_socket < 0) {
        perror("Error: Could not create socket.");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    conn_status = connect(control_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if(conn_status < 0) {
        perror("Error: Could not connect to server.");
        exit(EXIT_FAILURE);
    }

    // Receive welcome message from server
    bytes_recv = recv(control_socket, buffer, BUFFER_SIZE, 0);
    while(bytes_recv > 0) {
        buffer[bytes_recv] = '\0';
        printf("%s", buffer);
        if(strstr(buffer, "220") != NULL) {
            break;
        }
        bytes_recv = recv(control_socket, buffer, BUFFER_SIZE, 0);
    }

    // Send user name to server
    printf("Enter user name: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    bytes_sent = send(control_socket, buffer, strlen(buffer), 0);
    if(bytes_sent < 0) {
        perror("Error: Could not send user name to server.");
        exit(EXIT_FAILURE);
    }

    // Receive user name confirmation from server
    bytes_recv = recv(control_socket, buffer, BUFFER_SIZE, 0);
    while(bytes_recv > 0) {
        buffer[bytes_recv] = '\0';
        printf("%s", buffer);
        if(strstr(buffer, "331") != NULL) {
            break;
        }
        bytes_recv = recv(control_socket, buffer, BUFFER_SIZE, 0);
    }

    // Send password to server
    printf("Enter password: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    bytes_sent = send(control_socket, buffer, strlen(buffer), 0);
    if(bytes_sent < 0) {
        perror("Error: Could not send password to server.");
        exit(EXIT_FAILURE);
    }

    // Receive login confirmation from server
    bytes_recv = recv(control_socket, buffer, BUFFER_SIZE, 0);
    while(bytes_recv > 0) {
        buffer[bytes_recv] = '\0';
        printf("%s", buffer);
        if(strstr(buffer, "230") != NULL) {
            break;
        }
        bytes_recv = recv(control_socket, buffer, BUFFER_SIZE, 0);
    }

    // Switch to passive mode
    bytes_sent = send(control_socket, "PASV\r\n", 6, 0);
    if(bytes_sent < 0) {
        perror("Error: Could not switch to passive mode.");
        exit(EXIT_FAILURE);
    }

    // Receive port number from server
    bytes_recv = recv(control_socket, buffer, BUFFER_SIZE, 0);
    while(bytes_recv > 0) {
        buffer[bytes_recv] = '\0';
        if(strncmp(buffer, "227", 3) == 0) {
            // Parse port number
            int port1, port2;
            if(sscanf(buffer, "227 Entering Passive Mode (%*d,%*d,%*d,%*d,%d,%d)", &port1, &port2) == 2) {
                // Compute data socket address
                struct sockaddr_in data_addr;
                memset(&data_addr, 0, sizeof(data_addr));
                data_addr.sin_family = AF_INET;
                data_addr.sin_port = htons((port1 * 256) + port2);
                data_addr.sin_addr.s_addr = server_addr.sin_addr.s_addr;

                // Create data socket
                data_socket = socket(AF_INET, SOCK_STREAM, 0);
                if(data_socket < 0) {
                    perror("Error: Could not create data socket.");
                    exit(EXIT_FAILURE);
                }

                // Connect to data socket
                conn_status = connect(data_socket, (struct sockaddr *)&data_addr, sizeof(data_addr));
                if(conn_status < 0) {
                    perror("Error: Could not connect to data socket.");
                    exit(EXIT_FAILURE);
                }
            }
            break;
        }
        bytes_recv = recv(control_socket, buffer, BUFFER_SIZE, 0);
    }

    // Send download command to server
    char filename[BUFFER_SIZE];
    sprintf(filename, "RETR %s", argv[2]);
    bytes_sent = send(control_socket, filename, strlen(filename), 0);
    if(bytes_sent < 0) {
        perror("Error: Could not send download command to server.");
        exit(EXIT_FAILURE);
    }

    // Receive download response from server
    bytes_recv = recv(control_socket, buffer, BUFFER_SIZE, 0);
    while(bytes_recv > 0) {
        buffer[bytes_recv] = '\0';
        printf("%s", buffer);
        if(strstr(buffer, "150") != NULL) {
            break;
        }
        bytes_recv = recv(control_socket, buffer, BUFFER_SIZE, 0);
    }

    // Download file
    FILE *file = fopen(argv[2], "wb");
    if(file == NULL) {
        perror("Error: Could not create local file.");
        exit(EXIT_FAILURE);
    }
    bytes_recv = recv(data_socket, buffer, BUFFER_SIZE, 0);
    while(bytes_recv > 0) {
        fwrite(buffer, bytes_recv, 1, file);
        bytes_recv = recv(data_socket, buffer, BUFFER_SIZE, 0);
    }
    fclose(file);

    // Close data socket
    close(data_socket);

    // Receive download completion message from server
    bytes_recv = recv(control_socket, buffer, BUFFER_SIZE, 0);
    while(bytes_recv > 0) {
        buffer[bytes_recv] = '\0';
        printf("%s", buffer);
        if(strstr(buffer, "226") != NULL) {
            break;
        }
        bytes_recv = recv(control_socket, buffer, BUFFER_SIZE, 0);
    }

    // Send quit command to server
    bytes_sent = send(control_socket, "QUIT\r\n", 6, 0);
    if(bytes_sent < 0) {
        perror("Error: Could not send quit command to server.");
        exit(EXIT_FAILURE);
    }

    // Receive quit response from server
    bytes_recv = recv(control_socket, buffer, BUFFER_SIZE, 0);
    while(bytes_recv > 0) {
        buffer[bytes_recv] = '\0';
        printf("%s", buffer);
        if(strstr(buffer, "221") != NULL) {
            break;
        }
        bytes_recv = recv(control_socket, buffer, BUFFER_SIZE, 0);
    }

    // Close control socket
    close(control_socket);

    // Exit program
    exit(EXIT_SUCCESS);
}