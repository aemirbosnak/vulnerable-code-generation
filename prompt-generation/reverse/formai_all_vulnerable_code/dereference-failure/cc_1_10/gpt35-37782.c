//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Function: decode_morse_code
// This function will decode morse code and returns the corresponding character.
char decode_morse_code(const char *morse_code) {
    if (strcmp(morse_code, ".-") == 0)
        return 'A';
    else if (strcmp(morse_code, "-...") == 0)
        return 'B';
    else if (strcmp(morse_code, "-.-.") == 0)
        return 'C';
    else if (strcmp(morse_code, "-..") == 0)
        return 'D';
    // [ ... ] too many elifs to add, decoding morse code just with dots and dashes
    else if (strcmp(morse_code, "-.-") == 0)
        return 'K';
    else if (strcmp(morse_code, ".-.") == 0)
        return 'R';
    else if (strcmp(morse_code, "-..-") == 0)
        return 'X';
    else if (strcmp(morse_code, "-.--") == 0)
        return 'Y';
    else if (strcmp(morse_code, "--..") == 0)
        return 'Z';
    return -1;
}

// Function: handle_request
// This function will handle incoming HTTP requests by decoding the morse code in the request header.
void handle_request(int client_socket) {
    char request[2048] = {0};
    char buffer[1];
    while (recv(client_socket, buffer, 1, 0) != -1) {
        strcat(request, buffer);
        if (strstr(request, "\r\n\r\n") != NULL)
            break;  // request header received
    }

    char *morse_code = strstr(request, "Morse-Code:");
    if (morse_code == NULL)
        return;

    morse_code += strlen("Morse-Code: ");
    const size_t morse_code_size = strlen(morse_code) - 2;
    char *morse_code_decoded = calloc(morse_code_size + 1, sizeof(char));
    if (morse_code_decoded == NULL)
        return;

    char *token = strtok(morse_code, " ");
    while (token != NULL) {
        const char c = decode_morse_code(token);
        if (c != -1)
            strcat(morse_code_decoded, &c);
        else
            strcat(morse_code_decoded, " ");
        token = strtok(NULL, " ");
    }

    printf("[+] Incoming request: %s", request);
    printf("[+] Decoded morse code: %s\n", morse_code_decoded);
}

// Function: main
// This function will start the proxy server and accept incoming connections.
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    const int port = atoi(argv[1]);
    if (port <= 0) {
        puts("[ERR] Invalid port");
        return 1;
    }

    const int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        puts("[ERR] Failed to create server socket");
        return 1;
    }

    struct sockaddr_in server_address = {0};
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    const int yes = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
        puts("[ERR] Failed to set server socket options");
        return 1;
    }

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        puts("[ERR] Failed to bind server socket");
        return 1;
    }

    if (listen(server_socket, 5) == -1) {
        puts("[ERR] Failed to listen on server socket");
        return 1;
    }

    printf("[+] Server listening on port %d...\n", port);

    while (1) {
        struct sockaddr_in client_address = {0};
        socklen_t client_address_length = sizeof(client_address);

        const int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket == -1) {
            puts("[ERR] Failed to accept incoming connection");
            continue;
        }

        printf("[+] Incoming connection from %s:%d\n",
               inet_ntoa(client_address.sin_addr),
               ntohs(client_address.sin_port));

        handle_request(client_socket);
        close(client_socket);
    }

    return 0;
}