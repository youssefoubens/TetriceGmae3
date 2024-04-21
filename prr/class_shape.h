// the main class of list of shape
#include <unordered_map>
struct adress
{
    shape *head1;
    shape *tail1;
    int size;
};
class list_shape
{
private:
    shape *head;
    shape *tail;
    int score=0;
    int size;

public:
    list_shape();
    shape *create_shape(Color c ,ShapeType s);
    int insert_shape(Color c, ShapeType s, bool insert_on_left);
    shape delete_shape();
    void delete_all_shapes(list_shape *l);
    int getsize();
    int getscore();
   void setscore(int s);
    void display_same_form();
    void display_shapes();
    void delete_three_same_linked();
    adress *address_f_l(Color c_or_f,ShapeType f, bool search_by_color);
   void drawShape(sf::RenderWindow &window, Color color, ShapeType shapeType, sf::Vector2f position, float size);
   void display_shapes(sf::RenderWindow &window,float x,float y,int z);
   void link_same_color();
    void link_same_form();
    void remove_same_color_links();
    void remove_same_form_links();

    ~list_shape();
};

void list_shape::display_same_form()
{
    shape *current = head;
    while (current != nullptr)
    {


        current = current->next_same_form;
    }
}
int list_shape::getsize()
{
    return size;
};
list_shape::list_shape()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

shape* list_shape::create_shape(Color c,ShapeType s)
{
     shape *newShape = new shape;

    newShape->c = c;
    newShape->f = s;
    newShape->next_shape = nullptr;
    newShape->prev_shap = nullptr;
    newShape->next_same_color = nullptr;
    newShape->next_same_form = nullptr;
    return newShape;

}

int list_shape::insert_shape(Color c, ShapeType s, bool insert_on_left) {



    shape *newShape = create_shape(c, s);
    if (size == 15) {
        std::cout << "Impossible to add: maximum size reached";
        return 0;
    } else {
        if (head == nullptr) {
            head = newShape;
            tail = newShape;
        } else {
            if (insert_on_left) {
                shape *current = head;
                while (current != nullptr) {
                    if (newShape->c == current->c) {
                        newShape->next_same_color = current;
                        current->prev_same_color = newShape;
                        break;
                    }
                    current = current->next_shape;
                }
                shape *current1 = head;
                while (current1 != nullptr) {
                    if (newShape->f == current1->f) {
                        newShape->next_same_form = current1;
                        current1->prev_same_form = newShape;
                        break;
                    }
                    current1 = current1->next_shape;
                }
                head->prev_shap = newShape;
                newShape->next_shape = head;
                head = newShape;
            } else { // insert on right
                shape *current = tail;
                while (current != nullptr) {
                    if (newShape->c == current->c) {
                        newShape->prev_same_color = current;
                        current->next_same_color = newShape;
                        break;
                    }
                    current = current->prev_shap;
                }
                shape *current1 = tail;
                while (current1 != nullptr) {
                    if (newShape->f == current1->f) {
                        newShape->prev_same_form = current1;
                        current1->next_same_form = newShape;
                        break;
                    }
                    current1 = current1->prev_shap;
                }
                tail->next_shape = newShape;
                newShape->prev_shap = tail;
                tail = newShape;
            }
        }
        size++;
        return 1;
    }
}
shape list_shape::delete_shape()
{
    shape deletedShape;

    if (head == nullptr)
    {
        std::cerr << "List is empty. Cannot delete shape." << std::endl;
    }
    else
    {
        deletedShape = *head;
        shape *temp = head;
        head = head->next_shape;
        head->prev_shap = nullptr;
        delete temp;
        size--;
    }

    return deletedShape;
}
void list_shape::delete_all_shapes(list_shape *l)
{
      while (head != nullptr)
    {
        shape *temp = head;
        head = head->next_shape;
        delete temp;
        size--;
    }
    tail = nullptr;

}

void list_shape::delete_three_same_linked() {
    shape *current = head;

    while (current != nullptr) {
        if (current->next_shape != nullptr && current->next_shape->next_shape != nullptr) {
            if ((current->c == current->next_shape->c && current->c == current->next_shape->next_shape->c) ||
                ( current->f == current->next_shape->f && current->f == current->next_shape->next_shape->f)) {
                size -= 3;
                score=score+3;
                shape *temp1 = current;
                shape *temp2 = current->next_shape;
                shape *temp3 = current->next_shape->next_shape;
                if(size==0)
                {
                    head=nullptr;
                    tail=nullptr;
                delete temp1;
                delete temp2;
                delete temp3;

                break;
                }
                if (current == head) {

                    temp3->next_shape->prev_shap = nullptr;

                    head = temp3->next_shape;

                } else if (temp3 == tail) {

                    tail = temp1->prev_shap;
                    tail->next_shape = nullptr;

                } else {
                    temp1->prev_shap->next_shape = temp3->next_shape;
                }

                delete temp1;
                delete temp2;
                delete temp3;

                break;
            }
        }

        current = current->next_shape;
    }
}


