#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
main()
{
   int gd = DETECT, gm, midx, midy;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   midx = getmaxx()/2;
   midy = getmaxy()/2;

   setcolor(RED);
   settextstyle(SCRIPT_FONT, HORIZ_DIR, 3);
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   outtextxy(midx, midy-10, "Traffic Light Simulation");
   outtextxy(midx, midy+10, "Press any key to start");
   getch();
   cleardevice();
   setcolor(WHITE);
   settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
   rectangle(midx-30,midy-80,midx+30,midy+80);
   circle(midx, midy-50, 22);
   setfillstyle(SOLID_FILL,RED);
   floodfill(midx, midy-50,WHITE);
   setcolor(BLUE);
   outtextxy(midx,midy-50,"STOP");
   delay(2000);
   graphdefaults();
   cleardevice();
   setcolor(WHITE);
   rectangle(midx-30,midy-80,midx+30,midy+80);
   circle(midx, midy, 20);
   setfillstyle(SOLID_FILL,YELLOW);
   floodfill(midx, midy,WHITE);
   setcolor(BLUE);
   outtextxy(midx-18,midy-3,"READY");

   delay(2000);
   cleardevice();
   setcolor(WHITE);
   rectangle(midx-30,midy-80,midx+30,midy+80);
   circle(midx, midy+50, 22);
   setfillstyle(SOLID_FILL,GREEN);
   floodfill(midx, midy+50,WHITE);
   setcolor(BLUE);
   outtextxy(midx-7,midy+48,"GO");
   setcolor(RED);
   settextstyle(SCRIPT_FONT, HORIZ_DIR, 4);
   outtextxy(midx-150, midy+100, "Press any key to exit...");

   getch();
   closegraph();
   return 0;
}








👋 Hi, I’m @aarushinair - Aarushi Nair (she/her/ella)
👀 I’m a Computer Science Engineering Student
💞️ I’m looking to collaborate on #java, #python, #R, #applicationdevelopment
🌱 #GirlsWhoCode #WomenInTech #WomenInIT #WomenInSTEM #CyberSecurity #QuantumComputing #BlockChain #AI #ML
📫 How to reach me: https://www.linkedin.com/in/aarushinair/
👩‍🏫 YouTube Channel - Code with Aarushi : https://www.youtube.com/channel/UCKj5T1ELHCmkGKujkpqtl7Q
🙋‍ Follow me on Twitter: https://twitter.com/aarushinair_
