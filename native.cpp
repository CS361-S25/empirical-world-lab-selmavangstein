#include <iostream>

#include "Org.h"
#include "emp/base/vector.hpp"
#include "emp/math/random_utils.hpp"
#include "emp/math/Random.hpp"

#include "World.h"

// This is the main function for the NATIVE version of this project.

int main(int argc, char* argv[])
{
  emp::Random random(2);
  OrgWorld world(random);

  Organism* new_org = new Organism(&random, 0);
  world.Inject(*new_org);
  new_org = new Organism(&random, 1);
  world.Inject(*new_org);
  world.Resize(10,10);

  ::std::cout << world.size() << std::endl;
  ::std::cout << world.GetNumOrgs() << std::endl;

  //update 10 times
  for (int i = 0; i < 15; ++i) {
    world.Update();
  }

  ::std::cout << world.size() << std::endl;
  ::std::cout << world.GetNumOrgs() << std::endl;

}
