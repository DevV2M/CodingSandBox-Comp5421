//
// Created by Vithu Maheswaran on 2022-07-11.
//
#include <iterator>
#include "Canvas.h"

// validates row r and column c, 0-based
bool Canvas::check(int r, int c) const{
    return (r<height && c<width);
}
// resizes this Canvas’s dimensions
void Canvas::resize(size_t rows, size_t cols){
    if(height<rows) {

    }
    if(width<cols){

    }
}

// creates this canvas’s (rows x columns) grid filled with blank characters
Canvas::Canvas(int rows, int columns, char fillChar) : height{rows}, width{columns} {

    for (int i = 0; i < rows; i++) {
        vector<char> r;
        for (int j = 0; j < columns; j++) {
            r.push_back(fillChar);
        }
        grid.push_back(r);
    }
}

int Canvas::getRows() const { return height; }             // returns height of this Canvas object

int Canvas::getColumns() const { return width; }          // returns width of this Canvas object

// Private Helper Function
// Reverse vector<char>'s in vector<vector<char>> object
void Canvas::reverseV (vector<vector<char>>::iterator first, vector<vector<char>>::iterator last) {
    while ((first!=last)&&(first!=--last)) {
        std::iter_swap (first,last);
        ++first;
    }
}

// Private Helper Function
// Reverse char's in vector<char> object
void Canvas::reverseH (vector<char>::iterator first, vector<char>::iterator last) {
    while ((first!=last)&&(first!=--last)) {
        std::iter_swap (first,last);
        ++first;
    }
}


// flips this canvas horizontally
Canvas Canvas::flip_horizontal() {

    Canvas newCan{*this};
    for(auto &vec: newCan.grid)
    reverseH(vec.begin(), vec.end());
    return newCan;
}

// flips this canvas vertically
Canvas Canvas::flip_vertical()  {
    Canvas newCan{*this};
    reverseV(newCan.grid.begin(), newCan.grid.end());
    return newCan;
}

// prints this Canvas to ostream
void Canvas::print(ostream & sout) const {
    for(auto r:grid){
        for(char ch : r ){
            sout<<ch;
        }
        sout<<endl;
    }
}

// throws std::out_of_range{ "Canvas index out of range" }
//if r or c is invalid.
// returns char at row r and column c, 0-based;
char Canvas::get(int r, int c) const {
    if(!check(r,c)){
        throw std::out_of_range{ "Canvas index out of range" };
    }
    return grid.at(r).at(c);
}

// puts ch at row r and column c, 0-based;
// the only function used by a shape’s draw functon;
// throws std::out_of_range{ "Canvas index out of range" }
//if r or c is invalid.
void Canvas::put(int row, int col, char ch) {
    if(!check(row,col)){
        throw std::out_of_range{ "Canvas index out of range" };
    }
    grid.at(row).at(col) = ch;
}

// draws text starting at row r and col c on this canvas
void Canvas::drawString(int r, int c, const std::string text) {
    string str{text};
    string::iterator itr;
    itr = str.begin();
    while(itr!=str.end())
    {
        put(r,c,*itr);
        c++;
        itr++;
    }
}

// copies the non-blank characters of "can" onto the invoking Canvas object;
// maps can’s origin to row r and column c on the invoking Canvas object
void Canvas::overlap(const Canvas &can, size_t r, size_t c) {
    for(int i = 0;i<can.height;i++){
        for(int j = 0;j<can.width;j++){
            if(can.get(r,c)!=' '){
                put(i,j,can.get(r,c));
                c++;
            }
        }
        r++;
    }
}

ostream &operator<<(ostream &sout, const Canvas &can){
    can.print(sout);
    return sout;
}