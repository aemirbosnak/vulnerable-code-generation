//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_EMAILS 100
#define BUFFER_SIZE 1024

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

char *receive_response(int sock) {
    char *response = malloc(BUFFER_SIZE);
    recv(sock, response, BUFFER_SIZE - 1, 0);
    response[BUFFER_SIZE - 1] = '\0';
    return response;
}

void connect_to_server(const char *host, int port, int *sock) {
    struct sockaddr_in server_addr;
    struct hostent *host_info;

    host_info = gethostbyname(host);
    *sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host_info->h_addr, host_info->h_length);

    connect(*sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
}

void login_to_imap(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    sprintf(command, "A001 LOGIN %s %s\r\n", username, password);
    send_command(sock, command);
    char *response = receive_response(sock);
    printf("Response: %s\n", response);
    free(response);
}

void list_emails(int sock) {
    char command[BUFFER_SIZE];

    sprintf(command, "A002 LIST \"\" \"*\"\r\n");
    send_command(sock, command);
    char *response = receive_response(sock);
    printf("List of Emails:\n%s\n", response);
    free(response);
}

void fetch_email(int sock, const char *message_number) {
    char command[BUFFER_SIZE];

    sprintf(command, "A003 FETCH %s BODY[]\r\n", message_number);
    send_command(sock, command);
    char *response = receive_response(sock);
    printf("Fetched Email:\n%s\n", response);
    free(response);
}

void logout_from_imap(int sock) {
    send_command(sock, "A004 LOGOUT\r\n");
    free(receive_response(sock));
}

int main() {
    int sock;
    const char *host = "imap.example.com"; // Replace with your IMAP server
    const char *username = "your_username@example.com"; // Your IMAP username
    const char *password = "your_password"; // Your IMAP password
    char message_number[10];

    connect_to_server(host, 993, &sock);
    printf("Connected to IMAP server on a romantic journey...\n");

    login_to_imap(sock, username, password);

    list_emails(sock);

    printf("Enter the message number to fetch: ");
    fgets(message_number, sizeof(message_number), stdin);
    strtok(message_number, "\n"); // Remove trailing newline
    fetch_email(sock, message_number);
    
    logout_from_imap(sock);

    close(sock);
    printf("Goodbye, dear friend. Until we meet again...\n");
    return 0;
}