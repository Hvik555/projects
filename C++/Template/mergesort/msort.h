#ifndef MSORT_H_INCLUDED
#define MSORT_H_INCLUDED

#include <algorithm>


template<typename T, typename Comp = std::less<T> >
class mergesort_util
{

private:
    T* cont;
    int _size;
    bool b;
    Comp cmp;



public:
    mergesort_util(T* cont, int _size, bool b = true): cont(cont), _size(_size), b(b)
    {

    }

    void split(int a, int b)
    {
        if(mergesort_util::b == false)
        {
            for(int i=a;i<b;i += 2)
            {
                if(cont[i] > cont[i+1])
                {
                    std::swap(cont[i],cont[i+1]);
                }
            }
        }
        else
        {
            sort();
        }

    }

    void set_merge_on()
    {
        b = true;
    }

    void sort()
    {
        std::sort(cont,cont + _size,cmp);
    }

};


template<typename T, typename Comp = std::less<T> >
void mergesort(T* cont, int _size, Comp compare)
{
    std::sort(cont,cont + _size, compare);
}


template<typename T>
void mergesort(T* cont, int _size)
{
    std::sort(cont,cont + _size);
}


template<typename T,typename Comp = std::less<T> >
void mergesort(std::vector<T>& cont, Comp compare)
{
    std::sort(cont.begin(),cont.end(),compare);
}


template<typename T>
void mergesort(std::vector<T>& cont)
{
    std::sort(cont.begin(),cont.end());
}

#endif // MSORT_H_INCLUDED
