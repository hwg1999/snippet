#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

class MessagePro
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

BOOST_PYTHON_MODULE(property)
{
    // add properties to class
    boost::python::class_<MessagePro>("MessagePro")
        .add_property("info", &MessagePro::Get, &MessagePro::Set);
}

/*

>>> import property
>>> msg = property.MessagePro()
>>> msg.set()
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: 'MessagePro' object has no attribute 'set'
>>> msg.get()
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: 'MessagePro' object has no attribute 'get'
>>> msg.info
''
>>> msg.info = 'hello'
>>> msg.info
'hello'
>>> 

*/