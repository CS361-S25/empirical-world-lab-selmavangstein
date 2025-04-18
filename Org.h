#ifndef ORG_H
#define ORG_H

#include "emp/math/Random.hpp"
#include "emp/tools/string_utils.hpp"

class Organism {
    private:
        double points;
        emp::Ptr<emp::Random> random;
        int species;

    public:
    Organism(emp::Ptr<emp::Random> _random, int _species, double _points=0.0) :
        points(_points), random(_random), species(_species) {;}

    void SetPoints(double _in) {points = _in;}
    void AddPoints(double _in) {points += _in;}


    virtual void Process(int _pts) {
        if (species == 0){
            points += _pts;
        } else {
            points += _pts/2;
        }
    }

     virtual int GetSpecies() {return species;}
    int GetPoints() {return points;}
    void SetPoints(int _in) {points = _in;}

    virtual emp::Ptr<Organism> CheckReproduction(){
        /* if (points > 1000 && species == 0) {
            emp::Ptr<Organism> offspring = new Organism(*this);
            offspring->SetPoints(0);
            points -= 1000;
            ::std::cout << "Reproducing!" << std::endl;
            return offspring;
        } else if (points > 300 && species == 1) {
            emp::Ptr<Organism> offspring = new Organism(*this);
            offspring->SetPoints(0);
            points -= 300;
            ::std::cout << "Reproducing!" << std::endl;
            return offspring;
        } else {
            return nullptr;
        }
      */
    std::cout << "WRONG CheckReproduction" << std::endl;
    return nullptr;   
    }
};
#endif