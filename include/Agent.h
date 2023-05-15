#pragma once
#include <vector>
#include "SelectionPolicy.h"
class Simulation;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);

    void setCoId(int id);
    void setAgentId(int agentId);
    void setPartyId(int partyId);

    ~Agent(); // distructor
    Agent(const Agent& other); // copy constructor
    Agent& operator=(const Agent& other); // Copy Assignment Operator
    Agent(Agent&& other); // Move Constructor
    Agent& operator=(Agent&& other); // Move Assignment Operator
    int getCoId();

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;

    int mCoId; // What coalition the agent represent
};
