#include <iostream>
#include <map>
#include <set>

using namespace std;

template <typename K, typename V>
class map_template
{
public:
    map_template() {}
    virtual ~map_template() {}

    virtual void Insert(const K &key, const V &value)
    {
        this->data_[key] = value;
    }

protected:
    map<K, V> data_;
};


template <typename K, typename V>
class map_set_template : public map_template<K, set<V> >
{
public:
    map_set_template() {}
    ~map_set_template() {}

    void Insert(const K &key, const V &value)
    {
        this->data_[key].insert(value);
    }
};


int main()
{
    map_set_template<int, int> data;
    data.Insert(1,2);
    return 0;
}
