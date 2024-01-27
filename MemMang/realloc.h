/**
  ******************************************************************************
  * @file           : realloc.h
  * @brief          : this file export the prototype of pvPortRealloc since not 
  *                   included in portable.h
  ******************************************************************************
  */

#include <stddef.h>
#include "mpu_wrappers.h"

void * pvPortRealloc( void * pv, size_t xWantedSize ) PRIVILEGED_FUNCTION;

#ifdef REALLOC_TEST
    #ifndef BLOCK_STATS_T
    #define BLOCK_STATS_T
    typedef struct xBlockStats
    {
        void * pvBlock;
        void * pvData;
        size_t xBlockSize;
        size_t xDataSize;
        uint8_t ucIsAllocated;
    } BlockStats_t;

    #endif


    void vPortGetBlockStats(BlockStats_t * pxBlockStats, void * pv);
#endif
