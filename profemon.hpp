// An Van (Projecg 2- Task A)
#pragma once
#include "skill.hpp"
#include <string>
using namespace std; 

enum Specialty
{
    ML,
    SOFTWARE,
    HARDWARE,
}; 

class Profemon{
    public:
        Profemon();
        Profemon(string name, double max_health, Specialty specialty);
        string getName();
        Specialty getSpecialty();
        int getLevel();
        double getMaxHealth();
        Skill getSkill(int slot);
        bool setName(string name);
        void levelUp(int exp);
        bool learnSkill(int slot, Skill skill);
        void printProfemon(bool print_skills);
         
    private:
        string poke_name;
        int poke_level; 
        int require_exp;
        int current_exp;
        int max_hp; 
        Specialty poke_specialty; 
        Skill learned[3]; 
};
