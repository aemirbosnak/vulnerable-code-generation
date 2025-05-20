//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void reverseString(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int isPalindrome(char *str, int start, int end) {
    if (start >= end) {
        return 1;
    }

    if (tolower(str[start]) != tolower(str[end])) {
        return 0;
    }

    return isPalindrome(str, start + 1, end - 1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fileSize;
    char *fileContent = malloc(sizeof(char) * (fileSize + 1));

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    fileSize = read(fd, fileContent, sizeof(char) * fileSize);
    close(fd);

    fileContent[fileSize] = '\0';

    printf("Original String: %s\n", fileContent);

    reverseString(fileContent, 0, fileSize - 1);

    printf("Reversed String: %s\n", fileContent);

    if (isPalindrome(fileContent, 0, fileSize - 1)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    free(fileContent);

    return 0;
}