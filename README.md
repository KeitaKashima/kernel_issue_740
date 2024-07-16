# About this repo

This is a repo to share the project reproduce the Kernel issue for FreeRTOS for RL78 MCU. 
 https://github.com/FreeRTOS/FreeRTOS-Kernel/issues/740

# Test environment

- Kit : FPB-RL78/G23
- Compiler : CC-RL v1.12.01
- IDE : e2 studio v2024-04 (eclipse base IDE)

# Test project configuration

You can select the project behavior by setting `TEST_DO_CORRECT_KERNEL_CODE` macro on IDE.
Please open the setting window of IDE and select `C/C++ General` -> `Paths and Symbols`.
Please change the value of `TEST_DO_CORRECT_KERNEL_CODE` as you want to check.
Build it and Run.

Macro name: `TEST_DO_CORRECT_KERNEL_CODE`

`0`: Don’t fixed portYIELD_FROM_ISR()    : Default setting

`1`: Fixed portYIELD_FROM_ISR()

![image](https://github.com/user-attachments/assets/2eed5ad7-e2c8-44e5-9f59-af54874fb64d)


# about Workround code

It is fixed when change the below code in `portmacro.h`.

From `#define portYIELD_FROM_ISR( xHigherPriorityTaskWoken ) if( xHigherPriorityTaskWoken ) vTaskSwitchContext()` to `#define portYIELD_FROM_ISR( x )    if( x != pdFALSE ) portYIELD()`

* portmacro.h

![image](https://github.com/user-attachments/assets/d9834604-e158-4f10-84ac-870e18e567ba)


# Run result

You can see the log output on the Terminal window just running the project and check whether the issue is happening or not.

## When the issue reproduced(Set `TEST_DO_CORRECT_KERNEL_CODE=0(don’t fixed))

It stopped the log output.
![image](https://github.com/user-attachments/assets/e5f42173-e311-43d3-a88e-5ecba96e09a0)


## When the fixing code adapted(Set `TEST_DO_CORRECT_KERNEL_CODE=1'(fixed))

It shows the log output 
  ![image](https://github.com/user-attachments/assets/266b9de5-ed84-4d3d-a544-6f3f0e5d0fbc)
