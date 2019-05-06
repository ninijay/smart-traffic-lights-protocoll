#include <stdio.h>
#include <string.h>
#include "stlpp.h"
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

