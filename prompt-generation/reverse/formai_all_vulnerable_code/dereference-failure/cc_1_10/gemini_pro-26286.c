//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Message queue key
#define MSG_KEY 1234

// Maximum message size
#define MAX_MSG_SIZE 1024

// Message types
#define TEXT_TYPE 1
#define MORSE_TYPE 2

// Create a message queue
int create_queue() {
    key_t key = MSG_KEY;
    int queue_id = msgget(key, IPC_CREAT | 0666);
    if (queue_id == -1) {
        perror("msgget");
        exit(1);
    }
    return queue_id;
}

// Send a message to the queue
void send_message(int queue_id, long type, char *message) {
    struct msgbuf {
        long mtype;
        char mtext[MAX_MSG_SIZE];
    };

    struct msgbuf msg;
    msg.mtype = type;
    strcpy(msg.mtext, message);

    if (msgsnd(queue_id, &msg, sizeof(msg.mtext), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }
}

// Receive a message from the queue
char *receive_message(int queue_id, long type) {
    struct msgbuf {
        long mtype;
        char mtext[MAX_MSG_SIZE];
    };

    struct msgbuf msg;
    if (msgrcv(queue_id, &msg, sizeof(msg.mtext), type, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }

    return strdup(msg.mtext);
}

// Convert text to Morse code
char *text_to_morse(char *text) {
    char *morse_code[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    };
    char *alphabet = "abcdefghijklmnopqrstuvwxyz";

    int len = strlen(text);
    char *morse = malloc(len * 4 + 1);
    morse[0] = '\0';

    for (int i = 0; i < len; i++) {
        char c = text[i];
        for (int j = 0; j < 26; j++) {
            if (c == alphabet[j]) {
                strcat(morse, morse_code[j]);
                strcat(morse, " ");
                break;
            }
        }
    }

    return morse;
}

// Convert Morse code to text
char *morse_to_text(char *morse) {
    char *alphabet = "abcdefghijklmnopqrstuvwxyz";
    char *morse_code[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    };

    int len = strlen(morse);
    char *text = malloc(len + 1);
    text[0] = '\0';

    char *token = strtok(morse, " ");
    while (token != NULL) {
        for (int i = 0; i < 26; i++) {
            if (strcmp(token, morse_code[i]) == 0) {
                strcat(text, &alphabet[i]);
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    return text;
}

// Main function
int main() {
    // Create a message queue
    int queue_id = create_queue();

    // Create a child process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process: send text to the queue and receive Morse code
        char *text = "Hello, world!";
        send_message(queue_id, TEXT_TYPE, text);
        char *morse = receive_message(queue_id, MORSE_TYPE);

        // Print the Morse code
        printf("Morse code: %s\n", morse);

        // Convert the Morse code back to text
        char *text2 = morse_to_text(morse);

        // Print the converted text
        printf("Text: %s\n", text2);
    } else if (pid > 0) {
        // Parent process: receive text from the queue and send Morse code
        char *text = receive_message(queue_id, TEXT_TYPE);
        char *morse = text_to_morse(text);

        // Send the Morse code to the queue
        send_message(queue_id, MORSE_TYPE, morse);
    } else {
        perror("fork");
        exit(1);
    }

    // Cleanup
    msgctl(queue_id, IPC_RMID, NULL);

    return 0;
}