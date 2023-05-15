#include "SelectionPolicy.h"
#include "Graph.h"
#include <iostream>
using std::cout;
using std::endl;

int MandatesSelectionPolicy :: select(const Graph &g, int partyId, int coId) {

    int max = 0;
    int chosen = -1;
    bool alreadyOffered = false;

    for(int i = 0; i< g.getNumVertices(); i++){ 
        
        if(g.getEdgeWeight(i,partyId) > 0 && g.getParty(i).getState() != Joined){

           if(g.getMandates(i) > max ){

            vector<int> suggestions = g.getParty(i).getSuggestions();
            for(std::size_t j = 0; j<suggestions.size() && !alreadyOffered; j++){ 
                // Make Sure it wont select party that received an offer from the same coalition
                if(suggestions[j] == coId){
                    alreadyOffered = true;
                }
            }
            if(!alreadyOffered){
                max = g.getMandates(i);
                chosen = i;
            }
            alreadyOffered = false; // reset for next iteration
           } 
        }
    }
    return chosen;
}

int EdgeWeightSelectionPolicy :: select(const Graph &g, int partyId, int coId) {

    int max = 0;
    int chosen = -1;
    bool alreadyOffered = false;

    for(int i = 0; i< g.getNumVertices(); i++){ 

        if(g.getParty(i).getState() != Joined){

           if(g.getEdgeWeight(i,partyId) > max ){

            vector<int> suggestions = g.getParty(i).getSuggestions();
            for(std::size_t j = 0; j<suggestions.size() && !alreadyOffered; j++){
                // Make Sure it wont select party that received an offer from the same coalition
                if(suggestions[j] == coId){
                    alreadyOffered = true;
                }
            }
            if(!alreadyOffered){
                max = g.getEdgeWeight(i,partyId);
                chosen = i;
            }
            alreadyOffered = false; // reset for next iteration

           } 
        }
    }
    return chosen;


}
SelectionPolicy* MandatesSelectionPolicy :: clone(){
    return new MandatesSelectionPolicy(*this);
}

SelectionPolicy* EdgeWeightSelectionPolicy :: clone(){
    return new EdgeWeightSelectionPolicy(*this);
}

