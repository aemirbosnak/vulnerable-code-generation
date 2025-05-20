//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define IMAP_PORT 143 // IMAP server port number
#define MAX_BUFFER_SIZE 1024 // max buffer size for IMAP commands

void check_response(char* response) {
    if(response == NULL) {
        fprintf(stderr, "Server error: NULL response received.\n");
        exit(1);
    }
    if(response[0] == 'NO' || response[0] == 'BAD') {
        fprintf(stderr, "Server error: %s\n", response);
        exit(1);
    }
}

char* receive_response(int sock_fd) {
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    recv(sock_fd, buffer, sizeof(buffer), 0);
    return strdup(buffer);
}

void send_command(int sock_fd, char* command) {
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "%s\r\n", command);
    int len = strlen(buffer);
    int ret = send(sock_fd, buffer, len, 0);
    if(ret < len) {
        fprintf(stderr, "Server error: command sending failed.\n");
        exit(1);
    }
    printf("SENT: %s", buffer);
}

int main(int argc, char** argv) {
    char* imap_server = "imap.gmail.com";
    char* username = "example@gmail.com";
    char* password = "mypassword";
    int sock_fd;
    struct hostent* host;
    struct sockaddr_in server_address;
    char* response;

    // Connect to IMAP server
    host = gethostbyname(imap_server);
    if(host == NULL) {
        fprintf(stderr, "Error: Could not resolve host.\n");
        exit(1);
    }
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1) {
        fprintf(stderr, "Error: Socket creation failed.\n");
        exit(1);
    }
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(IMAP_PORT);
    memcpy(&server_address.sin_addr, host->h_addr_list[0], host->h_length);
    if(connect(sock_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error: Connection to IMAP server failed.\n");
        exit(1);
    }
    // receive connection response
    response = receive_response(sock_fd);
    check_response(response);
    printf("RECV: %s", response);

    // send login command
    char* login_cmd = "LOGIN %s %s";
    char login_buffer[MAX_BUFFER_SIZE];
    memset(login_buffer, 0, sizeof(login_buffer));
    sprintf(login_buffer, login_cmd, username, password);
    send_command(sock_fd, login_buffer);

    // receive login response
    response = receive_response(sock_fd);
    check_response(response);
    printf("RECV: %s", response);

    // send select inbox command
    char* select_inbox_cmd = "SELECT INBOX";
    send_command(sock_fd, select_inbox_cmd);

    // receive select inbox response
    response = receive_response(sock_fd);
    check_response(response);
    printf("RECV: %s", response);

    // send fetch all command
    char* fetch_all_cmd = "FETCH 1:* ALL";
    send_command(sock_fd, fetch_all_cmd);

    // receive fetch all response
    response = receive_response(sock_fd);
    check_response(response);
    printf("RECV: %s", response);

    // close connection
    send_command(sock_fd, "LOGOUT");
    response = receive_response(sock_fd); // ignore logout response
    close(sock_fd);
    return 0;
}