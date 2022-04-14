 //===============================================================================================================
// Name        : game.cpp
// Author      : Hassan Mustafa
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include <fstream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// GLOBAL VARIABLES,,,,..

//for second opponent car
float ffx=450;
float ffy= 230;
// for opponent car      
       
       float fx = 450; 
	float fy = 30;
// for my car
	bool fstart=true;
	float gx = 350; 
	float gy = 30;
	int food[8][8]={0};
int loop=1;
int loop1=1;
int level=1;
int flag=0;
int lives=3;
int score=0;
//_______________________________________________________________________________________________________________________________________________________________________


//funtion for help.....
void help(){
 DrawString( 102, 700, "1.)Level 1: At this level, the opponent car is less active and can only take the top and the bottom turns", colors[MISTY_ROSE]);
DrawString( 102, 600, "2.)Level 2: At this level, the opponent car is in the active mode and can take any turn just like the player car.", colors[MISTY_ROSE]);
DrawString( 102, 500, "3.)Level 3: At this level, the opponent car is in active mode and its speed is also doubled", colors[MISTY_ROSE]);
DrawString( 102, 400, "4.)Level 4: At this level, two opponent cars start chasing the player car in the active mode as in level ", colors[MISTY_ROSE]);  
            
    }
//======================================================================



    

//

void menu() {														//function for displaying menu=============
DrawString( 102, 760, "DODGE_EM", colors[YELLOW]); 
DrawString( 102, 676, "1.)START", colors[MISTY_ROSE]);
DrawString( 102, 540, "2.)HELP", colors[MISTY_ROSE]);
DrawString( 102, 420, "3.)HIGH SCORE", colors[MISTY_ROSE]);
DrawString( 102, 290, "4.)EXIT", colors[MISTY_ROSE]);
}
//=======================================================================

