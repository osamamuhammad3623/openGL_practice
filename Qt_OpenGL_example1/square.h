#ifndef SQUARE_H
#define SQUARE_H

enum Direction{
    LEFT, RIGHT
};

struct Square{
    float x_pos{-100};
    float y_pos{-30};

    float width{4};
    float height{5};

    float speed{1};

    Direction state{RIGHT};
};

extern Square square;

#endif // SQUARE_H
