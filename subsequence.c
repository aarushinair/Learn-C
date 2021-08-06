#include <stdio.h>
#include <string.h>
int check_subsequence (char [], char[]);

int main () {
  int t;
  char s1[1000], s2[1000];

  printf("Input first string\n");
  gets(s1);

  printf("Input second string\n");
  gets(s2);

  /** Passing smaller length string first */

  if (strlen(s1) < strlen(s2))
    t = check_subsequence(s1, s2);
  else
    t = check_subsequence(s2, s1);

  if (t)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}

int check_subsequence (char a[], char b[]) {
  int c, d;

  c = d = 0;

  while (a[c] != '\0') {
    while ((a[c] != b[d]) && b[d] != '\0') {
      d++;
    }
    if (b[d] == '\0')
      break;
    d++;
    c++;
  }
  if (a[c] == '\0')
    return 1;
  else
    return 0;
}








👋 Hi, I’m @aarushinair - Aarushi Nair (she/her/ella)
👀 I’m a Computer Science Engineering Student
💞️ I’m looking to collaborate on #java, #python, #R, #applicationdevelopment
🌱 #GirlsWhoCode #WomenInTech #WomenInIT #WomenInSTEM #CyberSecurity #QuantumComputing #BlockChain #AI #ML
📫 How to reach me: https://www.linkedin.com/in/aarushinair/
👩‍🏫 YouTube Channel - Code with Aarushi : https://www.youtube.com/channel/UCKj5T1ELHCmkGKujkpqtl7Q
🙋‍ Follow me on Twitter: https://twitter.com/aarushinair_
