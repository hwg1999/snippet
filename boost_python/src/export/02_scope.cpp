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

// BOOST_PYTHON_MODULE(scope)
// {
//     boost::python::scope().attr("yes") = 1;
//     boost::python::scope().attr("no") = 0;
//     boost::python::class_<Message>("Message")
//         .def("Set", &Message::Set)
//         .def("Get", &Message::Get);
// }

/**

>>> import scope
>>> scope.yes
1
>>> scope.no
0

*/

// 3.如果使用boost::python::scope对象，则改变了当前的作用域，yes和no成了message类的属性
// BOOST_PYTHON_MODULE(scope)
// {
//     // Change the current scope
//     boost::python::scope newScope = boost::python::class_<Message>("Message")
//                                         .def("Set", &Message::Set)
//                                         .def("Get", &Message::Get);
//     // const Defined in the current scope（Message）
//     boost::python::scope().attr("yes") = 1;
//     boost::python::scope().attr("no") = 0;
// }

/**

>>> import scope
>>> scope.Message.yes
1
>>> scope.Message.no
0

*/

// 4.使用boost::python::scope定义了新的域对象，改变了当前的作用域，这个对象出了作用域，则会恢复为之前的域对象
BOOST_PYTHON_MODULE(scope)
{
    // const
    {
        boost::python::scope newScope =
            boost::python::class_<Message>("Message")
                .def("Set", &Message::Set)
                .def("Get", &Message::Get);
        boost::python::scope().attr("yes") = 1;
        boost::python::scope().attr("no") = 0;
    }
    boost::python::scope().attr("exist") = 1;
    boost::python::scope().attr("none") = 0;
}

/**

>>> import scope
>>> scope.Message.yes
1
>>> scope.Message.no
0
>>> scope.exist
1
>>> scope.none
0

*/