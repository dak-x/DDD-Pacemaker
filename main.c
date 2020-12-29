/* ========================================
 * Contact: 
 *      Email: daksh879@live.com
 *      GitHub: https://github.com/dak-x
 * MIT License
 * 
 * Copyright (c) [2020] [Daksh Chauhan]
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * ========================================
*/
#include <project.h>
#include "scchart.h"

#define TRUE 1 
#define FALSE 0

// ========================================
// TIMER TIMEOUT PARAMETERS
#define AVI_VALUE 300
#define AEI_VALUE 900
#define PVARP_VALUE 50
#define VRP_VALUE 150
#define LRI_VALUE 1100
#define URI_VALUE 600

// ========================================
// vars used for counting time passed in ms 
// of each timer
uint32 timer_LRI_cnt = 0;
uint32 timer_URI_cnt = 0;
uint32 timer_VRP_cnt = 0;
uint32 timer_PVARP_cnt = 0;
uint32 timer_AVI_cnt = 0;
uint32 timer_AEI_cnt = 0;

// ========================================
// Prototypes defined for each isr_function
CY_ISR_PROTO(ISR_LRI_f);
CY_ISR_PROTO(ISR_URI_f);
CY_ISR_PROTO(ISR_VRP_f);
CY_ISR_PROTO(ISR_PVARP_f);
CY_ISR_PROTO(ISR_AVI_f);
CY_ISR_PROTO(ISR_AEI_f);

// ========================================

void handle_timers();
void handle_usb_input();
void handle_usb_output();

int main()
{   
    CyGlobalIntEnable; /* Enable global interrupts. */
    USBUART_Start(0,USBUART_5V_OPERATION);
    
    // Bind the respective ISR functions
    // of each timer block
    isr_LRI_StartEx(ISR_LRI_f);
    isr_URI_StartEx(ISR_URI_f);
    isr_VRP_StartEx(ISR_VRP_f);
    isr_PVARP_StartEx(ISR_PVARP_f);
    isr_AEI_StartEx(ISR_AEI_f);
    isr_AVI_StartEx(ISR_AVI_f);

    reset(); 
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {   V_Pulse = 0;
        A_Pulse = 0;
        // Get the sensing Input from Serial IN
        handle_usb_input();
        // Run throught the Timer States before SCChart tick
        handle_timers();
        // SCChart Tick
        tick();
        // Put the pacing output to Serial OUT
        handle_usb_output();
    }
}

/**
 * Handles the <Timer>_Start,
 * <Timer>_Stop , <Timer>_Restart
 * signals defined the SCChart for the 
 * DDD-Mode Pacemaker
*/
void handle_timers(){
    // Handle LRI Timer
    if( LRI_Start == TRUE ){
        timer_LRI_cnt = 0;
        Timer_LRI_Start();
    } 
    else if( LRI_Restart == TRUE ){
        timer_LRI_cnt = 0;
    }


    // Handle URI Timer
    if( URI_Start == TRUE ){
        timer_URI_cnt = 0;
        Timer_URI_Start();
    } else if( URI_Restart == TRUE){
        timer_URI_cnt = 0;
    } else if( URI_Stop == TRUE){
        Timer_URI_Stop();
    }


    // Handle VRP Timer
    if( VRP_Start == TRUE ){
        timer_VRP_cnt = 0;
        Timer_VRP_Start();
    }


    // Handle PVARP Timer
    if( PVARP_Start == TRUE ){
        timer_PVARP_cnt = 0;
        Timer_PVARP_Start();
    } else if ( PVARP_Stop == TRUE){
        Timer_PVARP_Stop();
    } 


    // Handle AEI Timer
    if( AEI_Start == TRUE ){
        timer_AEI_cnt = 0;
        Timer_AEI_Start();
    } 
    else if( AEI_Restart == TRUE ){
        timer_AEI_cnt = 0;
        Timer_AEI_Start();
    }


    // Handle AVI Timer
    if( AVI_Start == TRUE ){
        timer_AVI_cnt = 0;
        Timer_AVI_Start();
    } 
    else if( AVI_Restart == TRUE ){
        timer_AVI_cnt = 0;
        //Timer_AVI_Start();
    }
    else if( AVI_Stop == TRUE){
        Timer_AVI_Stop();
    }

}
//==========================================

/**
 * Fetches the A or V from the 
 * serial connection and assigns 
 * A_Pulse, V_Pulse proper values
*/
void handle_usb_input(){
    
    static uint8 usbStarted = FALSE;
    static uint16 usbBufCount = 0;
    uint8 c;
    uint8 s;    
   
    if (!usbStarted)
    {
        if (USBUART_GetConfiguration())
        {
            USBUART_CDC_Init();
            usbStarted = TRUE;
        }
    }
    
    else{ if (USBUART_DataIsReady() > 0){
        s = USBUART_GetChar();
        if( s == 'V'){
            V_Pulse = 1;
        } else {
            V_Pulse = 0;
        } 
        if( s == 'A'){
            A_Pulse = 1;
        } else {
            A_Pulse = 0;
        }
    }}
}

//=========================================
/**
 * Output A or V based on
 * AP or VP emitted from 
 * the logic
*/
void handle_usb_output(){
    while( USBUART_CDCIsReady() == 0);
    if( AP ){
        USBUART_PutChar('A');
    } else if (VP){
        USBUART_PutChar('V');
    } else {
        // Put Nothing
    }
}

//=========================================
/**
 * The following are the ISR defination
 * for each of the 6 Timers. Each Timer Counts 
 * 1 ms intervals and each isr updates the 
 * timer_<Timer>_cnt. If this count is 
 * greater than the defined <Timer>_VALUE
 * the <Timer>_Ex signal is generated
 * 
*/
CY_ISR( ISR_LRI_f ){
    timer_LRI_cnt++;

    if (timer_LRI_cnt >= LRI_VALUE ){
        LRI_Ex = TRUE;
        timer_LRI_cnt = 0;
    } else {
        LRI_Ex = FALSE;
    }

}
CY_ISR( ISR_URI_f ) {
    timer_URI_cnt++;

    if (timer_URI_cnt >= URI_VALUE ){
        URI_Ex = TRUE;
        timer_URI_cnt = 0;
    } else {
        URI_Ex = FALSE;
    }
    
}
CY_ISR( ISR_VRP_f) {
    timer_VRP_cnt++;

    if (timer_VRP_cnt >= VRP_VALUE ){
        VRP_Ex = TRUE;
        timer_VRP_cnt = 0;
    } else {
        VRP_Ex = FALSE;
    }

}
CY_ISR( ISR_AVI_f) {
    timer_AVI_cnt++;

    if (timer_AVI_cnt >= AVI_VALUE ){
        AVI_Ex = TRUE;
        timer_AVI_cnt = 0;
    } else {
        AVI_Ex = FALSE;
    }
}
CY_ISR( ISR_AEI_f) {
    timer_AEI_cnt++;

    if (timer_AEI_cnt >= AEI_VALUE ){
        AEI_Ex = TRUE;
        timer_AEI_cnt = 0;
    } else {
        AEI_Ex = FALSE;
    }

}
CY_ISR( ISR_PVARP_f) {
    timer_PVARP_cnt++;

    if (timer_PVARP_cnt >= PVARP_VALUE ){
        PVARP_Ex = TRUE;
        timer_PVARP_cnt = 0;
    } else {
        PVARP_Ex = FALSE;
    }
}
// =========================================


/* [] END OF FILE */
