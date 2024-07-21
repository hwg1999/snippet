#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>

class CalculatorPro
{
   public:
    CalculatorPro()
    {
        m_value = 0.0;
    }

    CalculatorPro(int a, double b = 2.0, int c = 10)
    {
        m_value = a + b + c;
    }
    double Func(int a, double b = 3.0, int c = 5)
    {
        return a + b - c;
    }
    double Value()
    {
        return m_value;
    }

   private:
    double m_value;
};

// 1为最少参数，3为最多参数
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(CalculatorPro_overloads, Func, 1, 3);

BOOST_PYTHON_MODULE(default_parameter_of_class)
{
    boost::python::class_<CalculatorPro>("CalculatorPro",
                                         boost::python::init<>())
        .def(boost::python::init<int, boost::python::optional<double, int>>())
        .def("Func", &CalculatorPro::Func, CalculatorPro_overloads())
        .def("Value", &CalculatorPro::Value);
}

/*

>>> import default_parameter_of_class as dpoc
>>> calc = dpoc.CalculatorPro()
>>> calc.Value()
0.0
>>> calc1 = dpoc.CalculatorPro(10)
>>> calc1.Value()
22.0
>>> calc2 = dpoc.CalculatorPro(10, 30)
>>> calc2.Value()
50.0
>>> calc3 = dpoc.CalculatorPro(10, 30, 50)
>>> calc3.Value()
90.0
>>> calc4 = dpoc.CalculatorPro(10, 30, 50, 60)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
Boost.Python.ArgumentError: Python argument types in
    CalculatorPro.__init__(CalculatorPro, int, int, int, int)
did not match C++ signature:
    __init__(_object*, int)
    __init__(_object*, int, double)
    __init__(_object*, int, double, int)
    __init__(_object*)
>>> calc5 = dpoc.CalculatorPro()
>>> calc5.Func(10)
8.0
>>> calc5.Func(10, 2.0)
7.0
>>> calc5.Func(10, 2.0, 30)
-18.0
>>> calc5.Func(10, 2.0, 40)
-28.0
>>> calc5.Func(10, 2.0, 30, 40)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
Boost.Python.ArgumentError: Python argument types in
    CalculatorPro.Func(CalculatorPro, int, float, int, int)
did not match C++ signature:
    Func(CalculatorPro {lvalue}, int)
    Func(CalculatorPro {lvalue}, int, double)
    Func(CalculatorPro {lvalue}, int, double, int)

*/