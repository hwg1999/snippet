#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>

class Calculator
{
   public:
    int Func(int a)
    {
        return a;
    }

    int Func(int a, int b)
    {
        return a + b;
    }

    int Func(int a, int b, int c)
    {
        return a + b - c;
    }
};

// 重载声明
int (Calculator::*Func1)(int) = &Calculator::Func;
int (Calculator::*Func2)(int, int) = &Calculator::Func;
int (Calculator::*Func3)(int, int, int) = &Calculator::Func;

BOOST_PYTHON_MODULE(overload)
{
    boost::python::class_<Calculator>("Calculator", boost::python::init<>())
        .def("Func", Func1)
        .def("Func", Func2)
        .def("Func", Func3);
}

/*

>>> import overload
>>> calc = overload.Calculator()
>>> calc.Func(3)
3
>>> calc.Func(3, 4)
7
>>> calc.Func(3, 4, 10, 15)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
Boost.Python.ArgumentError: Python argument types in
    Calculator.Func(Calculator, int, int, int, int)
did not match C++ signature:
    Func(Calculator {lvalue}, int, int, int)
    Func(Calculator {lvalue}, int, int)
    Func(Calculator {lvalue}, int)
>>> calc.Func(3, 4, 10)
-3

*/