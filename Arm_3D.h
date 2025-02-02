#ifndef ARM_3D_H
#define ARM_3D_H
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"



typedef struct {
    Vector3 pos;
    Vector3 rot;
    Vector3 rot_min;
    Vector3 rot_max;
    float rt;
    float h;
    int slice;
    Color color;
    Model model;
} ARM;

#endif
