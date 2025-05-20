//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: curious
// Behold, a tale of the curious and capricious RAM monitor!

#include <stdio.h>
#include <stdlib.h>

// Why, oh why, would we need a RAM monitor? For the sheer joy of it!

typedef struct {
    size_t size;
    void *ptr;
} RamBlock;

// Let us conjure up an array of memory blocks, each with a mischievous personality.
RamBlock *ramBlocks;

// Now, let us count the blocks, for curiosity's sake.
size_t ramBlockCount = 0;

// And because we can, let us make a grand entrance, announcing our arrival to the world.
void ramMonitorInit() {
    printf("Ahoy there, me hearties! The RAM monitor has arrived!\n");
    printf("Prepare yerselves for a grand spectacle of memory shenanigans!\n");
}

// Now, let us create a new block of memory. Shall we?
void *ramMonitorAlloc(size_t size) {
    printf("Arrr, shiver me timbers! A new land has been discovered!\n");
    printf("Allocating %lu bytes of memory, matey!\n", size);
    
    // Now, let us summon a block of memory from the depths of the abyss.
    void *ptr = malloc(size);
    
    // If the memory is as elusive as a ghost ship, we shall hoist a warning flag.
    if (ptr == NULL) {
        printf("Avast there, matey! The memory be scarce!\n");
        return NULL;
    }
    
    // Now, let us add this new block to our merry band of buccaneers.
    RamBlock block = {size, ptr};
    ramBlocks = realloc(ramBlocks, (ramBlockCount + 1) * sizeof(RamBlock));
    ramBlocks[ramBlockCount++] = block;
    
    // And finally, let us proudly proclaim our conquest!
    printf("Land ho! Memory block successfully allocated!\n");
    return ptr;
}

// But alas, all good things must come to an end. Let us free that memory block.
void ramMonitorFree(void *ptr) {
    printf("Avast there, matey! The time has come to bid farewell to a memory block.\n");
    
    // Let us search high and low for the block that be matching our pointer.
    size_t i;
    for (i = 0; i < ramBlockCount; i++) {
        if (ramBlocks[i].ptr == ptr) {
            break;
        }
    }
    
    // If the block could not be found, then shiver me timbers, it be a ghost!
    if (i == ramBlockCount) {
        printf("Yo ho ho, the memory block be nowhere to be found!\n");
        return;
    }
    
    // Now, let us send the memory block back to Davy Jones' Locker.
    free(ramBlocks[i].ptr);
    
    // And finally, let us remove the block from our merry band.
    ramBlocks[i] = ramBlocks[ramBlockCount - 1];
    ramBlockCount--;
    
    printf("Memory block successfully freed, me hearty!\n");
}

// Now, let us unleash our final act, a grand summary of our memory usage.
void ramMonitorPrint() {
    printf("Behold, mateys! The grand summary of our memory usage:\n");
    
    // Let us tally up the total memory we have plundered.
    size_t totalMemory = 0;
    for (size_t i = 0; i < ramBlockCount; i++) {
        totalMemory += ramBlocks[i].size;
    }
    
    printf("Total memory allocated: %lu bytes\n", totalMemory);
    printf("Number of memory blocks: %lu\n", ramBlockCount);
    
    // Now, let us sing a sea shanty about each and every block.
    for (size_t i = 0; i < ramBlockCount; i++) {
        printf("Memory block %lu: size %lu bytes, address %p\n", i, ramBlocks[i].size, ramBlocks[i].ptr);
    }
}

// And now, let us set sail and embark on our adventure!
int main() {
    // First, let us initialize our RAM monitor, for without it, we be lost at sea.
    ramMonitorInit();
    
    // Now, let us allocate a few memory blocks, just for the fun of it.
    void *block1 = ramMonitorAlloc(1024);
    void *block2 = ramMonitorAlloc(2048);
    void *block3 = ramMonitorAlloc(4096);
    
    // But hold on there, matey! Let us free one of the blocks, just to show off our prowess.
    ramMonitorFree(block2);
    
    // And now, let us print out a summary of our memory usage, for the world to see.
    ramMonitorPrint();
    
    // Finally, let us free the remaining memory blocks and bid farewell to the RAM monitor.
    ramMonitorFree(block1);
    ramMonitorFree(block3);
    
    printf("Farewell, me hearties! The RAM monitor has sailed into the sunset.\n");
    return 0;
}