#ifndef POSITION_H
#define POSITION_H


class Position
{
    public:
        Position();
        Position(int x, int y);
        Position(Position * pos);
        ~Position();
        Position(const Position& other);
        Position& operator=(const Position& other);

        int Getx() { return x; }
        void Setx(int val) { x = val; }
        int Gety() { return y; }
        void Sety(int val) { y = val; }

    protected:

    private:
        int x;
        int y;
};

#endif // POSITION_H
