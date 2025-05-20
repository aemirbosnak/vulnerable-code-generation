//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFF_SIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, port, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFF_SIZE];

    // Check if all necessary arguments are provided
    if (argc < 3) {
        printf("ERROR: Enter hostname and port numeber.\n");
        exit(1);
    }

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR: Unable to create server socket.");

    // Clear the buffer
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // Get the port number from argument
    port = atoi(argv[2]);

    // Set the address and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
        error("ERROR: Invalid hostname.");

    // Connect to the server FTP port (21)
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR: Connecting to server failed.");

    // Get the response from server
    bzero(buffer, BUFF_SIZE);
    n = read(sockfd, buffer, BUFF_SIZE - 1);
    if (n < 0)
        error("ERROR: Reading from server failed.");

    // Print the server response
    printf("%s", buffer);

    // Login to the FTP server with username and password
    char username[BUFF_SIZE], password[BUFF_SIZE];
    printf("Username: ");
    fgets(username, BUFF_SIZE, stdin);
    printf("Password: ");
    fgets(password, BUFF_SIZE, stdin);

    // Send the username and password to the server
    char login_command[BUFF_SIZE];
    snprintf(login_command, sizeof login_command, "USER %s", username);
    write(sockfd, login_command, strlen(login_command));
    bzero(buffer, BUFF_SIZE);
    n = read(sockfd, buffer, BUFF_SIZE - 1);
    if (n < 0)
        error("ERROR: Reading from server failed.");
    printf("%s", buffer);

    snprintf(login_command, sizeof login_command, "PASS %s", password);
    write(sockfd, login_command, strlen(login_command));
    bzero(buffer, BUFF_SIZE);
    n = read(sockfd, buffer, BUFF_SIZE - 1);
    if (n < 0)
        error("ERROR: Reading from server failed.");
    printf("%s", buffer);

    // Set the transfer mode to binary
    write(sockfd, "TYPE I", 6);
    bzero(buffer, BUFF_SIZE);
    n = read(sockfd, buffer, BUFF_SIZE - 1);
    if (n < 0)
        error("ERROR: Reading from server failed.");
    printf("%s", buffer);

    // Enter passive mode
    write(sockfd, "PASV", 4);
    bzero(buffer, BUFF_SIZE);
    n = read(sockfd, buffer, BUFF_SIZE - 1);
    if (n < 0)
        error("ERROR: Reading from server failed.");
    printf("%s", buffer);

    // Parse the IP and port from the PASV response
    int p1, p2, p3, p4, port1, port2;
    sscanf(strchr(buffer, '(')+1, "%d,%d,%d,%d,%d,%d", &p1, &p2, &p3, &p4, &port1, &port2);

    // Connect to the data port of the server
    int data_sockfd;
    struct sockaddr_in data_addr;
    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0)
        error("ERROR: Unable to create data socket.");

    bzero((char *) &data_addr, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons((port1 * 256) + port2);
    data_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0)
        error("ERROR: Connecting to server data port failed.");

    // Get the file name from user and open the file
    char filename[BUFF_SIZE];
    printf("Enter file name: ");
    fgets(filename, BUFF_SIZE, stdin);
    strtok(filename, "\n");

    int filefd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (filefd < 0)
        error("ERROR: Unable to create file.");

    // Request server to send the file
    char retr_command[BUFF_SIZE];
    snprintf(retr_command, sizeof retr_command, "RETR %s", filename);
    write(sockfd, retr_command, strlen(retr_command));
    bzero(buffer, BUFF_SIZE);
    n = read(sockfd, buffer, BUFF_SIZE - 1);
    if (n < 0)
        error("ERROR: Reading from server failed.");
    printf("%s", buffer);

    // Read the file data from the data port and write to the file
    while ((n = read(data_sockfd, buffer, BUFF_SIZE)) > 0) {
        if (write(filefd, buffer, n) < 0)
            error("ERROR: Writing to file failed.");
    }

    close(filefd);
    close(data_sockfd);
    close(sockfd);

    return 0;
}