#ifndef SINGLELIST_HPP
#define SINGLELIST_HPP

#include <initializer_list>
#include <iostream>

class SingleList {
    public:
        SingleList();
        SingleList(int val, int count);
        SingleList(std::initializer_list<int> list);
        SingleList(const SingleList& src);
        SingleList(SingleList&& src) noexcept;
        SingleList& operator=(const SingleList& rhs);
        SingleList& operator=(SingleList&& rhs) noexcept;
        ~SingleList();

        friend std::ostream& operator<<(std::ostream& ostr, const SingleList& src);
        friend std::istream& operator>>(std::istream& istr, SingleList& src);
        friend SingleList operator+(const SingleList& lhs, const SingleList& rhs); // will return the smaller size list concatenated
        SingleList& operator+=(const SingleList& rhs);
        bool operator==(const SingleList& rhs) const;
        bool operator!=(const SingleList& rhs) const;
        int& operator[](size_t index); // if index is negative it leads to undefined behavior(same for const version)
        const int& operator[](size_t index) const;
        bool operator!() const;
        SingleList& operator++();
        SingleList operator++(int);
        SingleList& operator--();
        SingleList operator--(int);

        void push_back(int val);
        void push_front(int val);
        void pop_front();
        void pop_back();
        int size() const;
        void clear();

    private:
        void copy(const SingleList& rhs);
        struct Node {
            int m_val;
            Node* m_next;
            Node(int val = 0, Node* next = nullptr) : m_val { val }, m_next { next } {}
        };
        Node* m_head;
};

#endif /* SINGLELIST_HPP */