using namespace std;
#include <iostream>

int depth = 0;

void printspaces(int n) 
{ 
  for (int i=0;i<n;i++)
    cout << "   "; 
}

long long fatt (int n) 
{
  long long res;
  
depth++;
printspaces(depth); 
cout <<  "> fact(" << n << ")\n";

  if (n==0) 
    res = 1;
  else
    res = n * fatt(n-1);

printspaces(depth); 
cout << "< " <<  res << endl;
depth--;

  return res;
}

int main() 
{
  int n;
  cout << "n? ";
  cin >> n;
  cout << "fattoriale(" << n << ") = \n" << fatt(n) << endl;
return 0;
}

