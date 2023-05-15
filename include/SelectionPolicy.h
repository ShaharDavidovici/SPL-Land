#pragma once
class Graph;

class SelectionPolicy { 
    public:
        virtual int select (const Graph &g, int partyId, int coId) =0;
        virtual SelectionPolicy* clone() =0;
        virtual ~SelectionPolicy() = default;
};

class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
        int select (const Graph &g, int partyId, int coId);
        SelectionPolicy* clone();
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        int select (const Graph &g, int partyId, int coId);
        SelectionPolicy* clone();
 };