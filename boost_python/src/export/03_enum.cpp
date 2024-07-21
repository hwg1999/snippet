#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

enum MessageType
{
    MT_START = 1,
    MT_PROCESS,
    MT_DONE,
    MT_EXCEPTION
};

BOOST_PYTHON_MODULE(enum)
{
    boost::python::enum_<MessageType>("MessageType")
        .value("MT_START", MT_START)
        .value("MT_PROCESS", MT_PROCESS)
        .value("MT_DONE", MT_DONE)
        .value("MT_EXCEPTION", MT_EXCEPTION);
}
/*

>>> import enum
>>> enum.MessageType.MT_START
enum.MessageType.MT_START
>>> int(enum.MessageType.MT_START)
1
>>>

*/