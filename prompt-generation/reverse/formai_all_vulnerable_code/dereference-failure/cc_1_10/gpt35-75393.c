//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH_LIMIT 100
#define MAX_HEIGHT_LIMIT 100

typedef struct Image {
   int width, height;
   char pixels[MAX_HEIGHT_LIMIT][MAX_WIDTH_LIMIT];
} Image;

char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

Image* create_image(int width, int height) {
   Image *img = (Image*) malloc(sizeof(Image));
   img->width = width;
   img->height = height;
   memset(img->pixels, 0, sizeof img->pixels);
   return img;
}

void parse_image_file(Image *img, FILE *fptr) {
   char line[MAX_WIDTH_LIMIT];
   int row = 0, col = 0;
   while (fgets(line, MAX_WIDTH_LIMIT, fptr) != NULL) {
       col = 0;
       while (line[col] != '\n') {
           img->pixels[row][col] = line[col];
           col++;
       }
       row++;
   }
   img->width = col;
   img->height = row;
}

void convert_image_to_ascii(Image *img) {
   int avg;
   for (int row = 0; row < img->height; row++) {
       for (int col = 0; col < img->width; col++) {
           avg = (int) img->pixels[row][col];
           avg = (avg * 10) / 256;
           img->pixels[row][col] = ascii_chars[avg];
       }
   }
}

void print_ascii_image(Image *img) {
   for (int row = 0; row < img->height; row++) {
       for (int col = 0; col < img->width; col++) {
           printf("%c", img->pixels[row][col]);
       }
       printf("\n");
   }
}

int main(int argc, char* argv[]) {
   if (argc < 2) {
       printf("Usage: %s <image filename>\n", argv[0]);
       return 0;
   }

   FILE *fptr = fopen(argv[1], "r");
   if (fptr == NULL) {
       printf("Error: could not open file %s\n", argv[1]);
       return 0;
   }

   Image *img = create_image(MAX_WIDTH_LIMIT, MAX_HEIGHT_LIMIT);
   parse_image_file(img, fptr);
   fclose(fptr);

   convert_image_to_ascii(img);
   print_ascii_image(img);

   free(img);
   return 0;
}