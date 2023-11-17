// An Van (Project 2 - Task A)



#include <iostream>
#include "skill.hpp"
using namespace std; 

/**
    @post       :   Initializes the name and description of the skill as
                    "Undefined". Initializes the total uses of the skill
                    and the skill specialty as -1.
*/  
Skill::Skill()
{
    skill_name = "Undefined";
    skill_description = "Undefined";
    skill_uses = -1; 
    skill_specialty = -1; 
}



/**
    @post       :   Parameterized constructor sets the corresponding
                    data members equal to the respective parameters.
*/
Skill::Skill(string name, string description, int specialty, int uses)
{
    skill_name = name;
    skill_description = description;
    skill_uses = uses;
    skill_specialty = specialty; 
}



/**
    @return     :   name of the skill.
*/
string Skill::getName()
{
    return skill_name; 
}



/**
    @return     :   description of the skill.
*/
string Skill::getDescription()
{
    return skill_description;
}



/**
    @return     :   total uses of the skill.
*/
int Skill::getTotalUses()
{
    return skill_uses; 
}



/**
    @return     :   specialty of the skill.
*/
int Skill::getSpecialty()
{
    return skill_specialty;
}



/**
    @post       :   set the name of the skill equal to the given parameter.
*/
void Skill::setName(string name)
{
    skill_name = name;
}



/**
    @return     :   return `true` if the given `description` is atleast 25
                    characters long, otherwise return `false`.
    @post       :   set the description of the skill equal to the given
                    `description` parameter if it is long enough.
*/
bool Skill::setDescription(string description)
{
    int description_length = description.size();
    if(description_length >= 25)
    {
        skill_description = description;
        return true; 
    }
    else
    {
        return false; 
    }
}



/**
    @return     :   return `false` if the given `uses` is greater than 50,
                    otherwise return `true`.
    @post       :   set the total uses of the skill equal to the given
                    parameter if the parameter is less than or equal to 50.
*/
bool Skill::setTotalUses(int uses)
{
    if(uses > 50)
    {
        return false;
    }
    else
    {
        skill_uses = uses;
        return true; 
    }
}



/**
    @return     :   Return `true` if the given parameter is 0, 1 or 2.
                    Otherwise, return `false`.
    @post       :   set the specialty of the skill equal to the given
                    parameter only if the given parameter is valid (0,1,2).
*/
bool Skill::setSpecialty(int specialty)
{
    if(specialty == 0 || specialty == 1 || specialty == 2)
    {
        skill_specialty = specialty;
        return true; 
    }
    else
    {
        return false; 
    }
}




