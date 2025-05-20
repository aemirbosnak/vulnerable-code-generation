//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *random_string(int length) {
    char *str = (char *) malloc(length + 1);
    if (str == NULL) {
        perror("Memory error");
        exit(1);
    }
    for (int i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[length] = '\0';
    return str;
}

int main(int argc, char **argv) {
    int fd, i, len;
    char *str, *temp;

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Open error");
        exit(1);
    }

    fseek(fd, 0, SEEK_END);
    len = ftell(fd);
    rewind(fd);

    str = (char *) malloc(len + 1);
    if (str == NULL) {
        perror("Memory error");
        exit(1);
    }

    read(fd, str, len);
    close(fd);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '!';
        }
    }

    temp = random_string(len);

    for (i = 0; i < len; i++) {
        if (str[i] != temp[i]) {
            str[i] = temp[i];
        }
    }

    printf("%s\n", str);

    free(str);
    free(temp);

    return 0;
}

void reverse(char *str, int start, int end) {
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void print_binary(unsigned int num) {
    int i;

    printf("%d = ", num);
    for (i = 31; i >= 0; i--) {
        printf("%d", (num >> i & 1));
    }
    printf("\n");
}

int binary_search(int arr[], int size, int key) {
    int low = 0, high = size - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main_menu() {
    int choice;

    printf("\n1. Randomize a file\n");
    printf("2. Reverse a string\n");
    printf("3. Print a number in binary\n");
    printf("4. Binary search\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}