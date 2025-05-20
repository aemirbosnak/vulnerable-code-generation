//FormAI DATASET v1.0 Category: Image Steganography ; Style: future-proof
#include <stdio.h>
#include <string.h>

// function to set the nth bit of an integer to 1
void set_bit(int* num, int n) {
    (*num) |= 1 << n;
}

// function to set the nth bit of an integer to 0
void clear_bit(int* num, int n) {
    (*num) &= ~(1 << n);
}

// function to get the nth bit of an integer
int get_bit(int num, int n) {
    return (num >> n) & 1;
}

// function to hide a message inside an integer
void hide_message(int* num, char* message) {
    int message_length = strlen(message);

    // make sure the message can fit inside the integer
    if (message_length > sizeof(int) * 8) {
        printf("Error: message is too long to be hidden in integer.\n");
        return;
    }

    // iterate over each bit in the integer
    for (int bit_index = 0; bit_index < sizeof(int) * 8; bit_index++) {
        int bit_value = get_bit(*num, bit_index);
        if (bit_index < message_length) {
            // if there are more bits in the message, set this bit to the corresponding message bit
            if (message[bit_index] == '1') {
                set_bit(num, bit_index);
            } else {
                clear_bit(num, bit_index);
            }
        } else {
            // if there are no more bits in the message, leave the bit alone
            break;
        }
    }
}

// function to extract a message from an integer
char* extract_message(int num) {
    char* message = malloc(sizeof(char) * (sizeof(int) * 8 + 1));
    int message_index = 0;

    // iterate over each bit in the integer
    for (int bit_index = 0; bit_index < sizeof(int) * 8; bit_index++) {
        int bit_value = get_bit(num, bit_index);
        if (bit_index <= message_index) {
            // if there are more bits in the message, append this bit to the message
            if (bit_value == 1) {
                message[message_index] = '1';
            } else {
                message[message_index] = '0';
            }
            message_index++;
        } else {
            // if there are no more bits in the message, stop iterating
            break;
        }
    }
    message[message_index] = '\0';

    return message;
}

int main() {
    int num = 0;

    // hide a message inside the integer
    char message[] = "This is a secret message.";
    hide_message(&num, message);
    printf("Original number: %d\n", num);

    // extract the message from the integer
    char* extracted_message = extract_message(num);
    printf("Extracted message: %s\n", extracted_message);

    free(extracted_message);

    return 0;
}