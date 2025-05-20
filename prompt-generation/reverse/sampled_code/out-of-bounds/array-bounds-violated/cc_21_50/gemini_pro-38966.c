//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <serial_device>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int serial_fd = open(argv[1], O_RDWR | O_NOCTTY);
    if (serial_fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    struct termios tty;
    if (tcgetattr(serial_fd, &tty) < 0) {
        perror("tcgetattr");
        return EXIT_FAILURE;
    }

    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~(PARENB | PARODD);
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    tty.c_iflag &= ~(INPCK | ISTRIP | IXON | IXOFF);
    tty.c_oflag &= ~OPOST;

    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 0;

    if (tcsetattr(serial_fd, TCSANOW, &tty) < 0) {
        perror("tcsetattr");
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        ssize_t n = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (n < 0) {
            perror("recvfrom");
            continue;
        }

        buffer[n] = '\0';

        if (strcmp(buffer, "takeoff") == 0) {
            printf("Taking off...\n");
            char *command = "takeoff\n";
            write(serial_fd, command, strlen(command));
        } else if (strcmp(buffer, "land") == 0) {
            printf("Landing...\n");
            char *command = "land\n";
            write(serial_fd, command, strlen(command));
        } else if (strcmp(buffer, "left") == 0) {
            printf("Moving left...\n");
            char *command = "left\n";
            write(serial_fd, command, strlen(command));
        } else if (strcmp(buffer, "right") == 0) {
            printf("Moving right...\n");
            char *command = "right\n";
            write(serial_fd, command, strlen(command));
        } else if (strcmp(buffer, "forward") == 0) {
            printf("Moving forward...\n");
            char *command = "forward\n";
            write(serial_fd, command, strlen(command));
        } else if (strcmp(buffer, "backward") == 0) {
            printf("Moving backward...\n");
            char *command = "backward\n";
            write(serial_fd, command, strlen(command));
        } else if (strcmp(buffer, "up") == 0) {
            printf("Moving up...\n");
            char *command = "up\n";
            write(serial_fd, command, strlen(command));
        } else if (strcmp(buffer, "down") == 0) {
            printf("Moving down...\n");
            char *command = "down\n";
            write(serial_fd, command, strlen(command));
        } else if (strcmp(buffer, "flip left") == 0) {
            printf("Flipping left...\n");
            char *command = "flip left\n";
            write(serial_fd, command, strlen(command));
        } else if (strcmp(buffer, "flip right") == 0) {
            printf("Flipping right...\n");
            char *command = "flip right\n";
            write(serial_fd, command, strlen(command));
        } else if (strcmp(buffer, "flip forward") == 0) {
            printf("Flipping forward...\n");
            char *command = "flip forward\n";
            write(serial_fd, command, strlen(command));
        } else if (strcmp(buffer, "flip backward") == 0) {
            printf("Flipping backward...\n");
            char *command = "flip backward\n";
            write(serial_fd, command, strlen(command));
        } else if (strcmp(buffer, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }
    }

    close(serial_fd);
    close(sockfd);

    return EXIT_SUCCESS;
}