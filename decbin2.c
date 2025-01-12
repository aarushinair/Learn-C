#include <stdio.h>
#include <stdlib.h>
char *decimal_to_binary(int);

int main()
{
  int n;
  char *p;

  printf("Enter an integer in decimal number system\n");
  scanf("%d", &n);

  p = decimal_to_binary(n);
  printf("Binary string of %d is: %s\n", n, p);

  free(p);

  return 0;
}

char *decimal_to_binary(int n)
{
  int c, d, t;
  char *p;

  t = 0;
  p = (char*)malloc(32+1);

  if (p == NULL)
    exit(EXIT_FAILURE);

  for (c = 31 ; c >= 0 ; c--)
  {
    d = n >> c;

    if (d & 1)
      *(p+t) = 1 + '0';
    else
      *(p+t) = 0 + '0';

    t++;
  }
  *(p+t) = '\0';

  return  p;
}









/*
👋 Hi, I’m @aarushinair - Aarushi Nair (she/her/ella)
👀 I’m a Computer Science Engineering Student
💞️ I’m looking to collaborate on #java, #python, #R, #applicationdevelopment
🌱 #GirlsWhoCode #WomenInTech #WomenInIT #WomenInSTEM #CyberSecurity #QuantumComputing #BlockChain #AI #ML
📫 How to reach me: https://www.linkedin.com/in/aarushinair/
👩‍🏫 YouTube Channel - Code with Aarushi : https://www.youtube.com/channel/UCKj5T1ELHCmkGKujkpqtl7Q
🙋‍ Follow me on Twitter: https://twitter.com/aarushinair_
*/
