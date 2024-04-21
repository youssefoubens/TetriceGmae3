#include "../prr/shape_decalage.h"

void switch_color(list_shape* l, sf::Event event)
{
    shape_color_form* colorForm = nullptr;

    switch (event.key.code)
    {
    case sf::Keyboard::B:

        colorForm = new shape_color_form(Color::Blue, l);
        std::cout << "blue";
        colorForm->decaler_color();
        delete colorForm;
        break;
    case sf::Keyboard::Y:

        colorForm = new shape_color_form(Color::Yellow, l);
        std::cout << "yellow";
        colorForm->decaler_color();
        delete colorForm;
        break;
    case sf::Keyboard::R:

        colorForm = new shape_color_form(Color::Red, l);
         std::cout << "red";
        colorForm->decaler_color();
        delete colorForm;
        break;
    case sf::Keyboard::G:

        colorForm = new shape_color_form(Color::Green, l);
        std::cout << "green";
        colorForm->decaler_color();
        delete colorForm;
        break;
    default:
        break;
    }
    l->link_same_form();
    l->link_same_color();

}

void switch_form(list_shape* l, sf::Event event)
{
     shape_color_form* colorForm = nullptr;
    switch (event.key.code)
    {
    case sf::Keyboard::S:

        colorForm = new shape_color_form(ShapeType::Square, l);
        std::cout << "square";
        colorForm->decaler_form();
        delete colorForm;
        break;
    case sf::Keyboard::D:

        colorForm = new shape_color_form(ShapeType::Diamond, l);
        std::cout << "diamond";
        colorForm->decaler_form();
        delete colorForm;
        break;

    case sf::Keyboard::C:
        colorForm = new shape_color_form(ShapeType::Circle, l);
        std::cout << "circle";
        colorForm->decaler_form();
        delete colorForm;
        break;

    case sf::Keyboard::T:
        colorForm = new shape_color_form(ShapeType::Triangle4, l);
        std::cout << "triangle";
        colorForm->decaler_form();
        delete colorForm;
        break;
    default:
        break;
    }
    l->link_same_color();
    l->link_same_form();
}
