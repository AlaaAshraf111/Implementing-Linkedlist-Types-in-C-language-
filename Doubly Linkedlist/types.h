
#ifndef __TYPES_H__
#define __TYPES_H__

typedef unsigned char u8;                     // 1 byte
typedef unsigned  short  u16;              //  2byte
// typedef unsigned  int  u16;              // 4 byte     -----> int == long  as (typedef unsigned  short  u16;            //  2byte)
typedef unsigned int u32;                // 4 byte
// typedef unsigned long int u32;                // 4 byte 
 
typedef signed char s8;                     // 1 byte
typedef signed short int s16;               // 2 byte
typedef signed long int s32;                // 4 byte

typedef  float f32;          // 4 byte             //there is no long float  (compilation error)
typedef  double f64;         // 8 byte
typedef long double f80;     // 16 byte 

#endif