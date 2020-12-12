#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__
#include "../header/base.hpp"
#include <stack>

class Base;

enum ChildIndicator { left, right, end };

class Iterator {
    protected:
        Base* self_ptr;

    public:
        Iterator(Base* ptr) { 
            this->self_ptr = ptr; 
        }

        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool is_done() = 0;
        virtual Base* current() = 0;
};

class BinaryIterator : public Iterator {
    protected:
        ChildIndicator c;

    public:
        BinaryIterator(Base* ptr);

        void first();
        void next();
        bool is_done();
        Base* current();
};

class NullIterator : public Iterator {
    public:
        NullIterator(Base* ptr) : Iterator(ptr) {}

        void first() {}
        void next() {}
        bool is_done() {
            return true;
        }
        Base* current() { 
            return nullptr; 
        }
};

class PreorderIterator : public Iterator {
    protected:
        std::stack<Iterator*> iterators;

    public:
        PreorderIterator(Base* ptr);

        void first();
        void next();
        bool is_done();
        Base* current();
};

#endif
