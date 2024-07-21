#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>

class Operand
{
   public:
    Operand() : m_num(0)
    {
    }
    Operand(int num) : m_num(num)
    {
    }

    int num()
    {
        return m_num;
    }
    Operand& operator+(const Operand& other)
    {
        m_num += other.m_num;
        return *this;
    }
    Operand& operator+(int num)
    {
        m_num += num;
        return *this;
    }
    Operand& operator-(const Operand& other)
    {
        m_num -= other.m_num;
        return *this;
    }
    Operand& operator-(int num)
    {
        m_num -= num;
        return *this;
    }
    Operand& operator+=(const Operand& other)
    {
        return operator+(other);
    }

    Operand& operator+=(int num)
    {
        return operator+(num);
    }
    Operand& operator-=(const Operand& other)
    {
        return operator-(other);
    }
    Operand& operator-=(int num)
    {
        return operator-(num);
    }
    bool operator<(const Operand& other)
    {
        return (m_num < other.m_num);
    }
    int abs()
    {
        m_num = std::abs(m_num);
        return m_num;
    }

   private:
    int m_num;
};

std::ostream& operator<<(std::ostream& out, Operand opr)
{
    out << opr.num();
    return out;
}

BOOST_PYTHON_MODULE(operators)
{
    boost::python::class_<Operand>("Operand", boost::python::init<>())
        .def(boost::python::init<int>())
        .def("num", &Operand::num)
        .def(boost::python::self + boost::python::self)
        .def(boost::python::self + int())
        .def(boost::python::self - boost::python::self)
        .def(boost::python::self - int())
        .def(boost::python::self += boost::python::self)
        .def(boost::python::self += int())
        .def(boost::python::self -= boost::python::self)
        .def(boost::python::self -= int())
        .def(boost::python::self < boost::python::self)
        .def("abs", &Operand::abs)
        .def(str(boost::python::self));
}

/*

>>> import operators
>>> opr1 = operators.Operand(10)
>>> opr1.num()
10
>>> opr1 + 50
<operators.Operand object at 0x7fdeeb7f65c0>
>>> opr1.num()
60
>>> opr2 = operators.Operand(30)
>>> opr2.num()
30
>>> opr1 - opr2
<operators.Operand object at 0x7fdeeb7f65c0>
>>> opr1.num()
30
>>> opr1 - 20
<operators.Operand object at 0x7fdeeb7f65c0>
>>> opr1.num()
10
>>> opr1 < opr2
True
>>> str(opr2)
'30'

*/