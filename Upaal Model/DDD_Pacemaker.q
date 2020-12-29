//This file was generated from (Commercial) UPPAAL 4.0.15 rev. CB6BB307F6F681CB, November 2019

/*
8. The pacemaker can deliver a pacing pulse (VP), where the time interval between this VP and its
preceding atrial event is greater than AVI.
*/
E<> AVI_Ext_Monitor.Detected imply AVI_Ext_Monitor.t >= TAVI

/*
4. The pacemaker never delivers a pacing pulse (AP) within AEI.
*/
A[] not AEI_Monitor.Detected

/*
5. The pacemaker never delivers a pacing pulse (VP) within AVI
*/
A[] not AVI_Monitor.Detected

/*
6. The pacemaker never delivers a pacing pulse (VP) within URI.
*/
A[] URI_Monitor.Detected imply URI_Monitor.t >= TURI

/*
3. An atrial sense (AS) cannot be generated within PVARP.
*/
A[] PVARP_Monitor.Detected imply PVARP_Monitor.t >= TPVARP

/*
2. A ventricular sense (VS) cannot be generated within VRP.
*/
A[] VRP_Monitor.Detected imply VRP_Monitor.t >= TVRP

/*
7. The time interval between two consecutive ventricular events is always less or equal to LRI
*/
A[] LRI_Monitor.Detected imply LRI_Monitor.t  <= TLRI

/*
1. The system is deadlock free.

*/
A[] not deadlock
