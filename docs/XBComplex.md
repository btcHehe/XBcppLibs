# XBComplex.h

## Description
Library contains template class xb::Complex implementing complex numbers and operations on them. The example of usage:
```cpp
xb::Complex<double> x = {1.5, 4.83};
xb::Complex<double> y = {2.1, -9.41};
std::cout << x.Re() << "+" << x.Im() << "j" << " " << x.abs() << " " << x.phase() << std::endl;
std::cout << x.Re() << " " << x.Im() << "j" << " " << y.abs() << " " << y.phase() << std::endl;

xb::Complex<double> z = x*y;
xb::Complex<double> g = x-y;

std::cout << z.Re() << "+" << z.Im() << "j" << " " << z.abs() << " " << z.phase() << std::endl;
std::cout << g.Re() << " " << g.Im() << "j" << " " << g.abs() << " " << g.phase() << std::endl;
```

## Constructors
- Complex(T re=0, T im=0);
- Complex(std::initializer_list<T> vals);

## Methods

Method name | Arguments         | Return type    |   Description
------------|-------------------|----------------|----------------------
Re          |       void        | &T             | Returns reference to real part
Im          |       void        | &T             | Returns reference to imaginary part
abs         |       void        | T              | Returns magnitude of complex number
magnitude   |       void        | T              | Returns magnitude of complex number
arg         |       void        | T              | Returns argument of complex number 
angle       |       void        | T              | Returns argument of complex number
conj        |       void        | Complex<T>     | Returns complex number conjugate
inv         |       void        | Complex<T>     | Returns complex number inverse
operator*   |   Complex<T> b    | Complex<T>     | Returns the result of complex multiplication
operator/   |   Complex<T> b    | Complex<T>     | Returns the result of complex division
operator+   |   Complex<T> b    | Complex<T>     | Returns the result of complex addition
operator-   |   Complex<T> b    | Complex<T>     | Returns the result of complex subtraction
operator=   |   Complex<T> b    | Complex<T>     | Assigns complex number
rt          |       int n       | Complex<T>     | Returns nth (n is integer) root of complex number
pow         |       int n       | Complex<T>     | Returns nth (n is integer) power of complex number