void car(){														//function for displaying cars=======
//drwing my car
	float width = 10; 
	float height =15;
	float* color = colors[BLUE_VIOLET]; 
	float radius = 8.0;
	DrawRoundRect(fx,fy,width,height,color,radius); // bottom left tyre
	DrawRoundRect(fx+width*3,fy,width,height,color,radius); // bottom right tyre
	DrawRoundRect(fx+width*3,fy+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(fx,fy+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(fx, fy+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(fx+width, fy+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(fx+width*3, fy+height*2, width, height, color, radius/2); // body right rect

// Drawing opponent car
 
	 width = 10; 
	 height = 15;
	 color = colors[BROWN]; 
	 radius = 8.0;
	DrawRoundRect(gx,gy,width,height,color,radius); // bottom left tyre
	DrawRoundRect(gx+width*3,gy,width,height,color,radius); // bottom right tyre
	DrawRoundRect(gx+width*3,gy+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(gx,gy+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(gx, gy+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(gx+width, gy+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(gx+width*3, gy+height*2, width, height, color, radius/2); // body right rect
         





 }
void secondcardisplay() {                                       // fuction for DISPLAYING SECOND CAR===========================



     float     width = 10; 
	float  height = 15;
	float* color = colors[PINK]; 
	  float radius = 8.0;
	DrawRoundRect(ffx,ffy,width,height,color,radius); // bottom left tyre
	DrawRoundRect(ffx+width*3,ffy,width,height,color,radius); // bottom right tyre
	DrawRoundRect(ffx+width*3,ffy+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(ffx,ffy+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(ffx, ffy+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(ffx+width, ffy+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(ffx+width*3, ffy+height*2, width, height, color, radius/2); // body right rect
         





}

//========================================================================


void arena(){															//function for displaying areana=========
// Drawing Arena


// Drawing Arena
        
	int gap_turn = 100;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BROWN];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
	


         gap_turn = 100;
	 sx = 120;
	 sy = 110;
	 swidth = 600/2 - gap_turn/2; // half width
	 sheight = 10;
	 
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+610, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+610, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down



    gap_turn = 100;
	 sx = 220;
	 sy = 210;
	 swidth = 400/2 - gap_turn/2; // half width
	 sheight = 10;
	 
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+410, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+410, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down




    gap_turn = 100;
	 sx = 320;
	 sy = 310;
	 swidth = 200/2 - gap_turn/2; // half width
	 sheight = 10;
	 
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+210, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+210, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down

   gap_turn = 0;
	 sx = 420;
	 sy = 410;
	 swidth = 10 - gap_turn/2; // half width
	 sheight = 10;
	 
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+30, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+30, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
}
//===============================================
void arenaforcolour()
{
    															//function for displaying areana FOR LEVEL 2 FOR COLUR CHANGE=========
// Drawing Arena


// Drawing Arena
        
	int gap_turn = 100;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[YELLOW];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
	


         gap_turn = 100;
	 sx = 120;
	 sy = 110;
	 swidth = 600/2 - gap_turn/2; // half width
	 sheight = 10;
	 
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+610, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+610, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down



    gap_turn = 100;
	 sx = 220;
	 sy = 210;
	 swidth = 400/2 - gap_turn/2; // half width
	 sheight = 10;
	 
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+410, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+410, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down




    gap_turn = 100;
	 sx = 320;
	 sy = 310;
	 swidth = 200/2 - gap_turn/2; // half width
	 sheight = 10;
	 
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+210, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+210, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down

   gap_turn = 0;
	 sx = 420;
	 sy = 410;
	 swidth = 10 - gap_turn/2; // half width
	 sheight = 10;
	 
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+30, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+30, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
}
  //======================================
void arenaforcolour1()
{
    															//function for displaying areana FOR LEVEL 3 FOR COLUR CHANGE=========
// Drawing Arena


// Drawing Arena
        
	int gap_turn = 100;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[PINK];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
	


         gap_turn = 100;
	 sx = 120;
	 sy = 110;
	 swidth = 600/2 - gap_turn/2; // half width
	 sheight = 10;
	 
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+610, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+610, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down



    gap_turn = 100;
	 sx = 220;
	 sy = 210;
	 swidth = 400/2 - gap_turn/2; // half width
	 sheight = 10;
	 
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+410, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+410, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down




    gap_turn = 100;
	 sx = 320;
	 sy = 310;
	 swidth = 200/2 - gap_turn/2; // half width
	 sheight = 10;
	 
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+210, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+210, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down

   gap_turn = 0;
	 sx = 420;
	 sy = 410;
	 swidth = 10 - gap_turn/2; // half width
	 sheight = 10;
	 
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+30, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+30, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
}


//========================================================================================================================

void makingfood(){ 													//function for making food========
// code for assigning food
	if(fstart==true)
	{
	for(int i=0,fy=40 ;i<8 ;i++,fy+=127)
	{
		for(int j=0,fx=50 ;j<8 ;j++,fx+=105)
		{
			food[i][j]=1;
		}
	}
	}
	fstart=false;
//====================================================================================================================================================================================
// code for drawing food==============================================================================================================================
	for(int i=0,fy=40 ;i<8 ;i++,fy+=127)
	{
		for(int j=0,fx=50 ;j<8 ;j++,fx+=105)
		{
			if(food[i][j]==1)
			{
				  DrawLine( fx , fy , fx+20 , fy , 30, colors[YELLOW] );
			}	
		}

	}
}
//========================================================================================================


void eatingfood(){														//function for eating food=============
// code for eating food =========================================================================================      
	for(int i=0,fy=40 ;i<8 ;i++,fy+=127)
	{
		for(int j=0,fx=50 ;j<8 ;j++,fx+=105)
		{
		if((abs(gx-fx)<=10 && abs(gy-fy)<=10) || (abs(gx-fx)<=10 && abs(gy+50-fy)<=20) ||(abs(gx+20-fx)<=20 && abs(gy-fy)<=10))
		{
			if(food[i][j]!=0)
			{
			food[i][j]=0;
			score++;
			
			}
		}
		else if((abs(gx+20-fx)<=20 && abs(gy+50-fy)<=20) ||(abs(gx-fx)<=20 && abs(gy+20-fy)<=10))
		{
			if(food[i][j]!=0)
			{
			food[i][j]=0;
			score++;
			}		
		}
		if(score==56)
				{
                                   
                                 
                                 level=2;
				fstart=true;
                                  
        
				}
                if (score==112)
                                 {
                                   level=3;
                                   fstart=true;
                                    
                                 }
               if (score==168)
                 {
                        level=4;
                        fstart=true;
                  }
		}
	}  


}
//===========================================================================================================================
void secondcarmovement(){                                              // FUNCTION FOR AUTOMATIC MOVEMENT OF SECOND CAR OPPONENT=============
      
//for first arena=================
if( ffx<=750 && ffx>=40 && ffy==30)
	{
            loop1=1;
		
		ffx+=2.5;
	}
if(ffx==750  && ffy>=30 && ffy<=740)
	{
             loop1=1;
		ffy+=2.5;
	}
if(ffx<=750  && ffx>=40 && ffy==740)
	{
              loop1=1;
		ffx-=2.5;
	}
if(ffx==40 && ffy>=30 && ffy<=740)
	{ 
                loop1=1;
		ffy-=2.5;
	}
// code of opponent car to move in second arena....................................

if( ffx<=650 && ffx>=140 && ffy==130)
	{
		loop1=2;
		ffx+=2.5;
	}
if(ffx==650  && ffy>=130 && ffy<=640)
	{
              loop1=2;
		ffy+=2.5;
	}
if(ffx<=650  && ffx>=140 && ffy==640)
	{
               loop1=2;
		ffx-=2.5;
	}
if(ffx==140 && ffy>=130 && ffy<=650)
	{
              loop1=2;
		ffy-=2.5;
	}

// code of opponent car to move in third arena....................................

if( ffx<=550 && ffx>=240 && ffy==230)
	{
		loop1=3;
		ffx+=2.5;
	}
if(ffx==550  && ffy>=230 && ffy<=540)
	{  
               loop1=3;
		ffy+=2.5;
	}
if(ffx<=550  && ffx>=240 && ffy==540)
	{
                loop1=3;
		ffx-=2.5;
	}
if(ffx==240 && ffy>=230 && ffy<=550)
	{
                 loop1=3;
		ffy-=2.5;
	}

// code of opponent car to move in forth arena....................................

if( ffx<=450 && ffx>=340 && ffy==330)
	{
		loop1=4;
		ffx+=2.5;
	}
if(ffx==450  && ffy>=330 && ffy<=440)
	{ 
                loop1=4;
		ffy+=2.5;
	}
if(ffx<=450  && ffx>=340 && ffy==440)
	{
                 loop1=4;
		ffx-=2.5;
	}
if(ffx==340 && ffy>=330 && ffy<=450)
	{
               loop1=4;
		ffy-=2.5;
	}
         }

//====================================================================================















//============================================================================================================================
void movement(){															//function for movement of the FIRRST OPPONENT car======
// code of opponent car to move in first arena....................................

if(level==3){ 														//FOR CONTROLLING SPEED OF LEVEL 3 OPPONENT CARS==========
            if( fx<=750 && fx>=40 && fy==30)
	{
            loop1=1;
		
		fx+=5;
	}
if(fx==750  && fy>=30 && fy<=740)
	{
             loop1=1;
		fy+=5;
	}
if(fx<=750  && fx>=40 && fy==740)
	{
              loop1=1;
		fx-=5;
	}
if(fx==40 && fy>=30 && fy<=740)
	{ 
                loop1=1;
		fy-=5;
	}
// code of opponent car to move in second arena....................................

if( fx<=650 && fx>=140 && fy==130)
	{
		loop1=2;
		fx+=5;
	}
if(fx==650  && fy>=130 && fy<=640)
	{
              loop1=2;
		fy+=5;
	}
if(fx<=650  && fx>=140 && fy==640)
	{
               loop1=2;
		fx-=5;
	}
if(fx==140 && fy>=130 && fy<=650)
	{
              loop1=2;
		fy-=5;
	}

// code of opponent car to move in third arena....................................

if( fx<=550 && fx>=240 && fy==230)
	{
		loop1=3;
		fx+=5;
	}
if(fx==550  && fy>=230 && fy<=540)
	{  
               loop1=3;
		fy+=5;
	}
if(fx<=550  && fx>=240 && fy==540)
	{
                loop1=3;
		fx-=5;
	}
if(fx==240 && fy>=230 && fy<=550)
	{
                 loop1=3;
		fy-=5;
	}

// code of opponent car to move in forth arena....................................

if( fx<=450 && fx>=340 && fy==330)
	{
		loop1=4;
		fx+=5;
	}
if(fx==450  && fy>=330 && fy<=440)
	{ 
                loop1=4;
		fy+=5;
	}
if(fx<=450  && fx>=340 && fy==440)
	{
                 loop1=4;
		fx-=5;
	}
if(fx==340 && fy>=330 && fy<=450)
	{
               loop1=4;
		fy-=5;
	} 
     }
 else{						//OPPONENT ORIGIONAL CODE START
// first arean.........
if( fx<=750 && fx>=40 && fy==30)
	{
            loop1=1;
		
		fx+=2.5;
	}
if(fx==750  && fy>=30 && fy<=740)
	{
             loop1=1;
		fy+=2.5;
	}
if(fx<=750  && fx>=40 && fy==740)
	{
              loop1=1;
		fx-=2.5;
	}
if(fx==40 && fy>=30 && fy<=740)
	{ 
                loop1=1;
		fy-=2.5;
	}
// code of opponent car to move in second arena....................................

if( fx<=650 && fx>=140 && fy==130)
	{
		loop1=2;
		fx+=2.5;
	}
if(fx==650  && fy>=130 && fy<=640)
	{
              loop1=2;
		fy+=2.5;
	}
if(fx<=650  && fx>=140 && fy==640)
	{
               loop1=2;
		fx-=2.5;
	}
if(fx==140 && fy>=130 && fy<=650)
	{
              loop1=2;
		fy-=2.5;
	}

// code of opponent car to move in third arena....................................

if( fx<=550 && fx>=240 && fy==230)
	{
		loop1=3;
		fx+=2.5;
	}
if(fx==550  && fy>=230 && fy<=540)
	{  
               loop1=3;
		fy+=2.5;
	}
if(fx<=550  && fx>=240 && fy==540)
	{
                loop1=3;
		fx-=2.5;
	}
if(fx==240 && fy>=230 && fy<=550)
	{
                 loop1=3;
		fy-=2.5;
	}

// code of opponent car to move in forth arena....................................

if( fx<=450 && fx>=340 && fy==330)
	{
		loop1=4;
		fx+=2.5;
	}
if(fx==450  && fy>=330 && fy<=440)
	{ 
                loop1=4;
		fy+=2.5;
	}
if(fx<=450  && fx>=340 && fy==440)
	{
                 loop1=4;
		fx-=2.5;
	}
if(fx==340 && fy>=330 && fy<=450)
	{
               loop1=4;
		fy-=2.5;
	}
         }
//===============================================================================================================================================================================================================

/* for car move in first arena
    my car moving clockwise*/
	
	if( gx>=40 && gx<=750 && gy==30)
	{
		loop=1;
		gx-=5;
	}
	if(gx==40  && gy>=30 && gy<=780)
	{
         loop=1;
		gy+=5;
	}
       if(gx>=40  && gx<=750 && gy==750)
	{
            loop=1;
		gx+=5;
	}
       if(gx==750 && gy>=30 && gy<=750)
	{
            loop=1;
		gy-=5;
	}
// second box
	if( gx>=140 && gx<=650 && gy==130)
	{
		loop=2;
		gx-=5;
	}
	if(gx==140  && gy>=130 && gy<=680)
	{
                loop=2;
		gy+=5;
	}
       if(gx>=140  && gx<=650 && gy==650)
	{
              loop=2;
		gx+=5;
	}
       if(gx==650 && gy>=130 && gy<=650)
	{
            loop=2;
		gy-=5;
	}
	

// third box...
        

   if( gx>=240 && gx<=550 && gy==230)
	{
		loop=3;
		gx-=5;
	}
	if(gx==240  && gy>=230 && gy<=580)
	{
               loop=3;
		gy+=5;
	}
       if(gx>=240  && gx<=550 && gy==550)
	{
          loop=3;
		gx+=5;
	}
       if(gx==550 && gy>=230 && gy<=550)
	{
            loop=3;
		gy-=5;
	}

// fourth box.............

	if( gx>=340 && gx<=450 && gy==330)
	{
		loop=4;
		gx-=5;
	}
	if(gx==340  && gy>=330 && gy<=480)
	{
             loop=4;
		gy+=5;
	}
       if(gx>=340  && gx<=450 && gy==450)
	{
             loop=4;
		gx+=5;
	}
       if(gx==450 && gy>=330 && gy<=450)
	{
             loop=4;
		gy-=5;
	}








//==========================================================================================================================================================================================================
//opponent follows you...                                               // AI MOVEMNT OF OPPONENT
  if(level==1)																	//LEVEL==1
   {
// for moving inside..........
// from up to centre....
if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==740))
{
fy=fy-100;
}
else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==640))
{
fy=fy-100;
}
   
else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==540))
{
fy=fy-100;
}
  //down to centre

else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==30))
{
fy=fy+100;
}
 
else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==130))
{
fy=fy+100;
}
  

else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==230))
{
fy=fy+100;
}
// for moving outside...
// from centre to up....
if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==640))
{
fy=fy+100;
}
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==540))
{
fy=fy+100;
}
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==440))
{
fy=fy+100;
}
   // from centre to dwonword........................
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==130))
{
fy=fy-100;
}
 
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==230))
{
fy=fy-100;
}
    
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==330))
{
fy=fy-100;
}
  }
