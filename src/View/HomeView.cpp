#include "View/HomeView.hpp"

#include "Encoder/RotaryEncoder.hpp"
#include "Layout.hpp"
#include "View.hpp"

extern Layout layout;
extern View view;
extern RotaryEncoder rotary_encoder;

// ---- //
// Page //
// ---- //

void HomeView::display_home()
{
    layout.clear();

    view.title("Accueil");

    rotary_encoder.define_total(3);
    view.line("Choix un");
    view.line("Choix deux");
    view.line("Choix trois");

    layout.display();

    if (!rotary_encoder.on_pressed())
    {
        return;
    }

    // comportement particulier lorsqu'on presse le bouton?
}
