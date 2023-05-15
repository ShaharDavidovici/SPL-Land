#include "Agent.h"
#include "Simulation.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy) , mCoId(agentId)
{
    // You can change the implementation of the constructor, but not the signature!
    
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::setCoId(int id){

    mCoId = id;
}

void Agent::setAgentId(int agentId){

    mAgentId = agentId;
}

void Agent::setPartyId(int partyId){

    mPartyId = partyId;
}

void Agent::step(Simulation &sim)
{
    
    int chosen = mSelectionPolicy->select(sim.getGraph(), mPartyId, mCoId); // chosen is the id of the selected party to offer
    if(chosen != -1){

        Party& p  = sim.getParty(chosen);
        p.addSuggestion(mCoId); // letting know p it can join mCoId
        
    }
    
}


// Copy Constructor
Agent::Agent(const Agent& other) 
    : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy->clone()), mCoId(other.mCoId){

}

// Destructor
Agent::~Agent(){
    delete mSelectionPolicy;
    mSelectionPolicy = nullptr;
}

// Copy Assignment Operator
Agent&  Agent :: operator=(const Agent& other) {
    if (this != &other) { 
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;

        if(mSelectionPolicy) { delete mSelectionPolicy;}
        mSelectionPolicy=other.mSelectionPolicy->clone();
        mCoId = other.mCoId;
        
    }
    return *this;
}

// //-------------Rule of 5-------------

// Move Constructor
Agent::Agent(Agent&& other) :mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy) , mCoId(other.mCoId) {
    other.mSelectionPolicy = nullptr;
    
}

// Move Assignment Operator
Agent& Agent::operator=(Agent&& other) {
    if (this != &other) { 
        
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy;
        
        other.mSelectionPolicy = nullptr;
        mCoId = other.mCoId;
       
    }
    return *this;
}


int Agent::getCoId() 
{
    return mCoId;
}