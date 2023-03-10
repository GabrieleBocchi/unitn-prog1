using namespace std;
#include <iostream>

double rec_array_sum(const double myarray[],int min,int max)
{
  double res;
  if (min>max) 
    res=0.0;
  else 
    res = myarray[min]+rec_array_sum(myarray,min+1,max);
  return res;
}

double array_sum (const double myarray[],int max) 
{
  double res;
  res = rec_array_sum(myarray,0,max-1);
  return res;
}

int main () 
{
  const int dim=10;
  double myarray[dim] = 
  {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};  
  cout << "La somma e' " << array_sum(myarray,dim) << endl;
return 0;
}

