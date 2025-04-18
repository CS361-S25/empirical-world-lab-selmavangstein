#include "emp/math/Random.hpp"
#include "emp/web/Animate.hpp"
#include "emp/web/web.hpp"
#include "World.h"
#include "Org.h"

emp::web::Document doc{"target"};

class AEAnimator : public emp::web::Animate {

    // arena width and height
    const int num_h_boxes = 10;
    const int num_w_boxes = 10;
    const double RECT_SIDE = 15;
    const double width{num_w_boxes * RECT_SIDE};
    const double height{num_h_boxes * RECT_SIDE};
    int update_count = 0;

    emp::web::Canvas canvas{width, height, "canvas"};

    private:
        emp::Random random{5};
        OrgWorld world{random};


    public:

    AEAnimator() {
        // shove canvas into the div
        // along with a control button
        doc << canvas;
        doc << GetToggleButton("Toggle");
        doc << GetStepButton("Step");

        Organism* new_org = new Organism(&random, 0);
        world.Inject(*new_org);
        new_org = new Organism(&random, 1);
        world.Inject(*new_org);
        world.Resize(num_h_boxes, num_w_boxes);
        world.SetPopStruct_Grid(num_w_boxes, num_h_boxes);

    }

    void DoFrame() override {
        canvas.Clear();

        if (update_count != 0){
            world.Update();
        }

        int org_num = 0;
        for (int x = 0; x < num_w_boxes; x++){
            for (int y = 0; y < num_h_boxes; y++) {
                if (world.IsOccupied(org_num)) {
                    Organism org = world.GetOrg(org_num);
                    int species = org.GetSpecies();
                    ::std::cout << species << std::endl;
                    if (species == 0) {
                        canvas.Rect(x * RECT_SIDE, y * RECT_SIDE, RECT_SIDE, RECT_SIDE, "red", "black");
                    } else if (species == 1) {
                        canvas.Rect(x * RECT_SIDE, y * RECT_SIDE, RECT_SIDE, RECT_SIDE, "blue", "black");
                    } 
                    
                } else {
                    canvas.Rect(x * RECT_SIDE, y * RECT_SIDE, RECT_SIDE, RECT_SIDE, "white", "black");
                }
                org_num++;
            }
        }
        update_count++;
    }

};

AEAnimator animator;

int main() {animator.Step();}