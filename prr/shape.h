#include <SFML/Graphics.hpp>

enum class Color
{
    Blue,
    Yellow,
    Red,
    Green,


};

enum class ShapeType
{

    Square,
    Diamond,
    Circle,
    Triangle4,

};

struct shape
{
    Color c;
    ShapeType f;
    shape *next_same_color;
    shape *prev_same_color;
    shape *next_same_form;
    shape *prev_same_form;
    shape *next_shape;
    shape *prev_shap;

};
