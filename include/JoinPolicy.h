#pragma once
#include <vector>
using std::vector;

class Coalition;

class JoinPolicy {
    public:
        virtual int join(vector<int> &suggestions, vector<Coalition> &coalition) =0;
        virtual JoinPolicy* clone() =0;
        virtual ~JoinPolicy() = default;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        int join(vector<int> &suggestions, vector<Coalition> &coalition);
        JoinPolicy* clone();
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        int join(vector<int> &suggestions, vector<Coalition> &coalition);
        JoinPolicy* clone();
};