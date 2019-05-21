#ifndef VEKTORIUS_VEKTORIUS_H
#define VEKTORIUS_VEKTORIUS_H

#include<iterator>
#include<memory>
#include<iostream>
#include<exception> //Exceptions provide a way to react to exceptional circumstances (like runtime errors) in programs by transferring control to special functions called handlers.

using std::cout;
using std::endl;
using std::size_t; //std::size_t is the unsigned integer type of the result of the sizeof operator as well as the sizeof... operator and the alignof operator

template <class T> class vector
{
public:
    //pavadinimai
    typedef T* iterator;
    typedef const iterator const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    //------------------------------------------
    vector() { create(); }
    explicit vector(size_type n, const T& value = T{}) { create(n, value); }
    vector(const vector& a) { create(a.begin(), a.end()); }

    //Operatoriai
    //------------------------------------------
    vector& operator=(const vector& a)
    {
        if (&a == this)  return *this;
        uncreate();
        create(a.begin(), a.end());
        return *this;
    }
    //--------------------------------------
    ~vector() { uncreate(); } //destruktorius
    //-------------------------------------
    T& operator[](size_type i) {
        if ( i > size() || i < 0) throw std::out_of_range("pasiektas [] operatoriaus limitas");
        return data[i];
    }
    //------------------------------------
    const T& operator[](size_type i) const { // toks pats kaip [] tik konstas
        if ( i > size() || i < 0 ) throw std::out_of_range("pasiektas [] operatoriaus limitas");
        return data[i];
    }
    //----------------------------------------
    size_type size() const { return avail - data; } //kaip ir skaidrėse
    //----------------------------------------
    bool empty() const //nenaudojama kolkas programoje
    {
        if (data == nullptr)
            return true;
        return false;
    }
    //----------------------------------------
    size_type capacity() const { return limit - data; } //kaip ir skaidrėse
    //----------------------------------------

    //Iteratoriai
    //---------------------------------------
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    //---------------------------------------
    iterator end() { return avail; }
    const_iterator end() const { return avail; }
    //--------------------------------------
    //Returns a reverse iterator to the first element of the reversed container.
    // It corresponds to the last element of the non-reversed container.
    // If the container is empty, the returned iterator is equal to rend().
    iterator rbegin()
    {
        iterator it = limit;
        return --it;
    }
    const_iterator rbegin() const
    {
        iterator it = limit;
        return --it;
    }
    iterator rend()
    {
        iterator it = data;
        return ++it;
    }
    const_iterator rend() const
    {
        iterator it = data;
        return ++it;
    }
    //----------------------
    //Elementų pasiekiamumas
    T& front()
    {
        return *data;
    }
    const T& front() const
    {
        return *data;
    }
    T& back()
    {
        iterator it = avail;
        return *(--it);
    }
    const T& back() const
    {
        iterator it = avail;
        return *(--it);
    }
    //--------------------------

    T& at(size_type pos)
    {
        if (size() <= pos || pos < 0) throw std::out_of_range("Ivyko klaida su at - out of range");
        return data[pos];
    }
    const T& at(size_type pos) const
    {
        if (size() < pos || pos < 0) throw std::out_of_range("Ivyko klaida su at - out of range");
        return data[pos];
    }
    //-----------------------
    void reserve(size_type new_cap)
    {
        if (new_cap > capacity())
        {
            iterator new_data = alloc.allocate(new_cap);
            iterator new_avail = std::uninitialized_copy(data, avail, new_data);
            uncreate();
            data = new_data;
            avail = new_avail;
            limit = data + new_cap;
        }
    }
    //Modifikatoriai
    void push_back(const T& val)
    {
        if (avail == limit)
        {
            grow();
        }
        unchecked_append(val);
    }
    //---------------------
    void clear()
    {
        iterator new_data = alloc.allocate(capacity());
        size_type cap = capacity();
        uncreate();
        limit = new_data + cap;
        data = avail = new_data;
    }
    //--------------------
    void pop_back()
    {
        iterator it = avail;
        alloc.destroy(--it);
        avail = it;
    }
    //---------------------
    void resize(size_type count, value_type value = T())
    {
        if (count < size())
        {
            size_type new_size = count;
            iterator new_data = alloc.allocate(new_size);
            iterator new_avail = std::uninitialized_copy(data, data + count, new_data);
            iterator new_limit = new_data + capacity();

            uncreate();

            data = new_data;
            avail = new_avail;
            limit =  new_limit;
        }
        else if (count > size())
        {
            size_type new_size = count;
            iterator new_data = alloc.allocate(new_size);
            iterator it = std::uninitialized_copy(data, avail, new_data);
            std::uninitialized_fill(it, new_data + new_size - 1, value);
            iterator new_avail = new_data + new_size;
            iterator new_limit;
            if (capacity() < new_avail - new_data)
            {
                new_limit = new_avail;
            }
            else
            {
                new_limit = new_data + capacity();
            }
            uncreate();

            data = new_data;
            avail = new_avail;
            limit = new_limit;
        }
    }
private:
    iterator data;
    iterator avail;
    iterator limit;

    std::allocator<T> alloc;
//--------------------------------
    void create()
    {
        data = avail = limit = nullptr;
    }
    void create(size_type n, const T& val)
    {
        data = alloc.allocate(n);
        limit = avail = data + n;
        std::uninitialized_fill(data, limit, val);
    }
    void create(const_iterator i, const_iterator j)
    {
        data = alloc.allocate(j - i);
        limit = avail = std::uninitialized_copy(i, j, data);
    }
    //-----------------------------------
    void uncreate()
    {
        if (data)
        {
            iterator it = avail;
            while (it != data)
                alloc.destroy(--it);
            alloc.deallocate(data, limit - data);
        }
        data = limit = avail = nullptr;
    }
    //-----------------------------------------------
    void grow()
    {
        size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

        iterator new_data = alloc.allocate(new_size);
        iterator new_avail = std::uninitialized_copy(data, avail, new_data);

        uncreate();

        data = new_data;
        avail = new_avail;
        limit = data + new_size;
    }
    //----------------------------------------------
    void unchecked_append(const T& val)
    {
        alloc.construct(avail++, val);
    }
};

#endif //VEKTORIUS_VEKTORIUS_H