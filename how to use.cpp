#include <iostream>
#include "bool_vec.hpp"
#include <stdlib.h>

char ch[] = { 0x1 | 0x2 | 0x8, 0x8 | 0x10| 0x4, 0x10 | 0x2 | 0x4};
ib::bool_vec vec = { 24, ch };
char hp[] = { 0x1 | 0x2 | 0x8, 0x8 | 0x10| 0x4, 0x10 | 0x2 | 0x4};
char hr[] = { 0x4 | 0x8 | 0x10, 0x2 | 0x1 | 0x4, 0x8|0x20 | 0x40};
ib::bool_vec vec2 = { 24, hr };

/*
There are uncommented examples given below 
Just compile and run (at your own risk) to observe the output
Don't Blame me for not optimizing code in performance
It is optimized in storage only
This is my first repository on github
For C users-
	remove namespaces
    make replacement for cout
	the functions are named with what they do
	you don't need to know everything about it, just use it
	besides namespace and cout in this file everything is c compatible
If your compiler doesn't support '#pragma once' then please add #ifndef and #endif
*/

int main(){
    for( unsigned int i = 1; i <= vec.size; i++)
        std::cout << ((i % 8 )? (i % 8) : 8) << "  ";
    std::cout << std::endl;
    for( unsigned int i = 0; i < vec.size; i++){
        std::cout << ib::getBit( &vec, i ) << "  ";
    }
    std::cout << "\t<- Original Bits\n";
    for( unsigned int i = 0; i < vec.size; i++ ){
        ib::flipBit( &vec, i );
        std::cout << ib::getBit( &vec, i) << "  ";
    }
    std::cout << "\t<- Flipped Bits\n";
    memcpy( ch, hp, 3);
    for( unsigned int i = 0; i < vec.size; i++ ){
        ib::activateBit( &vec, i );
        std::cout << ib::getBit( &vec, i) << "  ";
    }
    std::cout << "\t<- activated Bits\n";
    memcpy( ch, hp, 3);
    for( unsigned int i = 0; i < vec.size; i++ ){
        ib::eraseBit( &vec, i );
        std::cout << ib::getBit( &vec, i) << "  ";
    }
    std::cout << "\t<- Erased Bits\n\n\n\n";
    for( unsigned int i = 0; i < vec2.size; i++){
        std::cout << ib::getBit( &vec2, i ) << "  ";
    }
    std::cout << "\t<- Original Bits 2\n";
    for( unsigned int i = 0; i < vec.size; i++){
        ib::setBit( &vec, i, ib::getBit(&vec2, i));
        std::cout << ib::getBit( &vec, i ) << "  ";
    }
    std::cout << "\t<- Set Bits of vec2 into vec";
    return 0;
}