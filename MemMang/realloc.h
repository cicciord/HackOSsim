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
    typedef struct xBlockStats
    {
        void * pvBlock;
        void * pvData;
        size_t xBlockSize;
        size_t xDataSize;
    } BlockStats_t;


    void vPortGetBlockStats(BlockStats_t * pxBlockStats, void * pv);
#endif
