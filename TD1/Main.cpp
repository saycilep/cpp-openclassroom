#include <iostream>
#include "ZFraction.h"
using namespace std;

int main() {
  /* code */
  ZFraction a(1,5);
  ZFraction b(2);
  ZFraction c,d;

  c=a+b;
  cout << c << endl;

  return 0;
}
