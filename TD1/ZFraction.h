#ifndef DEF_FRACTION
#define DEF_FRACTION

#include <iostream>

class ZFraction
{
public:
  ZFraction(int numerateur,int denominateur);
  ZFraction(int numerateur);
  ZFraction();
  ZFraction calculAddition(ZFraction const& a) const;
  void afficher(std::ostream &flux) const;

private:
  int m_numerateur;
  int m_denominateur;
};

int pgcd(int a, int b);
ZFraction operator+(ZFraction const& a, ZFraction const& b);
std::ostream& operator<<( std::ostream &flux, ZFraction const& fraction );

#endif
