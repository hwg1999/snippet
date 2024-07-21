#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>
#include <iostream>

class Base
{
   public:
    virtual ~Base(){};
    virtual std::string Name()
    {
        return "Base";
    }
};

class Derived : public Base
{
   public:
    std::string Name()
    {
        return "Derived";
    }
};

void BaseName(Base *base)
{
    std::cout << base->Name().c_str() << std::endl;
}

void DerivedName(Derived *derived)
{
    std::cout << derived->Name().c_str() << std::endl;
}

Base *factory()
{
    return new Derived();
}

BOOST_PYTHON_MODULE(inheritance)
{
    // inherited
    boost::python::class_<Base>("Base", boost::python::init<>())
        .def("Name", &Base::Name);

    boost::python::class_<Derived, boost::python::bases<Base>>("Derived").def(
        "Name", &Derived::Name);

    boost::python::def("BaseName", BaseName);
    boost::python::def("DerivedName", DerivedName);

    // 因为factory是生成一个新的Direved对象
    // manage_new_object告知Python生成一个指针指向一个新生成的Python对象，
    boost::python::def(
        "factory", factory,
        boost::python::return_value_policy<boost::python::manage_new_object>());
}

/*

>>> import inheritance
>>> obj = inheritance.factory()
>>> obj.Name()
'Derived'
>>> inheritance.BaseName(obj)
Derived
>>> inheritance.DerivedName(obj)
Derived
>>> objBase = inheritance.Base()
>>> objBase.Name()
'Base'
>>> inheritance.BaseName(objBase)
Base
>>> inheritance.DerivedName(objBase)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
Boost.Python.ArgumentError: Python argument types in
    inheritance.DerivedName(Base)
did not match C++ signature:
    DerivedName(Derived*)

*/