//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUFFER_SIZE 1024  // Maximum buffer size to be read or sent

// Function to connect to the FTP server
int connect_to_server(char *ip_address, int port_number) {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);    // Creating a TCP socket
    if (sock_fd < 0) {
        perror("socket() error");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &(server_address.sin_addr));

    if (connect(sock_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("connect() error");
        exit(1);
    }

    return sock_fd;    // Returning the socket file descriptor
}

// Function to receive response from the server
int get_response(int sock_fd, char *buffer) {
    int num_bytes = recv(sock_fd, buffer, MAX_BUFFER_SIZE, 0);
    if (num_bytes < 0) {
        perror("recv() error");
        exit(1);
    }

    buffer[num_bytes] = '\0';    // Adding the null terminator to the end of the string
    printf("%s", buffer);    // Displaying the response

    return atoi(buffer);    // Converting the response code to integer and returning
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <IP_address> <port_number>\n", argv[0]);
        exit(1);
    }

    int sock_fd = connect_to_server(argv[1], atoi(argv[2]));    // Connecting to the FTP server
    char buffer[MAX_BUFFER_SIZE];    // Buffer to store the response

    // Receiving the welcome message from the server upon connecting
    int welcome_code = get_response(sock_fd, buffer);
    if (welcome_code != 220) {
        exit(1);
    }

    // Logging in to the server with user name and password
    printf("Username: ");
    char username[MAX_BUFFER_SIZE], password[MAX_BUFFER_SIZE];
    scanf("%s", username);
    write(sock_fd, "USER ", 5);
    write(sock_fd, username, strlen(username));
    write(sock_fd, "\r\n", 2);
    int response_code = get_response(sock_fd, buffer);
    if (response_code != 331) {
        exit(1);
    }

    printf("Password: ");
    scanf("%s", password);
    write(sock_fd, "PASS ", 5);
    write(sock_fd, password, strlen(password));
    write(sock_fd, "\r\n", 2);
    response_code = get_response(sock_fd, buffer);
    if (response_code != 230) {
        exit(1);
    }

    // Implement your FTP client here with various commands
    // Sample code to download a file
    write(sock_fd, "TYPE I\r\n", strlen("TYPE I\r\n"));    // Setting transfer mode to Binary
    response_code = get_response(sock_fd, buffer);
    if (response_code != 200) {
        exit(1);
    }

    write(sock_fd, "PASV\r\n", strlen("PASV\r\n"));    // Entering passive mode
    response_code = get_response(sock_fd, buffer);
    if (response_code != 227) {
        exit(1);
    }

    // Parsing the IP address and port number for the data connection
    int a, b, c, d, e, f;
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &a, &b, &c, &d, &e, &f);
    char data_address[MAX_BUFFER_SIZE];
    sprintf(data_address, "%d.%d.%d.%d", a, b, c, d);
    int data_port = (e * 256) + f;
    int data_sock_fd = connect_to_server(data_address, data_port);    // Creating a data socket

    write(sock_fd, "RETR sample_file.txt\r\n", strlen("RETR sample_file.txt\r\n"));    // Retrieving sample_file.txt
    response_code = get_response(sock_fd, buffer);
    if (response_code != 150) {
        exit(1);
    }

    FILE *fp = fopen("sample_file.txt", "wb");    // Opening the file to write the received data
    int num_bytes_read;
    while ((num_bytes_read = recv(data_sock_fd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), num_bytes_read, fp);    // Writing the received data to the file
    }

    fclose(fp);    // Closing the file
    close(data_sock_fd);    // Closing the data socket
    get_response(sock_fd, buffer);    // Getting the transfer completed response
    get_response(sock_fd, buffer);    // Getting the download complete response

    close(sock_fd);    // Closing the control socket
    return 0;
}