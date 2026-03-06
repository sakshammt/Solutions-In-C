#include <stdio.h>
int add(int x, int y)
{
  return x + y;
}

int multiply(int x, int y)
{
  return x*y;
}

int difference(int x, int y)
{
  int p = x - y;
  if (p<0)
    return -1*p;
  else
    return p;
}

int divide(int x, int y)
{
  int p = x/y;
  return p;
}

int main()
{
  int x, y, ans, opvalue;
  printf("Enter any two values (integers): ");
  scanf("%d%d", &x, &y);
  
  printf("List of Operations:\nValue\tOperation\n1\tAddition\n2\tDifference\n3\tMultiplication\n4\tDivision\n\nEnter the value of the operation you want to perform on the given two numbers: ");
  scanf("%d", &opvalue);
  
  if (opvalue == 1)
    printf("Sum = %d\n", add(x, y));
  else if (opvalue == 2)
    printf("Difference = %d\n", difference(x, y));
  else if (opvalue == 3)
    printf("Product = %d\n", multiply(x,y));
  else if (opvalue == 4)
    printf("Integral Quotient = %d\n", divide(x,y));
}