//-------------------------------------------------------------------------------------------------------

if(level==2) 												// level ===2
 {
// for moving inside..........
// from up to centre....
if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==740))   
{ 					     		
fy=fy-100;
}
else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==640))
{
fy=fy-100;
}
   
else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==540))
{
fy=fy-100;
}
  //down to centre

else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==30))
{
fy=fy+100;
}
 
else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==130))
{
fy=fy+100;
}
  

else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==230))
{
fy=fy+100;
}
// for moving outside...
// from centre to up....
if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==640))
{
fy=fy+100;
}
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==540))
{
fy=fy+100;
}
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==440))
{
fy=fy+100;
}
   // from centre to dwonword........................
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==130))
{
fy=fy-100;
}
 
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==230))
{
fy=fy-100;
}
    
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==330))
{
fy=fy-100;
}

//for moving left to right........
 //inside 
  
if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==750))
{
fx=fx-100;
}
else if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==650))
{
fx=fx-100;
}
   
else if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==550))
{
fx=fx-100;
}
// from right to left.....................
//inside...
else if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==240))
{
fx=fx+100;
}
else if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==140))
{
fx=fx+100;
}
   
else if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==40))
{
fx=fx+100;
}
  
 //for moving outside...
// from centre to right....
if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==340))
{
fx=fx-100;
}
else if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==240))
{
fx=fx-100;
}
   
