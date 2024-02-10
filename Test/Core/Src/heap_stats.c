/**
 ******************************************************************************
 * @file           : heap_stats.c
 * @brief          : Heap functions to print stats
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "heap_stats.h"
#include "hex_dump.h"

/* Private user code ---------------------------------------------------------*/
void vPrintHeapStats(HeapStats_t *pxHeapStats)
{
    printf("  Total Heap Size                   : %lu\n\r", (unsigned long)configTOTAL_HEAP_SIZE);
    printf("  Available Space in bytes          : %lu\n\r", (unsigned long)pxHeapStats->xAvailableHeapSpaceInBytes);
    printf("  Largest free block in bytes       : %lu\n\r", (unsigned long)pxHeapStats->xSizeOfLargestFreeBlockInBytes);
    printf("  Smallest free block in bytes      : %lu\n\r", (unsigned long)pxHeapStats->xSizeOfSmallestFreeBlockInBytes);
    printf("  Number of free block              : %lu\n\r", (unsigned long)pxHeapStats->xNumberOfFreeBlocks);
    printf("  Minumum Ever Free Bytes Remaining : %lu\n\r", (unsigned long)pxHeapStats->xMinimumEverFreeBytesRemaining);
    printf("  Successful allocations            : %lu\n\r", (unsigned long)pxHeapStats->xNumberOfSuccessfulAllocations);
    printf("  Successful frees                  : %lu\n\r", (unsigned long)pxHeapStats->xNumberOfSuccessfulFrees);
}

void vPrintBlockStats(BlockStats_t *pxBlockStats)
{
    printf("  Allocated     : %s\n\r", pxBlockStats->ucIsAllocated ? "Yes" : "No");
    printf("  Block pointer : %p\n\r", pxBlockStats->pvBlock);
    printf("  Data pointer  : %p\n\r", pxBlockStats->pvData);
    printf("  Block size    : %lu (bytes)\n\r", (unsigned long)pxBlockStats->xBlockSize);
    printf("  Data size     : %lu (bytes)\n\r", (unsigned long)pxBlockStats->xDataSize);
}
/*----------------------------------------------------------------------------*/