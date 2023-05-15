
#pragma once
#include <vector>
using std::vector;


class Coalition{

    public:
    Coalition(int coalitionId, int numMandates);
    void addParty(int partyId);
    const vector<int> &getParties() const;
    void addMandates(int numOfMandates);
    int getMandates() const;
    vector<int> &getParties();

    private:

        int coId;
        int nMandates;
        vector<int> mParties; // vector of all the parties ID that Joined the coalition
};