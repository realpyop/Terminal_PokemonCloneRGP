/*
Author: An Van
Course: CSCI-135
Assignment: TASKB
*/


#include "trainer.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <string>
using namespace std; 

/**
    @post       :   Initializes the pointer to the currently selected
                    profémon as `nullptr`.
*/
Trainer::Trainer()
{
    select = nullptr;
}
    


/**
    @param      :   a vector of profémons.
    @post       :   Adds the profémons from given parameter vector to the
                    team and the profédex. If the team is full, add the
                    profémons to the profedéx. Maintain the order of the 
                    given `profemons` vector. Assume that the parameter
                    vector has atleast one item. Select the profémon at 0
                    index of the team array to accompany the trainer.
*/
Trainer::Trainer(vector<Profemon> profemons)
{
    select = nullptr; 
    for (int i = 0; i < profemons.size(); i++)
    {
        if (i < 4)
        {
            Team[i] = profemons[i];
        }
        else
        {
            Profedex.push_back(profemons[i]); 
        }
    }
    select = &Team[0];
}



/**
    @param      :   the name of a profémon.
    @return     :   `true` if profémon with given name is in the team or
                    profedex, otherwise `false`   
    @post       :   return `true` if the profémon with the name same as the
                    given parameter is found either in current team, or in
                    the profédex. Return `false` if the profémon is
                    not found.
*/
bool Trainer::contains(string name)
{
    for (int i = 0; i < 3; i++)
    {
        if (Team[i].getName() == name)
        {
            return true;
        }
    }
    for (int j = 0; j < Profedex.size(); j++)
    {
        if (Profedex[j].getName() == name)
        {
            return true;
        }
    }
    return false;
}


bool Trainer::addProfemon(Profemon profemon)
{
    bool inTeam;
    for (int i = 0; i < 3; i++)
    {
        if (Team[i].getName() == profemon.getName())
        {
            return false;
        }
    }
    for (int j = 0; j < Profedex.size(); j++)
    {
        if (Profedex[j].getName() == profemon.getName())
        {
            return false;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (Team[i].getName() == "Undefined")
        {
            Team[i] = profemon;
            return true;
        }
    }
    for (int j = 0; j < Profedex.size(); j++)
    {
        if (Profedex[j].getName() == profemon.getName())
        {
            inTeam = true;
        }
        else
        {
            inTeam = false;
        }
    }
    if (inTeam != true)
    {
        Profedex.push_back(profemon);
        return true;
    }
    return false;
}

bool Trainer::removeProfemon(string name)
{
    for (int i = 0; i < 3; i++)
    {
        if (Team[i].getName() == name)
        {
            Team[i] = Profemon();
            return true;
        }
    }
    for (int i = 0; i < Profedex.size(); i++)
    {
        if (Profedex[i].getName() == name)
        {
            Profedex.erase(Profedex.begin() + i);
            return true;
        }
    }

    return false;
}


void Trainer::setTeamMember(int slot, string name)
{
    Profemon swap;
    if (Team[slot].getName() == "Undefined")
    {
        for (int i = 0; i < Profedex.size(); i++)
        {
            if (Profedex[i].getName() == name)
            {
                Team[slot] = Profedex[i];
                Profedex.erase(Profedex.begin() + i);
            }
        }
    }
    else
    {
        for (int i = 0; i < Profedex.size(); i++)
        {
            if (Profedex[i].getName() == name)
            {
                swap = Team[slot];
                Team[slot] = Profedex[i];
                Profedex[i] = swap;
            }
        }
    }
}

bool Trainer::chooseProfemon(int slot)
{
    if (Team[slot].getName() != "Undefined")
    {
        select = &Team[slot];
        return true;
    }
    return false;
}

Profemon Trainer::getCurrent()
{
    return *select;
}

vector<Profemon> Trainer::getProfedex()
{
    return Profedex; 
}


/**
    @post       :   prints profémons in the profédex in a specific format.

Format :
(Profemon1Name) ((Specialty)) | LVL (Level) | EXP (CurrentExp)/(RequiredExp) | HP (MaxHP)
(empty line)
(Profemon2Name) ((Specialty)) | LVL (Level) | EXP (CurrentExp)/(RequiredExp) | HP (MaxHP)
(empty line)
. . . PRINT ALL THE PROFEMONS IN THE PROFEDEX . . .
(LastProfemonName) ((Specialty)) | LVL (Level) | EXP (CurrentExp)/(RequiredExp) | HP (MaxHP)
(empty line)

For example:
Maryash (SOFTWARE) | LVL 2 | EXP 30/80 | HP 13500

Saad (HARDWARE) | LVL 3 | EXP 20/110 | HP 15000

Raja (ML) | LVL 1 | EXP 10/60 | HP 35000


Hint : The format looks familiar from Task A print doesn't it?
*/
void Trainer::printProfedex()
{
    for (int i = 0; i < Profedex.size(); i++)
    {
        Profedex[i].printProfemon(false);
        cout << endl;
    }
}

/*
    @post       :   prints profémons in the team in a specific format.
                    Do not print "Undefined" profémons.

Format :
(Profemon1Name) ((Specialty)) | LVL (Level) | EXP (CurrentExp)/(RequiredExp) | HP (MaxHP)
    (SkillNameSlot0) ((Uses)) : (description of skill in slot 0)
    (SkillNameSlot1) ((Uses)) : (description of skill in slot 1)
    (SkillNameSlot2) ((Uses)) : (description of skill in slot 2)
(empty line)
(Profemon2Name) ((Specialty)) | LVL (Level) | EXP (CurrentExp)/(RequiredExp) | HP (MaxHP)
    (SkillNameSlot0) ((Uses)) : (description of skill in slot 0)
    (SkillNameSlot1) ((Uses)) : (description of skill in slot 1)
    (SkillNameSlot2) ((Uses)) : (description of skill in slot 2)
(empty line)
(Profemon3Name) ((Specialty)) | LVL (Level) | EXP (CurrentExp)/(RequiredExp) | HP (MaxHP)
    (SkillNameSlot0) ((Uses)) : (description of skill in slot 0)
    (SkillNameSlot1) ((Uses)) : (description of skill in slot 1)
    (SkillNameSlot2) ((Uses)) : (description of skill in slot 2)
(empty line)
(Profemon4Name) ((Specialty)) | LVL (Level) | EXP (CurrentExp)/(RequiredExp) | HP (MaxHP)
    (SkillNameSlot0) ((Uses)) : (description of skill in slot 0)
    (SkillNameSlot1) ((Uses)) : (description of skill in slot 1)
    (SkillNameSlot2) ((Uses)) : (description of skill in slot 2)
(empty line)
*/
void Trainer::printTeam()
{
    for (int i = 0; i < 3; i++)
    {
        if (Team[i].getName() != "Undefined")
        {
            Team[i].printProfemon(true);
            cout << endl;
        }
    }
}