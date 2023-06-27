#pragma once

#ifndef _INITIALIZER_LIST_
#include <initializer_list>
#endif

#ifndef _INC_MATH
#include <math.h>
#endif

#ifndef _EXCEPTION_
#include <exception>
#endif

#ifndef XBCOMPLEX_H
#define XBCOMPLEX_H

namespace xb {

    template <typename T>

    class Complex {
        private:
            T real;
            T imag;
        public:
			Complex(T re=0, T im=0) {
                real = re;
                imag = im;
			}

			Complex(std::initializer_list<T> init_list) {
				if (init_list.size() == 2) {
                    real = init_list[0];
                    imag = init_list[1];
                } else {
                    throw std::
                }
			}

            T& Re();
            T& Im();
            T abs();
            T magnitude();
            T arg();
            T angle();
            Complex<T> conj();
            Complex<T> inv();
            Complex<T> operator*(const Complex<T> b);
            Complex<T> operator/(const Complex<T> b);
            Complex<T> operator+(const Complex<T> b);
            Complex<T> operator-(const Complex<T> b);
            Complex<T> operator=(const Complex<T> b);
            Complex<T> operator*(const T b);
            Complex<T> operator/(const T b);
            Complex<T> operator+(const T b);
            Complex<T> operator-(const T b);
            Complex<T> operator=(const T b);
            Complex<T> rt(int n);
            Complex<T> pow(int n);

    };


    template <typename T>
    T& Complex<T>::Re() {
        return real;
    }

    template <typename T>
    T& Complex<T>::Im() {
        return imag;
    }

    template <typename T>
    T Complex<T>::abs() {
        return sqrt(real*real + imag*imag);
    }

    template <typename T>
    T Complex<T>::magnitude() {
        return this->abs();
    }
    
    template <typename T>
    T Complex<T>::arg() {
        return acos(real/this->abs());
    }
    
    template <typename T>
    T Complex<T>::angle() {
        return this->arg();
    }

    template <typename T>
    Complex<T> Complex<T>::conj() {
        return Complex<T>(real, -imag);
    }

    template <typename T>
    Complex<T> Complex<T>::inv() {
        T r = real/(real*real + imag*imag);
        T i = -imag/(real*real + imag*imag);
        return Complex<T>(r, i);
    }

    template <typename T>
    Complex<T> Complex<T>::operator*(const Complex<T> b) {
        return Complex<T>(
            real*b.Re() - imag*b.Im(),
            real*b.Im() + b.real()*imag
            );
    }

    template <typename T>
    Complex<T> Complex<T>::operator/(const Complex<T> b) {
        return Complex<T>(
            (real*b.Re() + imag*b.Im())/(b.Re()*b.Re() + b.Im()*b.Im()),
            (imag*b.Re() - real*b.Im())/(b.Re()*b.Re() + b.Im()*b.Im())
            );
    }

    template <typename T>
    Complex<T> Complex<T>::operator+(const Complex<T> b) {
        return Complex<T>(real+b.Re(), imag+b.Im());
    }

    template <typename T>
    Complex<T> Complex<T>::operator-(const Complex<T> b) {
        return Complex<T>(real-b.Re(), imag-b.Im());
    }

    template <typename T>
    Complex<T> Complex<T>::operator=(const Complex<T> b) {
        real = b.Re();
        imag = b.Im();
    }

    template <typename T>
    Complex<T> Complex<T>::operator*(const T b) {
        return Complex<T>(real*b, imag*b);
    }

    template <typename T>
    Complex<T> Complex<T>::operator/(const T b) {
        return Complex<T>(real/b, imag/b);
    }

    template <typename T>
    Complex<T> Complex<T>::operator+(const T b) {
        return Complex<T>::(real+b, imag);
    }

    template <typename T>
    Complex<T> Complex<T>::operator-(const T b) {
        return Complex<T>(real-b, imag);
    }

    template <typename T>
    Complex<T> Complex<T>::operator=(const T b) {
        return Complex<T>(b, 0);
    }

    template <typename T>
    Complex<T> Complex<T>::rt(int n) {
        return Complex<T>(
            pow(this->abs(), 1/n)*cos(this->arg()/n),
            pow(this->abs(), 1/n)*sin(this->arg()/n)
            );
    }

    template <typename T>
    Complex<T> Complex<T>::pow(int n) {
        return Complex<T>(
            pow(this->abs(), n)*cos(n*this->arg()),
            pow(this->abs(), n)*sin(n*this->arg())
        );
    }
}

#endif