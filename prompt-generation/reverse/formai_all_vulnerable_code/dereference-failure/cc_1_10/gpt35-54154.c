//FormAI DATASET v1.0 Category: Audio processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  printf("Surprise! Let's do some audio processing.\n\n");
  
  // Set up sample rate and duration of audio clip
  int sampleRate = 44100; // samples per second
  int duration = 5; // seconds
  int numSamples = sampleRate * duration; // total number of samples
  
  // Allocate memory for audio data
  float* audioData = malloc(numSamples * sizeof(float));
  
  // Generate a simple sine wave
  for (int i = 0; i < numSamples; i++) {
    float t = (float) i / sampleRate; // time in seconds
    float freq = 440; // frequency of A4 note
    float amplitude = 0.5; // maximum amplitude of sine wave
    float value = amplitude * sin(2 * M_PI * freq * t); // sine value at current time
    audioData[i] = value;
  }
  
  // Write audio data to file
  FILE *file;
  file = fopen("audio.wav", "wb");
  
  // Write WAV file header
  int numChannels = 1; // mono audio
  int bitsPerSample = 16; // 16-bit audio
  int byteRate = sampleRate * numChannels * (bitsPerSample / 8);
  int blockAlign = numChannels * (bitsPerSample / 8);
  int dataSize = numSamples * numChannels * (bitsPerSample / 8);
  int fileSize = dataSize + 36; // add 36 bytes for WAV file header
  fwrite("RIFF", 4, 1, file);
  fwrite(&fileSize, 4, 1, file);
  fwrite("WAVE", 4, 1, file);
  fwrite("fmt ", 4, 1, file);
  fwrite("\x10\0\0\0", 4, 1, file); // PCM format
  fwrite(&numChannels, 2, 1, file);
  fwrite(&sampleRate, 4, 1, file);
  fwrite(&byteRate, 4, 1, file);
  fwrite(&blockAlign, 2, 1, file); 
  fwrite(&bitsPerSample, 2, 1, file); 
  fwrite("data", 4, 1, file);
  fwrite(&dataSize, 4, 1, file);
  
  // Write audio data
  for (int i = 0; i < numSamples; i++) {
    short value = (short) (audioData[i] * 32767); // convert from float to 16-bit int
    fwrite(&value, 2, 1, file); // write to file
  }
  
  // Clean up
  fclose(file);
  free(audioData);
  
  printf("Done! Check out the audio.wav file to hear the surprise.\n");
  
  return 0;
}