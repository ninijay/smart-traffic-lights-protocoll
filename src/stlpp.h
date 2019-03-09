#ifndef STLPP_H
#define STLPP_H

#include <stdlib.h>

const uint32_t default_stlpp_size = 21;
const uint8_t controller_id=0;

typedef enum traffic_lights_states {
    RED = 0b0001,
    RED_YELLOW = 0b0010,
    GREEN = 0b0100,
    GREEN_YELLOW = 0b1000,
    EMPTY = 0b0111
} tl_state;

typedef struct stlpp
{
    uint32_t size; // should always equal to default_stlpp_size 
    uint8_t s_id;
    uint8_t r_id;
    tl_state c_state;
    tl_state n_state;
} STLPP;



#endif //STLPP_H