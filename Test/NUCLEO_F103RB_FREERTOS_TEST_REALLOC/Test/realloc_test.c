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
    printf("************************************************************\n\r");
    printf("*  [TEST]   Reallocate memory to a greater size            *\n\r");
    printf("************************************************************\n\r");
    printf("\n\r");

    HeapStats_t xHeapStats;
    BlockStats_t xBlockStats;
    BlockStats_t xNewBlockStats;

    /* The number of elements to be allocated */
    size_t xInitSize = 10;
    size_t xNewSize = 30;

    /* Initialized pointer */
    char *pcBuff = NULL;
    char *pcNewBuff = NULL;

    /* The pointer is allocated */
    printf("---[DEBUG]--- Malloc is called with wantedSize %lu bytes\n\r", (unsigned long)xInitSize * sizeof(char));
    pcBuff = (char *)pvPortMalloc(xInitSize * sizeof(char));

    /* Check that the pointer is allocated */
    if (pcBuff == NULL)
    {
        printf("Malloc failed\n\r");
        return;
    }

    /* Initialize the buffer with some data */
    printf("---[DEBUG]--- Buffer initialized with %lu char (%c)\n\r", (unsigned long)xInitSize, 'a');
    for (int i = 0; i < xInitSize; i++)
    {
        pcBuff[i] = 'a';
    }

    printf("\n\r");
    printf("Initial Block stats:\n\r");
    vPortGetBlockStats(&xBlockStats, (void *)pcBuff);
    prvPrintBlockStats(&xBlockStats);
    printf("\n\r");
    hexDump("Block Memory", xBlockStats.pvBlock, xBlockStats.xBlockSize);

    /* Reallocate the memory */
    printf("\n\r");
    printf("---[DEBUG]--- Memory is reallocated with new size %lu\n\r", (unsigned long)xNewSize * sizeof(char));
    pcNewBuff = (char *)pvPortRealloc((void *)pcBuff, xNewSize);

    /* Check the memory is allocated */
    if (pcNewBuff == NULL)
    {
        printf("The memory has not been reallocated\n\r");
        return;
    }

    printf("\n\r");
    printf("New Block stats:\n\r");
    vPortGetBlockStats(&xNewBlockStats, (void *)pcNewBuff);
    prvPrintBlockStats(&xNewBlockStats);
    printf("\n\r");
    hexDump("Block Memory", xNewBlockStats.pvBlock, xNewBlockStats.xBlockSize);

    printf("\n\r");
    hexDump("Old Block Memory", xBlockStats.pvBlock, xBlockStats.xBlockSize);

    printf("\n\r");
    printf("---[DEBUG]--- Used memory is freed\n\r");
    vPortFree(pcNewBuff);

    printf("\n\r");
    printf("Heap Stats:\n\r");
    vPortGetHeapStats(&xHeapStats);
    prvPrintHeapStats(&xHeapStats);

    printf("\n\r");
    printf("************************************************************\n\r");

    printf("\n\r\n\r");

    printf("************************************************************\n\r");
    printf("*  [TEST]   Reallocate memory to a smaller size            *\n\r");
    printf("************************************************************\n\r");
    printf("\n\r");

    xInitSize = 30;
    xNewSize = 10;

    /* Initialize pointer */
    pcBuff = NULL;
    pcNewBuff = NULL;

    /* The pointer is allocated */
    printf("---[DEBUG]--- Malloc is called with wantedSize %lu bytes\n\r", (unsigned long)xInitSize * sizeof(char));
    pcBuff = (char *)pvPortMalloc(xInitSize * sizeof(char));

    /* Check that the pointer is allocated */
    if (pcBuff == NULL)
    {
        printf("Malloc failed\n\r");
        return;
    }

    /* Initialize the buffer with some data */
    printf("---[DEBUG]--- Buffer initialized with %lu char (%c)\n\r", (unsigned long)xInitSize, 'b');
    for (int i = 0; i < xInitSize; i++)
    {
        pcBuff[i] = 'b';
    }

    printf("\n\r");
    printf("Initial Block stats:\n\r");
    vPortGetBlockStats(&xBlockStats, (void *)pcBuff);
    prvPrintBlockStats(&xBlockStats);
    printf("\n\r");
    hexDump("Block Memory", xBlockStats.pvBlock, xBlockStats.xBlockSize);

    /* Reallocate the memory */
    printf("\n\r");
    printf("---[DEBUG]--- Memory is reallocated with new size %lu\n\r", (unsigned long)xNewSize * sizeof(char));
    pcNewBuff = (char *)pvPortRealloc((void *)pcBuff, xNewSize);

    /* Check the memory is allocated */
    if (pcNewBuff == NULL)
    {
        printf("The memory has not been reallocated\n\r");
        return;
    }

    printf("\n\r");
    printf("New Block stats:\n\r");
    vPortGetBlockStats(&xNewBlockStats, (void *)pcNewBuff);
    prvPrintBlockStats(&xNewBlockStats);
    printf("\n\r");
    hexDump("Block Memory", xNewBlockStats.pvBlock, xNewBlockStats.xBlockSize);

    printf("\n\r");
    hexDump("Old Block Memory", xBlockStats.pvBlock, xBlockStats.xBlockSize);

    printf("\n\r");
    printf("---[DEBUG]--- Used memory is freed\n\r");
    vPortFree(pcNewBuff);

    printf("\n\r");
    printf("Heap Stats:\n\r");
    vPortGetHeapStats(&xHeapStats);
    prvPrintHeapStats(&xHeapStats);

    printf("\n\r");
    printf("************************************************************\n\r");
}