else if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==140))
{
fx=fx-100;
}
// from centre to left......
else if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==450))
{
fx=fx+100;
}
else if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==550))
{
fx=fx+100;
}
   
else if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==650))
{
fx=fx+100;

}
}
//-------------------------------------------------------------------------------------------------------------------------
if(level==3) 												// LEVEL ===3
 {
// for moving inside..........
// from up to centre....
if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==740))   
{ 					     		
fy=fy-100;
}
else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==640))
{
fy=fy-100;
}
   
else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==540))
{
fy=fy-100;
}
  //down to centre

else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==30))
{
fy=fy+100;
}
 
else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==130))
{
fy=fy+100;
}
  

else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==230))
{
fy=fy+100;
}
// for moving outside...
// from centre to up....
if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==640))
{
fy=fy+100;
}
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==540))
{
fy=fy+100;
}
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==440))
{
fy=fy+100;
}
   // from centre to dwonword........................
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==130))
{
fy=fy-100;
}
 
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==230))
{
fy=fy-100;
}
    
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==330))
{
fy=fy-100;
}

//for moving left to right........
 //inside 
  
if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==750))
{
fx=fx-100;
}
else if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==650))
{
fx=fx-100;
}
   
else if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==550))
{
fx=fx-100;
}
// from right to left.....................
//inside...
else if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==240))
{
fx=fx+100;
}
else if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==140))
{
fx=fx+100;
}
   
