#include "Party.h"
#include "Simulation.h"
#include <iostream>
using std::cout;
using std::endl;


Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), suggestions()
{

}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::addSuggestion(int coId){

    if(mState == Waiting){
        mState = CollectingOffers; // updating status
        timer++;
    }
    suggestions.push_back(coId);
}

void Party::step(Simulation &s)
{
    
    if(mState == CollectingOffers){
        if(timer == 3){ // choosing coalition step

            mState = Joined;
            vector<Coalition> &allCoa = s.getCoalitions();
            int coa = mJoinPolicy->join(suggestions, allCoa); // the selected coalition to join
            allCoa[coa].addParty(mId);
            allCoa[coa].addMandates(mMandates);
            
            Agent agentClone = Agent(s.getAgents()[coa]);

            // update the ID and the PartyName, after the clone
            agentClone.setPartyId(mId);
            agentClone.setAgentId(s.getAgents().size());
            //add the agent to the simulation
            s.addAgent(agentClone);
        }
        else{
            timer++;
        }
    }
}

const vector<int> &Party:: getSuggestions() const
{
    return suggestions;

}


// Copy Constructor
Party::Party(const Party& other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(nullptr), mState(other.getState()), suggestions() {
   mJoinPolicy = other.mJoinPolicy->clone();
   for(int a : other.suggestions){
        suggestions.push_back(a);
   }
}

// Destructor
Party::~Party(){
    if(mJoinPolicy){delete mJoinPolicy;}
    mJoinPolicy = nullptr;
}

// Copy Assignment Operator
Party&  Party :: operator=(const Party& other) {
    if (this != &other) {
        mId = other.mId;
        mName = other.mName;
        mState = other.getState();
        suggestions.clear();
        for(int a : other.suggestions){
            suggestions.push_back(a);
        }
        if(mJoinPolicy){delete mJoinPolicy;}
        mJoinPolicy=other.mJoinPolicy->clone();
        
    }
    return *this;
}

// //-------------Rule of 5-------------

// Move Constructor
Party::Party(Party&& other) :mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.getState()), suggestions() {
    other.mJoinPolicy = nullptr;
    
    //std::cout << "move Constructor" << std::endl;
}

// Move Assignment Operator
Party& Party::operator=(Party&& other) {
    if (this != &other) {
        
        mId = other.mId;
        mName = other.mName;
        mState = other.getState();
        suggestions.clear();
        for(int a : other.suggestions){
            suggestions.push_back(a);
        }
        if(mJoinPolicy){delete mJoinPolicy;}
        mJoinPolicy=other.mJoinPolicy;
        other.mJoinPolicy = nullptr;
       
    }
    return *this;
}