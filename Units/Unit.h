#include "../Stats/PhysicalDefense.h"
#include "../Stats/MagiclaDegese.h"

class Unit {
    protected:
        LimitedFields<int>* hitPoitns;
        PhysicalDefense* physicalDef;
        MagicalDefense* magicalDef;
        
        virtual void attack() = 0;           
        virtual void reciveDamage() = 0;
        
    public:
        Unit(int maxHitPoints, LimitedFields<int> hitPoitns, 
            PhysicalDefense physicalDef, MagicalDefense magicalDef);
        virtual ~Unit();
        virtual Unit(const Unit& unit);
};