else if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==40))
{
fx=fx+100;
}
  
 //for moving outside...
// from centre to right....
if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==340))
{
fx=fx-100;
}
else if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==240))
{
fx=fx-100;
}
   
else if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==140))
{
fx=fx-100;
}
// from centre to left......
else if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==450))
{
fx=fx+100;
}
else if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==550))
{
fx=fx+100;
}
   
else if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==650))
{
fx=fx+100;

}
}
//==================================================================
if(level==4)                                                       					// LEVEL====4
 {
// for moving inside..........
// from up to centre....
if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==740))   
{ 					     		
fy=fy-100;
}
else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==640))
{
fy=fy-100;
}
   
else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==540))
{
fy=fy-100;
}
  //down to centre

else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==30))
{
fy=fy+100;
}
 
else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==130))
{
fy=fy+100;
}
  

else if((loop>loop1 ) && ((fx<=450 && fx>=372) && fy==230))
{
fy=fy+100;
}
// for moving outside...
// from centre to up....
if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==640))
{
fy=fy+100;
}
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==540))
{
fy=fy+100;
}
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==440))
{
fy=fy+100;
}
   // from centre to dwonword........................
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==130))
{
fy=fy-100;
}
 
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==230))
{
fy=fy-100;
}
    
else if((loop1>loop ) && ((fx<=450 && fx>=372) && fy==330))
{
fy=fy-100;
}

