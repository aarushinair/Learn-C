#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
union REGS i, o;
int leftcolor[15];

int get_key()
{
   union REGS i,o;

   i.h.ah = 0;
   int86(22, &i, &o);

   return ( o.h.ah );
}

void draw_color_panel()
{
   int left, top, c, color;

   left = 100;
   top = 436;

   color = getcolor();
   setcolor(GREEN);
   rectangle(4,431,635,457);
   setcolor(RED);
   settextstyle(TRIPLEX_FONT,0,2);
   outtextxy(10,431,"Colors : ");

   for( c = 1 ; c <= 15 ; c++ )
   {
      setfillstyle(SOLID_FILL, c);
      bar(left, top, left+16, top+16);
      leftcolor[c-1] = left;
      left += 26;
   }

   setcolor(color);
}

void draw_shape_panel()
{
   int left, top, c, color;

   left = 529;
   top = 45;

   color = getcolor();
   setcolor(GREEN);
   rectangle(525,40,633,255);

   for( c = 1 ; c <= 7 ; c++ )
   {
      rectangle(left, top, left+100, top+25);
      top += 30;
   }
   setcolor(RED);
   outtextxy(530,45,"Bar");
   outtextxy(530,75,"Line");
   outtextxy(530,105,"Pixel");
   outtextxy(530,135,"Ellipse");
   outtextxy(530,165,"Freehand");
   outtextxy(530,195,"Rectangle");
   outtextxy(530,225,"Clear");
   setcolor(color);
}

void change_color(int x, int y)
{
   int c;

   for( c = 0 ; c <= 13 ; c++ )
   {
      if( x > leftcolor[c] && x < leftcolor[c+1] && y > 437 && y < 453 )
         setcolor(c+1);
      if( x > leftcolor[14] && x < 505 && y > 437 && y < 453 )
         setcolor(WHITE);
   }
}

char change_shape(int x, int y)
{
   if ( x > 529 && x < 625 && y > 45 && y < 70 )
      return 'b';
   else if ( x > 529 && x < 625 && y > 75 && y < 100 )
      return 'l';
   else if ( x > 529 && x < 625 && y > 105 && y < 130 )
      return 'p';
   else if ( x > 529 && x < 625 && y > 135 && y < 160 )
      return 'e';
   else if ( x > 529 && x < 625 && y > 165 && y < 190 )
      return 'f';
   else if ( x > 529 && x < 625 && y > 195 && y < 220 )
      return 'r';
   else if ( x > 529 && x < 625 && y > 225 && y < 250 )
      return 'c';
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0x33, &i, &o);
}

void hidemouseptr()
{
   i.x.ax = 2;
   int86(0x33, &i, &o);
}

void restrictmouseptr( int x1, int y1, int x2, int y2)
{
   i.x.ax = 7;
   i.x.cx = x1;
   i.x.dx = x2;
   int86(0x33, &i, &o);

   i.x.ax = 8;
   i.x.cx = y1;
   i.x.dx = y2;
   int86(0x33, &i, &o);
}

void getmousepos(int *button,int *x,int *y)
{
   i.x.ax = 3;
   int86(0x33, &i, &o);

   *button = o.x.bx;
   *x = o.x.cx;
   *y = o.x.dx;
}

main()
{
   int gd = DETECT,gm;

   int maxx,maxy,x,y,button,prevx,prevy,temp1,temp2,key,color;
   char ch = 'f' ;            // default free-hand drawing

   initgraph(&gd,&gm,"C:\\TC\\BGI");

   maxx = getmaxx();
   maxy = getmaxy();

   setcolor(BLUE);
   rectangle(0,0,maxx,maxy);

   setcolor(WHITE);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   outtextxy(maxx/2-180,maxy-28,"<a href="http://www.programmingsimplified.com"">www.programmingsimplified.com"</a>);

   draw_color_panel();
   draw_shape_panel();

   setviewport(1,1,maxx-1,maxy-1,1);

   restrictmouseptr(1,1,maxx-1,maxy-1);
   showmouseptr();
   rectangle(2,2,518,427);
   setviewport(1,1,519,428,1);

   while(1)
   {
      if(kbhit())
      {
         key = get_key();

         if( key == 1 )
         {
            closegraph();
            exit(0);
         }
      }

      getmousepos(&button,&x,&y);

      if( button == 1 )
      {
         if( x > 4 && x < 635 && y > 431 && y < 457 )
            change_color( x, y );
         else if ( x > 529 && x < 625 && y > 40 && y < 250 )
             ch = change_shape( x, y );

         temp1 = x ;
         temp2 = y ;

         if ( ch == 'f' )
         {
            hidemouseptr();
            while( button == 1 )
            {
               line(temp1,temp2,x,y);
               temp1 = x;
               temp2 = y;
               getmousepos(&button,&x,&y);
            }
            showmouseptr();
         }

         while( button == 1)
            getmousepos(&button,&x,&y);

         /* to avoid interference of mouse while drawing */
         hidemouseptr();

         if( ch == 'p')
            putpixel(x,y,getcolor());

         else if ( ch == 'b' )
         {
            setfillstyle(SOLID_FILL,getcolor());
            bar(temp1,temp2,x,y);
         }
         else if ( ch == 'l')
            line(temp1,temp2,x,y);
         else if ( ch == 'e')
            ellipse(temp1,temp2,0,360,abs(x-temp1),abs(y-temp2));
         else if ( ch == 'r' )
            rectangle(temp1,temp2,x,y);
         else if ( ch == 'c' )
         {
            ch = 'f';          // setting to freehand drawing
            clearviewport();
            color = getcolor();
            setcolor(WHITE);
            rectangle(2,2,518,427);
            setcolor(color);
         }

         showmouseptr();
      }
   }
}








👋 Hi, I’m @aarushinair - Aarushi Nair (she/her/ella)
👀 I’m a Computer Science Engineering Student
💞️ I’m looking to collaborate on #java, #python, #R, #applicationdevelopment
🌱 #GirlsWhoCode #WomenInTech #WomenInIT #WomenInSTEM #CyberSecurity #QuantumComputing #BlockChain #AI #ML
📫 How to reach me: https://www.linkedin.com/in/aarushinair/
👩‍🏫 YouTube Channel - Code with Aarushi : https://www.youtube.com/channel/UCKj5T1ELHCmkGKujkpqtl7Q
🙋‍ Follow me on Twitter: https://twitter.com/aarushinair_
