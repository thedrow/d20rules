#ifndef __D20Character
#define __D20Character

#include "D20Abilities.hpp"
#include "D20SavingThrows.hpp"
#include "D20Skills.hpp"
#include "D20ArmorClass.hpp"

namespace D20Rules
{
    class D20Character
    {
    private:
        
    public:
        D20Character();
        
        Containers::D20Skills Skills;
        Containers::D20Abilities Abilities;
        Containers::D20SavingThrows SavingThrows;
        
        RolledAgainst::D20ArmorClass ArmorClass;
    };
}

#endif
