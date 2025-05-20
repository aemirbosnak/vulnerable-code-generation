//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_PORT 993
#define BUFFER_SIZE 1024

void check_error(int retVal, char *errorMsg) {
    if(retVal < 0) {
        perror(errorMsg);
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];

    // Step 1: Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    check_error(client_socket, "Error while creating socket");

    // Step 2: Get server address
    struct hostent *server = gethostbyname("imap.gmail.com");
    check_error(server == NULL ? -1 : 0, "Error while getting server address");

    // Step 3: Define the server address
    struct sockaddr_in server_address;
    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    bcopy((char *)server->h_addr_list[0], (char *)&server_address.sin_addr.s_addr, server->h_length);

    // Step 4: Connect to server
    int status = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    check_error(status, "Error while connecting to server");

    // Step 5: Receive the server greeting
    memset(buffer, 0, BUFFER_SIZE);
    status = read(client_socket, buffer, BUFFER_SIZE-1);
    check_error(status, "Error while reading from server");
    printf("%s\n", buffer);

    // Step 6: Send the login command
    char username[] = "username@gmail.com";
    char password[] = "password";
    char loginCommand[BUFFER_SIZE];
    memset(loginCommand, 0, BUFFER_SIZE);
    sprintf(loginCommand, "a login %s %s\r\n", username, password);
    status = write(client_socket, loginCommand, strlen(loginCommand));
    check_error(status, "Error while writing to server");

    // Step 7: Receive the login response
    memset(buffer, 0, BUFFER_SIZE);
    status = read(client_socket, buffer, BUFFER_SIZE-1);
    check_error(status, "Error while reading from server");
    printf("%s\n", buffer);

    // Step 8: Send the select command
    char selectCommand[] = "a select inbox\r\n";
    status = write(client_socket, selectCommand, strlen(selectCommand));
    check_error(status, "Error while writing to server");

    // Step 9: Receive the select response
    memset(buffer, 0, BUFFER_SIZE);
    status = read(client_socket, buffer, BUFFER_SIZE-1);
    check_error(status, "Error while reading from server");
    printf("%s\n", buffer);

    // Step 10: Send the fetch command
    char fetchCommand[] = "a fetch 1:* (uid flags body[header.fields (subject from)])\r\n";
    status = write(client_socket, fetchCommand, strlen(fetchCommand));
    check_error(status, "Error while writing to server");

    // Step 11: Receive the fetch response
    memset(buffer, 0, BUFFER_SIZE);
    status = read(client_socket, buffer, BUFFER_SIZE-1);
    check_error(status, "Error while reading from server");
    printf("%s\n", buffer);

    // Step 12: Send the logout command
    char logoutCommand[] = "a logout\r\n";
    status = write(client_socket, logoutCommand, strlen(logoutCommand));
    check_error(status, "Error while writing to server");

    // Step 13: Receive the logout response
    memset(buffer, 0, BUFFER_SIZE);
    status = read(client_socket, buffer, BUFFER_SIZE-1);
    check_error(status, "Error while reading from server");
    printf("%s\n", buffer);

    // Step 14: Close the socket
    close(client_socket);

    return 0;
}