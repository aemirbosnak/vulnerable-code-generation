//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pthread.h>

#define MAX_CHARS 70
#define DELAY_TIME 10000

/* Colors for ASCII art */
#define ANSI_COLOR_BLACK   "\x1b[30m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/* Struct for passing arguments to thread */
struct convertImageData {
    unsigned char *data;
    int width;
    int height;
    size_t data_size;
    char *file_name;
};

void *convertImageToAscii(void *arguments) {
    struct convertImageData *data = (struct convertImageData *)arguments;

    FILE *ascii_file = fopen(data->file_name, "w+");

    /* ASCII characters ordered from light to dark */
    char ascii_chars[] = "@#MWQBMmXNhdyzcvunxrjft7i:;,. ";

    /* Determine brightness of pixel based on RGB values */
    int brightness = 0;
    int ascii_index = 0;

    /* Loop through each pixel of the input image */
    for (int i = 0; i < data->height; i++) {
        for (int j = 0; j < data->width; j++) {
            /* Calculate the brightness of the pixel based on the RGB values */
            brightness = (data->data[3 * (i * data->width + j)] + \
                data->data[3 * (i * data->width + j) + 1] + \
                data->data[3 * (i * data->width + j) + 2]) / 3;

            /* Map the brightness to an ASCII character using the brightness range and length of the ascii_chars array */
            ascii_index = (int)((ascii_chars[strlen(ascii_chars) - 1] - ascii_chars[0]) * ((double)brightness / 255.0)) + ascii_chars[0];
            fprintf(ascii_file, "%c", ascii_chars[ascii_index]);
        }
        fprintf(ascii_file, "\n");
    }

    fclose(ascii_file);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int input_fd;
    struct stat input_stats;

    /* Check command line arguments */
    if (argc != 2) {
        printf("Usage: ./img2ascii path/to/image_file\n");
        exit(1);
    }

    /* Open the input file for reading */
    input_fd = open(argv[1], O_RDONLY);

    if (input_fd < 0) {
        perror("Error opening file");
        exit(2);
    }

    /* Get the size of the input file */
    if (fstat(input_fd, &input_stats)) {
        perror("Error getting file stats");
        exit(3);
    }

    /* Allocate memory to hold the input file data */
    unsigned char *input_data = (unsigned char *)malloc(sizeof(unsigned char) * input_stats.st_size);

    if (input_data == NULL) {
        perror("Error allocating input data memory");
        exit(4);
    }

    /* Read the input file into memory */
    ssize_t bytes_read = read(input_fd, input_data, input_stats.st_size);

    if (bytes_read != input_stats.st_size) {
        perror("Error reading input file");
        exit(5);
    }

    /* Close the input file */
    close(input_fd);

    /* Determine image format from magic number */
    char *image_format = malloc(sizeof(char) * 3);

    if (image_format == NULL) {
        perror("Error allocating image format memory");
        exit(6);
    }

    /* Check magic number */
    if (input_data[0] == 'B' && input_data[1] == 'M') {
        strcpy(image_format, "bmp");
    }
    else {
        fprintf(stderr, "Invalid image format\n");
        exit(7);
    }

    /* Extract image metadata */
    int width = *(int *)&input_data[18];
    int height = *(int *)&input_data[22];
    size_t data_size = (size_t)bytes_read - 54;

    /* Allocate argument struct for thread */
    struct convertImageData *arg = malloc(sizeof(struct convertImageData));
    arg->data = input_data + 54;
    arg->width = width;
    arg->height = height;
    arg->data_size = data_size;
    arg->file_name = "ascii.txt";

    /* Create thread to convert image data to ASCII art */
    pthread_t convert_thread;
    if (pthread_create(&convert_thread, NULL, convertImageToAscii, (void *) arg)) {
        fprintf(stderr, "Error creating thread\n");
        exit(8);
    }

    printf("Converting image to ASCII art...\n");

    /* Display loading animation while thread is running */
    int animation_index = 0;
    while (1) {
        /* Loop through the different loading animation frames using ANSI escape codes */
        switch (animation_index % 4) {
            case 0:
                printf("\r[%s=%s     ]", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
                break;
            case 1:
                printf("\r[%s =%s    ]", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
                break;
            case 2:
                printf("\r[%s  =%s   ]", ANSI_COLOR_MAGENTA, ANSI_COLOR_RESET);
                break;
            case 3:
                printf("\r[%s   =%s  ]", ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
                break;
        }
        
        fflush(stdout);
        usleep(DELAY_TIME);

        /* Stop the animation once the conversion process is complete */
        if (pthread_kill(convert_thread, 0) == 0) {
            break;
        }
        animation_index++;
    }

    printf("\nConversion complete!\n");

    /* Wait for convert thread to finish */
    if (pthread_join(convert_thread, NULL)) {
        fprintf(stderr, "Error waiting for thread\n");
        exit(9);
    }

    /* Free memory */
    free(image_format);
    free(input_data);
    free(arg);

    return 0;
}