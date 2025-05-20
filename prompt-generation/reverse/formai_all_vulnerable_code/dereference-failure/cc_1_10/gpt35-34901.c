//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 8192

int open_socket(char *host, int port);
int receive(int socket, char *buffer, int buffer_size);
int send_command(int socket, char *command);
void clear_buffer(char *buffer, int buffer_size);
void display_response(char *buffer);

int main(int argc, char *argv[])
{
    char *host = argv[1];
    int port = atoi(argv[2]);
    char username[64];
    char password[64];
    char buffer[MAX_BUFFER_SIZE];

    // connect to server
    int socket = open_socket(host, port);
    if (socket == -1) {
        printf("Error: could not connect to server\n");
        return 1;
    }

    // send login command
    printf("Enter username: ");
    scanf("%s", username);
    sprintf(buffer, "LOGIN %s ", username);
    printf("Enter password: ");
    scanf("%s", password);
    strcat(buffer, password);
    strcat(buffer, "\r\n");
    send_command(socket, buffer);
    receive(socket, buffer, MAX_BUFFER_SIZE);
    display_response(buffer);

    // send list command to retrieve list of mailbox folders
    send_command(socket, "LIST \"\" *\r\n");
    receive(socket, buffer, MAX_BUFFER_SIZE);
    display_response(buffer);

    // send select command to choose specific mailbox folder
    char mailbox[64];
    printf("Enter mailbox folder name: ");
    scanf("%s", mailbox);
    sprintf(buffer, "SELECT \"%s\"\r\n", mailbox);
    send_command(socket, buffer);
    receive(socket, buffer, MAX_BUFFER_SIZE);
    display_response(buffer);

    // send search command to retrieve messages in mailbox
    send_command(socket, "SEARCH ALL\r\n");
    receive(socket, buffer, MAX_BUFFER_SIZE);
    display_response(buffer);

    // send logout command to terminate connection
    send_command(socket, "LOGOUT\r\n");
    receive(socket, buffer, MAX_BUFFER_SIZE);
    display_response(buffer);

    // close socket
    close(socket);

    return 0;
}

int open_socket(char *host, int port)
{
    struct hostent *he;
    struct sockaddr_in server_address;
    int socket_desc;

    if ((he = gethostbyname(host)) == NULL) {
        return -1;
    }

    if ((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(server_address.sin_zero), '\0', 8);

    if (connect(socket_desc, (struct sockaddr *)&server_address, sizeof(struct sockaddr)) == -1) {
        return -1;
    }

    return socket_desc;
}

int receive(int socket, char *buffer, int buffer_size)
{
    clear_buffer(buffer, buffer_size);
    int bytes_received = recv(socket, buffer, buffer_size, 0);
    if (bytes_received == -1) {
        return -1;
    }
    else {
        return bytes_received;
    }
}

int send_command(int socket, char *command)
{
    int bytes_sent = send(socket, command, strlen(command), 0);
    if (bytes_sent == -1) {
        return -1;
    }
    else {
        return bytes_sent;
    }
}

void clear_buffer(char *buffer, int buffer_size)
{
    memset(buffer, 0, buffer_size);
}

void display_response(char *buffer)
{
    printf("%s", buffer);
}