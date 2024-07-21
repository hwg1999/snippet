#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>

class A
{
   public:
    int value;
};

class B
{
   public:
    A a;
};

A& getA(B& b)
{
    return b.a;
}

BOOST_PYTHON_MODULE(func_ret_ref)
{
    boost::python::class_<A>("A", boost::python::init<>())
        .def_readwrite("value", &A::value);
    boost::python::class_<B>("B", boost::python::init<>())
        .def_readwrite("a", &B::a);
    boost::python::def("getA", getA,
                       boost::python::return_value_policy<
                           boost::python::reference_existing_object>());
}

/*

>>> import func_ret_ref as frr
>>> bObj = frr.B()
>>> aObj = frr.getA(bObj)
>>> aObj.value
0
>>> bObj.a.value = 10
>>> aObj.value
10
>>> aObj.value = 20
>>> bObj.a.value
20

*/