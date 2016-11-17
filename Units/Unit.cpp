#include "Unit.h"

Unit::Unit(const std::string& name, int hp, int dmg) {
    this->name = name;
    this->hitPointsLimit = hp;
    this->hitPoints = hp;
    this->damage = dmg;
}

Unit::~Unit() {}

void Unit::ensureIsAlive() {
    if ( hitPoints == 0 ) {
        throw UnitIsDead();
    }
}

int Unit::getDamage() const {
    return damage;
}

int Unit::getHitPoints() const {
    return hitPoints;
}

int Unit::getHitPointsLimit() const {
    return hitPointsLimit;
}

const std::string& Unit::getName() const {
    return name;
}

void Unit::takeDamage(int dmg) {
    ensureIsAlive();
    
    if ( dmg >= hitPoints ) {
        hitPoints = 0;
        
        return;
    }
    
    hitPoints -= dmg;
}

void Unit::addHitPoints(int hp) {
    ensureIsAlive();
    
    if ( hitPoints + hp >= hitPointsLimit ) {
        hitPoints = hitPointsLimit;
        
        return;
    }
    
    hitPoints += hp;
}

void Unit::attack(Unit& enemy) {
    ensureIsAlive();
    
    enemy.takeDamage(damage);
    
    enemy.counterAttack(*this);
}
void Unit::counterAttack(Unit& enemy) {
    if ( this->hitPoints == 0 ) {
        return;
    }
    
    enemy.takeDamage(damage/2);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getName();
    out << ", Max HP = " << unit.getHitPointsLimit();
    out << ", Current HP = " << unit.getHitPoints();
    out << ", Damage = " << unit.getDamage();
    out << std::endl;
    
    return out;
}
