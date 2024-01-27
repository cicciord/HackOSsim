/**
 ******************************************************************************
 * @file           : malloc_test.c
 * @brief          : Test functions for malloc
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "malloc_test.h"
#include <stdio.h>
#include "FreeRTOS.h"
#include "hex_dump.h"
#include "realloc.h"
#include "heap_stats.h"

/* Private user code ---------------------------------------------------------*/
void vTestBestFit()
{
    printf("************************************************************\n\r");
    printf("*  [TEST]   Reallocate memory to a greater size            *\n\r");
    printf("************************************************************\n\r");
    printf("\n\r");

    BlockStats_t xFirstBlockStats;
    BlockStats_t xSecondBlockStats;
    BlockStats_t xThirdBlockStats;
    BlockStats_t xFourthBlockStats;
    BlockStats_t xBlockStats;
    void * pvFirstBlock64;
    void * pvSecondBlock32;
    void * pvThirdBlock32;
    void * pvFourthBlock32;
    void * pv;

    printf("---[DEBUG]--- A first block is allocated of size 64bytes\n\r");
    pvFirstBlock64 = pvPortMalloc(64);
    if( pvFirstBlock64 == NULL )
    {
        printf("Malloc failed\n");
        return;
    }

    printf("\n\r");
    printf("---[DEBUG]--- A second block is allocated of size 64bytes\n\r");
    pvSecondBlock32 = pvPortMalloc(32);
    if( pvSecondBlock32 == NULL )
    {
        printf("Malloc failed\n");
        return;
    }

    printf("\n\r");
    printf("---[DEBUG]--- A third block is allocated of size 64bytes\n\r");
    pvThirdBlock32 = pvPortMalloc(32);
    if( pvThirdBlock32 == NULL )
    {
        printf("Malloc failed\n");
        return;
    }

    printf("\n\r");
    printf("---[DEBUG]--- A fourth block is allocated of size 64bytes\n\r");
    pvFourthBlock32 = pvPortMalloc(32);
    if( pvFourthBlock32 == NULL )
    {
        printf("Malloc failed\n");
        return;
    }

    printf("\n\r");
    printf("---[DEBUG]--- Free the first block to leave a hole of 64bytes\n\r");
    vPortFree(pvFirstBlock64);

    printf("\n\r");
    printf("---[DEBUG]--- Free the third block to leave a hole of 32bytes\n\r");
    vPortFree(pvThirdBlock32);

    printf("\n\r");
    printf("First Block stats:\n\r");
    vPortGetBlockStats(&xFirstBlockStats, pvFirstBlock64);
    vPrintBlockStats(&xFirstBlockStats);

    printf("\n\r");
    printf("Second Block stats:\n\r");
    vPortGetBlockStats(&xSecondBlockStats, pvSecondBlock32);
    vPrintBlockStats(&xSecondBlockStats);

    printf("\n\r");
    printf("Third Block stats:\n\r");
    vPortGetBlockStats(&xThirdBlockStats, pvThirdBlock32);
    vPrintBlockStats(&xThirdBlockStats);

    printf("\n\r");
    printf("Fourth Block stats:\n\r");
    vPortGetBlockStats(&xFourthBlockStats, pvFourthBlock32);
    vPrintBlockStats(&xFourthBlockStats);

    printf("\n\r");
    printf("---[DEBUG]--- Allocate a new block of 32 bytes\n\r");
    pv = pvPortMalloc(32);
    if( pv == NULL )
    {
        printf("Malloc failed\n");
        return;
    }
    printf("\n\r");
    printf("Block stats:\n\r");
    vPortGetBlockStats(&xBlockStats, pv);
    vPrintBlockStats(&xBlockStats);
 
    printf("\n\r");
    printf("************************************************************\n\r");
}

/*----------------------------------------------------------------------------*/