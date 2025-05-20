//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: safe
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 21
#define BUFFER_SIZE 1024

int create_connection(char *ip)
{
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("Error: Failed to create socket!");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: Failed to connect to server!");
        return -1;
    }

    return sock;
}

int receive_response(int sock, char *output)
{
    char buffer[BUFFER_SIZE];
    int num_bytes = 0;
    int total_bytes = 0;
    int retry_count = 0;

    memset(buffer, 0, sizeof(buffer));
    memset(output, 0, sizeof(output));

    // set socket to non-blocking mode
    fcntl(sock, F_SETFL, O_NONBLOCK);

    while (retry_count < 3) {
        num_bytes = recv(sock, buffer, BUFFER_SIZE, 0);

        if (num_bytes < 0) {
            if (total_bytes == 0) {
                perror("Error: Failed to receive response from server!");
                return -1;
            }
            break; // exit loop if buffer is empty
        }

        total_bytes += num_bytes;

        if (total_bytes >= sizeof(output)) {
            break;
        }

        strcat(output, buffer);

        if (strstr(output, "\r\n") != NULL) {
            break; // exit loop if end of line is found
        }

        memset(buffer, 0, sizeof(buffer));
    }

    return 0;
}

int send_command(int sock, char *command)
{
    int num_bytes;

    num_bytes = send(sock, command, strlen(command), 0);

    if (num_bytes < 0) {
        perror("Error: Failed to send command to server!");
        return -1;
    }

    return 0;
}

int main()
{
    char ip[] = "127.0.0.1";
    int sock;
    char command[BUFFER_SIZE];
    char output[BUFFER_SIZE];

    // connect to server
    sock = create_connection(ip);

    if (sock < 0) {
        return -1;
    }

    // receive welcome message
    receive_response(sock, output);
    printf("%s", output);

    // login
    sprintf(command, "USER username\r\n");
    send_command(sock, command);
    receive_response(sock, output);
    printf("%s", output);

    sprintf(command, "PASS password\r\n");
    send_command(sock, command);
    receive_response(sock, output);
    printf("%s", output);

    // change to binary mode
    sprintf(command, "TYPE I\r\n");
    send_command(sock, command);
    receive_response(sock, output);
    printf("%s", output);

    // download file
    sprintf(command, "RETR file.txt\r\n");
    send_command(sock, command);
    receive_response(sock, output);
    printf("%s", output);

    // receive file data
    FILE *file;
    file = fopen("file.txt", "wb");

    while (1) {
        int num_bytes = recv(sock, output, BUFFER_SIZE, 0);

        if (num_bytes < 0) {
            perror("Error: Failed to receive file data from server!");
            return -1;
        }

        if (num_bytes == 0) {
            break; // exit loop if file transfer is complete
        }

        fwrite(output, 1, num_bytes, file);
    }

    fclose(file);

    // log out
    sprintf(command, "QUIT\r\n");
    send_command(sock, command);
    receive_response(sock, output);
    printf("%s", output);

    close(sock);

    return 0;
}