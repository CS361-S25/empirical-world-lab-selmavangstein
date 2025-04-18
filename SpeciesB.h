#ifndef SPECIESB_H
#define SPECIESB_H

#include "emp/math/random_utils.hpp"
#include "emp/math/Random.hpp"

#include "Org.h"

class SpeciesB : public Organism{

    public:
        SpeciesB(emp::Ptr<emp::Random> _random, double _points=0.0) : Organism(_random, 1, _points) {;}

        void Process(int _pts) override {
            SetPoints(GetPoints() + (_pts/2));
            //std::cout << "Processing" << std::endl; //feel free to get rid of this
        }

        int GetSpecies() override {return 1;}

        emp::Ptr<Organism> CheckReproduction() override{
            int points = GetPoints();
            if (points > 10000) { // make this an instance variable - birthThreshold or something. Make it a const?
                emp::Ptr<Organism> offspring = new Organism(*this);
                offspring->SetPoints(0);
                points -= 10000;
                SetPoints(points);
                ::std::cout << "Reproducing!" << std::endl;
                return offspring;
            } else {
                return nullptr;
            }
            
        }
};

#endif