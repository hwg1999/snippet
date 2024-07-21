#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

class Sum
{
   public:
    Sum(std::string data) : m_data(data)
    {
    }
    Sum(double a, double b) : m_a(a), m_b(b)
    {
    }

    void Set(std::string data)
    {
        m_data = data;
    }

    std::string Get()
    {
        return m_data;
    }
    double Result()
    {
        return m_a + m_b;
    }

   private:
    std::string m_data;
    double m_a;
    double m_b;
};

BOOST_PYTHON_MODULE(custom_constructor)
{
    // class of custom constructor
    boost::python::class_<Sum>("Sum", boost::python::init<std::string>())
        .def(boost::python::init<double, double>())
        .def("Set", &Sum::Set)
        .def("Get", &Sum::Get)
        .def("Result", &Sum::Result);
}

/*

>>> import custom_constructor as cc
>>> s1 = cc.Sum('Total')
>>> s1.Get()
'Total'
>>> s2 = cc.Sum(1, 2)
>>> s2.Result()
3.0

*/