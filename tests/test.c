#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "test_utils.h"

#include "../src/stlpp.h"
#include "../src/stlpp.c"
#ifndef TARGET // must be given by the make file --> see test target
//#error missing TARGET define
#endif

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

// Test input files
#define INFILE_NORMAL_USECASE "normal.input"

// setup & cleanup
static int setup(void)
{
	return 0; // success
}

static int teardown(void)
{
	// Do nothing.
	// Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
	return 0; // success
}

static void test_printenums(){
    // setup
    tl_state red = RED;
    tl_state ryellow = RED_YELLOW;
    tl_state green = GREEN;
    tl_state gyellow = GREEN_YELLOW;
    tl_state empty = EMPTY;
    // assert
    CU_ASSERT(red == 0b0001);
    CU_ASSERT(ryellow == 0b0010);
    CU_ASSERT(green == 0b0100);
    CU_ASSERT(gyellow == 0b1000 );
    CU_ASSERT(empty == 0b0111);
}

static void test_enumsize(){
    // setup
    tl_state red = RED;
    tl_state ryellow = RED_YELLOW;
    tl_state green = GREEN;
    tl_state gyellow = GREEN_YELLOW;
    tl_state empty = EMPTY;
    // assert
    CU_ASSERT(sizeof(red) == 4);
    CU_ASSERT(sizeof(ryellow) == 4);
    CU_ASSERT(sizeof(green) == 4);
    CU_ASSERT(sizeof(gyellow) == 4 );
    CU_ASSERT(sizeof(empty) == 4);
}

static void test_packet(){
    STLPP* pckt = (STLPP *) malloc(21);
    pckt->c_state=RED;
    pckt->n_state=RED_YELLOW;
    pckt->r_id=0b0001;
    pckt->s_id=controller_id;
    printf("\nPacket data:\nSender: %d\nReceiver: %d\nCurrent State: %d\nNext State:%d\n", pckt->s_id, pckt->r_id, pckt->c_state, pckt->n_state);
    
}

/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
	// setup, run, teardown
	// setup, run, teardown
    	TestMainBasic(
    	"Struct",
    	setup,
    	teardown,
    	test_printenums,
        test_enumsize,
        test_packet
    	);
}