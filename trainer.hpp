/*
Author: An Van
Course: CSCI-135
Assignment: TASKB
*/


#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "profemon.hpp"
#include "skill.hpp"
using namespace std; 

class Trainer{
    protected:
        vector<Profemon> Profedex; 
        Profemon Team[3];
        Profemon *select;
    
    public:
        Trainer();
        Trainer(vector<Profemon> profemons);
        bool contains(string name);
        bool addProfemon(Profemon profemon);
        bool removeProfemon(string name);
        void setTeamMember(int slot, string name);
        bool chooseProfemon(int slot);
        Profemon getCurrent();
        vector<Profemon> getProfedex();
        void printProfedex();
        void printTeam(); 
}; 