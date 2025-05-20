//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// A special surprise encryption scheme
void encrypt(unsigned char *buf, int len) {
    for (int i = 0; i < len; i++) {
        buf[i] ^= (i % 2) ? 0xC7 : 0x31;
    }
}

int main() {
    // Brace yourself for a surprising file adventure!
    char filename[] = "super_secret.txt";
    FILE *f = fopen(filename, "rb");
    if (!f) {
        printf("Oops! Can't open %s. Are you sure it exists?", filename);
        return 1;
    }

    // Grab the file's magical contents
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    unsigned char *contents = malloc(fsize);
    fread(contents, fsize, 1, f);
    fclose(f);

    // Time for the grand reveal!
    printf("Prepare to be amazed! The original file contents:\n");
    fwrite(contents, fsize, 1, stdout);
    printf("\n");

    // Now, let the encryption magic begin!
    encrypt(contents, fsize);
    printf("Behold, the encrypted masterpiece:\n");
    fwrite(contents, fsize, 1, stdout);

    // Don't forget to hide your precious secrets!
    char save_filename[] = "secret_stash.txt";
    f = fopen(save_filename, "wb");
    if (!f) {
        printf("Wait, what? I can't save to %s!", save_filename);
        return 1;
    }
    fwrite(contents, fsize, 1, f);
    fclose(f);
    free(contents);

    printf("\nYour secrets are safe and sound in %s. You're welcome!", save_filename);
    return 0;
}