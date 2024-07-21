#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>

class C
{
   public:
    int value;
};
C* getC()
{
    return new C();
}

BOOST_PYTHON_MODULE(func_ret_new_obj)
{
    boost::python::class_<C>("C", boost::python::init<>())
        .def_readwrite("value", &C::value);
    boost::python::def(
        "getC", getC,
        boost::python::return_value_policy<boost::python::manage_new_object>());
}

/*

>>> import func_ret_new_obj as frno
>>> cObj = frno.getC()
>>> cObj.value = 10
>>> cObj.value
10

*/