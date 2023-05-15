
#include "JoinPolicy.h"
#include "Coalition.h"
#include <iostream>
using std::cout;
using std::endl;


int MandatesJoinPolicy :: join(vector<int> &suggestions, vector<Coalition> &coalition){

    int max = 0;
    int chosen = -1;

    for(std::size_t i = 0; i<suggestions.size(); i++){ // run on all offers

        if(coalition[suggestions[i]].getMandates() > max){
            chosen = suggestions[i];
            max = coalition[suggestions[i]].getMandates();
        }
    }
    return chosen;
}


int LastOfferJoinPolicy :: join(vector<int> &suggestions, vector<Coalition> &coalition){
    return suggestions[suggestions.size()-1];
}


JoinPolicy* MandatesJoinPolicy :: clone(){
    return new MandatesJoinPolicy(*this);
}

JoinPolicy* LastOfferJoinPolicy :: clone(){
    return new LastOfferJoinPolicy(*this);
}


