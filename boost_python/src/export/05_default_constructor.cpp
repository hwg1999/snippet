#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

class Message
{
   public:
    void Set(std::string msg)
    {
        m_msg = msg;
    }
    std::string Get()
    {
        return m_msg;
    }

   private:
    std::string m_msg;
};

BOOST_PYTHON_MODULE(default_constructor)
{
    // class of default constructor
    boost::python::class_<Message>("Message")
        .def("Set", &Message::Set)
        .def("Get", &Message::Get);
}

/*

>>> import default_constructor as dc
>>> msg = dc.Message()
>>> msg.Get()
''
>>> msg.Set('123')
>>> msg.Get()
'123'

*/