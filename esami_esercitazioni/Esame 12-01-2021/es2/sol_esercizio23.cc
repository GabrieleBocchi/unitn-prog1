#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(const int source[],
		  const int size_s,
		  int dest1[], int msize_d1, int & d1,
		  int dest2[], int msize_d2, int & d2);

void print(const int a[], const int s, const char * prefix) {
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(int s[], const int ms, int & s_s) {
  int r = 0;
  for (s_s = 0; ((s_s < ms) && (r != -1)); ) {
    cin >> r;
    if (r != -1) s[s_s++] = r;
  }
}

int main() {
  const int maxdim = 10;

  const int md1_s = maxdim;
  int d1[md1_s];
  int d1_s = 0;

  const int md2_s = maxdim;
  int d2[md2_s];
  int d2_s = 0;

  const int ms = maxdim;
  int s[ms];
  int s_s = 0;

  read_elements(s, ms, s_s);

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}


void get_elements_aux(const int source[],
		      const int size_s,
		      int dest1[], int msize_d1, int & d1,
		      int dest2[], int msize_d2, int & d2,
		      int i);

void get_elements(const int source[],
		  const int size_s,
		  int dest1[], int msize_d1, int & d1,
		  int dest2[], int msize_d2, int & d2) {

  get_elements_aux(source, size_s,
		   dest1, msize_d1, d1,
		   dest2, msize_d2, d2,
		   0);
}

void get_elements_aux(const int source[],
		      const int size_s,
		      int dest1[], int msize_d1, int & d1,
		      int dest2[], int msize_d2, int & d2,
		      int i) {
  if ((i < size_s) && (d1 < msize_d1) && (d2 < msize_d2)) {
    if ((i % 2 == 0) && (source[i] % 3 == 0)) {
      dest1[d1++] = source[i];
    } else {
      dest2[d2++] = source[i];
    }
    get_elements_aux(source, size_s,
		     dest1, msize_d1, d1,
		     dest2, msize_d2, d2,
		     ++i);
  }
}