//for moving left to right........
 //inside 
  
if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==750))
{
fx=fx-100;
}
else if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==650))
{
fx=fx-100;
}
   
else if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==550))
{
fx=fx-100;
}
// from right to left.....................
//inside...
else if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==240))
{
fx=fx+100;
}
else if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==140))
{
fx=fx+100;
}
   
else if((loop>loop1 ) && ((fy>=380 && fy<=460) && fx==40))
{
fx=fx+100;
}
  
 //for moving outside...
// from centre to right....
if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==340))
{
fx=fx-100;
}
else if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==240))
{
fx=fx-100;
}
   
else if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==140))
{
fx=fx-100;
}
// from centre to left......
else if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==450))
{
fx=fx+100;
}
else if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==550))
{
fx=fx+100;
}
   
else if((loop1>loop ) && ((fy>=380 && fy<=460) && fx==650))
{
fx=fx+100;

}
 // for seconf opponent car================================                            /// AI MOVEMENT FOR SECOND  OPPONENT CAR===============================================
// for moving inside..........
// from up to centre....
if((loop>loop1 ) && ((ffx<=450 && ffx>=372) && ffy==740))   
{ 					     		
ffy=ffy-100;
}
else if((loop>loop1 ) && ((ffx<=450 && ffx>=372) && ffy==640))
{
ffy=ffy-100;
}
   
