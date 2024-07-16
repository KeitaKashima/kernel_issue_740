/*
 * event_process.h
 */
#ifndef EVENT_PROCESS_H_
#define EVENT_PROCESS_H_

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "rl78_serial_term_uart.h"

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/
#define INTERRUPT_PERIODIC_TIMER    ( 1 << 0 )

/**********************************************************************************************************************
 Global Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 External global variables
 *********************************************************************************************************************/
extern EventGroupHandle_t event_group_handle;
extern BaseType_t g_xHigherPriorityTaskWoken;
extern TaskHandle_t tskhdl_interrupt;
extern TaskStatus_t tskinfo_interrupt;

/**********************************************************************************************************************
 Exported global functions
 *********************************************************************************************************************/
void vCreate_event_group( void );
void event_receive_task( void * pvParameters );

#endif /* EVENT_PROCESS_H_ */