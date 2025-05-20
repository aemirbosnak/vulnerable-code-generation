//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char **argv)
{
        int sockfd, port = 80;
        struct hostent *server;
        struct sockaddr_in serv_addr;
        char buffer[512];

        if (argc < 2) {
                fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
                exit(1);
        }

        if ((server = gethostbyname(argv[1])) == NULL) {
                fprintf(stderr, "Error: Could not resolve hostname %s\n", argv[1]);
                exit(1);
        }

        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                perror("Error: Could not create socket");
                exit(1);
        }

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
                perror("Error: Could not connect to server");
                exit(1);
        }

        while (1) {
                printf("Enter a command (help, scan, quit): ");
                fgets(buffer, sizeof(buffer), stdin);

                if (strcmp(buffer, "help\n") == 0) {
                        printf("Commands:\n");
                        printf("  help: Display this help message\n");
                        printf("  scan: Scan for wireless networks\n");
                        printf("  quit: Quit the program\n");
                } else if (strcmp(buffer, "scan\n") == 0) {
                        printf("Scanning for wireless networks...\n");
                        write(sockfd, "scan\n", strlen("scan\n"));
                        while (read(sockfd, buffer, sizeof(buffer)) > 0) {
                                printf("%s", buffer);
                        }
                } else if (strcmp(buffer, "quit\n") == 0) {
                        printf("Quitting...\n");
                        close(sockfd);
                        exit(0);
                } else {
                        printf("Invalid command. Enter \"help\" for a list of valid commands.\n");
                }
        }

        return 0;
}