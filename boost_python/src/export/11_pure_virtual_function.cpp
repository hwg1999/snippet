#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>

class PVFObj
{
   public:
    virtual ~PVFObj()
    {
    }
    virtual int Func() = 0;
};

class PVFObjWrapper : public PVFObj, public boost::python::wrapper<PVFObj>
{
   public:
    int Func()
    {
        return this->get_override("Func")();
    }
};

BOOST_PYTHON_MODULE(pure_virtual_function)
{
    // pure virtual function
    boost::python::class_<PVFObjWrapper, boost::noncopyable>("PVFObj").def(
        "Func", boost::python::pure_virtual(&PVFObj::Func));
}

/*

>>> import pure_virtual_function as pvf
>>> pvf.Func()
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: module 'pure_virtual_function' has no attribute 'Func'
>>> class derivedObj(pvf.PVFObj):
...     def Func(self):
...             return 88
... 
>>> dObj = derivedObj()
>>> dObj.Func()
88

*/