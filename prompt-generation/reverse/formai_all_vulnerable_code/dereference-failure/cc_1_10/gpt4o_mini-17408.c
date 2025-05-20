//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdbool.h>

#define PORT 993
#define BUFFER_SIZE 2048

void romanticConnectionError(const char *message) {
    fprintf(stderr, "Alas, the connection could not be established: %s\n", message);
}

void tenderSend(int socket, const char *message) {
    send(socket, message, strlen(message), 0);
}

void sweetReceive(int socket, char *buffer, size_t size) {
    memset(buffer, 0, size);
    recv(socket, buffer, size - 1, 0);
}

bool enchantingAuthenticate(int socket, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];
  
    // Send the AUTHENTICATE command
    snprintf(buffer, sizeof(buffer), "a001 LOGIN %s %s\r\n", username, password);
    tenderSend(socket, buffer);
  
    sweetReceive(socket, buffer, sizeof(buffer));
    printf("%s", buffer);

    return strstr(buffer, "OK") != NULL;
}

void heavenlyListEmails(int socket) {
    char buffer[BUFFER_SIZE];

    // Request for email list
    tenderSend(socket, "a002 LIST \"\" \"*\"\r\n");
    sweetReceive(socket, buffer, sizeof(buffer));
  
    printf("Here is the list of our love letters:\n%s", buffer);
}

void affectionateFetchEmail(int socket, const char *emailNumber) {
    char buffer[BUFFER_SIZE];

    // Request for a specific email
    snprintf(buffer, sizeof(buffer), "a003 FETCH %s BODY[]\r\n", emailNumber);
    tenderSend(socket, buffer);
  
    sweetReceive(socket, buffer, sizeof(buffer));
    printf("Our romantic message:\n%s\n", buffer);
}

void heartwarmingDisconnect(int socket) {
    tenderSend(socket, "a004 LOGOUT\r\n");
    close(socket);
    printf("Until next time, dear heart.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
  
    int socket_fd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Talent of enlightenment, let us find the host
    if ((host = gethostbyname(hostname)) == NULL) {
        romanticConnectionError("Could not resolve hostname.");
        return EXIT_FAILURE;
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        romanticConnectionError("Could not create socket.");
        return EXIT_FAILURE;
    }

    // Our love's embrace, let us connect
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        romanticConnectionError("Could not connect to server.");
        close(socket_fd);
        return EXIT_FAILURE;
    }

    // A gentle kiss of authentication
    if (enchantingAuthenticate(socket_fd, username, password)) {
        printf("We've unlocked the gates to our love's secrets.\n");
        heavenlyListEmails(socket_fd);
      
        char emailNum[5];
        printf("Which promise shall we fetch? (Enter email number): ");
        fgets(emailNum, sizeof(emailNum), stdin);
        emailNum[strcspn(emailNum, "\n")] = 0; // Remove newline character

        affectionateFetchEmail(socket_fd, emailNum);
    } else {
        printf("The passwords between us are not aligned.\n");
    }

    heartwarmingDisconnect(socket_fd);
    return EXIT_SUCCESS;
}