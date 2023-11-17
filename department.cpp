/*
Author: An Van
Course: CSCI-135
Assignment: TASKB
*/

#include <iostream>
#include <string>
#include <vector>
#include "department.hpp"
using namespace std; 

MLDepartment::MLDepartment(vector<Profemon> profemons)
{
    for (int i = 0; i < profemons.size(); i++)
    {
        if (profemons[i].getSpecialty() == ML)
        {
            Trainer::addProfemon(profemons[i]);
        }
    }
}
bool MLDepartment::addProfemon(Profemon profemon)
{
    if (profemon.getSpecialty() == ML)
    {
        Profedex.push_back(profemon);
        return true;
    }
    return false;
}

SoftwareDepartment::SoftwareDepartment(vector<Profemon> profemons)
{
    for (int i = 0; i < profemons.size(); i++)
    {
        if (profemons[i].getSpecialty() == SOFTWARE)
        {
            Trainer::addProfemon(profemons[i]);
        }
    }
}
bool SoftwareDepartment::addProfemon(Profemon profemon)
{
    if (profemon.getSpecialty() == SOFTWARE)
    {
        Profedex.push_back(profemon);
        return true;
    }
    return false;
}

HardwareDepartment::HardwareDepartment(vector<Profemon> profemons)
{
    for (int i = 0; i < profemons.size(); i++)
    {
        if (profemons[i].getSpecialty() == HARDWARE)
        {
            Trainer::addProfemon(profemons[i]);
        }
    }
}

bool HardwareDepartment::addProfemon(Profemon profemon)
{
    if (profemon.getSpecialty() == HARDWARE)
    {
        Profedex.push_back(profemon);
        return true;
    }
    return false;
}
