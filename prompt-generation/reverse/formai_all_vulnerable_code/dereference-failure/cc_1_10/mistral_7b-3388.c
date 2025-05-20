//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Morse code array
const char morse[][4] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

// Function to print Morse code for a character
void print_morse(char ch) {
    int index = isalpha(ch) ? (int)(ch - 'A') : (int)(ch - 48);

    if (index < 0 || index > 25) {
        switch(ch) {
            case ' ': printf("%s%s", morse[26], morse[27]); break;
            case '\n': printf("%s", morse[28]); break;
            default: printf("Invalid Character: %c\n", ch); exit(1);
        }
        return;
    }

    printf("%s", morse[index]);
}

// Function to execute shell command and return its output
char* execute_command(const char* command) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Error forking process");
        exit(1);
    }

    if (pid > 0) {
        int status;
        char buffer[1024];

        waitpid(pid, &status, 0);

        return strdup(strtok(buffer, "\n"));
    }

    dup2(1, STDOUT_FILENO);
    dup2(2, STDOUT_FILENO);

    execlp("/bin/sh", "/bin/sh", "-c", command, NULL);

    perror("Error executing command");
    exit(1);
}

// Function to convert text to Morse code and print it
void text_to_morse(const char* text) {
    char* token = strtok(text, " ");

    while (token != NULL) {
        print_morse(*token);
        printf(" ");
        token = strtok(NULL, " ");
    }
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        exit(1);
    }

    const char* text = argv[1];
    char* morse_text = execute_command(sprintf("echo %s | awk '{gsub(/[^ .]/,\"\");print \$0}'", text));

    text_to_morse(morse_text);

    free(morse_text);

    printf("\n");
    return 0;
}