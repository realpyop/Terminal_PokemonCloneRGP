/*
Author: An Van
Course: CSCI-135
Assignment: TASKB
*/

#ifndef DEPARTMENT
#define DEPARTMENT
#include "trainer.hpp"
#include <vector>
using namespace std;

class MLDepartment : public Trainer
{
public:
    MLDepartment(vector<Profemon> profemons);
    bool addProfemon(Profemon profemon);
};

class SoftwareDepartment : public Trainer
{
public:
    SoftwareDepartment(vector<Profemon> profemons);
    bool addProfemon(Profemon profemon);
};

class HardwareDepartment : public Trainer
{
public:
    HardwareDepartment(vector<Profemon> profemons);
    bool addProfemon(Profemon profemon);
};

#endif
