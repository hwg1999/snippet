#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>

class D
{
   public:
    int value;
};

D& getStaticD()
{
    static D d;
    d.value = 10;
    return d;
}

BOOST_PYTHON_MODULE(func_ret_static)
{
    boost::python::class_<D>("D", boost::python::init<>())
        .def_readwrite("value", &D::value);

    boost::python::def("getD", getStaticD,
                       boost::python::return_value_policy<
                           boost::python::reference_existing_object>());
}

/*

>>> import func_ret_static as frs
>>> dObj = frs.getD()
>>> dObj.value
10
>>> dObj.value = 20
>>> dObj.value
20

*/