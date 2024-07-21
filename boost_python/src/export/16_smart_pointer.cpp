#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>

class Data
{
   public:
    void Set(int data)
    {
        m_data = data;
    }
    int Get()
    {
        return m_data;
    }

   private:
    int m_data;
};

// smart pointer defined
using DataPtr = std::shared_ptr<Data>;

// smart pointer object
DataPtr pData(new Data);

BOOST_PYTHON_MODULE(smart_pointer)
{
    boost::python::class_<Data>("Data", boost::python::init<>())
        .def("Set", &Data::Set)
        .def("Get", &Data::Get);
    boost::python::register_ptr_to_python<DataPtr>();
    boost::python::scope().attr("pData") = pData;
}

/*

>>> import smart_pointer
>>> smart_pointer.pData.Get()
-1124999402
>>> smart_pointer.pData.Set(12345)
>>> smart_pointer.pData.Get()
12345

*/