//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: surprised
#include <stdio.h>
#include <string.h>

// define max length of message
#define MAX_MSG_LEN 1000

// define max length of watermark
#define MAX_WMARK_LEN 50

// define the character used as the watermark
#define WATERMARK '*'

int main() {

    // use a surprise message for the watermarking
    char surprise[] = "You have won a million dollars!";

    // ask user for input message
    char msg[MAX_MSG_LEN];
    printf("Enter a message: ");
    fgets(msg, MAX_MSG_LEN, stdin);

    // ask user for input key
    char key[MAX_WMARK_LEN];
    printf("Enter a key: ");
    fgets(key, MAX_WMARK_LEN, stdin);

    // get length of the key
    int key_len = strlen(key);

    // loop through message and add watermark at every key index
    for (int i = 0; i < strlen(msg); i++) {
        if (i % key_len == 0) {
            // add watermark at current index
            msg[i] = WATERMARK;

            // add the surprise message after watermark
            strcat(&msg[i+1], surprise);

            // add key length to index to skip over added characters
            i += key_len + strlen(surprise);

            // make sure we don't exceed the max length of the message
            if (i >= MAX_MSG_LEN) {
                break;
            }
        }
    }

    // print out the final message with watermark and surprise message added
    printf("Watermarked message: %s", msg);

    return 0;
}