#include <stdio.h>
int check_anagram(char [], char []);

int main()
{
  char a[1000], b[1000];

  printf("Enter two strings\n");
  gets(a);
  gets(b);

  if (check_anagram(a, b))
    printf("The strings are anagrams.\n");
  else
    printf("The strings aren't anagrams.\n");

  return 0;
}

int check_anagram(char a[], char b[])
{
  int first[26] = {0}, second[26] = {0}, c=0;

  // Calculating frequency of characters of the first string

  while (a[c] != '\0') {
    first[a[c]-'a']++;
    c++;
  }

  c = 0;

  while (b[c] != '\0') {
    second[b[c]-'a']++;
    c++;
  }

  // Comparing the frequency of characters

  for (c = 0; c < 26; c++)
    if (first[c] != second[c])
      return 0;

  return 1;
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
