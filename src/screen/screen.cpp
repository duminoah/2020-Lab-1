#include "screen.h"

// Screen's constructor
Screen::Screen(string::size_type height, string::size_type width, char bkground):
    height_{height},// initialises height_ with height
    width_{width},  // initialises width_ with width
    _screen(height * width, bkground)	// size of _screen is height * width
    // all positions initialized with
    // character value of bkground
{ /* all the work is done in the member initialization list */ }

void Screen::forward()
{
    // advance cursor_ one screen element
    ++cursor_;

    // wrap around if the cursor_ is at the end of the screen
    if ( cursor_ == _screen.size()) home();

    return;
}

void Screen::back()
{
    // move cursor_ backward one screen element
    // check for top of screen; wrap around
    if ( cursor_ == TOP_LEFT )
        end();
    else
        --cursor_;

    return;
}

void Screen::up()
{
    // move cursor_ up one row of screen
    // do not wrap around
    if ( row() == 1 ) // at top?
    {
        //cerr << "Screen::up - Cannot wrap around in a vertical direction" << endl;
        //Exercise 4.4: new lines of code for wrapping around vertically
        int sub_num = height_*width_ - width_;
        cursor_ += sub_num;
    }
    else
        cursor_ -= width_;

    return;
}

void Screen::down()
{
    // move cursor_ down one row of screen
    // do not wrap around
    if ( row() == height_ ) // at bottom?
    {
        //cerr << "Screen::down - Cannot wrap around in a vertical direction" << endl;
        //Exercise 4.4: new lines of code for wrapping around vertically
        int sub_num = height_*width_ - width_;
        cursor_ -= sub_num;
    }
    else
        cursor_ += width_;

    return;
}

void Screen::move( string::size_type row, string::size_type col )
{
    // move cursor_ to absolute position
    // valid screen position?
    if ( checkRange( row, col ) )
    {
        // row location
        auto row_loc = (row-1) * width_;
        cursor_ = row_loc + col - 1;
    }

    return;
}

char Screen::get( string::size_type row, string::size_type col )
{
    // position cursor_
    move( row, col );
    // the other get() member function
    return get();
}

void Screen::set( char ch )
{
    if ( ch == '\0' )
        cerr << "Screen::set warning: " << "null character (ignored).\n";
    else _screen[cursor_] = ch;

    return;
}

void Screen::set( const string& s )
{
    // write string beginning at current cursor_ position
    auto space = remainingSpace();
    auto len = s.size();
    if ( space < len )
    {
        cerr << "Screen::set - Truncating, "
             << "space available: " << space
             << ", string length: " << len
             << endl;
        len = space;
    }

    _screen.replace( cursor_, len, s );
    cursor_ += len - 1;

    return;
}

void Screen::clear( char bkground )
{
    // reset the cursor and clear the screen
    cursor_ = TOP_LEFT;
    // assign the string
    _screen.assign(
        // with size() characters
        _screen.size(),
        // of value bkground
        bkground
    );

    return;
}

void Screen::reSize( string::size_type h, string::size_type w, char bkground )
{
    // can only *increase* a screen's size to height h and width w
    // remember the content of the screen
    string local{_screen};
    auto local_pos = TOP_LEFT;

    // replaces the string to which _screen refers
    _screen.assign(      // assign the string
        h * w,           // with h * w characters
        bkground         // of value bkground
    );

    // copy content of old screen into the new one
    for ( string::size_type ix = 0; ix < height_; ++ix )
    {
        // for each row
        string::size_type offset = w * ix; // row position
        for ( string::size_type iy = 0; iy < width_; ++iy )
            // for each column, assign the old value
            _screen.at(offset + iy) = local[ local_pos++ ];
    }

    height_ = h;
    width_ = w;
    // cursor_ remains unchanged

    return;
}

void Screen::display() const
{
    for ( string::size_type ix = 0; ix < height_; ++ix )
    {
        // for each row
        string::size_type offset = width_ * ix; // row position
        for ( string::size_type iy = 0; iy < width_; ++iy )
            // for each column, write element
            cout << _screen[ offset + iy ];
        cout << endl;
    }
    return;
}

