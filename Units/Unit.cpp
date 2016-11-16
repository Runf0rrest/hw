#include "Unit.h"

Unit::Unit(int maxHitPoints, PhysicalDefense* physicalDef, MagicalDefense* magicalDef) {
    LimitedFields<int>* hitPoitns = new LimitedFields<int>(maxHitPoints);
    PhysicalDefense physicalDef = physicalDef;
    MagicalDefense magicalDef() = magicalDef;
}

Unit::~Unit() {
    delete this->hitPoitns;
    delete this->physicalDef;
    delete this->magicalDef;    
}

Unit::Unit(const Unit& unit) {
    unit.hitPoitns = this->hitPoitns;
    unit.physicalDef = this->physicalDef;
    unit.magicalDef = this->magicalDef;
}
