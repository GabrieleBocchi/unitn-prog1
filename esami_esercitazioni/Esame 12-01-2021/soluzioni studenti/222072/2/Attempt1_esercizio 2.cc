#include <iostream>
#include <cstddef>

using namespace std;

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

void get_elements (int s[], int s_s, int d1[], const int md1_s, int & d1_s, int d2[], const int md2_s, int & d2_s, int index = 0) {
  if (index < s_s) {
    if (index % 3 == 0 && s[index] % 2 == 0) {
      // MR: Manca controllo che d1_s < md1_s
      d1[d1_s] = s[index] * 2;
      d1_s ++;
    }
    else {
      // MR: Manca controllo che d2_s < md2_s
      d2[d2_s] = s[index] * 3;
      d2_s ++;
    }
    get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, index+1);
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
