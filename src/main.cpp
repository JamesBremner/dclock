#include <iostream>
#include "wex.h"

using namespace std;
using namespace wex;

class segment
{
public:
    segment(  )
    {

    }

    // set index number
    void set( int k );

    vector<int> display() const
    {
        vector< int > r;
        r.push_back( myR[0] * scale );
        r.push_back( myR[1] * scale );
        r.push_back( myR[2] * scale );
        r.push_back( myR[3] * scale );
        return r;
    }

    static int scale;

private:
    vector<int> myR;
};

class number : public panel
{
public:
    number( gui* parent )
        : panel( parent )
        , myNumber( 1 )
    {
        for( int k=0; k<16; k++ )
        {
            mySegment[k].set(k);
        }
    }
    void set( int n )
    {
        myNumber = n;
    }
    void draw( PAINTSTRUCT& ps );

private:
    int myNumber;
    segment mySegment[16];
};

int segment::scale = 1;

void segment::set( int k )
{
    int w = 3;
    int h = 5;

    switch( k )
    {
    case 0:
        myR.push_back( 1 );
        myR.push_back( 0 );
        myR.push_back( 3 );
        myR.push_back( 1 );
        break;
    case 1:
        myR.push_back( w+2 );
        myR.push_back( 0 );
        myR.push_back( 3 );
        myR.push_back( 1 );
        break;
    case 2:
        myR.push_back( 2*w+2 );
        myR.push_back( 1 );
        myR.push_back( 1 );
        myR.push_back( h );
        break;
    case 3:
        myR.push_back( 2*w+2 );
        myR.push_back( h+2 );
        myR.push_back( 1 );
        myR.push_back( h );
        break;
    case 4:
        myR.push_back( w+2 );
        myR.push_back( 2*h+2 );
        myR.push_back( w );
        myR.push_back( 1 );
        break;
    case 5:
        myR.push_back( 1 );
        myR.push_back( 2*h+2 );
        myR.push_back( w );
        myR.push_back( 1 );
        break;
    case 6:
        myR.push_back( 0 );
        myR.push_back( h+2 );
        myR.push_back( 1 );
        myR.push_back( h );
        break;
    case 7:
        myR.push_back( 0 );
        myR.push_back( 1 );
        myR.push_back( 1 );
        myR.push_back( h );
        break;
    case 8:
        myR.push_back( w+1 );
        myR.push_back( 1 );
        myR.push_back( 1 );
        myR.push_back( 2*h+1 );
        break;
    case 10:
        myR.push_back( 1 );
        myR.push_back( h+1 );
        myR.push_back( 2*w+1 );
        myR.push_back( 1 );
        break;
    }
}

