//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PIXELS 1000000
#define MAX_CHARS 1000000

typedef struct {
    int width, height;
    char *data;
} image_t;

typedef struct {
    char *filename;
    image_t *image;
    int hidden;
    FILE *fp;
    char *buffer;
} context_t;

image_t *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error loading image '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    char *data = malloc(size);
    if (fread(data, size, 1, fp)!= 1) {
        printf("Error reading image '%s'\n", filename);
        exit(1);
    }

    fclose(fp);

    int width, height;
    if (sscanf(filename, "%dx%d.%c", &width, &height, &filename[strlen(filename) - 1])!= 3) {
        printf("Error parsing image dimensions from filename '%s'\n", filename);
        exit(1);
    }

    image_t *img = malloc(sizeof(image_t));
    img->width = width;
    img->height = height;
    img->data = data;

    return img;
}

void save_image(const char *filename, image_t *img) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error saving image '%s'\n", filename);
        exit(1);
    }

    fwrite(img->data, img->width * img->height * 3, 1, fp);
    fclose(fp);
}

void hide_message(context_t *ctx) {
    int hidden_size = strlen(ctx->buffer);
    int pixel_size = ctx->image->width * ctx->image->height * 3;

    int i = 0;
    while (i < pixel_size - hidden_size) {
        ctx->image->data[i] = ctx->image->data[i] ^ ctx->buffer[i % hidden_size];
        i++;
    }
}

void reveal_message(context_t *ctx) {
    int hidden_size = strlen(ctx->buffer);
    int pixel_size = ctx->image->width * ctx->image->height * 3;

    int i = 0;
    while (i < pixel_size - hidden_size) {
        ctx->image->data[i] = ctx->image->data[i] ^ ctx->buffer[i % hidden_size];
        i++;
    }
}

int main() {
    context_t ctx;
    ctx.filename = "input.png";
    ctx.image = load_image(ctx.filename);
    ctx.hidden = 0;
    ctx.fp = NULL;
    ctx.buffer = NULL;

    char *message = "Hello, world!";
    ctx.buffer = malloc(strlen(message));
    strcpy(ctx.buffer, message);

    hide_message(&ctx);

    save_image("output.png", ctx.image);

    reveal_message(&ctx);

    free(ctx.image->data);
    free(ctx.buffer);
    free(ctx.image);
    fclose(ctx.fp);

    return 0;
}