//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: puzzling
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

void printError(const char *errorMessage) {
    fprintf(stderr, "Error: %s\n", errorMessage);
}

int connectToServer(const char *serverName, const char *port) {
    struct addrinfo hints, *addressList, *address;
    int socketFd, result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    if ((result = getaddrinfo(serverName, port, &hints, &addressList)) != 0) {
        printError(gai_strerror(result));
        return -1;
    }
    for (address = addressList; address != NULL; address = address->ai_next) {
        if ((socketFd = socket(address->ai_family, address->ai_socktype, address->ai_protocol)) == -1) {
            continue;
        }
        if (connect(socketFd, address->ai_addr, address->ai_addrlen) == -1) {
            close(socketFd);
            continue;
        }
        break;
    }
    freeaddrinfo(addressList);
    if (address == NULL) {
        printError("Failed to connect to server.");
        return -1;
    }
    return socketFd;
}

char *readResponseString(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    char *responseString = malloc(BUFFER_SIZE);
    int responseStringLength = 0;
    int bytesRead;
    do {
        if ((bytesRead = SSL_read(ssl, buffer, BUFFER_SIZE)) == -1) {
            printError(ERR_error_string(ERR_get_error(), NULL));
            free(responseString);
            return NULL;
        }
        memcpy(responseString + responseStringLength, buffer, bytesRead);
        responseStringLength += bytesRead;
    } while (bytesRead == BUFFER_SIZE);
    return responseString;
}

bool sendCommand(SSL *ssl, const char *command) {
    char *commandString = malloc(strlen(command) + 3);
    sprintf(commandString, "%s\r\n", command);
    int commandStringLength = strlen(commandString);
    if (SSL_write(ssl, commandString, commandStringLength) == -1) {
        printError(ERR_error_string(ERR_get_error(), NULL));
        free(commandString);
        return false;
    }
    free(commandString);
    return true;
}

void listMailbox(SSL *ssl) {
    if (!sendCommand(ssl, "LIST \"\" *")) {
        return;
    }
    char *responseString = readResponseString(ssl);
    printf("%s", responseString);
    free(responseString);
}

void examineMailbox(SSL *ssl, const char *mailbox) {
    char command[strlen(mailbox) + 8];
    sprintf(command, "EXAMINE %s", mailbox);
    if (!sendCommand(ssl, command)) {
        return;
    }
    char *responseString = readResponseString(ssl);
    printf("%s", responseString);
    free(responseString);
}

void printMessage(SSL *ssl, const char *mailbox, int messageId) {
    char command[strlen(mailbox) + 3];
    sprintf(command, "FETCH %d BODY[]", messageId);
    if (!sendCommand(ssl, command)) {
        return;
    }
    char *responseString = readResponseString(ssl);
    printf("%s", responseString);
    free(responseString);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printError("Usage: imap_client server port username");
        return 1;
    }
    const char *serverName = argv[1];
    const char *port = argv[2];
    const char *username = argv[3];

    SSL_library_init();
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    OpenSSL_add_all_algorithms();

    SSL_CTX *sslContext = SSL_CTX_new(SSLv23_client_method());
    if (sslContext == NULL) {
        printError(ERR_error_string(ERR_get_error(), NULL));
        return 1;
    }
    SSL *ssl = NULL;

    int socketFd;
    if ((socketFd = connectToServer(serverName, port)) == -1) {
        return 1;
    }

    if ((ssl = SSL_new(sslContext)) == NULL) {
        printError(ERR_error_string(ERR_get_error(), NULL));
        return 1;
    }

    SSL_set_fd(ssl, socketFd);

    if (SSL_connect(ssl) == -1) {
        printError(ERR_error_string(ERR_get_error(), NULL));
        return 1;
    }

    char *responseString = readResponseString(ssl);
    printf("%s", responseString);
    free(responseString);

    if (!sendCommand(ssl, "CAPABILITY")) {
        return 1;
    }
    responseString = readResponseString(ssl);
    printf("%s", responseString);
    free(responseString);

    if (!sendCommand(ssl, "LOGIN \"\"")) {
        return 1;
    }
    responseString = readResponseString(ssl);
    printf("%s", responseString);
    free(responseString);

    if (!sendCommand(ssl, "SELECT INBOX")) {
        return 1;
    }
    responseString = readResponseString(ssl);
    printf("%s", responseString);
    free(responseString);

    listMailbox(ssl);

    examineMailbox(ssl, "INBOX");

    printMessage(ssl, "INBOX", 1);

    if (!sendCommand(ssl, "LOGOUT")) {
        return 1;
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(socketFd);
    SSL_CTX_free(sslContext);
    return 0;
}