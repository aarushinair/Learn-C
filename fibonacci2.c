#include <stdio.h>
int main() {
  int t1 = 0, t2 = 1, nextTerm = 0, n;
  printf("Enter a positive number: ");
  scanf("%d", &n);

  // displays the first two terms which is always 0 and 1
  printf("Fibonacci Series: %d, %d, ", t1, t2);
  nextTerm = t1 + t2;

  while (nextTerm <= n) {
    printf("%d, ", nextTerm);
    t1 = t2;
    t2 = nextTerm;
    nextTerm = t1 + t2;
  }

  return 0;
}








š Hi, Iām @aarushinair - Aarushi Nair (she/her/ella)
š Iām a Computer Science Engineering Student
šļø Iām looking to collaborate on #java, #python, #R, #applicationdevelopment
š± #GirlsWhoCode #WomenInTech #WomenInIT #WomenInSTEM #CyberSecurity #QuantumComputing #BlockChain #AI #ML
š« How to reach me: https://www.linkedin.com/in/aarushinair/
š©āš« YouTube Channel - Code with Aarushi : https://www.youtube.com/channel/UCKj5T1ELHCmkGKujkpqtl7Q
šā Follow me on Twitter: https://twitter.com/aarushinair_
