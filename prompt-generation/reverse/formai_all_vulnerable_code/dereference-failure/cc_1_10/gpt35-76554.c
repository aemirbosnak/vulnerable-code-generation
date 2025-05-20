//FormAI DATASET v1.0 Category: Audio processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

typedef struct {
    float real;
    float imag;
} Complex;

void printAudioData(float *audioData, int numSamples, float sampleRate) {
    printf("Audio Data:\n");
    for (int i = 0; i < numSamples; i++) {
        printf("%f\n", audioData[i]);
    }
    printf("Sample Rate: %f Hz\n", sampleRate);
}

void printSpectrogram(float **spectrogram, int numFrames, int numBins) {
    printf("Spectrogram:\n");
    for (int i = 0; i < numFrames; i++) {
        for (int j = 0; j < numBins; j++) {
            printf("%f ", spectrogram[i][j]);
        }
        printf("\n");
    }
}

void computeFrame(float *audioData, int numSamples, int sampleRate, int frameSize, int hopSize, int frameIdx, float *frameData) {
    int startIndex = frameIdx * hopSize;
    int endIndex = startIndex + frameSize - 1;
    for (int i = startIndex, j = 0; i <= endIndex; i++, j++) {
        if (i < numSamples) {
            frameData[j] = audioData[i];
        }
        else {
            frameData[j] = 0.0;
        }
    }
}

void computeWindow(float *window, int windowSize, int type) {
    for (int i = 0; i < windowSize; i++) {
        switch (type) {
            case 0:
                window[i] = 1.0;
                break;
            case 1:
                window[i] = 0.54 - 0.46 * cos(2 * PI * i / (windowSize - 1));
                break;
            case 2:
                window[i] = 0.5 * (1 - cos(2 * PI * i / (windowSize - 1)));
                break;
            case 3:
                window[i] = 0.42 - 0.5 * cos(2 * PI * i / (windowSize - 1)) + 0.08 * cos(4 * PI * i / (windowSize - 1));
                break;
            default:
                window[i] = 1.0;
                break;
        }
    }
}

void applyWindow(float *frameData, float *window, int frameSize) {
    for (int i = 0; i < frameSize; i++) {
        frameData[i] *= window[i];
    }
}

void computeFFT(Complex *signal, int signalLength) {
    if (signalLength <= 1) {
        return;
    }
    int halfLength = signalLength / 2;
    Complex *evenArray = (Complex *) malloc(halfLength * sizeof(Complex));
    Complex *oddArray = (Complex *) malloc(halfLength * sizeof(Complex));
    for (int i = 0; i < halfLength; i++) {
        evenArray[i] = signal[2 * i];
        oddArray[i] = signal[2 * i + 1];
    }
    computeFFT(evenArray, halfLength);
    computeFFT(oddArray, halfLength);
    for (int i = 0; i < signalLength; i++) {
        Complex twiddleFactor;
        if (i < halfLength) {
            float angle = i * (360.0 / signalLength);
            float radian = angle * PI / 180.0;
            twiddleFactor.real = cos(radian);
            twiddleFactor.imag = -sin(radian);
            signal[i].real = evenArray[i].real + twiddleFactor.real * oddArray[i].real - twiddleFactor.imag * oddArray[i].imag;
            signal[i].imag = evenArray[i].imag + twiddleFactor.real * oddArray[i].imag + twiddleFactor.imag * oddArray[i].real;
        }
        else {
            signal[i].real = evenArray[i - halfLength].real + oddArray[i - halfLength].real;
            signal[i].imag = evenArray[i - halfLength].imag + oddArray[i - halfLength].imag;
        }
    }
    free(evenArray);
    free(oddArray);
}

