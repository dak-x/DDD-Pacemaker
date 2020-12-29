#ifndef SCCHARTS_H_
#define SCCHARTS_H_

void reset();
void tick();

//Inputs
extern char AVI_Ex;
extern char AVI_Stop;
extern char V_Pulse;
extern char A_Pulse;
extern char LRI_Ex;
extern char VRP_Ex;
extern char URI_Ex;
extern char PVARP_Ex;
extern char AEI_Ex;

//Outputs
extern char VP;
extern char VS;
extern char VR;
// extern char VP_Req;
extern char AS;
extern char AP;
extern char AR;
extern char LRI_Start;  
extern char VRP_Start;
extern char LRI_Restart;
extern char URI_Start;
extern char PVARP_Start;
extern char PVARP_Stop;
extern char AEI_Start;
extern char AEI_Restart;
extern char AVI_Start;
extern char AVI_Restart;
extern char URI_Restart;
extern char URI_Stop;
   



    
#endif