bool Screen::checkRange( string::size_type row, string::size_type col ) const
{
    // validate coordinates
    if (row < 1 || row > height_ || col < 1 || col > width_)
    {
        cerr << "Screen coordinates ("<< row << ", " << col << " ) out of bounds.\n";
        return false;
    }
    return true;
}

string::size_type Screen::remainingSpace() const
{
    // includes current position
    auto size = width_ * height_;
    return(size - cursor_);
}

string::size_type Screen::row() const
{
    // return current row
    return (cursor_ + width_)/width_;
}
//Exercise 4.3 Direction Function Implementation
void Screen::move(Direction dir)
{
    switch(dir)
    {
    case Direction::HOME:
        cursor_ = 0;
        break;
    case Direction::FORWARD:
        ++cursor_;
        if ( cursor_ == _screen.size()) home();
        break;
    case Direction::BACK:
        if ( cursor_ == TOP_LEFT )end();
        else
            --cursor_;
        break;
    case Direction::UP:
        if ( row() == 1 ) // at top?
        {
            //cerr << "Screen::up - Cannot wrap around in a vertical direction" << endl;
            //Exercise 4.4: new lines of code for wrapping around vertically
            int sub_num = height_*width_ - width_;
            cursor_ += sub_num;
        }
        else
            cursor_ -= width_;
        break;
    case Direction::DOWN:
        if ( row() == height_ ) // at bottom?
        {
            //cerr << "Screen::down - Cannot wrap around in a vertical direction" << endl;
            //Exercise 4.4: new lines of code for wrapping around vertically
            int sub_num = height_*width_ - width_;
            cursor_ -= sub_num;
        }
        else
            cursor_ += width_;
        break;
    case Direction::END:
        cursor_ = width_ * height_ - 1;
        break;
    }
}

//Exercise 4.5:Draw Square Function
void Screen::drawSquare(string::size_type x, string::size_type y,string::size_type boxWidth, string::size_type boxHeight) //const
{
    move(x,y);//move to the position specified by x,y coordinates;
    box_width = boxWidth;//store box width and height in member variables
    box_height = boxHeight;
    //Program executes only if
    auto hor_space = hor_remainingSpace(y);//finding the remaining space horizontal to the placed coordinate
    auto ver_space = ver_remainingSpace();// finding the remaining space vertical the the placed coordinate
    if(x < width_ && y < height_ && isSquare())//box should be a square and coordinates should be within the screen size
    {
        if(hor_space < boxWidth-1)//if horizontal remaining space is less than the specified box length there should be truncation
        {
            cerr << "Screen::drawSquare - Truncating horizontal part of square, "
                 << "space available: " << hor_space
                 << ", square length: " << box_width
                 << endl;

        }
        if(ver_space < boxHeight-1)//if vertical remaining space is less than the specified box length there should be truncation
        {
            cerr << "Screen::drawSquare - Truncating vertical part of square, "
                 << "space available: " << ver_space
                 << ", square height: " << box_height
                 << endl;

        }
        set('x');
        for(string::size_type i = 0; i < box_width-1; i++)
        {
            if(i == hor_space)
            {
                goto opposite_side;
            }
            forward();
            set('x');
        }
        for(string::size_type i = 0; i < box_height-1; i++)
        {
            if(i == ver_space)
            {
                break;
            }
            down();
            set('x');
        }
opposite_side:
        ;
        move(x,y);
        for(string::size_type i = 0; i < box_width-1; i++)
        {
            if(i == ver_space)
            {
                goto end;
            }
            down();
            set('x');

        }
        for(string::size_type i = 0; i < box_height-1; i++)
        {
            if(i == hor_space)
            {
                break;
            }
            forward();
            set('x');

        }
end:
        ;
    }
}

string::size_type Screen::hor_remainingSpace(string::size_type col) const
{
    auto edge_cursor = (cursor_ + (width_ - col));
    return (edge_cursor-cursor_);
}
string::size_type Screen::ver_remainingSpace() const
{
    auto row_num = row();
    return (height_-row_num);
}
bool Screen::isSquare()const
{
    if(box_height != box_width)
    {
        cout <<"Not Square"<< endl;
        return false;
    }
    return true;
}
