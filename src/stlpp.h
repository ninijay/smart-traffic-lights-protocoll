#ifndef STLPP_H
#define STLPP_H

#include <stdlib.h>
#include <stdint.h>

const uint8_t controller_id=0b0000;

typedef enum traffic_lights_states {
    RED = 0b0001,
    RED_YELLOW = 0b0010,
    GREEN = 0b0100,
    GREEN_YELLOW = 0b1000,
    EMPTY = 0b0111
} tl_state;

typedef struct stlpp
{
    uint8_t s_id;
    uint8_t r_id;
    tl_state c_state;
    tl_state n_state;
} STLPP;

STLPP* makeSTLPP(uint8_t s_id, uint8_t r_id, tl_state c_state, tl_state n_state);
char* serializeSTLPP(STLPP* packet);

#endif //STLPP_H
