
// this class for decaler les shapes de meme color
class shape_color_form
{
private:
    adress *adr;
    Color c;
    ShapeType f;

public:
    shape_color_form(Color c1, list_shape *l)
    {

        c = c1;
        adr = l->address_f_l(c,ShapeType::Circle,true);
    }
    shape_color_form(ShapeType f1, list_shape *l)
    {
        f = f1;

        adr = l->address_f_l(Color::Blue,f,false);
    }
    int decaler_color();
    int decaler_form();
};

int shape_color_form::decaler_color()
{
    shape *head, *current, temp,temp1;
    shape *tail;
    if(adr->head1 !=nullptr && adr->tail1 !=nullptr)
    {

      head = adr->head1;
    tail = adr->tail1;

    temp.f = head->f;

    current = head;
    while (current != nullptr)
    {
if (current->next_same_color == nullptr)
        {
            break;
        }

        current->f = current->next_same_color->f;

        current = current->next_same_color;
    }
    tail->f = temp.f;
    return 1;
    }
    else{
        std::cout<<"nullptr";
        return 0;
    }

}

int shape_color_form::decaler_form()
{
    shape *head, *current, temp,temp1;
    shape *tail;
    if(adr->head1 !=nullptr && adr->tail1 !=nullptr)
    {

      head = adr->head1;
    tail = adr->tail1;

    temp.c = head->c;

    current = head;
    while (current != nullptr)
    {
if (current->next_same_form == nullptr)
        {
            break;
        }

        current->c = current->next_same_form->c;

        current = current->next_same_form;
    }
    tail->c = temp.c;
    return 1;
    }
    else{
        std::cout<<"nullptr";
        return 0;
    }

}



