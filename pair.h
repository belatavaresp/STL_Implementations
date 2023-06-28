#ifndef PAIR_H
#define PAIR_H

template <typename T1, typename T2>
class Pair{
    public:
    T1 first;
    T2 second;

    Pair(const T1& f, const T2& s) : first(f), second(s) {}
};

#endif