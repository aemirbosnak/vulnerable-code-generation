//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_NUM 1000

void factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    printf("Factorial of %d is %d\n", n, result);
}

int main() {
    char input[MAX_NUM + 1];
    int num;

    printf("Enter a number: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input buffer
    int len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    num = atoi(input);

    if (num < 0 || num > MAX_NUM) {
        printf("Invalid number. Exiting...\n");
        return 1;
    }

    pid_t child = fork();

    if (child == 0) { // Child process
        factorial(num);
        exit(0);
    } else { // Parent process
        int status;
        waitpid(child, &status, 0);

        if (WIFEXITED(status)) {
            if (WEXITSTATUS(status) != 0) {
                printf("Error in factorial calculation. Exiting...\n");
                return 1;
            }
        } else {
            printf("Error occurred during calculation. Exiting...\n");
            return 1;
        }
    }

    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd < 0) {
        perror("Error opening output file");
        return 1;
    }

    dprintf(fd, "Factorial of %d is:\n", num);
    factorial(num);
    fclose(fd);

    printf("Factorial calculation completed successfully!\n");
    return 0;
}