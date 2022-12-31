#include <iostream>
#include <limits.h>
class DoubleA {
private:
    long double m_a;
public:
    DoubleA() { m_a = 0; }
    DoubleA(double a) { m_a = a; }
    void setNum() {
        std::cout << "Enter the number a";
        std::cin >> m_a;
    }
    void toNull() { m_a = 0; }
    void showA() const {
        std::cout << "a is " << m_a;
    }
    double getA() { return m_a; }
    void sum(DoubleA b, DoubleA c) {
        m_a = b.getA() + c.getA();
    }
    friend DoubleA operator+(const DoubleA& a, const DoubleA& b);
    friend DoubleA operator-(const DoubleA& a, const DoubleA& b);
    friend DoubleA operator/(const DoubleA& a, const DoubleA& b);
    friend DoubleA operator*(const DoubleA& a, const DoubleA& b);
    friend DoubleA operator<(const DoubleA& a, const DoubleA& b);
    friend DoubleA operator>(const DoubleA& a, const DoubleA& b);
    friend DoubleA operator==(const DoubleA& a, const DoubleA& b);
};
DoubleA operator+(const DoubleA& a, const DoubleA& b)
{
    if ((b.m_a > 0) && (a.m_a > INT_MAX - b.m_a))
    {
        std::cout << "error";        exit(0);
    }
    if ((b.m_a < 0) && (a.m_a < INT_MIN - b.m_a))
    {
        std::cout << "error";        exit(0);
    };
    return(a.m_a + b.m_a);
}
DoubleA operator-(const DoubleA& a, const DoubleA& b)
{
    if ((b.m_a < 0) && (a.m_a > INT_MAX + b.m_a))
    {
        std::cout << "error";        exit(0);
    }
    if ((b.m_a > 0) && (a.m_a < INT_MIN + b.m_a))
    {
        std::cout << "error";        exit(0);
    }
    return(a.m_a - b.m_a);
}
DoubleA operator/(const DoubleA& a, const DoubleA& b)
{
    return(a.m_a / b.m_a);
}
DoubleA operator*(const DoubleA& a, const DoubleA& b)
{
   
    return(a.m_a * b.m_a);
}
DoubleA operator<(const DoubleA& a, const DoubleA& b) {
    return a.m_a < b.m_a;
}
DoubleA operator>(const DoubleA& a, const DoubleA& b) {
    return a.m_a > b.m_a;
}
DoubleA operator==(const DoubleA& a, const DoubleA& b) {
    return a.m_a == b.m_a;
}
int main(int argc, char* argv[]) {
    DoubleA c(5.1), b(8.2), n3, n4(21.01);
    std::cout << "b is" << b.getA() << std::endl;
    std::cout << "c is" << c.getA() << std::endl;
    n3 = c + b;
    std::cout << "c+b " << n3.getA() << std::endl;
    n3 = c - b;
    std::cout << "c-b = " << n3.getA() << std::endl;
    n3 = c / b;
    std::cout << "c/b = " << n3.getA() << std::endl;
    n3 = c * b;
    std::cout << "b*c = " << n3.getA() << std::endl;
    n3 = n4 * b;

}
