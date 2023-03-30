#pragma once
#include <malloc.h>
#define IB_FULL_BYTE 0xff

namespace ib{
    typedef struct{
        long long   size;
        char*       Ptr;
    } bool_vec;

    bool_vec    generate_bool_vec( long long size );
    bool        getBit( bool_vec* vec, long long bit);
    void        flipBit( bool_vec* vec, long long bit );
    void        activateBit( bool_vec* vec, long long bit );
    void        eraseBit( bool_vec* vec, long long bit );
    void        setBit( bool_vec* vec, long long bit, bool bit_value);
}

ib::bool_vec ib::generate_bool_vec( long long size ){
    ib::bool_vec ret_val;
    long long malloc_size = size / 8 + ( 8 - size) % 8 ? 1 : 0;
    ret_val.size = malloc_size;
    ret_val.Ptr = (char*) malloc( size );
    return ret_val;
}

inline bool ib::getBit( ib::bool_vec *vec, long long bit ){
    return (vec->Ptr[ (bit - 1) / 8 ] >> ((bit - 1) % 8)+1) & 0x1;
}

inline void ib::flipBit( ib::bool_vec* vec, long long bit ){
    vec->Ptr[ (bit - 1)/8] ^= (1 << ((bit)%8));
}

inline void ib::activateBit( ib::bool_vec* vec, long long bit ){
    vec->Ptr[ (bit - 1)/8] |= (1 << ((bit)%8));
}

inline void ib::eraseBit( ib::bool_vec* vec, long long bit ){
    vec->Ptr[ (bit - 1)/8] &= IB_FULL_BYTE ^ (1 << ((bit)%8));
}

inline void ib::setBit( ib::bool_vec* vec, long long bit, bool bit_value){
    if( !ib::getBit( vec, bit) && bit_value )
        ib::flipBit( vec, bit);
    else if( ib::getBit( vec, bit) && !bit_value)
        ib::flipBit( vec, bit );
}