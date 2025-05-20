//FormAI DATASET v1.0 Category: Digital signal processing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int frequency = 100; // assign frequency of signal
  float amplitude = 1.5; // assign amplitude of signal
  float phase = 30; // assign phase of signal
  int duration = 500; // assign duration of signal
  float samplingFrequency = 5000.0; // assign sampling frequency
  float time = 0; // variable to keep track of time
  
  // calculate the number of samples needed
  int numSamples = duration * samplingFrequency / 1000;
  
  // allocate memory for input signal
  float* inputSignal = (float*) malloc(numSamples * sizeof(float));
  
  // generate input signal
  for(int i = 0; i < numSamples; i++) {
    inputSignal[i] = amplitude * sin((2 * M_PI * frequency * time) + (M_PI * phase / 180.0));
    time += 1 / samplingFrequency;
  }
  
  // allocate memory for output signal
  float* outputSignal = (float*) malloc(numSamples * sizeof(float));
  
  // apply high-pass filter to input signal
  float RC = 1.0 / (2.0 * M_PI * 100.0);
  float dt = 1.0 / samplingFrequency;
  float alpha = RC / (RC + dt);
  float prevOutput = 0.0;
  
  for(int i = 0; i < numSamples; i++) {
    outputSignal[i] = alpha * (prevOutput + inputSignal[i] - inputSignal[i - 1]);
    prevOutput = outputSignal[i];
  }
  
  // print input and output signals to console
  printf("Input Signal\tOutput Signal\n");
  
  for(int i = 0; i < numSamples; i++) {
    printf("%f\t%f\n", inputSignal[i], outputSignal[i]);
  }
  
  // free memory allocated for input and output signals
  free(inputSignal);
  free(outputSignal);
  
  return 0;
}