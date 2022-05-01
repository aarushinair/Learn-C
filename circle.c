#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
union REGS i, o;

int initmouse()
{
   i.x.ax = 0;
   int86(0X33, &i, &o);
   return ( o.x.ax );
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33, &i, &o);
}

void hidemopuseptr()
{
   i.x.ax = 2;
   int86(0X33, &i, &o);
}

void getmousepos(int *x, int *y)
{
   i.x.ax = 3;
   int86(0X33, &i, &o);
   *x = o.x.cx;
   *y = o.x.dx;

}

void movemouseptr(int x, int y)
{
   i.x.ax = 4;
   i.x.cx = x;
   i.x.dx = y;
   int86(0X33, &i, &o);
}

main()
{
   int gd = DETECT, gm, midx, midy, radius, x, y, tempx, tempy;

   radius = 100;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   if(!initmouse())
   {
      closegraph();
      exit(1);
   }

   midx = getmaxx()/2;
   midy = getmaxy()/2;

   showmouseptr();
   movemouseptr(midx, midy);
   circle(midx, midy, radius);

   x = tempx = midx;
   y = tempy = midy;

   while(!kbhit())
   {
      getmousepos(&x, &y);

      if((pow(x-midx,2)+pow(y-midy,2)-pow(radius,2))>0)
      {
         movemouseptr(tempx, tempy);
         x = tempx;
         y = tempy;
      }

      tempx = x;
      tempy = y;
   }

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