else if((loop>loop1 ) && ((ffx<=450 && ffx>=372) && ffy==540))
{
ffy=ffy-100;
}
  //down to centre

else if((loop>loop1 ) && ((ffx<=450 && ffx>=372) && ffy==30))
{
ffy=ffy+100;
}
 
else if((loop>loop1 ) && ((ffx<=450 && ffx>=372) && ffy==130))
{
ffy=ffy+100;
}
  

else if((loop>loop1 ) && ((ffx<=450 && ffx>=372) && ffy==230))
{
ffy=ffy+100;
}
// for moving outside...
// from centre to up....
if((loop1>loop ) && ((ffx<=450 && ffx>=372) && ffy==640))
{
ffy=ffy+100;
}
else if((loop1>loop ) && ((ffx<=450 && ffx>=372) && ffy==540))
{
ffy=ffy+100;
}
else if((loop1>loop ) && ((ffx<=450 && ffx>=372) && ffy==440))
{
ffy=ffy+100;
}
   // from centre to dwonword........................
else if((loop1>loop ) && ((ffx<=450 && ffx>=372) && ffy==130))
{
ffy=ffy-100;
}
 
else if((loop1>loop ) && ((ffx<=450 && ffx>=372) && ffy==230))
{
ffy=ffy-100;
}
    
else if((loop1>loop ) && ((ffx<=450 && ffx>=372) && ffy==330))
{
ffy=ffy-100;
}

//for moving left to right........
 //inside 
  
if((loop>loop1 ) && ((ffy>=380 && ffy<=460) && ffx==750))
{
ffx=ffx-100;
}
else if((loop>loop1 ) && ((ffy>=380 && ffy<=460) && ffx==650))
{
ffx=ffx-100;
}
   
else if((loop>loop1 ) && ((ffy>=380 && ffy<=460) && ffx==550))
{
ffx=ffx-100;
}
// from right to left.....................
//inside...
else if((loop>loop1 ) && ((ffy>=380 && ffy<=460) && ffx==240))
{
ffx=ffx+100;
}
else if((loop>loop1 ) && ((ffy>=380 && ffy<=460) && ffx==140))
{
ffx=ffx+100;
}
   
else if((loop>loop1 ) && ((ffy>=380 && ffy<=460) && ffx==40))
{
ffx=ffx+100;
}
  
 //for moving outside...
// from centre to right....
if((loop1>loop ) && ((ffy>=380 && ffy<=460) && ffx==340))
{
ffx=ffx-100;
}
else if((loop1>loop ) && ((ffy>=380 && ffy<=460) && ffx==240))
{
ffx=ffx-100;
}
   
else if((loop1>loop ) && ((ffy>=380 && ffy<=460) && ffx==140))
{
ffx=ffx-100;
}
// from centre to left......
else if((loop1>loop ) && ((ffy>=380 && ffy<=460) && ffx==450))
{
ffx=ffx+100;
}
else if((loop1>loop ) && ((ffy>=380 && ffy<=460) && ffx==550))
{
ffx=ffx+100;
}
   
else if((loop1>loop ) && ((ffy>=380 && ffy<=460) && ffx==650))
{
ffx=ffx+100;

}


}

   }  
//============================================================================================
void highscores(){
  

}
//==========================================================================================###
void displaying()														// FUNCTION FOR DISPLAYING  SCORE AND LIVES ON SCREEN
{
DrawString( 70, 820, "Score=", colors[MISTY_ROSE]);// for displaying score
string temp=Num2Str(score);
DrawString( 140, 820, temp, colors[MISTY_ROSE]);// for displaying score

DrawString( 740, 820, "lives=", colors[MISTY_ROSE]);// for displaying lives
string temper=Num2Str(lives);
DrawString( 810, 820, temper, colors[MISTY_ROSE]);// for displaying score
}

//==============================================================================================

