#ifndef AREA_HPP_INCLUDED
#define AREA_HPP_INCLUDED

class Area{
    private:
        string area;

    public;
        Area();
        Area(string _area);
        void setarea(string _area);
        string getarea();
        string toString();

        Area& operator = (const Area&);

        bool operator == (const Area&) const; //== de comparacion
        bool operator != (const Area&) const;
        bool operator < (const Area&) const;
        bool operator <= (const Area&) const;
        bool operator > (const Area&) const;
        bool operator >= (const Area&) const;

        friend ostream& operator<<(ostream& os, const Area& _area);
        friend istream& operator>>(istream& is, const Area& _area);
};


#endif // AREA_HPP_INCLUDED
