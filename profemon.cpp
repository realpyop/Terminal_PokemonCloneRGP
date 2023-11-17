// An Van (Project 2 - Task A)

#include <iostream>
#include <string>
#include "profemon.hpp"


/**
    @post       :   Initializes the name of the profémon as "Undefined".
*/  
Profemon::Profemon()
{
    poke_name = "Undefined";
}



/**
    @post       :   Initializes the name, max health and specialty as the
                    corresponding parameters. Set the required experience
                    equal to 50. Initializes the current experience and 
                    level as 0.
*/
Profemon::Profemon(string name, double max_health, Specialty specialty)
{
    poke_name = name;
    poke_level = 0; 
    require_exp = 50; 
    current_exp = 0;
    max_hp = max_health; 
    poke_specialty = specialty;
}



/**
    @return     :   name of the profémon.
*/
string Profemon::getName()
{
    return poke_name; 
}



/**
    @return     :   specialty of the profémon.
*/
Specialty Profemon::getSpecialty()
{
    return poke_specialty; 
}



/**
    @return     :   level of the profémon.
*/
int Profemon::getLevel()
{
    return poke_level;
}



/**
    @return     :   maximum health of the profémon.
*/
double Profemon::getMaxHealth()
{
    return max_hp;
}



/**
    @param      :   the skill slot or index.
    @return     :   Skill object stored at `slot` index of learned skills
                    data-member array
*/
Skill Profemon::getSkill(int slot)
{
    return learned[slot]; 
}



/**
    @return     :   return `true` if the parameter is alphabetic and starts
                    with an upper-case alphabet.
    @post       :   set the name of the skill equal to the given parameter
                    if the parameter starts with an upper-case alphabet
                    and all the characters are alphabetic.
*/
bool Profemon::setName(string name)
{
    bool alphabetic = false; 
    for(int i = 0; i < name.length(); i++)
    {
        if(isalpha(name[i]))
        {
            alphabetic = true; 
        }
    }

    if(alphabetic == true && isupper(name[0]))
    {
        poke_name = name; 
        return true; 
    }
    else
    {
        return false; 
    }
}



/**
    @param      :   experience points earned by the profémon.
    @post       :   Increase the profémon's level based on the given `exp`.
                    The profémon will level up if it reaches the required
                    experience. Depending on the profémon's specialty,
                    the required experience goes up by a certain amount 
                    everytime the profémon levels up. `ML` required
                    experience goes up by 10, `SOFTWARE` goes up by 15,
                    and `HARDWARE` goes up by 20. Make sure to update the
                    required, current experience and level private data
                    members accordingly. The given `exp` can result in
                    the profémon leveling up multiple times.
  
  For example   :   starting at lvl 0, calling `levelUp(115)` on different
                    types of profémon would result in the following:

                    ML:
                      - new level: 2
                      - current exp: 5
                      - required exp: 70

                    SOFTWARE:
                      - new level: 2
                      - current exp: 0
                      - required exp: 80

                    HARDWARE:
                      - new level: 1
                      - current exp: 65
                      - required exp: 70

                    As stated above, each specialty has a different speed of
                    leveling up
*/
void Profemon::levelUp(int exp)
{
    int requiredEXP = require_exp; 
    int increaseEXP = exp + current_exp;

    switch(poke_specialty)
    {
        case ML:
            while (increaseEXP / requiredEXP != 0)
            {
                poke_level = poke_level + (((increaseEXP / requiredEXP) + 1) - (increaseEXP / requiredEXP));
                increaseEXP = increaseEXP - requiredEXP;
                requiredEXP += 10; 
            }
            require_exp = requiredEXP;
            current_exp = increaseEXP; 
            break; 

        case SOFTWARE:
            while (increaseEXP / requiredEXP != 0)
            {
                poke_level = poke_level + (((increaseEXP / requiredEXP) + 1) - (increaseEXP / requiredEXP));
                increaseEXP = increaseEXP - requiredEXP;
                requiredEXP += 15; 
            }
            require_exp = requiredEXP;
            current_exp = increaseEXP; 
            break;

        case HARDWARE:
            while (increaseEXP / requiredEXP != 0)
            {
                poke_level = poke_level + (((increaseEXP / requiredEXP) + 1) - (increaseEXP / requiredEXP));
                increaseEXP = increaseEXP - requiredEXP;
                requiredEXP += 20; 
            }
            require_exp = requiredEXP;
            current_exp = increaseEXP; 
            break;
    }
}



/**
    @param      :   the skill slot or index.
    @param      :   the new skill to be learned.
    @return     :   return `true` if the skill has been successfully learned.
                    Return `false` if `slot` parameters is not within the
                    valid range(0,1,2) or the specialty of the `skill` does
                    not match the specialty of the profémon. 
    @post       :   if the given slot is valid(0,1,2) and the skill
                    specialty matched with the profémon, add the `skill`
                    to the `slot` index of the learned skills array                
*/
bool Profemon::learnSkill(int slot, Skill skill)
{
    if (slot > 2 || slot < 0 || skill.getSpecialty() != poke_specialty)
    {
        return false; 
    }

    learned[slot].setName(skill.getName());
    learned[slot].setDescription(skill.getDescription());
    learned[slot].setSpecialty(skill.getSpecialty());
    learned[slot].setTotalUses(skill.getTotalUses()); 
    return true; 

}



/**
    @param      :   bool indicating whether or not the profémon's skills
                    should be printed
    @post       :   Prints the profémon's information in a specific format.
                    Additionally, lists the profémon's skills if the given 
                    `print_skills` parameter is true. Only print the skills
                    that are not "Undefined"
Format:
(ProfemonName) ((Specialty)) | LVL (Level) | EXP (CurrentExp)/(RequiredExp) | HP (MaxHP)
    (SkillNameSlot0) ((Uses)) : (description of skill in slot 0)
    (SkillNameSlot1) ((Uses)) : (description of skill in slot 1)
    (SkillNameSlot2) ((Uses)) : (description of skill in slot 2)

For example:
Maryash (SOFTWARE) | LVL 2 | EXP 30/80 | HP 13500
    OOP (30) : a programming paradigm based on the concept of objects
    Vector (30) : a c++ dynamic array library
    Pointer (10) : a pointer stores a memory address

Note: There are four spaces before the each line of skills. The last line
      prints an endline.
*/
void Profemon::printProfemon(bool print_skills)
{
    switch(getSpecialty())
    {
        case 0:
            cout << poke_name << " (ML) | LVL " << poke_level << " | EXP " << current_exp << "/" << require_exp << " | HP " << max_hp << endl; 
            break; 
        
        case 1:
            cout << poke_name << " (SOFTWARE) | LVL " << poke_level << " | EXP " << current_exp << "/" << require_exp << " | HP " << max_hp << endl; 
            break;

        case 2:
            cout << poke_name << " (HARDWARE) | LVL " << poke_level << " | EXP " << current_exp << "/" << require_exp << " | HP " << max_hp << endl; 
            break;
    }

    if(print_skills == true)    
    {
        for (int i = 0; i < 3; i++)
        {
            if (learned[i].getName() != "Undefined")
            {
                cout << "    " << learned[i].getName() << " (" <<learned[i].getTotalUses() << ") : " << learned[i].getDescription() << endl;
            }
        }
    }
}
