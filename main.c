#include <stdio.h>

int main (void)
{
  FILE *f1, *f2, *h;
  char str[100];

  printf("Opening files\n\n");
  f1 = fopen("f1.txt", "r");
  f2 = fopen("f2.txt", "r");
  h = fopen("h.txt", "w");

  while (fgets(str, 100, f1) != NULL)
    fprintf(h, "%s", str);

  f1 = fopen("f1.txt", "w");

  while (fgets(str, 100, f2) != NULL)
    fprintf(f1, "%s", str);
    printf("Wrote file f2 to file f1\n\n");

  f2 = fopen("f2.txt", "w");
  fclose(h);
  h = fopen("h.txt", "r");

  while (fgets(str, 100, h) != NULL)
    fprintf(f2, "%s", str);
    printf("Wrote file f1 to file f2\n\n");

  printf("Successfully\n");
  fopen("h.txt", "w");
  fclose(f1);
  fclose(f2);
  fclose(h);
}