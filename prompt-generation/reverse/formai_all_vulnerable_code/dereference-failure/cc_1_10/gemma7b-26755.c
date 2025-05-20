//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STASH_SIZE 1024

typedef struct stash_node {
    char *data;
    struct stash_node *next;
} stash_node;

stash_node *stash_push(stash_node *head, char *data) {
    stash_node *new_node = malloc(sizeof(stash_node));
    new_node->data = strdup(data);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
    }

    return head;
}

char *stash_pop(stash_node *head) {
    if (head == NULL) {
        return NULL;
    }

    char *data = head->data;
    head = head->next;

    return data;
}

int main() {
    stash_node *stash = NULL;

    // Embed secret message into image
    FILE *fp = fopen("image.jpg", "rb");
    fseek(fp, 0, SEEK_END);
    int image_size = ftell(fp);
    rewind(fp);

    char *image_data = (char *)malloc(image_size);
    fread(image_data, image_size, 1, fp);

    char *secret_message = "Hello, world!";

    for (int i = 0; i < strlen(secret_message); i++) {
        int offset = (int)secret_message[i] * MAX_STASH_SIZE;
        stash_push(stash, image_data + offset);
    }

    fclose(fp);

    // Extract secret message from image
    fp = fopen("image.jpg", "rb");
    image_size = ftell(fp);
    rewind(fp);

    image_data = (char *)malloc(image_size);
    fread(image_data, image_size, 1, fp);

    char *extracted_secret_message = "";

    for (int i = 0; i < strlen(secret_message); i++) {
        int offset = (int)secret_message[i] * MAX_STASH_SIZE;
        char *data = stash_pop(stash);
        extracted_secret_message = strcat(extracted_secret_message, data);
    }

    fclose(fp);

    printf("Extracted secret message: %s\n", extracted_secret_message);

    return 0;
}