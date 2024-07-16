/*
 * event_recv_task.c
 */

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "event_recv_task.h"

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Local Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Exported global variables
 *********************************************************************************************************************/
EventGroupHandle_t event_group_handle;
BaseType_t g_xHigherPriorityTaskWoken;
TaskHandle_t tskhdl_current;
TaskHandle_t tskhdl_interrupt;
TaskStatus_t tskinfo_interrupt;
TaskStatus_t tskinfo_current;

/**********************************************************************************************************************
 Private (static) variables and functions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Functions
 *********************************************************************************************************************/
void vCreate_event_group(void)
{
    event_group_handle = xEventGroupCreate ();
    /* Was the event group created successfully? */
    if (NULL == event_group_handle)
    {
        /* The event group was not created. */
        while (1)
        {
            __nop ();
        }
    }
}
/*-----------------------------------------------------------*/

void event_receive_task(void *pvParameters)
{
    EventBits_t uxBits;

    while (1)
    {
        /* Wait maximum for event "INTERRUPT_PERIODIC_TIMER" to be set within the event group. */
        uxBits = xEventGroupWaitBits (event_group_handle,
                                      INTERRUPT_PERIODIC_TIMER,
                                      pdTRUE,
                                      pdFALSE,
                                      portMAX_DELAY);
        (void)(uxBits);

        vTaskGetInfo (NULL, &tskinfo_current, pdFALSE, eRunning );
        tskhdl_current = xTaskGetCurrentTaskHandle();
        char* tskname_current = pcTaskGetName(tskhdl_current);
        char* tskname_interrupt = pcTaskGetName(tskhdl_interrupt);
        configPRINTF (("%ld %s(pri:%d) -> portYIELD_FROM_ISR(xHigherPriorityTaskWoken:%d) -> %s(pri:%d)\r\n",
                      xTaskGetTickCount(),
                      tskname_interrupt,
                      tskinfo_interrupt.uxCurrentPriority,
                      g_xHigherPriorityTaskWoken,
                      tskname_current,
                      tskinfo_current.uxCurrentPriority));
        __nop ();
    }
}
