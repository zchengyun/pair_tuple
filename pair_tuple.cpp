#include <iostream>
#include <cassert>
#include <tuple>
#include <functional>

std::tuple<int, double, std::string> get_tuple() {
	return std::make_tuple(1, 2.5, "Lisa");
}

int main()
{
    int a = 1;
    double b = 2.2;
    auto pa = std::make_pair(a, b);
    std::cout << "pa.first="<<pa.first<<",pa.second="<<pa.second<<"\n";

    auto pb = pa;//operator= 运算符重载
    std::cout<< "pb.first=" << pb.first << ",pb.second=" << pb.second << "\n";

    std::pair<int, std::string> pc = std::make_pair(123, "hello");
    std::pair<int, std::string> pd = std::make_pair(456, "world");
    pd.swap(pc);//交换函数
    std::cout << "pc.first=" << pc.first << ",pc.second=" << pc.second << "\n";
    std::cout << "pd.first=" << pd.first << ",pd.second=" << pd.second << "\n";

    auto pe = pc;
    assert(pc == pe);//operator== 运算符重载

    int pf1;
    double pg1;
    std::string ph1;
    std::tie(pf1, pg1, ph1)= get_tuple();// tie创建一个左值引用元组
    std::cout << "pf1=" << pf1 << ",pg1=" << pg1<< ",ph1=" << ph1<< "\n";

}
