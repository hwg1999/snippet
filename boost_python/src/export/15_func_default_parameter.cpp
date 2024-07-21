#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>

double FuncofDefaultParas(int a, double b = 2.0, double c = 3.0)
{
    return a + b + c;
}
BOOST_PYTHON_FUNCTION_OVERLOADS(FuncofDefaultParas_overload, FuncofDefaultParas,
                                1, 3);

BOOST_PYTHON_MODULE(func_default_parameter)
{
    boost::python::def("FuncofDefaultParas", FuncofDefaultParas,
                       FuncofDefaultParas_overload());
}

/*

>>> import func_default_parameter as fdp
>>> Func = fdp.FuncofDefaultParas
>>> Func
<Boost.Python.function object at 0x560a634b9b80>
>>> Func(1)
6.0
>>> Func(1, 5)
9.0
>>> Func(1, 10)
14.0
>>> Func(1, 5, 10)
16.0
>>> Func(2, 5, 10, 3)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
Boost.Python.ArgumentError: Python argument types in
    func_default_parameter.FuncofDefaultParas(int, int, int, int)
did not match C++ signature:
    FuncofDefaultParas(int)
    FuncofDefaultParas(int, double)
    FuncofDefaultParas(int, double, double)

*/