void vTestAllocate()
{
    printf("************************************************************\n\r");
    printf("*  [TEST]   Allocate memory using realloc                  *\n\r");
    printf("************************************************************\n\r");
    printf("\n\r");

    HeapStats_t xHeapStats;
    BlockStats_t xBlockStats;

    /* The number of elements to be allocated */
    size_t xWantedSize = 10;

    /* Initialized pointer */
    char *pcBuff = NULL;

    /* The pointer is allocated */
    printf("---[DEBUG]--- Realloc is called with wantedSize %lu bytes and\n\r", (unsigned long)xWantedSize * sizeof(char));
    printf("              NULL pointer\n\r");
    pcBuff = (char *)pvPortRealloc(NULL, xWantedSize * sizeof(char));

    /* Check that the pointer is allocated */
    if (pcBuff == NULL)
    {
        printf("Realloc failed\n\r");
        return;
    }

    /* Initialize the buffer with some data */
    printf("---[DEBUG]--- Buffer initialized with %lu char (%c)\n\r", (unsigned long)xWantedSize, 'c');
    for (int i = 0; i < xWantedSize; i++)
    {
        pcBuff[i] = 'c';
    }

    printf("\n\r");
    printf("Block stats:\n\r");
    vPortGetBlockStats(&xBlockStats, (void *)pcBuff);
    prvPrintBlockStats(&xBlockStats);
    printf("\n\r");
    hexDump("Block Memory", xBlockStats.pvBlock, xBlockStats.xBlockSize);

    printf("\n\r");
    printf("---[DEBUG]--- Used memory is freed\n\r");
    vPortFree(pcBuff);

    printf("\n\r");
    printf("Heap Stats:\n\r");
    vPortGetHeapStats(&xHeapStats);
    prvPrintHeapStats(&xHeapStats);

    printf("\n\r");
    printf("************************************************************\n\r");
}

void vTestFree()
{
    printf("************************************************************\n\r");
    printf("*  [TEST]   Free memory uising realloc                     *\n\r");
    printf("************************************************************\n\r");
    printf("\n\r");

    HeapStats_t xHeapStats;
    BlockStats_t xBlockStats;

    /* The number of elements to be allocated */
    size_t xWantedSize = 10;
    size_t xNewSize = 0;

    /* Initialized pointer */
    char *pcBuff = NULL;
    char *pcNewBuff = NULL;

    /* The pointer is allocated */
    printf("---[DEBUG]--- Malloc is called with wantedSize %lu\n\r", (unsigned long)xWantedSize * sizeof(char));
    pcBuff = (char *)pvPortMalloc(xWantedSize * sizeof(char));

    /* Check that the pointer is allocated */
    if (pcBuff == NULL)
    {
        printf("Malloc failed\n\r");
        return;
    }

    /* Initialize the buffer with some data */
    printf("---[DEBUG]--- Buffer initialized with %lu char (%c)\n\r", (unsigned long)xWantedSize, 'd');
    for (int i = 0; i < xWantedSize; i++)
    {
        pcBuff[i] = 'd';
    }

    printf("\n\r");
    printf("Block stats:\n\r");
    vPortGetBlockStats(&xBlockStats, (void *)pcBuff);
    prvPrintBlockStats(&xBlockStats);
    printf("\n\r");
    hexDump("Block Memory", xBlockStats.pvBlock, xBlockStats.xBlockSize);

    /* Reallocate the memory */
    printf("\n\r");
    printf("---[DEBUG]--- Memory is reallocated with new size %lu\n\r", (unsigned long)xNewSize * sizeof(char));
    pcNewBuff = (char *)pvPortRealloc((void *)pcBuff, xNewSize);

    /* Check that the pointer has been freed */
    if (pcNewBuff != NULL)
    {
        printf("Realloc free failed\n\r");
        return;
    }

    printf("\n\r");
    hexDump("Block Memory", xBlockStats.pvBlock, xBlockStats.xBlockSize);

    printf("\n\r");
    printf("Heap Stats:\n\r");
    vPortGetHeapStats(&xHeapStats);
    prvPrintHeapStats(&xHeapStats);

    printf("\n\r");
    printf("************************************************************\n\r");
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
    printf("Block size    : %lu (bytes)\n\r", (unsigned long)pxBlockStats->xBlockSize);
    printf("Data size     : %lu (bytes)\n\r", (unsigned long)pxBlockStats->xDataSize);
}