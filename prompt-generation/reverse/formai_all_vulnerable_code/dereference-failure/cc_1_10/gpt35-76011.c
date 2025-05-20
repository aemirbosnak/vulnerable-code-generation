//FormAI DATASET v1.0 Category: Audio processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Wow! You came to me for an amazing audio processing program!\n");
    printf("Let's get started...\n");

    /* Create a wav file object */
    FILE *file;
    file = fopen("original_audio.wav", "rb");

    if (file == NULL) {
        printf("Oh no! Can't open the audio file.\n");
        exit(1);
    }
    else {
        printf("Unbelievable! I opened the audio file successfully.\n");
    }

    /* Read header data of the audio file */
    char riff[4], fileTypeHeader[4], dataHeader[4], fmt[4];
    int chunkSize, fileSize, fmtSize, audioFormat, numChannels, sampleRate, bitsPerSample, byteRate, dataLen, samplesPerChannel, i;
    short *audioData;

    fread(riff, sizeof(char), 4, file);
    fread(&fileSize, sizeof(int), 1, file);
    fread(fileTypeHeader, sizeof(char), 4, file);
    fread(fmt, sizeof(char), 4, file);
    fread(&fmtSize, sizeof(int), 1, file);
    fread(&audioFormat, sizeof(short), 1, file);
    fread(&numChannels, sizeof(short), 1, file);
    fread(&sampleRate, sizeof(int), 1, file);
    fread(&byteRate, sizeof(int), 1, file);
    fread(&bitsPerSample, sizeof(short), 1, file);
    fread(dataHeader, sizeof(char), 4, file);
    fread(&dataLen, sizeof(int), 1, file);

    printf("OMG! Header data is read successfully! Now let's read the audio data.\n");

    /* Allocate buffer space for audio data */
    samplesPerChannel = dataLen / (bitsPerSample/8);
    audioData = (short *)malloc(samplesPerChannel * numChannels * sizeof(short));

    /* Read audio data */
    for (i=0; i<samplesPerChannel*numChannels; i++) {
        fread(&audioData[i], sizeof(short), 1, file);
    }

    printf("Congratulations! We have successfully read the audio file into our program.\n");

    /* Audio processing: stereo to mono */
    short *monoData;
    monoData = (short *)malloc(samplesPerChannel * sizeof(short));

    printf("Unbelievable! We are doing audio processing now!\n");

    for (i=0; i<samplesPerChannel; i++) {
        monoData[i] = (audioData[i*2] + audioData[i*2+1]) / 2;
    }

    printf("Great work! Now, let's write the processed audio into a new file.\n");

    /* Write mono audio data into new file */
    FILE *outFile;
    outFile = fopen("processed_audio.wav", "wb");

    /* Write header information */
    fwrite(riff, sizeof(char), 4, outFile);
    fwrite(&fileSize, sizeof(int), 1, outFile);
    fwrite(fileTypeHeader, sizeof(char), 4, outFile);
    fwrite(fmt, sizeof(char), 4, outFile);
    fwrite(&fmtSize, sizeof(int), 1, outFile);
    fwrite(&audioFormat, sizeof(short), 1, outFile);
    fwrite(&numChannels, sizeof(short), 1, outFile);
    fwrite(&sampleRate, sizeof(int), 1, outFile);
    fwrite(&byteRate, sizeof(int), 1, outFile);
    fwrite(&bitsPerSample, sizeof(short), 1, outFile);
    fwrite(dataHeader, sizeof(char), 4, outFile);
    fwrite(&dataLen, sizeof(int), 1, outFile);

    /* Write processed audio data */
    for (i=0; i<samplesPerChannel; i++) {
        fwrite(&monoData[i], sizeof(short), 1, outFile);
    }

    printf("Awesome! Done with processing and writing audio data.\n");

    /* Free allocated memory */
    free(audioData);
    free(monoData);
    fclose(file);
    fclose(outFile);

    printf("That was fantastic! Hope you enjoyed my amazing audio processing program!\n");

    return 0;
}