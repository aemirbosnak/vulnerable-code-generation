//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define COMMAND_SIZE 10

int connect_to_server(char* ip_address, int port);
bool send_command(int sockfd, char* command);
bool receive_response(int sockfd, char* response);
void print_menu();
void get_input(char* input, int size);
int get_port_number();
void parse_input(char* input, char* command, char* argument);
bool authenticate_user(int sockfd);
void download_file(int sockfd, char* filename);
void upload_file(int sockfd, char* filename);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s IP_ADDRESS\n", argv[0]);
        exit(1);
    }

    char* ip_address = argv[1];
    int port_number = get_port_number();

    int sockfd = connect_to_server(ip_address, port_number);
    if (sockfd == -1) {
        printf("Failed to connect to server\n");
        exit(1);
    }

    if (!authenticate_user(sockfd)) {
        printf("Authentication failed\n");
        exit(1);
    }

    printf("Welcome to the FTP client\n");

    while (true) {
        print_menu();
        char input[COMMAND_SIZE + BUFFER_SIZE];
        get_input(input, COMMAND_SIZE + BUFFER_SIZE);

        char command[COMMAND_SIZE];
        char argument[BUFFER_SIZE];
        parse_input(input, command, argument);

        if (strcmp(command, "quit") == 0) {
            send_command(sockfd, "QUIT");
            char response[BUFFER_SIZE];
            receive_response(sockfd, response);
            printf("%s", response);
            break;
        } else if (strcmp(command, "get") == 0) {
            download_file(sockfd, argument);
        } else if (strcmp(command, "put") == 0) {
            upload_file(sockfd, argument);
        } else {
            printf("Invalid command\n");
        }
    }

    close(sockfd);
    return 0;
}

int connect_to_server(char* ip_address, int port) {
    struct sockaddr_in server_addr;

    //Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return -1;
    }

    //Set server address
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    //Connect to server
    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        return -1;
    }

    return sockfd;
}

bool send_command(int sockfd, char* command) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "%s\r\n", command);

    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        return false;
    }

    return true;
}

bool receive_response(int sockfd, char* response) {
    int bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    if (bytes_received == -1) {
        return false;
    }

    response[bytes_received] = '\0';
    return true;
}

void print_menu() {
    printf("\n---FTP CLIENT MENU---\n");
    printf("Commands: get, put, quit\n");
    printf("Enter command followed by filename (e.g. get file.txt)\n");
}

void get_input(char* input, int size) {
    printf("> ");
    fgets(input, size, stdin);
    input[strcspn(input, "\n")] = '\0';
}

int get_port_number() {
    int port_number;
    printf("Enter port number: ");
    scanf("%d", &port_number);
    getchar(); //Consume newline character
    return port_number;
}

void parse_input(char* input, char* command, char* argument) {
    //Get command
    int i = 0;
    while (input[i] != ' ' && input[i] != '\0') {
        command[i] = input[i];
        i++;
    }
    command[i] = '\0';

    //Get argument
    if (input[i] == ' ') {
        i++;
        int j = 0;
        while (input[i] != '\0') {
            argument[j] = input[i];
            i++;
            j++;
        }
        argument[j] = '\0';
    } else {
        argument[0] = '\0';
    }
}

bool authenticate_user(int sockfd) {
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];

    printf("Enter username: ");
    get_input(username, BUFFER_SIZE);

    printf("Enter password: ");
    get_input(password, BUFFER_SIZE);

    //Send username and password
    send_command(sockfd, "USER");
    send_command(sockfd, username);
    send_command(sockfd, "PASS");
    send_command(sockfd, password);

    //Check response
    char response[BUFFER_SIZE];
    receive_response(sockfd, response);
    if (strncmp(response, "230", 3) == 0) {
        return true;
    }

    return false;
}

void download_file(int sockfd, char* filename) {
    //Send command
    send_command(sockfd, "RETR");
    send_command(sockfd, filename);

    //Check response
    char response[BUFFER_SIZE];
    receive_response(sockfd, response);
    if (strncmp(response, "550", 3) == 0) {
        printf("File not found on server\n");
        return;
    }

    //Download file
    FILE* file = fopen(filename, "wb");
    int bytes_received;
    char buffer[BUFFER_SIZE];
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }
    fclose(file);

    printf("File %s downloaded from server\n", filename);
}

void upload_file(int sockfd, char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("File not found\n");
        return;
    }

    //Send command
    send_command(sockfd, "STOR");
    send_command(sockfd, filename);

    //Upload file
    int bytes_read;
    char buffer[BUFFER_SIZE];
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        send(sockfd, buffer, bytes_read, 0);
    }
    fclose(file);

    //Check response
    char response[BUFFER_SIZE];
    receive_response(sockfd, response);
    if (strncmp(response, "226", 3) == 0) {
        printf("File %s uploaded to server\n", filename);
    } else {
        printf("Error uploading file %s\n", filename);
    }
}