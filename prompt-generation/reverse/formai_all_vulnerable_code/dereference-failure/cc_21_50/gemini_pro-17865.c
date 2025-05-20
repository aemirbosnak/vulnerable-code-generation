//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

#define MAX_CHAR_LEN 1024

typedef struct {
    char *text;
    char *morse;
    int len;
    int fd;
} conversion_data;

void *convert_text_to_morse(void *data) {
    conversion_data *d = (conversion_data *)data;

    // Convert text to morse code
    char *morse = malloc(MAX_CHAR_LEN);
    memset(morse, 0, MAX_CHAR_LEN);
    int len = 0;
    for (int i = 0; i < d->len; i++) {
        char c = d->text[i];
        switch (c) {
            case 'A':
            case 'a':
                strcat(morse, ".-");
                len += 2;
                break;
            case 'B':
            case 'b':
                strcat(morse, "-...");
                len += 4;
                break;
            case 'C':
            case 'c':
                strcat(morse, "-.-.");
                len += 4;
                break;
            case 'D':
            case 'd':
                strcat(morse, "-..");
                len += 3;
                break;
            case 'E':
            case 'e':
                strcat(morse, ".");
                len += 1;
                break;
            case 'F':
            case 'f':
                strcat(morse, "..-.");
                len += 4;
                break;
            case 'G':
            case 'g':
                strcat(morse, "--.");
                len += 3;
                break;
            case 'H':
            case 'h':
                strcat(morse, "....");
                len += 4;
                break;
            case 'I':
            case 'i':
                strcat(morse, "..");
                len += 2;
                break;
            case 'J':
            case 'j':
                strcat(morse, ".---");
                len += 4;
                break;
            case 'K':
            case 'k':
                strcat(morse, "-.-");
                len += 3;
                break;
            case 'L':
            case 'l':
                strcat(morse, ".-..");
                len += 4;
                break;
            case 'M':
            case 'm':
                strcat(morse, "--");
                len += 2;
                break;
            case 'N':
            case 'n':
                strcat(morse, "-.");
                len += 2;
                break;
            case 'O':
            case 'o':
                strcat(morse, "---");
                len += 3;
                break;
            case 'P':
            case 'p':
                strcat(morse, ".--.");
                len += 4;
                break;
            case 'Q':
            case 'q':
                strcat(morse, "--.-");
                len += 4;
                break;
            case 'R':
            case 'r':
                strcat(morse, ".-.");
                len += 3;
                break;
            case 'S':
            case 's':
                strcat(morse, "...");
                len += 3;
                break;
            case 'T':
            case 't':
                strcat(morse, "-");
                len += 1;
                break;
            case 'U':
            case 'u':
                strcat(morse, "..-");
                len += 3;
                break;
            case 'V':
            case 'v':
                strcat(morse, "...-");
                len += 4;
                break;
            case 'W':
            case 'w':
                strcat(morse, ".--");
                len += 3;
                break;
            case 'X':
            case 'x':
                strcat(morse, "-..-");
                len += 4;
                break;
            case 'Y':
            case 'y':
                strcat(morse, "-.--");
                len += 4;
                break;
            case 'Z':
            case 'z':
                strcat(morse, "--..");
                len += 4;
                break;
            case '0':
                strcat(morse, "-----");
                len += 5;
                break;
            case '1':
                strcat(morse, ".----");
                len += 5;
                break;
            case '2':
                strcat(morse, "..---");
                len += 5;
                break;
            case '3':
                strcat(morse, "...--");
                len += 5;
                break;
            case '4':
                strcat(morse, "....-");
                len += 5;
                break;
            case '5':
                strcat(morse, ".....");
                len += 5;
                break;
            case '6':
                strcat(morse, "-....");
                len += 5;
                break;
            case '7':
                strcat(morse, "--...");
                len += 5;
                break;
            case '8':
                strcat(morse, "---..");
                len += 5;
                break;
            case '9':
                strcat(morse, "----.");
                len += 5;
                break;
            case ' ':
                strcat(morse, " ");
                len += 1;
                break;
            default:
                break;
        }
    }

    // Store the morse code in the data structure
    d->morse = morse;
    d->len = len;

    return NULL;
}

void *write_morse_to_file(void *data) {
    conversion_data *d = (conversion_data *)data;

    // Write morse code to the file
    int fd = open(d->fd, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    write(fd, d->morse, d->len);

    close(fd);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <text file> <morse file>\n", argv[0]);
        exit(1);
    }

    // Read text from the file
    char *text = NULL;
    long len = 0;
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    text = malloc(len + 1);
    memset(text, 0, len + 1);
    fread(text, 1, len, fp);
    fclose(fp);

    // Create a data structure to store the conversion data
    conversion_data d;
    d.text = text;
    d.len = len;
    d.fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // Create two threads to perform the conversion and writing operations asynchronously
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, convert_text_to_morse, &d);
    pthread_create(&tid2, NULL, write_morse_to_file, &d);

    // Wait for the threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // Close the file descriptor
    close(d.fd);

    // Free the allocated memory
    free(text);
    free(d.morse);

    return 0;
}