#include "SingleList.hpp"

SingleList::SingleList() : m_head { nullptr } {}

SingleList::SingleList(int val, int count = 1) : m_head { nullptr } {
    for (int i = 0; i < count; ++i) {
        push_front(val);
    }
}

SingleList::SingleList(std::initializer_list<int> list) : m_head { nullptr } {
    for (int i: list) {
        push_back(i);
    }
}

SingleList::SingleList(const SingleList& src) {
    copy(src);
}

SingleList::SingleList(SingleList&& src) noexcept : m_head { src.m_head } {
    src.m_head = nullptr;
}

SingleList& SingleList::operator=(const SingleList& rhs) {
    if (this != &rhs) {
        clear();
        copy(rhs);
    }
    return *this;
}

SingleList& SingleList::operator=(SingleList&& rhs) noexcept {
    if (this != &rhs) {
        clear();
        m_head = rhs.m_head;
        rhs.m_head = nullptr;
    }
    return *this;
}

SingleList::~SingleList() {
    clear();
}

std::ostream& operator<<(std::ostream& ostr, const SingleList& src) {
    SingleList::Node* tmp = src.m_head;
    while (tmp != nullptr) {
        ostr << tmp->m_val << ' ';
        tmp = tmp->m_next;
    }
    ostr << std::endl;
    return ostr;
}

std::istream& operator>>(std::istream& istr, SingleList& src) {
    int val;
    istr >> val;
    src.push_back(val);
    return istr;
}

SingleList operator+(SingleList lhs, SingleList rhs) {
    return lhs += std::move(rhs);
}

SingleList& SingleList::operator+=(SingleList&& rhs) {
    if (m_head == nullptr) {
        m_head = rhs.m_head;
    }
    else if (this != &rhs) {
        Node* tmp = m_head;
        while (tmp->m_next != nullptr) {
            tmp = tmp->m_next;
        }
        tmp->m_next = rhs.m_head;
    }
    rhs.m_head = nullptr;
    return *this;
}

bool SingleList::operator==(const SingleList& rhs) const {
    if (size() == rhs.size()) {
        Node* Ltmp = m_head;
        Node* Rtmp = rhs.m_head;
        while (Ltmp != nullptr) {
            if (Ltmp->m_val != Rtmp->m_val) {
                return false;
            }
            Ltmp = Ltmp->m_next;
            Rtmp = Rtmp->m_next;
        }
        return true;
    }
    return false;
}

bool SingleList::operator!=(const SingleList& rhs) const {
    return !(*this == rhs);
}

int& SingleList::operator[](size_t index) {
    return const_cast<int&>(static_cast<const SingleList&>(*this)[index]); // Scott Meyers(55) Item 3.
}

const int& SingleList::operator[](size_t index) const {
    boundsCheck(index);
    const Node* tmp = m_head;
    while (index-- != 0) {
        tmp = tmp->m_next;
    }
    return tmp->m_val;
}

bool SingleList::operator!() const {
    if (m_head == nullptr) {
        return true;
    }
    return false;
}

SingleList& SingleList::operator++() {
    push_back(0);
    return *this;
}

SingleList SingleList::operator++(int) {
    SingleList tmp = *this;
    ++(*this);
    return tmp;
}

SingleList& SingleList::operator--() {
    pop_back();
    return *this;
}

SingleList SingleList::operator--(int) {
    SingleList tmp = *this;
    --(*this);
    return tmp;
}

void SingleList::push_front(int val) {
    Node* tmp = new Node(val, m_head);
    m_head = tmp;
}

void SingleList::push_back(int val) {
    if (m_head == nullptr) {
        m_head = new Node(val);
    }
    else {
        Node* tmp = m_head;
        while (tmp->m_next != nullptr) {
            tmp = tmp->m_next;
        }
        tmp->m_next = new Node(val);
    }
}

void SingleList::pop_front() {
    Node* tmp = m_head;
    m_head = m_head->m_next;
    delete tmp;
}

void SingleList::pop_back() {
    if (m_head != nullptr) {
        Node* tmp = m_head;
        Node* tmpBack = tmp;
        while (tmp->m_next != nullptr) {
            tmpBack = tmp;
            tmp = tmp->m_next;
        }
        delete tmp;
        tmpBack->m_next = nullptr;
    }
};

int SingleList::size() const {
    int count = 0;
    SingleList::Node* tmp = m_head;
    while (tmp != nullptr) {
        tmp = tmp->m_next;
        ++count;
    }
    return count;
}

void SingleList::clear() {
    while (m_head != nullptr) {
        pop_front();
    }
}

void SingleList::boundsCheck(size_t index) const {
    if (index >= size() || index < 0) {
        std::cout << "Invalid Index; Exiting\n";
        std::exit(EXIT_FAILURE);
    }
}

void SingleList::copy(const SingleList& rhs) {
    Node* Rtmp = rhs.m_head;
    Node dummy;
    Node* Ltmp = &dummy;
    while (Rtmp != nullptr) {
        Ltmp->m_next = new Node(Rtmp->m_val);
        Ltmp = Ltmp->m_next;
        Rtmp = Rtmp->m_next;
    }
    m_head = dummy.m_next;
}