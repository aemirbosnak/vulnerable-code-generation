//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: Romeo and Juliet
// Wherefore art thou, Romeo?
#include <stdio.h>
#include <string.h>

// A compression algorithm, fair as a summer's day
char* Juliet(char* message, int length) {
    // Extract the essence of the message, like Juliet's beauty
    int essenceLength = length / 2;
    char* essence = malloc(essenceLength + 1);
    for (int i = 0; i < length; i += 2) {
        essence[i / 2] = message[i];
    }
    essence[essenceLength] = '\0';

    // Return the compressed message, a whisper in the wind
    return essence;
}

// Where art thou now, fair Juliet?
#include <stdio.h>
#include <string.h>

// A decompression algorithm, as passionate as Romeo's love
char* Romeo(char* essence, int essenceLength) {
    // Restore the message from its essence, like Romeo's longing
    int length = essenceLength * 2;
    char* message = malloc(length + 1);
    for (int i = 0; i < essenceLength; i++) {
        message[2 * i] = message[2 * i + 1] = essence[i];
    }
    message[length] = '\0';

    // Return the decompressed message, a symphony for their hearts
    return message;
}

// The prologue to their tragic tale
int main() {
    // The message, a secret shared between star-crossed lovers
    char* message = "Two households, both alike in dignity, In fair Verona, where we lay our scene";

    // The length of the message, a measure of their love's depth
    int length = strlen(message);

    // Juliet's compression, a testament to her wisdom and grace
    char* essence = Juliet(message, length);

    // Romeo's decompression, a reflection of his unwavering devotion
    char* restoredMessage = Romeo(essence, strlen(essence));

    // The epilogue of their timeless love story
    printf("Original Message: %s\n", message);
    printf("Compressed Essence: %s\n", essence);
    printf("Restored Message: %s\n", restoredMessage);
    return 0;
}