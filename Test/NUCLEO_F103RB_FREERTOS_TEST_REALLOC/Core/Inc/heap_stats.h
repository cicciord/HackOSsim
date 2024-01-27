/**
  ******************************************************************************
  * @file           : heap_stats.h
  * @brief          : Header for heap_stats.c file.
  ******************************************************************************
  */

#ifndef HEAP_STATS
#define HEAP_STATS

#include "FreeRTOS.h"
#include "realloc.h"

/* Exported functions prototypes ---------------------------------------------*/
void vPrintHeapStats(HeapStats_t *pxHeapStats);
void vPrintBlockStats(BlockStats_t *pxBlockStats);

#endif