void computeMelFilterbank(float **melFilterbank, int numBins, int sampleRate, int numFilters) {
    int minFrequency = 0;
    int maxFrequency = sampleRate / 2;
    float melMin = 2595 * log10(1 + minFrequency / 700.0);
    float melMax = 2595 * log10(1 + maxFrequency / 700.0);
    float melSpacing = (melMax - melMin) / (numFilters + 1);
    float *hzBins = (float *) malloc(numBins * sizeof(float));
    float *melBins = (float *) malloc((numFilters + 2) * sizeof(float));
    for (int i = 0; i < numBins; i++) {
        hzBins[i] = ((float) i / numBins) * maxFrequency;
    }
    for (int i = 0; i < numFilters + 2; i++) {
        melBins[i] = melMin + i * melSpacing;
    }
    for (int i = 0; i < numFilters; i++) {
        for (int j = 0; j < numBins; j++) {
            melFilterbank[i][j] = 0.0;
        }
        for (int j = 0; j < numBins; j++) {
            float hz = hzBins[j];
            if (hz > melBins[i] && hz < melBins[i + 1]) {
                melFilterbank[i][j] = (hz - melBins[i]) / (melBins[i + 1] - melBins[i]);
            }
            else if (hz > melBins[i + 1] && hz < melBins[i + 2]) {
                melFilterbank[i][j] = (melBins[i + 2] - hz) / (melBins[i + 2] - melBins[i + 1]);
            }
        }
    }
    free(hzBins);
    free(melBins);
}

void computeSpectrogram(float *audioData, int numSamples, int sampleRate, int frameSize, int hopSize, int numFilters, float **spectrogram) {
    int numBins = frameSize / 2 + 1;
    float *window = (float *) malloc(frameSize * sizeof(float));
    float *frameData = (float *) malloc(frameSize * sizeof(float));
    Complex *fftData = (Complex *) malloc(frameSize * sizeof(Complex));
    float **melFilterbank = (float **) malloc(numFilters * sizeof(float *));
    for (int i = 0; i < numFilters; i++) {
        melFilterbank[i] = (float *) malloc(numBins * sizeof(float));
    }
    computeMelFilterbank(melFilterbank, numBins, sampleRate, numFilters);
    for (int i = 0; i < numSamples; i += hopSize) {
        computeFrame(audioData, numSamples, sampleRate, frameSize, hopSize, i / hopSize, frameData);
        computeWindow(window, frameSize, 1);
        applyWindow(frameData, window, frameSize);
        for (int j = 0; j < frameSize; j++) {
            fftData[j].real = frameData[j];
            fftData[j].imag = 0.0;
        }
        computeFFT(fftData, frameSize);
        for (int j = 0; j < numFilters; j++) {
            float filterValue = 0.0;
            for (int k = 0; k < numBins; k++) {
                filterValue += melFilterbank[j][k] * pow(fftData[k].real * fftData[k].real + fftData[k].imag * fftData[k].imag, 0.5);
            }
            spectrogram[i / hopSize][j] = 10 * log10(filterValue);
        }
    }
    free(window);
    free(frameData);
    free(fftData);
    for (int i = 0; i < numFilters; i++) {
        free(melFilterbank[i]);
    }
    free(melFilterbank);
}

int main() {
    float sampleRate = 44100.0;
    int numSamples = 220500;
    int frameSize = 2048;
    int hopSize = 512;
    int numFilters = 40;
    float *audioData = (float *) malloc(numSamples * sizeof(float));
    float **spectrogram = (float **) malloc((numSamples - frameSize) / hopSize * sizeof(float *));
    for (int i = 0; i < (numSamples - frameSize) / hopSize; i++) {
        spectrogram[i] = (float *) malloc(numFilters * sizeof(float));
    }
    for (int i = 0; i < numSamples; i++) {
        audioData[i] = sin(2 * PI * 440.0 * i / sampleRate);
    }
    computeSpectrogram(audioData, numSamples, sampleRate, frameSize, hopSize, numFilters, spectrogram);
    printAudioData(audioData, numSamples, sampleRate);
    printSpectrogram(spectrogram, (numSamples - frameSize) / hopSize, numFilters);
    free(audioData);
    for (int i = 0; i < (numSamples - frameSize) / hopSize; i++) {
        free(spectrogram[i]);
    }
    free(spectrogram);
    return 0;
}