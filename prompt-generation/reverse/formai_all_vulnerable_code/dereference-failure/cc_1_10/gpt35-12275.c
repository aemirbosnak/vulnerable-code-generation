//FormAI DATASET v1.0 Category: Image Steganography ; Style: safe
#include <stdio.h>
#include <stdlib.h>

/* Function to get binary value of a character */
char* char_to_binary(char c) {
    char *binary = malloc(9 * sizeof(char));
    int i, j;

    /* Converting character to binary */
    for (i = 7, j = 0; i >= 0; --i, ++j)
        binary[j] = ((c >> i) & 1) ? '1' : '0';
    binary[j] = '\0';

    return binary;
}

/* Function to extract least significant bit of a value */
int extract_lsb(int val) {
    return (val & 1);
}

/* Function to hide message in image */
void hide_message(FILE *image, char *message) {
    char *binary_message, new_byte;
    int i, j, k = 0;

    /* Getting binary value of message */
    binary_message = malloc(8 * sizeof(char));
    for (i = 0; message[i]; ++i) {
        /* Converting each character of message to binary */
        char *binary_char = char_to_binary(message[i]);

        /* Appending binary value of character to the binary message */
        for (j = 0; j < 8; ++j, ++k)
            binary_message[k] = binary_char[j];
        free(binary_char);
    }

    /* Hiding message in image */
    while ((new_byte = fgetc(image)) != EOF && k < i * 8) {
        /* Extracting binary value of each byte */
        char *binary_byte = char_to_binary(new_byte);

        /* Changing last bit of each byte to the corresponding bit of binary message */
        binary_byte[7] = binary_message[k++];

        /* Converting binary byte back to character and writing to file */
        int val = strtol(binary_byte, NULL, 2);
        fputc(val, image);
        free(binary_byte);
    }
    fclose(image);

    if (k < i * 8)
        printf("Image size too small to embed message"); 
    else
        printf("Message hidden successfully");
    free(binary_message);
}

/* Function to retrieve message hidden in image */
void retrieve_message(FILE *image) {
    char *binary_message, message[1024];
    int i, j, k = 0;

    /* Getting binary value of hidden message */
    binary_message = malloc(8 * sizeof(char));
    while ((k % 8) || (k == 0)) {
        char *binary_byte = char_to_binary(fgetc(image));
        binary_message[k % 8] = binary_byte[7];
        ++k;
        free(binary_byte);
    }
    binary_message[k % 8] = '\0';
    k = 0;

    /* Retrieving message from binary message */
    for (i = 0; binary_message[i]; ++i) {
        if (k == 0) message[i] = 0;
        /* Appending bit to character */
        message[i] |= extract_lsb(binary_message[i + k]) << (k % 7);
        if ((i + k + 1) % 8 == 0) k++;
    }

    /* Writing retrieved message to stdout */
    printf("Retrieved message: %s", message);
    free(binary_message);
}

int main() {
    FILE *image;
    char message[1024], filename[256];
    int choice;

    printf("Enter image filename along with extension: ");
    scanf("%s", filename);
    if ((image = fopen(filename, "r+b")) == NULL) {
        printf("Could not open image");
        return 1;
    }

    printf("Image opened successfully\n");
    printf("Choose option:\n\t1. Hide message in image\n\t2. Retrieve message from image\n\t3. Exit\n");

    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter message to hide: ");
            scanf("%s", message);
            hide_message(image, message);
            break;
        case 2:
            retrieve_message(image);
            break;
        case 3:
            fclose(image);
            return 0;
        default:
            printf("Invalid option\n");
            break;
    }

    fclose(image);
    return 0;
}