void list_shape::display_shapes()
{
    shape *current = head;

    while (current != nullptr)
    {

        current = current->next_shape;
    }

    std::cout << std::endl;
}

list_shape::~list_shape()
{
    while (head != nullptr)
    {
        shape *temp = head;
        head = head->next_shape;
        delete temp;
    }
}

adress *list_shape::address_f_l(Color c,ShapeType f, bool search_by_color) {
    shape *current = head;
    adress *temp = new adress;
    int size = 0;

    while (current != nullptr) {
        if ((search_by_color && current->c == c) || (!search_by_color && current->f == f)) {
            size = 1;
            temp->head1 = current;

            while (current != nullptr) {
                if ((search_by_color && current->next_same_color == nullptr) || (!search_by_color && current->next_same_form == nullptr)) {
                    temp->tail1 = current;
                    std::cout<<" yyy ";
                    temp->size = size;
                    return temp;
                } else {
                    size++;
                    current = (search_by_color) ? current->next_same_color : current->next_same_form;
                }
            }
        }
        current = current->next_shape;
    }

    return temp;
}



void list_shape::drawShape(sf::RenderWindow &window, Color color, ShapeType shapeType, sf::Vector2f position, float size)
{
    sf::Shape *shape;

    switch (shapeType)
    {
    case ShapeType::Square:
        shape = new sf::RectangleShape(sf::Vector2f(size, size));
        break;
    case ShapeType::Diamond:
        shape = new sf::ConvexShape(4);
        static_cast<sf::ConvexShape *>(shape)->setPoint(0, sf::Vector2f(size / 2.f, 0.f));
        static_cast<sf::ConvexShape *>(shape)->setPoint(1, sf::Vector2f(size, size / 2.f));
        static_cast<sf::ConvexShape *>(shape)->setPoint(2, sf::Vector2f(size / 2.f, size));
        static_cast<sf::ConvexShape *>(shape)->setPoint(3, sf::Vector2f(0.f, size / 2.f));
        break;
    case ShapeType::Circle:
        shape = new sf::CircleShape(size / 2.f);
        break;
    case ShapeType::Triangle4:
        shape = new sf::ConvexShape(3);
        static_cast<sf::ConvexShape *>(shape)->setPoint(0, sf::Vector2f(size / 2.f, 0.f));
        static_cast<sf::ConvexShape *>(shape)->setPoint(1, sf::Vector2f(size, size));
        static_cast<sf::ConvexShape *>(shape)->setPoint(2, sf::Vector2f(0.f, size));
        break;
    }

    switch (color)
    {
    case Color::Blue:
        shape->setFillColor(sf::Color::Blue);
        break;
    case Color::Yellow:
        shape->setFillColor(sf::Color::Yellow);
        break;
    case Color::Red:
        shape->setFillColor(sf::Color::Red);
        break;
    case Color::Green:
        shape->setFillColor(sf::Color::Green);
        break;
    }

    shape->setPosition(position);
    window.draw(*shape);
    delete shape; // Freeing dynamically allocated memory
}

void list_shape::display_shapes(sf::RenderWindow &window,float x,float y,int z)

{


    shape *current = head;


    while (current != nullptr)
    {
        drawShape(window, current->c, current->f, sf::Vector2f(x, y), 50.f);
      x=x+64;

        current = current->next_shape;
    }
}
int list_shape::getscore()
{
    return score;
}
void list_shape::setscore(int s)
{
    score=s;
}



// Function to remove links between shapes of the same color
void list_shape::remove_same_color_links()
{
    shape *current = head;

    while (current != nullptr)
    {
        current->prev_same_color = nullptr;
        current->next_same_color = nullptr;
        current = current->next_shape;
    }
}

// Function to remove links between shapes of the same form
void list_shape::remove_same_form_links()
{
    shape *current = head;

    while (current != nullptr)
    {
        current->prev_same_form = nullptr;
        current->next_same_form = nullptr;
        current = current->next_shape;
    }
}

// Function to establish new links between shapes of the same color
void list_shape::link_same_color()
{
    // Remove existing links between shapes of the same color
    remove_same_color_links();

    // Re-establish new links between shapes of the same color
    std::unordered_map<Color, shape*> lastColorMap;

    shape *current = head;

    while (current != nullptr)
    {
        if (lastColorMap.find(current->c) != lastColorMap.end())
        {
            lastColorMap[current->c]->next_same_color = current;
            current->prev_same_color = lastColorMap[current->c];
        }

        lastColorMap[current->c] = current;

        current = current->next_shape;
    }
}

// Function to establish new links between shapes of the same form
void list_shape::link_same_form()
{
    // Remove existing links between shapes of the same form
    remove_same_form_links();

    // Re-establish new links between shapes of the same form
    std::unordered_map<ShapeType, shape*> lastFormMap;

    shape *current = head;

    while (current != nullptr)
    {
        if (lastFormMap.find(current->f) != lastFormMap.end())
        {
            lastFormMap[current->f]->next_same_form = current;
            current->prev_same_form = lastFormMap[current->f];
        }

        lastFormMap[current->f] = current;

        current = current->next_shape;
    }
}

