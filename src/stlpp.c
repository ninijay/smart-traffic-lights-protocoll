#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stlpp.h"
#include <assert.h>
STLPP* makeSTLPP(uint8_t s_id, uint8_t r_id, tl_state c_state, tl_state n_state){
    STLPP* p=(STLPP*)malloc(sizeof(STLPP));
    if(p){	
	p->s_id=s_id;
	p->r_id=r_id;
	p->c_state=c_state;
	p->n_state=n_state;
	return p;
    }
    return NULL;
}

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = (char**)malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

STLPP* makeSTLPP(char* p){
    char d='|';
    char** tokens;

    tokens = str_split(p, d);
    uint8_t s_id = atoi(*(tokens+0));
    uint8_t r_id = atoi(*(tokens+1));
    tl_state c_state = (tl_state)atoi(*(tokens+2));
    tl_state n_state = (tl_state)atoi(*(tokens+3));
    return makeSTLPP(s_id, r_id, c_state, n_state);
}

char* serializeSTLPP(STLPP* p){
   char* s = (char*)malloc(256);
   char s_id[32];
   char r_id[32];
   char c_state[32];
   char n_state[32];
   char* d= "|";

   sprintf(s_id, "%d", p->s_id);
   sprintf(r_id, "%d", p->r_id);
   sprintf(c_state, "%d", p->c_state);
   sprintf(n_state, "%d", p->n_state);
   strcat(s, s_id);
   strcat(s,d);
   strcat(s, r_id);
   strcat(s, d);
   strcat(s, c_state);
   strcat(s, d);
   strcat(s, n_state);

   return s;
}

