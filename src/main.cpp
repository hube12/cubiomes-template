// check the biome at a block position
#include "finders.h"
#include <cstdio>

int main() {
    // Initialize a stack of biome layers that reflects the biome generation of
    // Minecraft 1.16
    Generator g;
    setupGenerator(&g, MC_1_16, 0);

    int64_t seed;
    Pos3 pos = {0, 0, 0}; // block position to be checked

    for (seed = 0;; seed++) {
        // Go through the layers in the layer stack and initialize the seed
        // dependent aspects of the generator.
        applySeed(&g, DIM_OVERWORLD, seed);

        // To get the biome at single block position we can use getBiomeAtPos().
        int biomeID = getBiomeAt(&g, 1, pos.x, pos.y, pos.z);
        if (biomeID == jungle_edge)
            break;
    }

    printf("Seed %" PRId64 " has a Junge Edge biome at block position "
           "(%d, %d).\n", seed, pos.x, pos.z);

    return 0;
}