// AUTOR: Salazar González Alejandro
// FECHA: 
// EMAIL: alu0101583211@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "rational_t.hpp"

// constructor de la clase
rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
//getter del numerador
inline
int
rational_t::get_num() const
{
  return num_;
}


//getter del denominador
inline
int
rational_t::get_den() const
{
  return den_;
}


//setter del numerador
void
rational_t::set_num(const int n)
{
  num_ = n;
}


//setter del denominador
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}


// metodo que devuelve el valor racional de la operacion de divison entre el numerador y el denominador
inline
double
rational_t::value() const
{ 
  return double(get_num()) / get_den();
}


//metodo que devuelve el numero racional en negativo multiplicando el numerador por -1
rational_t 
rational_t::opposite() const
{ 
  return rational_t((-1)*get_num(), get_den());
}


//metodo que cambia el denominador por el numerador y viceversa 
rational_t
rational_t::reciprocal() const
{ 
  return rational_t(get_den(), get_num());
}



// comparaciones
//metodo que comprueba si el numerador y el denominador son iguales
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{ 
  return fabs(value() - r.value()) < precision;
}


//metodo que compara si el numerador es mas grande que el denominador
bool
rational_t::is_greater(const rational_t& r, const double precision) const
{
  return (value() - r.value()) > precision;
}


//metodo que comprueba si el numerador es mas pequeño que el denominador usando el metodo is_greater()
bool
rational_t::is_less(const rational_t& r, const double precision) const
{
  return r.is_greater(*this, precision);
}


// operaciones
//metodo que realiza la operacion de suma de dos racionales
rational_t
rational_t::add(const rational_t& r) const
{
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), 
                    get_den() * r.get_den());
}


//metodo para restar dos racionales usando el metodo add() para sumarle el negativo usando  opposite()
rational_t
rational_t::substract(const rational_t& r) const
{
  return add(r.opposite());
}


//metodo que hace la multiplicacion de numeros racionales, multiplicando numerador por numerador y denominador por denominador
rational_t
rational_t::multiply(const rational_t& r) const
{
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}


// metodo que hace la division de numeros racionales, usando el metodo multiply() y usando con un racional con el que se ha usado el metodo reciprocal()
rational_t
rational_t::divide(const rational_t& r) const
{
  return multiply(r.reciprocal());
}


// FASE I: operadores
//sobrecarga de operador +
rational_t
operator+(const rational_t& a, const rational_t& b)
{
  // rellenar código
}


//sobrecarga de operador -
rational_t
operator-(const rational_t& a, const rational_t& b)
{
  // rellenar código
}


//sobrecarga de operador *
rational_t
operator*(const rational_t& a, const rational_t& b)
{
  // rellenar código
}


//sobrecarga de operador /
rational_t
operator/(const rational_t& a, const rational_t& b)
{
  // rellenar código
}



// E/S
//metodo que imprime el numero racional y el resutado por pantalla
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}


//metodo por que se introducen el numerador y el denominador de la calsa rational_t
void
rational_t::read(istream& is)
{
  is >> num_ >> den_;
  assert(den_ != 0);
}


//sobrecarga del operador << para la imprecion de los resultados
ostream&
operator<<(ostream& os, const rational_t& r)
{
  r.write(os);
  return os;
}

//sobracarfa del operador >> para la introduccion de datos
istream&
operator>>(istream& is, rational_t& r)
{
  r.read(is);
  return is;
}