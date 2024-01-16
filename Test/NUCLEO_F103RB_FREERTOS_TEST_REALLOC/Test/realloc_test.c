/**
 ******************************************************************************
 * @file           : realloc_test.c
 * @brief          : Test functions for realloc
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "realloc_test.h"
#include <stdio.h>
#include "FreeRTOS.h"
#include "hex_dump.h"
#include "realloc.h"

/* Private function prototypes -----------------------------------------------*/
void prvPrintHeapStats(HeapStats_t *pxHeapStats);
void prvPrintBlockStats(BlockStats_t *pxBlockStats);

/* Private user code ---------------------------------------------------------*/
void vTestReallocate()
{
    printf("[TEST] Reallocate memory to a greater size\n\r\n\r");

    HeapStats_t xHeapStats;
    BlockStats_t xBlockStats;
    BlockStats_t xNewBlockStats;

    /* The number of elements to be allocated */
    size_t xInitSize = 10;
    size_t xNewSize = 30;

    /* Initialized pointer */
    char *buff = NULL;
    char *newBuff = NULL;

    /* The pointer is allocated */
    printf("Malloc is called with wantedSize %lu bytes\n\r\n\r", (unsigned long) xInitSize * sizeof(char));
    buff = (char *)pvPortMalloc(xInitSize * sizeof(char));

    /* Check that the pointer is allocated */
    if (buff == NULL)
    {
        printf("Malloc failed\n\r");
        return;
    }

    /* Initialize the buffer with some data */
    printf("Buffer initialized with %lu char (%c)\n\r\n\r", (unsigned long)xInitSize, 'a');
    for (int i = 0; i < xInitSize; i++)
    {
        buff[i] = 'a';
    }

    printf("Initial Block stats:\n\r");
    vPortGetBlockStats(&xBlockStats, (void *)buff);
    prvPrintBlockStats(&xBlockStats);
    printf("\n\r");
    hexDump("Block Memory", xBlockStats.pvBlock, xBlockStats.xBlockSize);

    printf("\n\r\n\r");
    /* Reallocate the memory */
    printf("Memory is reallocated with new size %lu\n\r\n\r", (unsigned long)xNewSize * sizeof(char));
    newBuff = (char *)pvPortRealloc((void *)buff, xNewSize);

    /* Check the memory is allocated */
    if (newBuff == NULL)
    {
        printf("The memory has not been reallocated\n\r");
        return;
    }

    printf("New Block stats:\n\r");
    vPortGetBlockStats(&xNewBlockStats, (void *)newBuff);
    prvPrintBlockStats(&xNewBlockStats);
    printf("\n\r");
    hexDump("Block Memory", xNewBlockStats.pvBlock, xNewBlockStats.xBlockSize);

    printf("\n\r");
    hexDump("Old Block Memory", xBlockStats.pvBlock, xBlockStats.xBlockSize);

    printf("\n\r\n\rHeap Stats:\n\r");
    vPortGetHeapStats(&xHeapStats);
    prvPrintHeapStats(&xHeapStats);

    printf("\n\r[END TEST]\n\r");
}

/*----------------------------------------------------------------------------*/

void prvPrintHeapStats(HeapStats_t *pxHeapStats)
{
    printf("Total Heap Size                   : %lu\n\r", (unsigned long)configTOTAL_HEAP_SIZE);
    printf("Available Space in bytes          : %lu\n\r", (unsigned long)pxHeapStats->xAvailableHeapSpaceInBytes);
    printf("Largest free block in bytes       : %lu\n\r", (unsigned long)pxHeapStats->xSizeOfLargestFreeBlockInBytes);
    printf("Smallest free block in bytes      : %lu\n\r", (unsigned long)pxHeapStats->xSizeOfSmallestFreeBlockInBytes);
    printf("Number of free block              : %lu\n\r", (unsigned long)pxHeapStats->xNumberOfFreeBlocks);
    printf("Minumum Ever Free Bytes Remaining : %lu\n\r", (unsigned long)pxHeapStats->xMinimumEverFreeBytesRemaining);
    printf("Successful allocations            : %lu\n\r", (unsigned long)pxHeapStats->xNumberOfSuccessfulAllocations);
    printf("Successful frees                  : %lu\n\r", (unsigned long)pxHeapStats->xNumberOfSuccessfulFrees);
}

void prvPrintBlockStats(BlockStats_t *pxBlockStats)
{
    printf("Block pointer : %p\n\r", pxBlockStats->pvBlock);
    printf("Data pointer  : %p\n\r", pxBlockStats->pvData);
    printf("Block size    : %lu (bytes)\n\r", (unsigned long) pxBlockStats->xBlockSize);
    printf("Data size     : %lu (bytes)\n\r", (unsigned long) pxBlockStats->xDataSize);
}