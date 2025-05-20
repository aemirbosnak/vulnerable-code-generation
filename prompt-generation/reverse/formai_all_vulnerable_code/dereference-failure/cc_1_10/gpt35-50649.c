//FormAI DATASET v1.0 Category: Image Steganography ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SECRET_SIZE 500
#define MAX_IMAGE_SIZE 40000

typedef struct {
    char* message;
    char* image;
    int offset;
    int secret_size;
} steg_data;

void* steganographer(void* arg){
    steg_data* data = (steg_data*)arg;

    for(int i = 0; i < data->secret_size; i++){
        data->image[i + data->offset] = data->message[i];
    }

    pthread_exit(0);
}

int main(){
    char secret[MAX_SECRET_SIZE];
    char image[MAX_IMAGE_SIZE];

    printf("Enter the secret message to hide:\n");
    fgets(secret, MAX_SECRET_SIZE, stdin);

    printf("Enter the image file name (PNG only):\n");
    fgets(image, MAX_IMAGE_SIZE, stdin);

    FILE* img_file = fopen(image, "r+b");

    if(img_file == NULL){
        printf("Error opening image file.\n");
        return 0;
    }

    fseek(img_file, 0, SEEK_END);
    int img_size = ftell(img_file);
    fseek(img_file, 0, SEEK_SET);

    if(img_size < MAX_SECRET_SIZE){
        printf("Image file is too small to hide the secret message.\n");
        return 0;
    }

    pthread_t thread;

    steg_data data;
    data.message = secret;
    data.image = (char*)malloc(img_size);
    data.offset = 100;
    data.secret_size = strlen(secret);

    fread(data.image, img_size, 1, img_file);
    fclose(img_file);

    int status = pthread_create(&thread, NULL, steganographer, &data);

    if(status != 0) {
        printf("Error creating thread.\n");
        return 0;
    }

    status = pthread_join(thread, NULL);

    if(status != 0) {
        printf("Error joining thread.\n");
        return 0;
    }

    img_file = fopen(image, "wb");

    if(img_file == NULL){
        printf("Error opening image file.\n");
        return 0;
    }

    fwrite(data.image, img_size, 1, img_file);
    fclose(img_file);

    printf("Secret message hidden successfully!\n");

    free(data.image);

    return 0;
}