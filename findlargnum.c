#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  double *data;
  printf("Enter the total number of elements: ");
  scanf("%d", &n);

  // Allocating memory for n elements
  data = (double *)calloc(n, sizeof(double));
  if (data == NULL) {
  printf("Error!!! memory not allocated.");
  exit(0);
  }

  // Storing numbers entered by the user.
  for (int i = 0; i < n; ++i) {
  printf("Enter number%d: ", i + 1);
  scanf("%lf", data + i);
  }

  // Finding the largest number
  for (int i = 1; i < n; ++i) {
    if (*data < *(data + i)) {
      *data = *(data + i);
Ā    }
  }
  printf("Largest number = %.2lf", *data);

  free(data);

  return 0;
}









š Hi, Iām @aarushinair - Aarushi Nair (she/her/ella)
š Iām a Computer Science Engineering Student
šļø Iām looking to collaborate on #java, #python, #R, #applicationdevelopment
š± #GirlsWhoCode #WomenInTech #WomenInIT #WomenInSTEM #CyberSecurity #QuantumComputing #BlockChain #AI #ML
š« How to reach me: https://www.linkedin.com/in/aarushinair/
š©āš« YouTube Channel - Code with Aarushi : https://www.youtube.com/channel/UCKj5T1ELHCmkGKujkpqtl7Q
šā Follow me on Twitter: https://twitter.com/aarushinair_
