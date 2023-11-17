/*
Author: An Van
Course: CSCI-135
Assignment: PROJECT2 - TaskA
*/

#pragma once
#include <iostream> 
#include <istream>
#include <string>
using namespace std; 



class Skill
{
    public:
        Skill();
        Skill(string name, string description, int specialty, int uses); 
        string getName();
        string getDescription();
        int getTotalUses();
        int getSpecialty();
        void setName(string name);
        bool setDescription(string description);
        bool setTotalUses(int uses);
        bool setSpecialty(int specialty);
        
    private:
        string skill_name;
        string skill_description; 
        int skill_uses; 
        int skill_specialty; 
};

