//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct remote_control {
    bool on;
    int channel;
    int volume;
};

void turn_on(struct remote_control *remote) {
    remote->on = true;
    printf("Remote turned on.\n");
}

void turn_off(struct remote_control *remote) {
    remote->on = false;
    printf("Remote turned off.\n");
}

void change_channel(struct remote_control *remote, int new_channel) {
    if(remote->on) {
        remote->channel = new_channel;
        printf("Channel changed to %d.\n", remote->channel);
    }
    else {
        printf("Remote is off, turn on first.\n");
    }
}

void adjust_volume(struct remote_control *remote, int change) {
    if(remote->on) {
        remote->volume += change;
        if(remote->volume < 0)
            remote->volume = 0;
        else if(remote->volume > 100)
            remote->volume = 100;

        printf("Volume adjusted to %d.\n", remote->volume);
    }
    else {
        printf("Remote is off, turn on first.\n");
    }
}

int main() {
    struct remote_control *my_remote = malloc(sizeof(struct remote_control));

    my_remote->on = false;
    my_remote->channel = 1;
    my_remote->volume = 50;

    turn_on(my_remote);
    change_channel(my_remote, 5);
    adjust_volume(my_remote, 10);
    adjust_volume(my_remote, -15);
    
    turn_off(my_remote);

    free(my_remote);

    return 0;
}