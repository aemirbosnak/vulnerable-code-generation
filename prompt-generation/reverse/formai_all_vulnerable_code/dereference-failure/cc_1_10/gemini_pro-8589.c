//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <portaudio.h>

#define NUM_SECONDS   (2)
#define SAMPLE_RATE   (44100)
#define NUM_CHANNELS   (2)
#define NUM_FRAMES    (NUM_SECONDS * SAMPLE_RATE)
#define PI            (3.14159265)

typedef struct {
    float frequency;
    float amplitude;
} Note;

typedef struct {
    int numNotes;
    Note *notes;
} Music;

Music createMusic() {
    Music music;
    music.numNotes = 4;
    music.notes = malloc(sizeof(Note) * music.numNotes);

    music.notes[0].frequency = 261.63; // C4
    music.notes[0].amplitude = 0.5;
    music.notes[1].frequency = 329.63; // E4
    music.notes[1].amplitude = 0.3;
    music.notes[2].frequency = 392.00; // G4
    music.notes[2].amplitude = 0.2;
    music.notes[3].frequency = 440.00; // A4
    music.notes[3].amplitude = 0.1;

    return music;
}

void freeMusic(Music *music) {
    free(music->notes);
}

int main() {
    PaStream *stream;
    PaError err;

    Music music = createMusic();

    err = Pa_Initialize();
    if (err != paNoError) goto error;

    err = Pa_OpenDefaultStream(&stream, NUM_CHANNELS, paFloat32, paNoFlag, SAMPLE_RATE, NUM_FRAMES, NULL, NULL);
    if (err != paNoError) goto error;

    err = Pa_StartStream(stream);
    if (err != paNoError) goto error;

    float buffer[NUM_FRAMES * NUM_CHANNELS];
    for (int i = 0; i < NUM_FRAMES * NUM_CHANNELS; i++) {
        buffer[i] = 0.0;
    }

    for (int i = 0; i < music.numNotes; i++) {
        Note note = music.notes[i];
        for (int j = 0; j < NUM_FRAMES; j++) {
            buffer[j * NUM_CHANNELS] += note.amplitude * sin(2 * PI * note.frequency * j / SAMPLE_RATE);
            buffer[j * NUM_CHANNELS + 1] += note.amplitude * sin(2 * PI * note.frequency * j / SAMPLE_RATE);
        }
    }

    err = Pa_WriteStream(stream, buffer, NUM_FRAMES);
    if (err != paNoError) goto error;

    err = Pa_StopStream(stream);
    if (err != paNoError) goto error;

    err = Pa_CloseStream(stream);
    if (err != paNoError) goto error;

    Pa_Terminate();
    freeMusic(&music);
    return 0;

error:
    Pa_Terminate();
    freeMusic(&music);
    fprintf(stderr, "An error occurred: %s\n", Pa_GetErrorText(err));
    return 1;
}