#include "Coalition.h"

Coalition::Coalition(int coalitionId, int numMandates) : coId(coalitionId), nMandates(numMandates), mParties()
{
    
}


void Coalition:: addParty(int partyId){
    mParties.push_back(partyId);

}
const vector<int> &Coalition::getParties() const{
    return mParties;
}

vector<int> &Coalition::getParties(){
    return mParties;
}


void Coalition:: addMandates(int numOfMandates){
    nMandates += numOfMandates;
}

int Coalition:: getMandates() const{
    return nMandates;
}