void number::draw( PAINTSTRUCT& ps )
{
    shapes S( ps );
    S.color( 0x0ab4ff );
    S.bgcolor( 0 );
    S.fill();
    //S.text(to_string(myNumber),{1,1,20,30});
    segment::scale = 10;
    switch( myNumber )
    {
    case 0:
        S.rectangle( mySegment[0].display() );
        S.rectangle( mySegment[1].display() );
        S.rectangle( mySegment[2].display() );
        S.rectangle( mySegment[3].display() );
        S.rectangle( mySegment[4].display() );
        S.rectangle( mySegment[5].display() );
        S.rectangle( mySegment[6].display() );
        S.rectangle( mySegment[7].display() );
        break;
    case 1:
        S.rectangle( mySegment[0].display() );
        S.rectangle( mySegment[8].display() );
        break;
    case 2:
        S.rectangle( mySegment[0].display() );
        S.rectangle( mySegment[1].display() );
        S.rectangle( mySegment[2].display() );
        S.rectangle( mySegment[4].display() );
        S.rectangle( mySegment[5].display() );
        S.rectangle( mySegment[6].display() );
        S.rectangle( mySegment[10].display() );
        break;
    case 3:
        S.rectangle( mySegment[0].display() );
        S.rectangle( mySegment[1].display() );
        S.rectangle( mySegment[2].display() );
        S.rectangle( mySegment[3].display() );
        S.rectangle( mySegment[4].display() );
        S.rectangle( mySegment[5].display() );
        S.rectangle( mySegment[10].display() );
        break;
    case 4:
        S.rectangle( mySegment[2].display() );
        S.rectangle( mySegment[3].display() );
        S.rectangle( mySegment[7].display() );
        S.rectangle( mySegment[10].display() );
        break;
    case 5:
        S.rectangle( mySegment[0].display() );
        S.rectangle( mySegment[1].display() );
        S.rectangle( mySegment[3].display() );
        S.rectangle( mySegment[4].display() );
        S.rectangle( mySegment[5].display() );
        S.rectangle( mySegment[7].display() );
        S.rectangle( mySegment[10].display() );
        break;
    case 6:
        S.rectangle( mySegment[0].display() );
        S.rectangle( mySegment[1].display() );
        S.rectangle( mySegment[3].display() );
        S.rectangle( mySegment[4].display() );
        S.rectangle( mySegment[5].display() );
        S.rectangle( mySegment[6].display() );
        S.rectangle( mySegment[7].display() );
        S.rectangle( mySegment[10].display() );
        break;
    case 7:
        S.rectangle( mySegment[0].display() );
        S.rectangle( mySegment[1].display() );
        S.rectangle( mySegment[2].display() );
        S.rectangle( mySegment[3].display() );
        break;
    case 8:
        S.rectangle( mySegment[0].display() );
        S.rectangle( mySegment[1].display() );
        S.rectangle( mySegment[2].display() );
        S.rectangle( mySegment[3].display() );
        S.rectangle( mySegment[4].display() );
        S.rectangle( mySegment[5].display() );
        S.rectangle( mySegment[6].display() );
        S.rectangle( mySegment[7].display() );
        S.rectangle( mySegment[10].display() );
        break;
    case 9:
        S.rectangle( mySegment[0].display() );
        S.rectangle( mySegment[1].display() );
        S.rectangle( mySegment[2].display() );
        S.rectangle( mySegment[3].display() );
        S.rectangle( mySegment[4].display() );
        S.rectangle( mySegment[5].display() );
        S.rectangle( mySegment[7].display() );
        S.rectangle( mySegment[10].display() );
        break;
    }
}

int main()
{
    gui& form = maker::make();
    form.move({ 50,50,1000,400});
    form.text("Digital Clock");
    form.bgcolor( 0x000000 );

    number& secs0 = maker::make<number>( form );
    secs0.move( { 5, 5, 100, 200});
    secs0.set( 0 );
    number& secs1 = maker::make<number>( form );
    secs1.move( { 105, 5, 100, 200});
    secs1.set( 1 );
    number& secs2 = maker::make<number>( form );
    secs2.move( { 205, 5, 100, 200});
    secs2.set( 2 );
    number& secs3 = maker::make<number>( form );
    secs3.move( { 305, 5, 100, 200});
    secs3.set( 3 );
    number& secs4 = maker::make<number>( form );
    secs4.move( { 405, 5, 100, 200});
    secs4.set( 4 );
    number& secs5 = maker::make<number>( form );
    secs5.move( { 505, 5, 100, 200});
    secs5.set( 5 );
    number& secs6 = maker::make<number>( form );
    secs6.move( { 605, 5, 100, 200});
    secs6.set( 6 );
    number& secs7 = maker::make<number>( form );
    secs7.move( { 705, 5, 100, 200});
    secs7.set( 7 );
    number& secs8 = maker::make<number>( form );
    secs8.move( { 805, 5, 100, 200});
    secs8.set( 8 );
        number& secs9 = maker::make<number>( form );
    secs9.move( { 905, 5, 100, 200});
    secs9.set( 9 );
    form.show();
    form.run();
    return 0;
}
