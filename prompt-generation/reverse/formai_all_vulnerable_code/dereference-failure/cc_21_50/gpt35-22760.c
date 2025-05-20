//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: minimalist
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE] = {0};
    char username[BUFFER_SIZE] = {0};
    char password[BUFFER_SIZE] = {0};
    char command[BUFFER_SIZE] = {0};
    char filename[BUFFER_SIZE] = {0};

    if(argc != 3) {
        printf("Usage: %s <IP ADDRESS> <PORT NUMBER>\n", argv[0]);
        return -1;
    }

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&server_address, '0', sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));

    if(inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if(connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    while(1) {
        printf("Username: ");
        fgets(username, BUFFER_SIZE, stdin);
        printf("Password: ");
        fgets(password, BUFFER_SIZE, stdin);

        if(strchr(username, '\n')) {
            *strchr(username, '\n') = 0;
        }

        if(strchr(password, '\n')) {
            *strchr(password, '\n') = 0;
        }

        sprintf(buffer, "%s %s", username, password);
        send(sock, buffer, strlen(buffer), 0);

        valread = read(sock, buffer, BUFFER_SIZE);
        buffer[valread] = '\0';
        if(!strcmp(buffer, "Login Successful!")) {
            printf("%s\n", buffer);
            break;
        } else {
            printf("%s\n", buffer);
        }
    }

    while(1) {
        memset(&command, '\0', sizeof(command));
        printf("FTP> ");
        fgets(command, BUFFER_SIZE, stdin);

        if(strchr(command, '\n')) {
            *strchr(command, '\n') = 0;
        }

        if(!strcmp(command, "quit")) {
            printf("Exiting...\n");
            send(sock, "quit", strlen("quit"), 0);
            break;
        } else if(!strcmp(command, "ls")) {
            send(sock, "ls", strlen("ls"), 0);
            valread = read(sock, buffer, BUFFER_SIZE);
            buffer[valread] = '\0';
            printf("%s\n", buffer);
        } else if(isalpha(command[0])) {
            sscanf(command, "%s %s", filename, command);
            if(!strcmp(command, "get")) {
                send(sock, command, strlen(command), 0);
                valread = read(sock, buffer, BUFFER_SIZE);
                buffer[valread] = '\0';
                if(!strcmp(buffer, "READY")) {
                    send(sock, filename, strlen(filename), 0);
                    valread = read(sock, buffer, BUFFER_SIZE);
                    buffer[valread] = '\0';
                    if(!strcmp(buffer, "FILE NOT FOUND")) {
                        printf("%s\n", buffer);
                    } else {
                        FILE *fp = fopen(filename, "w");
                        if(fp == NULL) {
                            printf("Error opening file.\n");
                        } else {
                            char buf[1024];
                            while((valread = read(sock, buf, sizeof(buf))) > 0) {
                                fwrite(buf, sizeof(char), valread, fp);
                            }
                            fclose(fp);
                            printf("%s\n", buffer);
                        }
                    }
                } else {
                    printf("%s\n", buffer);
                }
            } else if(!strcmp(command, "put")) {
                FILE *fp = fopen(filename, "r");
                if(fp == NULL) {
                    printf("Error opening file.\n");
                } else {
                    send(sock, command, strlen(command), 0);
                    valread = read(sock, buffer, BUFFER_SIZE);
                    buffer[valread] = '\0';
                    if(!strcmp(buffer, "READY")) {
                        send(sock, filename, strlen(filename), 0);
                        while(fgets(buffer, BUFFER_SIZE, fp)) {
                            send(sock, buffer, strlen(buffer), 0);
                        }
                        fclose(fp);
                        valread = read(sock, buffer, BUFFER_SIZE);
                        buffer[valread] = '\0';
                        printf("%s\n", buffer);
                    } else {
                        printf("%s\n", buffer);
                    }
                }
            } else {
                printf("Command not found.\n");
            }
        } else {
            printf("Command not found.\n");
        }
    }

    close(sock);
    return 0;
}