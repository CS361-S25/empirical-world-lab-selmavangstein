#ifndef WORLD_H
#define WORLD_H

#include "emp/Evolve/World.hpp"
#include "emp/math/random_utils.hpp"
#include "emp/math/Random.hpp"

#include "Org.h"

class OrgWorld : public emp::World<Organism> {

    emp::Random &random;
    emp::Ptr<emp::Random> random_ptr;

    public:

    OrgWorld(emp::Random &_random) : emp::World<Organism>(_random), random(_random) {
        random_ptr.New(_random);
    }

    ~OrgWorld() {
    }

    //This function removes the organism at position i and returns it
    emp::Ptr<Organism> ExtractOrganism(int i) {
        emp::Ptr<Organism> org = pop[i];
        pop[i] = nullptr;
        return org;
    }


    void Update() {
        //std::cout << "Updating!" << std::endl; //feel free to get rid of this
        emp::vector<size_t> schedule = emp::GetPermutation(random, GetSize());
        for (int i : schedule) {
            if(!IsOccupied(i)) {continue;}
            pop[i]->Process(100);

            //abstract this at some point. Current issue: sometimes it moves too far
            emp::Ptr<Organism> org = ExtractOrganism(i);
            emp::WorldPosition newPos = GetRandomNeighborPos(i);
            if(IsOccupied(newPos)) {AddOrgAt(org, i);}
            else {AddOrgAt(org, newPos);}
        }

        schedule = emp::GetPermutation(random, GetSize());
        for (int i : schedule) {
            if(!IsOccupied(i)) {continue;}
            emp::Ptr<Organism> offspring = pop[i]->CheckReproduction();

            if(offspring) {
                //abstract this at some point.
                emp::WorldPosition newPos = GetRandomNeighborPos(i);
                if(IsOccupied(newPos)) {AddOrgAt(offspring, i);}
                else {AddOrgAt(offspring, newPos);}
            }
        }


    }

};
#endif
