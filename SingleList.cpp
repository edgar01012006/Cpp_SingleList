#include "SingleList.hpp"

SingleList::SingleList() : m_head { nullptr } {}

SingleList::SingleList(int val, int count = 1) : m_head { new Node(val) } {
    Node* tmp = m_head;
    while (count-- != 1) {
        tmp->m_next = new Node(val);
        tmp = tmp->m_next;
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

SingleList operator+(const SingleList& lhs, const SingleList& rhs) {
    SingleList::Node* Ltmp = lhs.m_head;
    SingleList::Node* Rtmp = rhs.m_head;
    SingleList dummy;
    while (Ltmp != nullptr || Rtmp != nullptr) {
        dummy.push_back(Ltmp->m_val + Rtmp->m_val);
        Ltmp = Ltmp->m_next;
        Rtmp = Rtmp->m_next;
    }
    return dummy;
}

SingleList& SingleList::operator+=(const SingleList& rhs) {
    Node* Ltmp = m_head;
    Node* Rtmp = rhs.m_head;
    while (Ltmp != nullptr || Rtmp != nullptr) {
        Ltmp->m_val += Rtmp->m_val;
        Ltmp = Ltmp->m_next;
        Rtmp = Rtmp->m_next;
    }
    return *this;
}

bool SingleList::operator==(const SingleList& rhs) const {
    int Lsize = size();
    int Rsize = rhs.size();
    if (Lsize == Rsize) {
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
    int size = this->size();
    if (index >= size) {
        std::cout << "Invalid Index; Exiting\n";
        std::exit(EXIT_FAILURE);
    }
    Node* tmp = m_head;
    while (index-- != 0) {
        tmp = tmp->m_next;
    }
    return tmp->m_val;
}

const int& SingleList::operator[](size_t index) const {
    int size = this->size();
    if (index >= size) {
        std::cout << "Invalid Index; Exiting\n";
        std::exit(EXIT_FAILURE);
    }
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
    m_head = nullptr;
}

void SingleList::copy(const SingleList& src) {
    Node* tmp = src.m_head;
    Node dummy;
    Node* tmp2 = &dummy;
    while (tmp != nullptr) {
        tmp2->m_next = new Node(tmp->m_val);
        tmp2 = tmp2->m_next;
        tmp = tmp->m_next;
    }
    m_head = dummy.m_next;
}