void collision()									      //function for collision AND LIVES--     ============
 {
   if ((fx<=gx+10 && fx>=gx-10 )&&(fy<=gy+10 && fy>=gy-10))
     { lives--;
	gx=350;
	gy=30;
	fx=450;
	fy=30;
       sleep(3);        }
       if (lives==0)
           {
               DrawString( 350, 400, "GAME OVER", colors[MISTY_ROSE]);// for displaying game over                     // DISPLAYING GAME OVER==================
               }
		
     }
  //=========================================================================================== 

         
   void stop()												//FUNCTION FOR PAUSING THE GAME========================
         {
       menu();
        DrawString( 102, 170, "5.) CONTINUE", colors[MISTY_ROSE]);// for displaying continue option
 }    
void start() { 													// FUNCTION FOR CONTINUING AGAIN GAME FROM PAUSE

             car();
           arena();
          makingfood();
          eatingfood();
          movement();
          displaying();
          collision();
          
          if (level==4) {  
          secondcardisplay();
          secondcarmovement();
                      }
          if (level==2) 									// for changing colour of arean
           {
             arenaforcolour();
             }
           if (level==3) 											// for changing colour of arean
             {
               arenaforcolour1();
              }
             }


      

//=================================================================================================
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
//Board *b;

void GameDisplay()/**/{  										//functions for gamedisplay=======================
         
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	if (flag==0)
         {
          menu();                                   // for menu
          }
         else if( flag==1)
           {
           car();                                        // if 1 pressed then display all functions
           arena();
          makingfood();
          eatingfood();
          movement();
          displaying();
          collision();
       if (level==4) {                             
          secondcardisplay();                      // for 4th level 2 cars display 
          secondcarmovement();
                      }
        if (level==2)
         {
               arenaforcolour();                    //  change colour for second level
          
         }
          if (level==3)
          {
               arenaforcolour1();                // change colur for 3rd level
           }
          
        //  changinglevel();
 }
          else if(flag==2)
                {                                        
                 help();                               //press 2 for help
                }
           else if(flag==3)
                { 
                    highscores();
                } 
          else if (flag==4)
                 {                                        //           press 4 for exit
                    exit(1);
                 }
          if(flag==5)
                {                                          // press p to pause
                    stop();
                }
          if (flag==6)
                {                                       //  press 6 to start
                  start();
                }
//================================================================================================================================================================================================//===============================================================================================================================================================================================================
//......................................................................................................................................................................................


	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
//  for MY car==========================================================================================================================================================================================

	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
 {
        
                  {           
                   if((gy>=380 && gy<=460 )&& (gx==750 || gx==650 || gx==550 || gx==340 || gx==240 || gx==140))		

                     gx=gx-100;

                   }
} 
         else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
        {
	   
           {
	if((gy>=375 && gy<=460 )&& (gx==450 || gx==650 || gx==550 || gx==40 || gx==240 || gx==140))		

                     gx=gx+100;
                }


       } 




         else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) 
        {
           {

            if((gx<=450 && gx>=372 )&& (gy==30|| gy==130 || gy==230 ||gy==450||gy==550 ||gy== 650  ))		

                     gy=gy+100;
           }
	
	}

	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) 
       {
	    {if((gx<=450 && gx>=372 )&& (gy==330|| gy==130 || gy==230 ||gy==650 ||gy==550 ||gy==750 ))		

                     gy=gy-100;
                                }

          

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();


}
/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {                                                    //SETTING (KEY==ASCII)   FOR  MENU WORKING
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 49 )
			{
		flag=1;

	}
        
         if(key == 50)
               {
                 flag=2;
               }
         if (key == 51)
          {
                flag=3;
           }
         if (key ==52)
           {
                 flag=4;
           }
          if (key==112)
           {
               flag=5;
            }
            
           if (key==53) 
           {
              flag=6;          
 
           }
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	glutPostRedisplay();
	bool flag1=true;
	bool flag2=true;

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(20.0, Timer, 0);
	
      
   





















}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...
       
	
	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys);// tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
