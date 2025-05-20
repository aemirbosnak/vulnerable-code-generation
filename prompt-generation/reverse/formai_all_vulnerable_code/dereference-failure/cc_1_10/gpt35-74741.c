//FormAI DATASET v1.0 Category: Image Editor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

void apply_filter(int width, int height, unsigned char* image, float* filter)
{
  unsigned char* new_image = malloc(width*height*sizeof(unsigned char));

  // zero padding
  int pad_size = 5;
  int padded_width = width + 2*pad_size;
  int padded_height = height + 2*pad_size;

  // apply filter
  for (int y = pad_size; y < padded_height - pad_size; y++) {
    for (int x = pad_size; x < padded_width - pad_size; x++) {
      int pixel_index = y*width + x;
      float sum = 0;
      for (int fy = -pad_size; fy <= pad_size; fy++) {
        for (int fx = -pad_size; fx <= pad_size; fx++) {
          int filter_index = (fy+pad_size)*(2*pad_size+1) + (fx+pad_size);
          int neighbour_index = (y+fy)*width + (x+fx);
          float filter_value = filter[filter_index];
          if (neighbour_index >= 0 && neighbour_index < width*height) {
            sum += image[neighbour_index]*filter_value;
          }
        }
      }
      sum = sum > 255 ? 255 : sum < 0 ? 0 : sum;
      new_image[pixel_index] = (unsigned char)sum;
    }
  }

  // replace original image
  for (int i = 0; i < width*height; i++) {
    image[i] = new_image[i];
  }

  free(new_image);
}

int main(int argc, char** argv)
{
  int width = 640;
  int height = 480;

  // create image
  unsigned char* image = malloc(width*height*sizeof(unsigned char));
  for (int i = 0; i < width*height; i++) {
    image[i] = (unsigned char)rand()%256;
  }

  // apply filter
  float filter[25] = { 1,  4,  7,  4, 1,
                       4, 16, 26, 16, 4,
                       7, 26, 41, 26, 7,
                       4, 16, 26, 16, 4,
                       1,  4,  7,  4, 1 };
  apply_filter(width, height, image, filter);

  // output image to file
  FILE* fout = fopen("output.pgm", "wb");
  fprintf(fout, "P5\n%d %d\n255\n", width, height);
  fwrite(image, sizeof(unsigned char), width*height, fout);
  fclose(fout);

  free(image);
  return 0;
}