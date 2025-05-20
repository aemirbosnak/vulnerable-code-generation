//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT 993 // IMAP over SSL is usually on 993

// Function declarations
int create_socket(char *host, int port);
void *receive_messages(void *sock);
void user_login(int sock, char *username, char *password);
void list_mailboxes(int sock);
void fetch_email(int sock, const char *email_id);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <IMAP Server> <Username> <Password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sock = create_socket(server, PORT);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    pthread_t recv_thread;
    pthread_create(&recv_thread, NULL, receive_messages, (void *)&sock);
    
    user_login(sock, username, password);
    list_mailboxes(sock);

    pthread_join(recv_thread, NULL);
    close(sock);
    return 0;
}

int create_socket(char *host, int port) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    
    host_info = gethostbyname(host);
    if (host_info == NULL) {
        fprintf(stderr, "Couldn't resolve host: %s\n", host);
        return -1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Cannot create socket");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }
    
    return sock;
}

void *receive_messages(void *sock) {
    int socket = *(int *)sock;
    char buffer[BUF_SIZE];
    while (1) {
        memset(buffer, 0, BUF_SIZE);
        int bytes_received = recv(socket, buffer, BUF_SIZE - 1, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Received: %s\n", buffer);
    }
    return NULL;
}

void user_login(int sock, char *username, char *password) {
    char command[BUF_SIZE];
    sprintf(command, "A001 LOGIN %s %s\r\n", username, password);
    send(sock, command, strlen(command), 0);
    // We could wait for a response here, omitted for brevity.
}

void list_mailboxes(int sock) {
    char command[BUF_SIZE];
    sprintf(command, "A002 LIST \"\" *\r\n");
    send(sock, command, strlen(command), 0);
}

void fetch_email(int sock, const char *email_id) {
    char command[BUF_SIZE];
    sprintf(command, "A003 FETCH %s *\r\n", email_id);
    send(sock, command, strlen(command), 0);
}