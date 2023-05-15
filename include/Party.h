#pragma once
#include <string>
#include <vector>
#include "JoinPolicy.h"
using std::vector;
using std::string;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;

    const vector<int> &getSuggestions() const;
    void addSuggestion(int coId);

    Party(const Party& other); // copy constructor
    ~Party(); // distructor
    Party& operator=(const Party& other); // Copy Assignment Operator
    Party(Party&& other); // Move Constructor
    Party& operator=(Party&& other); // Move Assignment Operator


private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    
    vector<int> suggestions;
    int timer = 0;

};
