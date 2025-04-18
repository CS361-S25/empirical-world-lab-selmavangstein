#ifndef SPECIESA_H
#define SPECIESA_H

#include "emp/math/random_utils.hpp"
#include "emp/math/Random.hpp"

#include "Org.h"

class SpeciesA : public Organism{

    public:
        SpeciesA(emp::Ptr<emp::Random> _random, double _points=0.0) : Organism(_random, 0, _points) {;}

        void Process(int _pts) override {
            SetPoints(GetPoints() + _pts);
            //std::cout << "Processing" << std::endl; //feel free to get rid of this
        }

        int GetSpecies() override {return 0;}

        emp::Ptr<Organism> CheckReproduction() override{
            int points = GetPoints();
            if (points > 1000) {
                emp::Ptr<Organism> offspring = new Organism(*this);
                offspring->SetPoints(0);
                points -= 1000;
                SetPoints(points);
                ::std::cout << "Reproducing!" << std::endl;
                return offspring;
            } else {
                return nullptr;
            }
            
        }
};

#endif