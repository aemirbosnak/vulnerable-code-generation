//FormAI DATASET v1.0 Category: Email Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void secure_clear(char *string, size_t length) {
    volatile char *pointer = string;
    while (length--) {
        *pointer++ = 0;
    }
}

void paranoid_copy(char *source, char *destination, size_t length) {
    memset(destination, 0, length);
    strncpy(destination, source, length - 1);
    secure_clear(source, length);
}

int main(int argc, char *argv[]) {

    if (argc < 4) {
        printf("Usage: email_client <from_address> <to_address> <message>\n");
        exit(1);
    }

    char from_address[BUFFER_SIZE];
    paranoid_copy(argv[1], from_address, BUFFER_SIZE);

    char to_address[BUFFER_SIZE];
    paranoid_copy(argv[2], to_address, BUFFER_SIZE);

    char message[BUFFER_SIZE];
    paranoid_copy(argv[3], message, BUFFER_SIZE);

    // check for suspicious characters in email addresses
    char *suspicious_chars = "<>@;:";
    if (strpbrk(from_address, suspicious_chars) != NULL ||
        strpbrk(to_address, suspicious_chars) != NULL) {
        printf("Suspicious characters detected in email addresses\n");
        exit(1);
    }

    // set up secure password prompt
    char password[BUFFER_SIZE];
    memset(password, 0, BUFFER_SIZE);
    printf("Enter email account password:\n");
    fflush(stdout);
    ssize_t password_length = read(STDIN_FILENO, password, BUFFER_SIZE);
    if (password_length <= 0) {
        printf("Error: password not entered\n");
        exit(1);
    }
    password[--password_length] = '\0';

    // securely clear password from memory after use
    sleep(3);
    secure_clear(password, password_length);

    printf("Sending email from \"%s\" to \"%s\"\n", from_address, to_address);
    printf("Message:\n%s\n", message);

    return 0;
}