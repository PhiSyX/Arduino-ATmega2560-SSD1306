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

    view
        .line("Choix un")
        .on_press(Page::VIEW_HOME_CHOICE_ONE);

    view
        .line("Choix deux")
        .on_press(Page::VIEW_HOME_CHOICE_TWO);

    view
        .line("Choix trois")
        .on_press(Page::VIEW_HOME_CHOICE_THREE);

    layout.display();

    if (!rotary_encoder.is_pressed())
    {
        return;
    }

    // comportement particulier lorsqu'on presse le bouton?
}
