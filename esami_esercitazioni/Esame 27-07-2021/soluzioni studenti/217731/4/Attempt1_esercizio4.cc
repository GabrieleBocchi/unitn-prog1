#include <iostream>
#include <cstdlib>

using namespace std;

// Possibile funzione di supporto per il calcolo dei valori della
// continued fraction representation
int gcd(int n, int d)
{
  while (n != d)
  {
    if (n > d)
      n -= d;
    else
      d -= n;
  }
  return n;
}

//wrap fun
void wrap_ccfe(const int num, const int den, int res[], int i, const int res_madim)
{
  if (i < res_madim && den > 0) // sistemare condizione di uscita
  {
    res[i] = num / den;
    // MR: manca controllo che num%den > 0!
    int g = gcd(den, num % den);
    cout << res[i] << endl; //testing
    wrap_ccfe(den / g, (num % den) / g, res, i + 1, res_madim);
  }
}

// Inserire qui sotto la dichiarazione e definizione della procedura
// compute_continued_fraction_elements
void compute_continued_fraction_elements(const int num, const int den, int res[], const int res_madim)
{
  wrap_ccfe(num, den, res, 0, res_madim);
}

// Inserire qui sopra la dichiarazione e definizione della procedura
// compute_continued_fraction_elements

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    std::cout << "Usage: " << argv[0] << " <numerator_positivenum> <denominator_positivenum>" << std::endl;
    exit(1);
  }
  int num = atoi(argv[1]);
  int den = atoi(argv[2]);
  int res_maxdim = 20;
  int *res = new int[res_maxdim];

  for (int i = 0; i < res_maxdim; i++)
    res[i] = -1;

  compute_continued_fraction_elements(num, den, res, res_maxdim);

  cout << "The continued fraction representation for "
       << num << "/" << den << " is" << endl;
  for (int i = 0; ((i < res_maxdim) && (res[i] != -1)); i++)
    cout << " " << res[i];
  cout << endl;

  delete[] res;
}
