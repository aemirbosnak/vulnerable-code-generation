//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <alsa/asoundlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define PLAYER_COUNT 2
#define BUFFER_SIZE 44100

typedef struct {
    int player_id;
    char *sound_file;
} player_t;

void *play_sound(void *arg) {
    player_t *player = (player_t *)arg;
    
    // Open the sound file
    FILE *file = fopen(player->sound_file, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    // Prepare ALSA
    snd_pcm_t *pcm_handle;
    snd_pcm_hw_params_t *params;

    snd_pcm_open(&pcm_handle, "default", SND_PCM_STREAM_PLAYBACK, 0);
    snd_pcm_hw_params_malloc(&params);
    snd_pcm_hw_params_any(pcm_handle, params);
    snd_pcm_hw_params_set_rate_near(pcm_handle, params, &(snd_pcm_uframes_t){44100}, 0);
    snd_pcm_hw_params_set_format(pcm_handle, params, SND_PCM_FORMAT_S16_LE);
    snd_pcm_hw_params_set_channels(pcm_handle, params, 2);
    snd_pcm_hw_params(pcm_handle, params);
    snd_pcm_hw_params_free(params);
    
    // Read sound data and play
    short buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(short), BUFFER_SIZE, file)) > 0) {
        snd_pcm_writei(pcm_handle, buffer, bytes_read);
    }

    fclose(file);
    snd_pcm_drain(pcm_handle);
    snd_pcm_close(pcm_handle);
    return NULL;
}

void *player_action(void *arg) {
    player_t *player = (player_t *)arg;

    printf("Player %d is waiting to perform an action...\n", player->player_id);
    sleep(rand() % 5 + 1); // Simulate random delays for player actions
    printf("Player %d performed an action!\n", player->player_id);
    
    pthread_t sound_thread;
    pthread_create(&sound_thread, NULL, play_sound, (void *)player);
    pthread_detach(sound_thread); // Detach thread to play sound independently
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < PLAYER_COUNT + 1) {
        fprintf(stderr, "Usage: %s <sound_file_1> <sound_file_2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pthread_t players[PLAYER_COUNT];
    player_t player_data[PLAYER_COUNT];

    for (int i = 0; i < PLAYER_COUNT; i++) {
        player_data[i].player_id = i + 1;
        player_data[i].sound_file = argv[i + 1];
        pthread_create(&players[i], NULL, player_action, (void *)&player_data[i]);
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        pthread_join(players[i], NULL);
    }

    return 0;
}