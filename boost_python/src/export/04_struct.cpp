#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>
#include <iostream>

struct StructionData
{
    void hello()
    {
        std::cout << "hello, this is boost::python sample!" << std::endl;
    }
    void printmsg()
    {
        std::cout << "print message done!" << std::endl;
    }
};

BOOST_PYTHON_MODULE(struct)
{
    boost::python::class_<StructionData>("StructionData")
        .def("hello", &StructionData::hello)
        .def("printmsg", &StructionData::printmsg);
}

/**

>>> import example
>>> ptr = example.StructionData()
>>> ptr.hello()
hello, this is boost::python sample!
>>> ptr.printmsg()
print message done!

*/