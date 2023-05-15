#include "Simulation.h"
#include "Party.h"
#include <iostream>
using std::cout;
using std::endl;

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), mCoalitons()
{

    for (std::size_t i = 0; i < mAgents.size(); i++)
    {
        int mandat = mGraph.getParty(agents[i].getPartyId()).getMandates();
        Coalition coal =  Coalition(i, mandat); // Making new coalition that that agent represent
        coal.addParty(agents[i].getPartyId());
        mCoalitons.push_back(coal); 
        agents[i].setCoId(i);
    }
}

void Simulation::step()
{
    for(int i=0; i<mGraph.getNumVertices(); i++)
        mGraph.getParty(i).step(*this);
    
    for(std::size_t i=0; i<mAgents.size(); i++)
        mAgents[i].step(*this);

}

bool Simulation::shouldTerminate() const
{
    int mone = 0;
    //61 mandates
    for (std::size_t i = 0; i < mCoalitons.size(); i++)
    {
        int mandates = mCoalitons[i].getMandates();
        if(mandates >= 61){
            return true;
        }
        mone += mandates;
    }
    //everyone in JOINED state
    if(mone == 120){
        return true;
    }
    return false;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
} 

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

Party &Simulation::getParty(int partyId)
{
    return mGraph.getParty(partyId);
}

vector<Coalition> &Simulation::getCoalitions(){

    return mCoalitons;
}

void Simulation::addAgent(Agent a){
    mAgents.push_back(a);
}


/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> ret;
    for(std::size_t i=0; i<mCoalitons.size(); i++){

        ret.push_back(mCoalitons[i].getParties()) ;
    }
    return ret;
}
