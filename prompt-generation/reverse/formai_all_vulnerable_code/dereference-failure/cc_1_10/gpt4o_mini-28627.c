//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <pthread.h>

#define IMAP_PORT 143
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    char username[100];
    char password[100];
} ImapClient;

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void *receive_message(void *arg) {
    ImapClient *client = (ImapClient *)arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        int n = recv(client->socket, buffer, BUFFER_SIZE - 1, 0);
        if (n <= 0) {
            break; // Connection closed or error
        }
        
        buffer[n] = '\0'; // Null-terminate received string
        printf("Server: %s\n", buffer); // Echo received data
    }
    
    return NULL;
}

void send_command(ImapClient *client, const char *command) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    send(client->socket, buffer, strlen(buffer), 0); // Send command to server
    printf("Client: %s", buffer); // Show sent command
}

void authenticate(ImapClient *client) {
    char command[200];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s", client->username, client->password);
    send_command(client, command);
    // Here you would want to handle the server's response to the login command
}

void fetch_emails(ImapClient *client) {
    send_command(client, "A002 SELECT INBOX");
    send_command(client, "A003 FETCH 1:* (ENVELOPE)");
    // Handle the responses accordingly to parse the emails
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    ImapClient client;
    strncpy(client.username, username, sizeof(client.username) - 1);
    strncpy(client.password, password, sizeof(client.password) - 1);

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return EXIT_FAILURE;
    }

    client.socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client.socket < 0) {
        error("ERROR opening socket");
    }

    struct sockaddr_in serv_addr;
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(IMAP_PORT);

    if (connect(client.socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting to server");
    }
    
    pthread_t recv_thread;
    pthread_create(&recv_thread, NULL, receive_message, (void *)&client);

    authenticate(&client); // Authenticate to the IMAP server
    fetch_emails(&client); // Fetching emails

    // Join thread and clean up
    pthread_join(recv_thread, NULL);

    close(client.socket);
    return EXIT_SUCCESS;
}