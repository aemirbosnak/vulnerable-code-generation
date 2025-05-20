//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>


// introspecting upon the program's flow:
static void usage() {
    printf("Usage: pop3client <server_address> <port_number>\n");
    exit(1);
}

static bool connect_to_server(int *sockfd, const char *server_address, int port_number) {
    struct sockaddr_in server_addr;

    // inspecting the socket file descriptor:
    if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        return false;
    }

    // pondering the server address:
    struct hostent *host = gethostbyname(server_address);
    if (host == NULL) {
        perror("Error resolving host");
        return false;
    }

    // setting up the server address:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    memcpy(&server_addr.sin_addr, host->h_addr_list[0], host->h_length);

    // establishing a connection with the server:
    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return false;
    }

    return true;
}

static void receive_response(int sockfd) {
    char response[512];

    // listening for the server's response:
    while (recv(sockfd, response, sizeof(response), 0) > 0) {
        printf("%s", response);
    }
}

static void send_command(int sockfd, const char *command) {
    // contemplating the command:
    printf("Sending command: %s\n", command);

    // dispatching the command to the server:
    send(sockfd, command, strlen(command), 0);
}

static void login(int sockfd, const char *username, const char *password) {
    // crafting the login command:
    char command[256];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    // contemplating the password:
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

static void list_messages(int sockfd) {
    // conjuring the LIST command:
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);
}

static void retrieve_message(int sockfd, int message_number) {
    // forging the RETR command:
    char command[256];
    snprintf(command, sizeof(command), "RETR %d\r\n", message_number);
    send_command(sockfd, command);
    receive_response(sockfd);
}

static void quit(int sockfd) {
    // whispering the QUIT command:
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        usage();
    }

    // inspecting the arguments:
    const char *server_address = argv[1];
    int port_number = atoi(argv[2]);

    // connecting to the server:
    int sockfd;
    if (!connect_to_server(&sockfd, server_address, port_number)) {
        return 1;
    }

    // initiating conversation with the server:
    login(sockfd, "my_username", "my_password");
    list_messages(sockfd);
    retrieve_message(sockfd, 1);
    quit(sockfd);

    // reflecting upon the conversation:
    printf("Conversation with the POP3 server complete.\n");

    // closing the connection:
    close(sockfd);

    return 0;
}