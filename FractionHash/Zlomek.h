#include <iostream>

using std::cout;
using std::endl;

inline int gcd(int a, int b)
{
	int t = 0;

	while (b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}

	return a;
}

class Zlomek { int a,b;
	template<int n> friend class HashZlomky;

  public: Zlomek(int aa,int bb) { a=aa,b=bb; }
          Zlomek operator + (Zlomek &z) {
            Zlomek v(a*z.b+b*z.a,b*z.b); 
            return v;
          }
          Zlomek operator * (Zlomek &z) {
            Zlomek v(a*z.a,b*z.b);
            return v;
          }
          void operator () () {
            cout << a << '/' << b << endl;
          }

		  Zlomek& Zkratit()
		  {
			  int i = gcd(a, b);
			  a /= i;
			  b /= i;
			  return *this;
		  }

		  bool operator>(Zlomek& z)
		  {
			  return a*z.b > z.a*b;
		  }

		  bool operator==(Zlomek& z)
		  {
			  Zkratit();
			  Zlomek zz = z.Zkratit();
			  return a == z.a && b == z.b;
		  }
};