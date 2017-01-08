#include "ZFraction.h"
using namespace std;

ZFraction::ZFraction(int numerateur,int denominateur) : m_numerateur(numerateur), m_denominateur(denominateur)
{

  int a = pgcd(m_numerateur, m_denominateur);
  m_numerateur /= a;
  m_denominateur /= a;
}


ZFraction::ZFraction(int numerateur) : m_numerateur(numerateur), m_denominateur(1) {

}
ZFraction::ZFraction() : m_numerateur(0), m_denominateur(1) {

}

ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
  ZFraction resultat;
  // Calcul des valeurs des attributs de resultat
  resultat = a.calculAddition(b);
  return resultat;
}

ZFraction ZFraction::calculAddition(ZFraction const& a) const {
  ZFraction resultat;
  resultat.m_denominateur = m_denominateur * a.m_denominateur;
  resultat.m_numerateur = (m_numerateur * a.m_denominateur) + (a.m_numerateur * m_denominateur);
  int a_res = pgcd(resultat.m_numerateur, resultat.m_denominateur);
  resultat.m_numerateur /= a_res;
  resultat.m_denominateur /= a_res;
  return resultat;
}

int pgcd(int a, int b)
{
  while (b != 0)
  {
    const int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

ostream& operator<<( ostream &flux, ZFraction const& fraction )
{
  //Affichage des attributs
  fraction.afficher(flux);
  return flux;
}
void ZFraction::afficher(ostream &flux) const
{
  flux << m_numerateur << '/' << m_denominateur;
}
