//FormAI DATASET v1.0 Category: Digital signal processing ; Style: multivariable
/* This program is a multivariable example of digital signal processing that applies a low-pass filter to a noisy audio signal to improve sound quality */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FREQUENCY_CUTOFF 1000
#define SMOOTHNESS 0.99

int main() {
   // Read in and allocate memory for the audio signal
   FILE *fp = fopen("audio.wav", "rb");
   if (!fp) {
      printf("Error: could not open file!\n");
      return 1;
   }
   fseek(fp, 44, SEEK_SET); // Skip over the header information
   int signal_size = 0;
   short *signal = malloc(sizeof(short));
   while (fread(&signal[signal_size++], sizeof(short), 1, fp)) {
      signal = realloc(signal, (signal_size + 1) * sizeof(short));
   }
   fclose(fp);

   // Compute filter coefficients
   double alpha = exp(-2.0 * M_PI * FREQUENCY_CUTOFF / SAMPLE_RATE);
   double a[2] = {1.0 - alpha, -alpha};
   double b[3] = {1.0 - SMOOTHNESS, 0, SMOOTHNESS - 1.0};

   // Apply low-pass filter
   double y[signal_size];
   double x[3] = {0, 0, 0};
   for (int n = 0; n < signal_size; n++) {
      x[0] = b[0] * signal[n] + b[1] * x[1] + b[2] * x[2];
      y[n] = a[0] * x[0] + a[1] * x[1] + a[1] * x[2];
      x[2] = x[1];
      x[1] = x[0];
   }

   // Write the filtered audio signal to a new file
   fp = fopen("filtered_audio.wav", "wb");
   if (!fp) {
      printf("Error: could not open file for writing!\n");
      return 1;
   }
   fseek(fp, 44, SEEK_SET); // Skip over the header information
   for (int n = 0; n < signal_size; n++) {
      fwrite(&y[n], sizeof(double), 1, fp);
   }
   fclose(fp);

   // Free memory
   free(signal);

   return 0;
}