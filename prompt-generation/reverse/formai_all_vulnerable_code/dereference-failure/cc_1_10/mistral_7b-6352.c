//MISTRAL-7B DATASET v1.0 Category: Networking ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_NAME_LEN 50
#define LOVE_LETTER_SIZE 200
#define LOVE_LETTER_FILE "love_letter.txt"

int main(int argc, char *argv[]) {
    int fd, ret;
    char name1[MAX_NAME_LEN], name2[MAX_NAME_LEN], love_letter[LOVE_LETTER_SIZE];

    if (argc != 3) {
        printf("Usage: %s <Name of Lover 1> <Name of Lover 2>\n", argv[0]);
        return 1;
    }

    strcpy(name1, argv[1]);
    strcpy(name2, argv[2]);

    fd = open(LOVE_LETTER_FILE, O_RDONLY);
    if (fd < 0) {
        perror("Error opening love letter file");
        return 1;
    }

    ret = read(fd, love_letter, LOVE_LETTER_SIZE - 1);
    if (ret < 0) {
        perror("Error reading love letter from file");
        close(fd);
        return 1;
    }

    love_letter[ret] = '\0';

    printf("%s dear %s,\n", love_letter, name1);
    printf("%s,\n", name2);
    printf("I have read your name in the stars,\n");
    printf("I have heard your voice in the wind,\n");
    printf("Your love letter has reached me,\n");
    printf("And now I am yours.\n");

    fd = open(LOVE_LETTER_FILE, O_WRONLY | O_TRUNC);
    if (fd < 0) {
        perror("Error opening love letter file for writing");
        close(fd);
        return 1;
    }

    printf("Please write your love letter to %s below:\n", name2);
    scanf("%[^\n]", love_letter);

    ret = write(fd, love_letter, strlen(love_letter) + 1);
    if (ret < 0) {
        perror("Error writing love letter to file");
        close(fd);
        return 1;
    }

    close(fd);

    printf("Your love letter to %s has been saved.\n", name2);

    return 0;
}