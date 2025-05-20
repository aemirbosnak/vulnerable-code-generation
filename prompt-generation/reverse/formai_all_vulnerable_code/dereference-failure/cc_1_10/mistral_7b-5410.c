//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_LINES 1000
#define PASSWORD_LENGTH 10

char password[PASSWORD_LENGTH];
char eBook[MAX_LINES][1024];
int linesRead = 0;

void readFile(char *filename) {
    int fd;
    char line[1024];

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    while (fgets(line, sizeof(line), fd) != NULL) {
        strcpy(eBook[linesRead], line);
        linesRead++;
    }

    close(fd);
}

void printBook() {
    int i;

    printf("\n--- Start of eBook ---\n");
    for (i = 0; i < linesRead; i++) {
        printf("%s", eBook[i]);
    }
    printf("\n--- End of eBook ---\n");
}

void checkPassword(char *input) {
    int i;

    for (i = 0; i < PASSWORD_LENGTH && input[i] != '\0'; i++) {
        if (input[i] != password[i]) {
            printf("Incorrect password!\n");
            exit(1);
        }
    }

    printf("Password correct!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ebook.txt>\n", argv[0]);
        exit(1);
    }

    strcpy(password, "password12345"); // Change this to your desired password

    readFile(argv[1]);

    printf("Enter password to view eBook:\n");
    scanf("%s", password);

    checkPassword(password);

    printBook();

    return 0;
}