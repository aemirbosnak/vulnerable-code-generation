//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

char* read_input(char* prompt);
char* read_file(char* filename);
void send_smtp(int sock, char* msg, char* response);
void smtp_quit(int sock);

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Usage: smtp_client [SERVER_IP] [PORT]\n");
        exit(1);
    }

    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(client_sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if(inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("IP Address not valid");
        exit(1);
    }

    if(connect(client_sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    char response[1024];
    send_smtp(client_sock, "EHLO example.com\r\n", response);

    printf("Connected to server with response: %s", response);

    char* from = read_input("From: ");
    char* to = read_input("To: ");
    char* subject = read_input("Subject: ");
    char* message_file = read_input("Message file: ");

    char* message = read_file(message_file);
    if(message == NULL) {
        printf("Invalid message file\n");
        exit(1);
    }

    char* data = malloc(strlen(from) + strlen(to) + strlen(subject) + strlen(message) + 100);

    sprintf(data, "MAIL FROM: <%s>\r\nRCPT TO: <%s>\r\nDATA\r\nFrom: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, from, to, subject, message);

    send_smtp(client_sock, data, response);

    printf("Sent message with response: %s", response);

    smtp_quit(client_sock);
    close(client_sock);

    free(from);
    free(to);
    free(subject);
    free(message_file);
    free(message);
    free(data);

    return 0;
}

char* read_input(char* prompt) {
    printf("%s", prompt);
    char* input = malloc(1024);
    fgets(input, 1024, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    return input;
}

char* read_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        return NULL;
    }

    fseek(file, 0L, SEEK_END);
    long length = ftell(file);
    fseek(file, 0L, SEEK_SET);

    char* buffer = malloc(length + 1);
    if(buffer == NULL) {
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, length, file);
    fclose(file);

    buffer[length] = '\0';

    return buffer;
}

void send_smtp(int sock, char* msg, char* response) {
    if(send(sock, msg, strlen(msg), 0) < 0) {
        perror("Failed to send message");
        exit(1);
    }

    if(recv(sock, response, 1024, 0) < 0) {
        perror("Failed to receive response");
        exit(1);
    }
}

void smtp_quit(int sock) {
    char response[1024];
    send_smtp(sock, "QUIT\r\n", response);
}