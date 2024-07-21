#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>

class VFObj
{
   public:
    virtual ~VFObj(){};
    virtual int Func()
    {
        return 0;
    }
};

class VFObjWrapper : public VFObj, public boost::python::wrapper<VFObj>
{
   public:
    int Func()
    {
        if (boost::python::override Func = this->get_override("Func"))
        {
            return Func();
        }
        return VFObj::Func();
    }
    int default_Func()
    {
        return this->VFObj::Func();
    }
};

BOOST_PYTHON_MODULE(virtual_function)
{
    boost::python::class_<VFObjWrapper, boost::noncopyable>("VFObj").def(
        "Func", &VFObj::Func, &VFObjWrapper::Func);
}

/*

>>> import virtual_function as vf
>>> objVF = vf.VFObj()
>>> objVF.Func()
0
>>> class newObj(vf.VFObj):
...     def Func(self):
...             return 88
... 
>>> obj = newObj()
>>> obj.Func()
88
>>> class derivedObj(vf.VFObj):
...     def newFunc():
...             pass
... 
>>> dObj = derivedObj()
>>> dObj.Func()
0

*/