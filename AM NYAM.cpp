#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

class Hedgehog
{
public:
    Hedgehog() = default;
    Hedgehog(int val) :val_(val){}
    Hedgehog(double val):val_(val){}
    ~Hedgehog() = default;
    void SetVal(int val) { val_ = val; }
    void SetVal(double val) { val_ = ::ceil(val); }

    int GetVal()const { return val_; }

    Hedgehog& operator=(const Hedgehog& other) = default;
    bool operator<(const Hedgehog& other)const
    {
        return val_ < other.val_;
    }
    bool operator>(const Hedgehog& other)const
    {
        return val_ > other.val_;
    }


private:
    int val_;
};



int main()
{
    
    std::vector<Hedgehog> collection;
    collection.reserve(15);
    for (size_t i = 0; i < collection.capacity(); i++)
    {
        double tmp = 1 + ::rand() % 10;
        tmp += 1. / (1 + ::rand() % 10);
        collection.emplace_back(tmp);
    }

    for (size_t i = 0; i < collection.size(); i++)
    {
        std::cout << collection[i].GetVal() << " ";
    }
    std::cout << "\n";

    std::sort(collection.begin(), collection.end());

    for (size_t i = 0; i < collection.size(); i++)
    {
        std::cout << collection[i].GetVal() << " ";
    }
    std::cout << "\n";

    std::set<Hedgehog> sortedcollection;

    for (const auto& el : collection)
    {
        sortedcollection.insert(el);
    }
    
    for (const auto& el : sortedcollection)
    {
        std::cout << el.GetVal() << " ";
    }
    std::cout << "\n";

    return 0;
}

