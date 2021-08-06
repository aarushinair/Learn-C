#include <stdio.h>
#include <string.h>
void reverse_string(char*);
void reverse_words(char*);

int main() {
  char a[100];

  gets(a);

  reverse_words(a);

  printf("%s\n", a);

  return 0;
}

void reverse_words(char *s) {
  char b[100], *t, *z;
  int c = 0;

  t = s;

  while(*t) {                           //processing complete string
    while(*t != ' ' && *t != '\0') {    //extracting word from string
      b[c] = *t;
      t++;
      c++;
    }
    b[c] = '\0';
    c = 0;
 
    reverse_string(b);        // reverse the extracted word

    z = b;

    while (*z) {    //copying the reversed word into original string
      *s = *z;
      z++;
      s++;
    }

    while (*s == ' ') {                 // skipping space(s)
      s++;
    }
    /*
     * You may use if statement in place of while loop if
     * you are assuming only one space between words. If condition is
     * used because null terminator can also occur after a word, in
     * that case we don't want to increment pointer.
     * if (*s == ' ') {
     *   s++;
     * }
     */
    t = s;                              // pointing to next word
  }
}

/*
 * Function to reverse a word.
 */

void reverse_string(char *t) {
  int l, c;
  char *e, s;

  l = strlen(t);
  e = t + l - 1;

  for (c = 0; c < l/2; c++) {
    s  = *t;
    *t = *e;
    *e = s;
    t++;
    e--;
  }
}








👋 Hi, I’m @aarushinair - Aarushi Nair (she/her/ella)
👀 I’m a Computer Science Engineering Student
💞️ I’m looking to collaborate on #java, #python, #R, #applicationdevelopment
🌱 #GirlsWhoCode #WomenInTech #WomenInIT #WomenInSTEM #CyberSecurity #QuantumComputing #BlockChain #AI #ML
📫 How to reach me: https://www.linkedin.com/in/aarushinair/
👩‍🏫 YouTube Channel - Code with Aarushi : https://www.youtube.com/channel/UCKj5T1ELHCmkGKujkpqtl7Q
🙋‍ Follow me on Twitter: https://twitter.com/aarushinair_
