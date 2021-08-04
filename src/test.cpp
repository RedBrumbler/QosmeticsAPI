#include "Components/AltTrail.hpp"
#include "Components/TrailHelper.hpp"
#include "Components/ColorComponent.hpp"
#include "NoteAPI.hpp"
#include "QosmeticsAPI.hpp"
#include "SaberAPI.hpp"
#include "WallAPI.hpp"

using namespace Qosmetics;
int main ()
{
    // this at least makes it so nothing gets stripped
    TrailHelper* ptr = new TrailHelper();
    ColorComponent* ptr2 = new ColorComponent();
    AltTrail* ptr3 = new AltTrail();

    return 0;
}