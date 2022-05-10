/*
 * profiling.h
 */

#ifndef _PROFILING_H_
#define _PROFILING_H_

#define PROFILE


extern int comp; 
#define INC_COMP comp++
#define GET_COMP comp
#define RESET_COMP comp=0

extern int rotations; 
#define INC_ROTATIONS rotations++
#define GET_ROTATIONS rotations
#define RESET_ROTATIONS rotations=0

#endif // _PROFILING_H_
