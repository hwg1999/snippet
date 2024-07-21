#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

const char *greet()
{
    return "Hello World!";
}

BOOST_PYTHON_MODULE(function)
{
    boost::python::def("greet", greet);
}

/**

>>> import function
>>> function.greet()
'Hello World!'

*/
