#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

class User
{
   public:
    User(std::string name) : m_name(name), m_number(-1)
    {
    }
    std::string m_name;
    int m_number;
};

BOOST_PYTHON_MODULE(member)
{
    boost::python::class_<User>("User", boost::python::init<std::string>())
        .def_readonly("name", &User::m_name)
        .def_readwrite("number", &User::m_number);
}

/*

>>> import member
>>> user = member.User('Jason')
>>> user.name = 'Micky'
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: can't set attribute
>>> user.number = 12345
>>> user.number
12345

*/