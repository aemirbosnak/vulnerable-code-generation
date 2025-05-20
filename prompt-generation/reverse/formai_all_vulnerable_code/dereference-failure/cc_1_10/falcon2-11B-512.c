//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 110
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int socket_fd, ret;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];
    char command[100];

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Error creating socket");
        return -1;
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    ret = connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        perror("Error connecting to server");
        return -1;
    }

    // Send the login command
    sprintf(command, "USER %s\r\n", "your_username");
    ret = write(socket_fd, command, strlen(command));
    if (ret == -1) {
        perror("Error sending command");
        return -1;
    }

    // Send the password command
    sprintf(command, "PASS %s\r\n", "your_password");
    ret = write(socket_fd, command, strlen(command));
    if (ret == -1) {
        perror("Error sending command");
        return -1;
    }

    // Send the CAPA command
    sprintf(command, "CAPA\r\n");
    ret = write(socket_fd, command, strlen(command));
    if (ret == -1) {
        perror("Error sending command");
        return -1;
    }

    // Read the CAPA response
    ret = read(socket_fd, buffer, MAX_BUFFER_SIZE);
    if (ret == -1) {
        perror("Error reading response");
        return -1;
    }

    // Check for CAPA capabilities
    if (strstr(buffer, "TOP")) {
        printf("Server supports TOP\n");
    } else {
        printf("Server does not support TOP\n");
    }

    // Send the LIST command
    sprintf(command, "LIST\r\n");
    ret = write(socket_fd, command, strlen(command));
    if (ret == -1) {
        perror("Error sending command");
        return -1;
    }

    // Read the LIST response
    ret = read(socket_fd, buffer, MAX_BUFFER_SIZE);
    if (ret == -1) {
        perror("Error reading response");
        return -1;
    }

    // Print the message headers
    printf("%s", buffer);

    // Close the socket
    close(socket_fd);

    return 0;
}