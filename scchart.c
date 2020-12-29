/*****************************************************************************/
/*                 G E N E R A T E D       C    C O D E                      */
/*****************************************************************************/
/* KIELER - Kiel Integrated Environment for Layout Eclipse RichClient        */
/*                                                                           */
/* http://www.informatik.uni-kiel.de/rtsys/kieler/                           */
/* Copyright 2014 by                                                         */
/* + Kiel University                                                         */
/*   + Department of Computer Science                                        */
/*     + Real-Time and Embedded Systems Group                                */
/*                                                                           */
/* This code is provided under the terms of the Eclipse Public License (EPL).*/
/*****************************************************************************/
char AVI_Ex;
char AVI_Stop;
char V_Pulse;
char A_Pulse;
char LRI_Ex;
char VRP_Ex;
char URI_Ex;
char PVARP_Ex;
char AEI_Ex;
char VP;
char VS;
char VR;
char VP_Req;
char AS;
char AP;
char AR;
char LRI_Start;
char VRP_Start;
char LRI_Restart;
char URI_Start;
char URI_Restart;
char URI_Stop;
char PVARP_Start;
char PVARP_Stop;
char AEI_Start;
char AEI_Restart;
char AVI_Start;
char AVI_Restart;
char g0;
char g1;
char g2;
char g3;
char g4;
char PRE_g4;
char g5;
char g5b;
char g6;
char g7;
char g8;
char g9;
char g10;
char g10b;
char g11;
char PRE_g11;
char g12;
char g13;
char g14;
char g15;
char g16;
char g17;
char g18;
char PRE_g18;
char g19;
char g20;
char g21;
char g22;
char g23;
char PRE_g23;
char g24;
char g25;
char g26;
char g27;
char g28;
char g29;
char PRE_g29;
char g30;
char g30b;
char g31;
char g32;
char g33;
char g34;
char g35;
char g36;
char g36b;
char g37;
char PRE_g37;
char g38;
char g38b;
char g39;
char g40;
char g41;
char g42;
char g43;
char g44;
char g45;
char PRE_g45;
char g46;
char g47;
char g48;
char g49;
char g50;
char g51;
char PRE_g51;
char g52;
char g53;
char g54;
char g55;
char g56;
char PRE_g56;
char g57;
char g58;
char g59;
char g60;
char g61;
char g62;
char g63;
char PRE_g63;
char g64;
char g64b;
char g65;
char g66;
char g67;
char g68;
char g69;
char g70;
char g71;
char g72;
char PRE_g72;
char g73;
char g74;
char g75;
char g76;
char g77;
char g78;
char PRE_g78;
char g79;
char g80;
char g81;
char g82;
char g83;
char g84;
char g85;
char g86;
char g87;
char g88;
char g89;
char g90;
char PRE_g90;
char g91;
char g92;
char g93;
char g94;
char PRE_g94;
char g95;
char g96;
char g97;
char _GO;
char _cg2;
char _cg9;
char _cg5;
char _cg7;
char _cg19;
char _cg15;
char _cg22;
char _cg20;
char _cg27;
char _cg42;
char _cg34;
char _cg30;
char _cg32;
char _cg41;
char _cg35;
char _cg40;
char _cg38;
char _cg43;
char _cg52;
char _cg57;
char _cg49;
char _cg55;
char _cg53;
char _cg64;
char _cg61;
char _cg71;
char _cg69;
char _cg65;
char _cg67;
char _cg76;
char _cg89;
char _cg87;
char _cg79;
char _cg81;
char _cg83;
char _cg85;
char g13_e1;
char g25_e2;
char g47_e3;
char g59_e4;
char g74_e5;
char g92_e6;
char g96_e7;
int _PRE_GO;
void reset(){
   _GO = 1;
   _PRE_GO = 0;
   PRE_g4 = 0;
   PRE_g11 = 0;
   PRE_g18 = 0;
   PRE_g23 = 0;
   PRE_g29 = 0;
   PRE_g37 = 0;
   PRE_g45 = 0;
   PRE_g51 = 0;
   PRE_g56 = 0;
   PRE_g63 = 0;
   PRE_g72 = 0;
   PRE_g78 = 0;
   PRE_g90 = 0;
   PRE_g94 = 0;
   return;
}
void tick(){
   if(_PRE_GO == 1){
      _GO = 0;
   }
   {
      g0 = _GO;
      g1 = g0;
      g93 = g0;
      g95 =(PRE_g94);
      g94 =(g93||g95);
      if(g94){
         VP = 0;
         VS = 0;
         VR = 0;
         VP_Req = 0;
         AS = 0;
         AP = 0;
         AR = 0;
         LRI_Start = 0;
         VRP_Start = 0;
         LRI_Restart = 0;
         URI_Start = 0;
         URI_Restart = 0;
         URI_Stop = 0;
         PVARP_Start = 0;
         PVARP_Stop = 0;
         AEI_Start = 0;
         AEI_Restart = 0;
         AVI_Start = 0;
         AVI_Restart = 0;
         AVI_Stop = 0;
      }
      g14 = g0;
      g19 =(PRE_g18);
      _cg19 = VRP_Ex;
      g24 =(PRE_g23);
      g15 =(g14||(g19&&_cg19)||g24);
      _cg15 = V_Pulse;
      g16 =(g15&&_cg15);
      if(g16){
         VS =(VS||1);
      }
      g12 =(PRE_g11);
      g2 =(g1||g12);
      _cg2 = VS;
      g3 =(g2&&_cg2);
      if(g3){
         LRI_Start =(LRI_Start||1);
      }
      g79 =(PRE_g78);
      _cg79 = AVI_Ex;
      g80 =(g79&&_cg79);
      if(g80){
         VP_Req =(VP_Req||1);
      }
      g30 =(PRE_g29);
      g30b = g30;
      _cg30 = VS;
      g32 =(g30b&&(!(_cg30)));
      _cg32 = URI_Ex;
      g34 =(g32&&(!(_cg32)));
      _cg34 = VP_Req;
      g38 =(PRE_g37);
      g38b = g38;
      _cg38 = VS;
      g40 =(g38b&&(!(_cg38)));
      _cg40 = URI_Ex;
      g41 =(g40&&(!(_cg40)));
      _cg41 = VP_Req;
      g35 =((g34&&_cg34)||(g41&&_cg41));
      _cg35 = URI_Ex;
      g36 =((g35&&_cg35)||(g40&&_cg40));
      if(g36){
         VP =(VP||1);
      }
      g36b = g36;
      if(g36b){
         URI_Restart =(URI_Restart||1);
      }
      g31 =(g30b&&_cg30);
      if(g31){
         URI_Restart =(URI_Restart||1);
      }
      g39 =(g38b&&_cg38);
      if(g39){
         URI_Restart =(URI_Restart||1);
      }
      g5 =(PRE_g4);
      g5b = g5;
      _cg5 = URI_Restart;
      g7 =(g5b&&(!(_cg5)));
      _cg7 = VS;
      g9 =(g7&&(!(_cg7)));
      _cg9 = LRI_Ex;
      g6 =(g5b&&_cg5);
      if(g6){
         LRI_Restart =(LRI_Restart||1);
      }
      g10 =(g9&&_cg9);
      if(g10){
         VP =(VP||1);
      }
      g10b = g10;
      if(g10b){
         LRI_Start =(LRI_Start||1);
      }
      g8 =(g7&&_cg7);
      if(g8){
         LRI_Restart =(LRI_Restart||1);
      }
      g4 =(g3||(g9&&(!(_cg9)))||g6||g10b||g8);
      g11 =(g2&&(!(_cg2)));
      g26 = g0;
      g33 =(g32&&_cg32);
      if(g33){
         URI_Stop =(URI_Stop||1);
      }
      g46 =(PRE_g45);
      g27 =(g26||g33||g46);
      _cg27 = VS;
      g42 =(g27&&(!(_cg27)));
      _cg42 = VP;
      g43 =(g42&&(!(_cg42)));
      _cg43 = VP_Req;
      g44 =(g43&&_cg43);
      if(g44){
         VP =(VP||1);
      }
      g22 =(g15&&(!(_cg15)));
      _cg22 = VP;
      g17 =((g22&&_cg22)||g16);
      if(g17){
         VRP_Start =(VRP_Start||1);
      }
      g20 =(g19&&(!(_cg19)));
      _cg20 = V_Pulse;
      g21 =(g20&&_cg20);
      if(g21){
         VR =(VR||1);
      }
      g18 =(g17||g21||(g20&&(!(_cg20))));
      g23 =(g22&&(!(_cg22)));
      g28 =((g42&&_cg42)||g44||(g27&&_cg27));
      if(g28){
         URI_Start =(URI_Start||1);
      }
      g29 =(g39||g31||(g34&&(!(_cg34)))||g28||g36b);
      g37 =((g41&&(!(_cg41)))||(g35&&(!(_cg35))));
      g45 =(g43&&(!(_cg43)));
      g48 = g0;
      g57 =(PRE_g56);
      _cg57 = A_Pulse;
      g58 =(g57&&_cg57);
      if(g58){
         AS =(AS||1);
      }
      g52 =(PRE_g51);
      _cg52 = PVARP_Ex;
      g49 =(g58||(g57&&(!(_cg57)))||g48||(g52&&_cg52));
      _cg49 = VP;
      g55 =(g49&&(!(_cg49)));
      _cg55 = VS;
      g50 =((g55&&_cg55)||(g49&&_cg49));
      if(g50){
         PVARP_Start =(PVARP_Start||1);
      }
      g53 =(g52&&(!(_cg52)));
      _cg53 = A_Pulse;
      g54 =(g53&&_cg53);
      if(g54){
         AR =(AR||1);
      }
      g51 =(g50||(g53&&(!(_cg53)))||g54);
      g56 =(g55&&(!(_cg55)));
      g60 = g0;
      g64 =(PRE_g63);
      g64b = g64;
      _cg64 = AS;
      g65 =(g64b&&(!(_cg64)));
      _cg65 = AEI_Ex;
      g66 =(g65&&_cg65);
      if(g66){
         AP =(AP||1);
      }
      g73 =(PRE_g72);
      g61 =(g60||(g64b&&_cg64)||g66||g73);
      _cg61 = VS;
      g71 =(g61&&(!(_cg61)));
      _cg71 = VP;
      g62 =((g61&&_cg61)||(g71&&_cg71));
      if(g62){
         AEI_Start =(AEI_Start||1);
      }
      g67 =(g65&&(!(_cg65)));
      _cg67 = VS;
      g69 =(g67&&(!(_cg67)));
      _cg69 = VP;
      g68 =(g67&&_cg67);
      if(g68){
         AEI_Restart =(AEI_Restart||1);
      }
      g70 =(g69&&_cg69);
      if(g70){
         AEI_Restart =(AEI_Restart||1);
      }
      g63 =((g69&&(!(_cg69)))||g68||g70||g62);
      g72 =(g71&&(!(_cg71)));
      g75 = g0;
      g91 =(PRE_g90);
      g81 =(g79&&(!(_cg79)));
      _cg81 = VP;
      g82 =(g81&&_cg81);
      if(g82){
         AVI_Stop =(AVI_Stop||1);
      }
      g83 =(g81&&(!(_cg81)));
      _cg83 = VS;
      g84 =(g83&&_cg83);
      if(g84){
         AVI_Stop =(AVI_Stop||1);
      }
      g76 =(g75||g91||g82||g80||g84);
      _cg76 = AS;
      g89 =(g76&&(!(_cg76)));
      _cg89 = AP;
      g77 =((g89&&_cg89)||(g76&&_cg76));
      if(g77){
         AVI_Start =(AVI_Start||1);
      }
      g85 =(g83&&(!(_cg83)));
      _cg85 = AP;
      g86 =(g85&&_cg85);
      if(g86){
         AVI_Restart =(AVI_Restart||1);
      }
      g87 =(g85&&(!(_cg85)));
      _cg87 = AS;
      g88 =(g87&&_cg87);
      if(g88){
         AVI_Restart =(AVI_Restart||1);
      }
      g78 =(g86||g77||(g87&&(!(_cg87)))||g88);
      g90 =(g89&&(!(_cg89)));
      g13_e1 =(!((g12||g5)));
      g25_e2 =(!((g24||g19)));
      g47_e3 =(!((g30||g46||g38)));
      g59_e4 =(!((g52||g57)));
      g74_e5 =(!((g64||g73)));
      g92_e6 =(!((g79||g91)));
      g96_e7 =(!(g95));
   }
   PRE_g4 = g4;
   PRE_g11 = g11;
   PRE_g18 = g18;
   PRE_g23 = g23;
   PRE_g29 = g29;
   PRE_g37 = g37;
   PRE_g45 = g45;
   PRE_g51 = g51;
   PRE_g56 = g56;
   PRE_g63 = g63;
   PRE_g72 = g72;
   PRE_g78 = g78;
   PRE_g90 = g90;
   PRE_g94 = g94;
   _PRE_GO = _GO;
   return;
}
