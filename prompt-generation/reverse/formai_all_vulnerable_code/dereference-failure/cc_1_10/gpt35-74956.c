//FormAI DATASET v1.0 Category: Image Steganography ; Style: complete
#include <stdio.h>
#include <stdlib.h>

/* returns the i-th bit of x */
#define BIT(x, i) (x & (1 << i))

/* clears the i-th bit of x */
#define CLEAR_BIT(x, i) x &= ~(1 << i)

/* sets the i-th bit of x to b */
#define SET_BIT(x, i, b) x = (x & ~(1 << i)) | (b << i)

/* maximum message length */
#define MAX_MSG_LEN 1024

/*
 * embeds the message 'msg' in the least significant
 * bits of image 'image' and stores the result in
 * 'output'. The message is pre-pended by its length.
 * Returns 1 if the message could be embedded, 0 otherwise.
 */
int embed_message(char *image, char *msg, char *output) {
    int img_len;
    int msg_len;
    int i, j, b;

    /* get image length */
    img_len = strlen(image);

    /* get message length */
    msg_len = strlen(msg);

    /* check if message length is valid */
    if (msg_len > img_len / 8 - 4) {
        return 0;
    }

    /* prepend message length to message */
    msg_len = htonl(msg_len);
    memcpy(output, &msg_len, 4);
    memcpy(output + 4, msg, strlen(msg));

    /* embed message in image */
    for (i = 0; i < img_len / 8 && i < msg_len + 4; i++) {
        for (j = 0; j < 8; j++) {
            if (i * 8 + j < msg_len * 8 + 32) {
                b = BIT(output[i], j);
                SET_BIT(image[i], j, b);
            }
        }
    }

    /* copy the rest of the image */
    memcpy(output + msg_len + 4, image + msg_len + 4, img_len - msg_len - 4);

    return 1;
}

/*
 * extracts a message from image 'image' and 
 * stores it in 'msg'. Returns the length of
 * the message or 0 if no message was found.
 */
int extract_message(char *image, char *msg) {
    int img_len;
    int i, j;
    int msg_len = 0;

    /* get image length */
    img_len = strlen(image);

    /* extract message length */
    for (i = 0; i < 4; i++) {
        msg_len |= (BIT(image[i], 0) << i);
    }
    msg_len = ntohl(msg_len);

    /* extract message */
    for (i = 4; i < img_len / 8 && i - 4 < msg_len; i++) {
        for (j = 0; j < 8; j++) {
            if (i * 8 + j < msg_len * 8 + 32) {
                SET_BIT(msg[i - 4], j, BIT(image[i], j));
            }
        }
    }

    return msg_len;
}

int main(int argc, char **argv) {
    char *image;
    char *msg;
    char *output;
    int img_len;
    int msg_len;

    /* check arguments */
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image> <message> <output>\n", argv[0]);
        return 1;
    }

    /* read image */
    FILE *f = fopen(argv[1], "rb");
    fseek(f, 0, SEEK_END);
    img_len = ftell(f);
    rewind(f);
    image = malloc(img_len);
    fread(image, img_len, 1, f);
    fclose(f);

    /* read message */
    FILE *f2 = fopen(argv[2], "rb");
    fseek(f2, 0, SEEK_END);
    msg_len = ftell(f2);
    rewind(f2);
    msg = malloc(msg_len);
    fread(msg, msg_len, 1, f2);
    fclose(f2);

    /* allocate output buffer */
    output = malloc(img_len);

    /* embed message */
    if (embed_message(image, msg, output)) {
        /* write output */
        FILE *f3 = fopen(argv[3], "wb");
        fwrite(output, img_len, 1, f3);
        fclose(f3);
        printf("Embedded message in %s.\n", argv[3]);
    } else {
        printf("Message too long.\n");
    }

    /* extract message */
    msg_len = extract_message(output, msg);
    if (msg_len > 0) {
        /* write output */
        FILE *f4 = fopen("out.txt", "wb");
        fwrite(msg, msg_len, 1, f4);
        fclose(f4);
        printf("Extracted message in out.txt.\n");
    } else {
        printf("No message found.\n");
    }

    free(image); 
    free(msg);
    free(output);

    return 0;
}