//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define BUFFER_SIZE 512

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void read_line(int sock, char *buffer, size_t size) {
    memset(buffer, 0, size);
    ssize_t bytes_received = recv(sock, buffer, size - 1, 0);
    if (bytes_received < 0) {
        error_exit("recv failed");
    }
    buffer[bytes_received] = '\0';
}

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

void connect_to_pop3(const char *hostname, int port, int *sock) {
    struct sockaddr_in server_addr;

    *sock = socket(AF_INET, SOCK_STREAM, 0);
    if (*sock < 0) {
        error_exit("socket creation failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(*sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_exit("connection failed");
    }

    char buffer[BUFFER_SIZE];
    read_line(*sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
}

void login(int sock, const char *user, const char *pass) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", user);
    send_command(sock, command);
    char buffer[BUFFER_SIZE];
    read_line(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
    
    snprintf(command, sizeof(command), "PASS %s\r\n", pass);
    send_command(sock, command);
    read_line(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
}

void list_emails(int sock) {
    char command[] = "LIST\r\n";
    send_command(sock, command);
    
    char buffer[BUFFER_SIZE];
    read_line(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
    
    while (1) {
        read_line(sock, buffer, sizeof(buffer));
        if (strncmp(buffer, ".", 1) == 0) {
            break;
        }
        printf("Email Info: %s\n", buffer);
    }
}

void retrieve_email(int sock, int email_id) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d\r\n", email_id);
    send_command(sock, command);

    char buffer[BUFFER_SIZE];
    read_line(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
    
    while (1) {
        read_line(sock, buffer, sizeof(buffer));
        if (strncmp(buffer, ".", 1) == 0) {
            break;
        }
        printf("%s\n", buffer);
    }
}

void disconnect(int sock) {
    send_command(sock, "QUIT\r\n");
    char buffer[BUFFER_SIZE];
    read_line(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sock;
    connect_to_pop3(hostname, POP3_PORT, &sock);
    login(sock, username, password);
    list_emails(sock);
    
    int email_id;
    printf("Enter the email ID you want to retrieve: ");
    scanf("%d", &email_id);
    retrieve_email(sock, email_id);
    
    disconnect(sock);
    return 0;
}