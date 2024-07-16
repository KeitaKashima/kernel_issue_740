/*
 * test_main.h
 */

#ifndef TEST_MAIN_H_
#define TEST_MAIN_H_

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "FreeRTOS.h"
#include "rl78_serial_term_uart.h"
#include "event_recv_task.h"

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/
#define CFG_TSKPRI_DAEMON                  (configTIMER_TASK_PRIORITY)
#define CFG_TSKPRI_EVENT_RECV_TASK         (CFG_TSKPRI_DAEMON)
#define CFG_STACK_DEPTH_EVENT_RECV_TASK    (512)

/**********************************************************************************************************************
 Global Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 External global variables
 *********************************************************************************************************************/
extern TaskHandle_t main_task_handle;
extern EventGroupHandle_t event_group_handle;

/**********************************************************************************************************************
 Exported global functions
 *********************************************************************************************************************/
extern void test_start(void);

#endif /* TEST_MAIN_H_ */
