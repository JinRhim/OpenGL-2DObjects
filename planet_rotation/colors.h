#ifndef colors_h
#define colors_h
#include <string>



typedef enum ColorCode
{
    kWHITE = 0,
    kRED,
    kGREEN,
    kBLUE,
    kYELLOW,
    kSalmon,
    kTurquoise,
    kDeepSkyBlue,
    kIndigo,
    kThistle,
    
    kNB_COLORS
}
ColorCode;


static    float    COLOR[kNB_COLORS][4] = {    {1.f, 1.f, 1.f, 1.f},    //    white
                                            {1.f, 0.f, 0.f, 1.f},    //    red
                                            {0.f, 1.f, 0.f, 1.f},    //    green
                                            {0.f, 0.f, 1.f, 1.f},    //    blue
                                            {1.f, 1.f, 0.f, 11.f}  ,  //    yellow
    {250/255.0f, 128/255.0f, 114/255.0f},
    {64/2550.f, 224/255.0f,208/255.0f},
    {0, 191/255.0f, 1.0f},
    {75/255.0f, 0.f, 130/255.0f},
    {216/255.0f, 191/255.0f, 216/255.0f}
    
                                        };

#endif  
